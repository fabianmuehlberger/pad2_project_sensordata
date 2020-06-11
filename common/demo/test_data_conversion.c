#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//DEFINES

#define DT 0.02 // [s/loop] loop period. 20ms
#define AA 0.97 // complementary filter constant

#define A_GAIN 0.0573 // [deg/LSB]
#define G_GAIN 0.070  // [deg/s/LSB]
#define RAD_TO_DEG 57.29578
#define M_PI 3.14159265358979323846

//#define ACC_GAIN 0.732 // [mg/LBS] (FS:+-16g)
//#define MAG_GAIN 0.43 // [mgauss/LBS] (FS:+-12gauss)
//#define GYRO_GAIN 70 // [mdps/LBS] (FS:+-2000dps)

typedef struct Raw_Data
{
    int index;
    int validationCheck;
    int timeStampMS;

    int acc_X;
    int acc_Y;
    int acc_Z;

    int gyro_X;
    int gyro_Y;
    int gyro_Z;

    int mag_X;
    int mag_Y;
    int mag_Z;

} Raw_Data;

typedef struct Clean_Data
{
    float gyroXangle;
    float gyroYangle;
    float gyroZangle;

    float AccYangle;
    float AccXangle;

    float CFangleX;
    float CFangleY;

} Clean_Data;

Raw_Data readRawDataFromCSV(char *buffer);
Clean_Data dataConversion(Raw_Data rawData);

void printRawData(Raw_Data someData);
void printCleanData(Clean_Data c_data);

void changeAccAxis(Clean_Data *tmp);

int main(void)
{
    char string[200];
    strcpy(string, "1;0;00000005;fffffff3;ffffffe7;0000056e;ffffffee;ffffffdd;fffffff7;000001e8;000000e8;fffffba4");

    Raw_Data dataPoint;
    Clean_Data theData;

    dataPoint = readRawDataFromCSV(string);

    theData = dataConversion(dataPoint);

    printRawData(dataPoint);
    printCleanData(theData);
}

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

void printRawData(Raw_Data data)
{
    printf("Acc: %i %i %i  | Gyro: %i %i %i  | Magn: %i %i %i\n",
           data.acc_X, data.acc_Y, data.acc_Z,
           data.gyro_X, data.gyro_Y, data.gyro_Z,
           data.mag_X, data.mag_Y, data.mag_Z);
}

void printCleanData(Clean_Data data)
{
    printf("Gyro: %f %f %f  | Acc: %f %f   | CFangle: %f %f \n",
           data.gyroXangle, data.gyroYangle, data.gyroZangle,
           data.AccXangle, data.AccYangle,
           data.CFangleX, data.CFangleY);
}


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

    return tmpData;
}