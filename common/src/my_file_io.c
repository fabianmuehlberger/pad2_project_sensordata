#include <stdio.h>
#include <stdlib.h>
#include "my_file_io.h"
#include "my_structure.h"
#include "my_validation.h"
#include "my_helpers.h"
#include <math.h>
#include <string.h>

//DEFINES
#define FILEBUFFER 256
#define NAMELEN 80

#define DT 0.02 // [s/loop] loop period. 20ms
#define AA 0.97 // complementary filter constant

#define A_GAIN 0.0573 // [deg/LSB]
#define G_GAIN 0.070  // [deg/s/LSB]
#define RAD_TO_DEG 57.29578
#define M_PI 3.14159265358979323846

void openDestinationFile(); //Funktions Reihenfolge Debug


void removeNewLineFromString(char *line)
{
    int new_line = strlen(line) - 1;
    if (line[new_line] == '\n')
    {
        line[new_line] = '\0';
    }
}

// 1: DATEN LESEN 
void readSourceFile(char *fileName)
{
     // 1. Funktion: openSourceFile() in extra funktion auslagern
    FILE *pFile = fopen(fileName, "r");
    if (pFile == NULL)
    {
        printf("ERROR could not open source File\n");
        exit(-1);
    }
    else
    {
        printf("File opened...\n");
    }

    openDestinationFile();  //Aufruf 
}
    // end of openSourcefile(). 

        void openDestinationFile() //Ausgelagert in eigene Funktion
{
    int validationcheck = 0;
    int lines = 1;
    char buffer[FILEBUFFER];
    // Falls moeglich: 1 und 2 Funktion durch eine Allgemeine Funktion ersetzen
    FILE *pWriteFile;
    pWriteFile = fopen("raw_Data.csv", "w+");
    if (pWriteFile == NULL)
    {
        printf("ERROR could not open destination File\n");
    }

    FILE *pFile;
      while (fgets(buffer, FILEBUFFER, pFile) != NULL)
    {
        /*
        if (lineValidatonChecks(buffer, lines))
        {
            validationcheck = 1;
        }
        */
        removeNewLineFromString(buffer);

        fprintf(pWriteFile, "%d;%d;%s\n", lines, validationcheck, buffer);

        validationcheck = 0;
        lines++;
    }
    printf("\nEnd of READFILE\n");
     fclose(pWriteFile);
     fclose(pFile);
    //end of openDestinationFile
}

// DATEN AUS DESTINATION LESEN UND IN RAW STRUKTUR SPEICHERN 
Raw_Data readRawDataFromCSV(char *buffer)
{
    Raw_Data tmpData;

    char *curser;
    char seperator[] = ";";

    curser = strtok(buffer, seperator);
    tmpData.index = atof(curser);

    curser = strtok(NULL, seperator);
    tmpData.validationCheck = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.timeStampMS = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.acc_X = (int)strtoul(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.acc_Y = (int)strtoul(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.acc_Z = (int)strtoul(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.gyro_X = (int)strtoul(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.gyro_Y = (int)strtoul(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.gyro_Z = (int)strtoul(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.mag_X = (int)strtoul(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.mag_Y = (int)strtoul(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.mag_Z = (int)strtoul(curser, NULL, 16);

    // TO FIX!!!!
    return tmpData;
}
// KOVERTIERUNG DER RAW DATEN IN CLEAN DATEN 
Clean_Data dataConversion(Raw_Data rawData)
{
    Clean_Data tmpData;

    float rate_gyr_y = 0.0; // [deg/s]
    float rate_gyr_x = 0.0; // [deg/s]
    float rate_gyr_z = 0.0; // [deg/s]

    //Convert Gyro raw to degrees per second
    rate_gyr_x = (float)rawData.gyro_X * G_GAIN;
    rate_gyr_y = (float)rawData.gyro_Y * G_GAIN;
    rate_gyr_z = (float)rawData.gyro_Z * G_GAIN;

    //Calculate the angles from the gyro
    tmpData.gyroXangle += rate_gyr_x * DT;
    tmpData.gyroYangle += rate_gyr_y * DT;
    tmpData.gyroZangle += rate_gyr_z * DT;

    //Convert Accelerometer values to degrees
    tmpData.AccXangle = (float)(atan2(rawData.acc_Y, rawData.acc_Z) + M_PI) * RAD_TO_DEG;
    tmpData.AccYangle = (float)(atan2(rawData.acc_Z, rawData.acc_X) + M_PI) * RAD_TO_DEG;

    changeAccAxis(&tmpData);
    
    //Complementary filter used to combine the accelerometer and gyro values.
    tmpData.CFangleX = AA * (tmpData.CFangleX + rate_gyr_x * DT) + (1 - AA) * tmpData.AccXangle;
    tmpData.CFangleY = AA * (tmpData.CFangleY + rate_gyr_y * DT) + (1 - AA) * tmpData.AccYangle;

    return tmpData;
}

// 2. DATEN AUS DESTINATION LESEN 
void readRawDataFile(char *fileNameDestination)
{
    FILE *pDestOpen = fopen(fileNameDestination, "r");

    char buffer[FILEBUFFER];
    int lines = 0;

    Raw_Data someData;
    Clean_Data anotherDataPoint;

    while (fgets(buffer, FILEBUFFER, pDestOpen) != NULL)
    {
        someData = readRawDataFromCSV(buffer);
        
        anotherDataPoint = dataConversion(someData);

        printDataToCleanData(anotherDataPoint);
        lines++;
    }     
}

void printDataToCleanData(Clean_Data theData)
{
    FILE *pClean;
    pClean = fopen("cleanData.csv", "a+");
    fprintf(pClean, "gyro angle: X: %f ", theData.gyroXangle);
}

// KALKULATIONEN 
void changeAccAxis(Clean_Data *tmp)
{
    //Change the rotation value of the accelerometer to -/+ 180 and move the Y axis '0' point to up.
    //Two different pieces of code are used depending on how your IMU is mounted.
    //If IMU is upside down

    //If IMU is up the correct way, use these lines
    tmp->AccXangle -= (float)180.0;
    if (tmp->AccYangle > 90)
        tmp->AccYangle -= (float)270;
    else
        tmp->AccYangle += (float)90;

    /*
	if (AccXangle >180)
		AccXangle -= (float)360.0;

		AccYangle-=90;
	if (AccYangle >180)
			AccYangle -= (float)360.0;
    */
}

// PRINT DER RAW DATENSTRUKTUR
void printRawData(Raw_Data data)
{
    printf("Acc: %i %i %i  | Gyro: %i %i %i  | Magn: %i %i %i\n",
           data.acc_X, data.acc_Y, data.acc_Z,
           data.gyro_X, data.gyro_Y, data.gyro_Z,
           data.mag_X, data.mag_Y, data.mag_Z);
}

// PRINT DER CLEAN DATENSTRUKTUR
void printCleanData(Clean_Data data)
{
    printf("Gyro: %f %f %f  | Acc: %f %f   | CFangle: %f %f \n",
           data.gyroXangle, data.gyroYangle, data.gyroZangle,
           data.AccXangle, data.AccYangle,
           data.CFangleX, data.CFangleY);
}


//old f

int my_file_io_Test()
{
    return 1;
}

void getUserInputStringFromConsole(char *fileName)
{
    do
    {
        scanf("%s", fileName);
    } while (getchar() != '\n');
}

void printHelp()
{
    printf("\nHauptmenu: (Auswahl treffen)\n"
           "p: Messpunkte printen\n"
           "h: Hauptmenu\n"
           "e: exit\n");
}

void printData()
{
    printf("printsData\n");
}
