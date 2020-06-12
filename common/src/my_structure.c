#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_structure.h"
#include "my_validation.h"


void printRawData(Raw_Data someData);

void printCleanData(Clean_Data c_data);

void changeAccAxis(Clean_Data *tmp);

void removeNewLineFromString(char *line);

void printDataToCleanData(Clean_Data data);

/*
void createArray(Data *dataArray, int lineCount)
{
    Data *tmp = malloc(lineCount * sizeof(Data));
    if (tmp == NULL)
    {
        printf("NO MEMORY ALLOCATED");
        exit(-1);
    }
    dataArray = tmp;
}


Data writeDataToStructureArray(char *buffer)
{
    Data tmpData;

    char *curser;
    char seperator[] = ";";

    curser = strtok(buffer, seperator);
    tmpData.timeStampMS = atof(curser);

    curser = strtok(NULL, seperator);
    tmpData.gyro_X = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.gyro_Y = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.gyro_z = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.acc_X = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.acc_Y = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.acc_Z = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.mag_X = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.mag_Y = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.mag_Z = (int)strtol(curser, NULL, 16);

    return tmpData;
}

*/