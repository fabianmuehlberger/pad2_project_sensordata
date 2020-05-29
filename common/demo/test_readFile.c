#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "my_validation/my_validation.h"

#define FILEBUFFER 80
#define NAMELEN 40

typedef struct Data
{
    int timeStamp;
    int accelerometer_X;
    int accelerometer_Y;
    int accelerometer_Z;

    int gyroscope_X;
    int gyroscope_Y;
    int gyroscope_Z;

    int magnetometer_X;
    int magnetometer_Y;
    int magnetometer_Z;
} Data;

int checkFile(char *p);

int main(void)
{

    FILE *pFile;
    char buffer[FILEBUFFER];

    int pTimeStamp;

    int *ptr1, *ptr2, *ptr3;

    int accelerometer_X, accelerometer_Y, accelerometer_Z;
    int gyroscope_X, gyroscope_Y, gyroscope_Z;
    int magnetometer_X, magnetometer_Y, magnetometer_Z;

    char stringToken = ';';

    //help to count lines

    char fileName[NAMELEN] = "../../ressources/test_data.csv";

    //open File
    pFile = fopen(fileName, "r");
    if (pFile == NULL)
    {
        printf("ERROR could not open File\n");
        exit(-1);
    }
    else
    {
        printf("File opened\n");
    }


    //check Line Count of opened File
    int lineCount = checkLineCount(&pFile);
    printf("LineCount2 = %i\n", lineCount);

    //checkl File Size of opened File
    int fileSize = checkFileSize(&pFile);

    printf("Filesize = %d\n", fileSize);

    fclose(pFile);
}
