#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

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

int checkLineCount(char *fileName);
int checkLineCount2(FILE **pFile);
int checkFileSize(char *fileName);

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

    //int lineCount = checkLineCount(fileName);
    //printf("LineCount = %i\n", lineCount);


    int lineCount = checkLineCount2(&pFile);
    printf("LineCount2 = %i\n", lineCount);


    long int fileSize = checkFileSize(fileName);

    printf("Filesize = %d\n", fileSize);

    fclose(pFile);
}

int checkLineCount(char *fileName)
{
    int lineCount = 0;
    FILE *tmp = fopen(fileName, "r");
    char c = getc(tmp);
    while (c != EOF)
    {
        if (c == '\n')
        {
            lineCount++;
        }
        c = getc(tmp);
    }
    printf("Filename = %s\n", fileName);
    printf("Linecount = %i\n", lineCount);

    fclose(tmp);

    return lineCount;
}

int checkLineCount2(FILE **pFile)
{
    int lineCount = 0;
    FILE *tmp = *pFile;
    char c = getc(tmp);
    while (c != EOF)
    {
        if (c == '\n')
        {
            lineCount++;
        }
        c = getc(tmp);
    }
    printf("Filename(pFile) = %s\n", pFile);
    printf("Linecount = %i\n", lineCount);

    fclose(tmp);

    return lineCount;
}

int checkFileSize(char *fileName)
{
    long int fileSize = 0;
    FILE *tmp = fopen(fileName, "r");

    fseek(tmp, 0L, SEEK_END);
    fileSize = ftell(tmp);

    return fileSize;
}

int checkFile(char *p)
{
}