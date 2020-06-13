#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_file_io.h"
#include "my_structure.h"
#include "my_validation.h"
#include "sensor_config.h"

int my_file_io_Test()
{
    return 1;
}

FILE *openCSVFile(char *fileName, FILE *pFile, char *mode)
{
    FILE *tmp = fopen(fileName, mode);
    if (tmp == NULL)
    {
        printf("ERROR could not open %s File\n", fileName);
        exit(-1);
    }
    else
    {
        //printf("File %s opened...\n", fileName);
    }
    pFile = tmp;
    return pFile;
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

void writeToCleanDataCSV(Clean_Data tmp, char *FileName_CleanData)
{
    /*
    pClean = fopen(FileName_CleanData, "a+");
    */
    FILE *pClean = NULL;
    if (pClean = openCSVFile(FileName_CleanData, pClean, "a"))
    {
        fprintf(pClean, "%f;%f;%f;%f;%f;%f;%f;\n",
                tmp.gyroXangle,
                tmp.gyroYangle,
                tmp.gyroZangle,
                tmp.AccXangle,
                tmp.AccYangle,
                tmp.CFangleX,
                tmp.CFangleY);
    }
    
/*
    if (pClean == NULL)
    {
        printf("COULD NOT OPEN FILE!\n");
    }
*/
    fclose(pClean);
}