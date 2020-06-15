#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "my_structure.h"
#include "sensor_config.h"
#include "my_file_io.h"
#include "my_helpers.h"
#include "my_validation.h"

#define NAMELEN 80
#define FILEBUFFER 256

void readSourceFile(char *sourceFileName, char *rawFileName, char *errorFileName);
void readRawDataFile(char *fileName_RawData, char *fileName_CleanData);
void printRawData(Raw_Data RawDataArray);
void printCleanData(Clean_Data CleanDataArray);

int main(void)
{
    // PLACEHOLDER
    Raw_Data RawDataArray;
    allocateMemoryForRawDataArray(&RawDataArray);

    // PLACEHOLDER
    Clean_Data CleanDataArray;
    allocateMemoryForCleanDataArray(&CleanDataArray);

    //Path regulator
    /*
    char sourceFileName[NAMELEN] = ".\\ressources\\source_data.csv";
    char rawFileName[NAMELEN] = ".\\ressources\\raw_data.csv";
    char cleanFileName[NAMELEN] = ".\\ressources\\clean_data.csv";
    char errorLogFileName[NAMELEN] = ".\\ressources\\error_log.csv";
*/

    char sourceFileName[NAMELEN] = "..\\..\\ressources\\test_data.csv";    // <- realfile/ testfile:   "\\source_data.csv"
    char rawFileName[NAMELEN] = "..\\..\\ressources\\raw_data.csv";
    char cleanFileName[NAMELEN] = "..\\..\\ressources\\clean_data.csv";
    char errorLogFileName[NAMELEN] = "..\\..\\ressources\\error_log.csv";

    
    int alive = 1; //keeps the main while loop alive
    printf("\n_____WELCOME_____\n");
    printHelp(); 

    while (alive != 0)
    {
        printf("\nenter a number to choose option: ");

        int auswahl = 0;
        scanf("%d", &auswahl);
        
        switch (auswahl)
        {
        case 1:
            printf("\n| reading source file... |\n\n");
            readSourceFile(sourceFileName, rawFileName, errorLogFileName);
            break;
        case 2:
            printf("\n| reading RawDataFile... |\n\n");
            readRawDataFile(rawFileName, cleanFileName);
            break;
        case 3:
            printf("\n| printing RawData... |\n");
            printRawData(RawDataArray);
            break;
        case 4:
            printf("\n| printing CleanData... |\n");
            printCleanData(CleanDataArray);
            break;
        case 5:
            printHelp();
            break;
        case 6: 
            printf("\n| END OF PROGRAM |");
            alive = 0;
            break;
        default:
            printf("\n| choosen number not supported |\n");
            break;
        }
    }   
}

void readSourceFile(char *sourceFileName, char *rawFileName, char *errorFileName)
{
    int validationcheck = 0;
    int lines = 1;
    char buffer[FILEBUFFER];

    FILE *fp_ReadSourceFile = NULL;
    fp_ReadSourceFile = openCSVFile(sourceFileName, fp_ReadSourceFile, "r");

    FILE *fp_WriteRawDataFile = NULL;
    fp_WriteRawDataFile = openCSVFile(rawFileName, fp_WriteRawDataFile, "w");

    printf("errors in CSV file detected -> ");

    while (fgets(buffer, FILEBUFFER, fp_ReadSourceFile) != NULL)
    {

        if (lineValidatonChecks(buffer, lines, errorFileName))
        {
            validationcheck = 1;
        }

        removeNewLineFromString(buffer);

        fprintf(fp_WriteRawDataFile, "%d;%d;%s\n", lines, validationcheck, buffer);

        validationcheck = 0;
        lines++;
    }

    fclose(fp_ReadSourceFile);
    fclose(fp_WriteRawDataFile);;
    printf("\nsource Data -> Data validation -> raw Data -> (raw_data.csv generated)\n");
}

void readRawDataFile(char *fileName_RawData, char *fileName_CleanData)
{
    printf("Reading RawData:..");
    
    FILE *fp_ReadRaw = NULL;
    fp_ReadRaw = openCSVFile(fileName_RawData, fp_ReadRaw, "r");

    char buffer[FILEBUFFER];
    int lines = 0;

    Raw_Data tmp_RawData;
    Clean_Data tmp_CleanData;

    while (fgets(buffer, FILEBUFFER, fp_ReadRaw) != NULL)
    {
        tmp_RawData = readRawDataFromCSV(buffer);

        tmp_CleanData = convertRawToClean(tmp_RawData);

        writeToCleanDataCSV(tmp_CleanData, fileName_CleanData);
        lines++;
        loadingBar(lines);
    }
    fclose(fp_ReadRaw);
    printf("\n\nraw Data -> Data conversion -> Clean -> (clean_data.csv generated)\n");
}