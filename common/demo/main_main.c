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

int main(void)
{
    printf("Start of main\n");

    Raw_Data RawDataArray;
    allocateMemoryForRawDataArray(&RawDataArray);

    Clean_Data CleanDataArray;
    allocateMemoryForCleanDataArray(&CleanDataArray);

    /*
    char sourceFileName[NAMELEN] = ".\\ressources\\source_data.csv";
    char rawFileName[NAMELEN] = ".\\ressources\\raw_data.csv";
    char cleanFileName[NAMELEN] = ".\\ressources\\clean_data.csv";
    char errorLogFileName[NAMELEN] = ".\\ressources\\error_log.csv";
*/

    char sourceFileName[NAMELEN] = "..\\..\\ressources\\source_data.csv";
    char rawFileName[NAMELEN] = "..\\..\\ressources\\raw_data.csv";
    char cleanFileName[NAMELEN] = "..\\..\\ressources\\clean_data.csv";
    char errorLogFileName[NAMELEN] = "..\\..\\ressources\\error_log.csv";

    //variable to keep the main while loop going
    int alive = 1;

    while (alive != 0)
    {
        printf("_____WELCOME_____\n");
        printf("enter number to choose option: ");
    
        int auswahl = 0;
        scanf("%d", &auswahl);
        
        switch (auswahl)
        {
        case 1:
            printf("reading source file...\n");
            readSourceFile(sourceFileName, rawFileName, errorLogFileName);
            break;
        case 2:
            printf("Option two\n");
            readRawDataFile(rawFileName, cleanFileName);
            break;
        case 3:
            printf("Option three\n");
            printf("show help\n");
        case 4:
            printf("Option 4 \n");
            break;
        default:
            printf("choosen number not supported\n");
            break;
        }
    }
  
    

    //printRawData(RawDataArray);
    //printCleanData(CleanDataArray);
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
    fclose(fp_WriteRawDataFile);
    printf("\nEnd of READFILE\n");
}

void readRawDataFile(char *fileName_RawData, char *fileName_CleanData)
{
    printf("Reading RawData:....\n");

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
    }
    fclose(fp_ReadRaw);

    printf("END OF READ RAW DATA\n");
}