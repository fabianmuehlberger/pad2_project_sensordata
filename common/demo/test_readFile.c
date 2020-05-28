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

int checkLineCount(FILE **pFile);
long int checkFileSize(FILE **pFile);

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


    int lineCount;
    char c = getc(pFile);
    while (c != EOF)
    {
        if (c == '\n')
        {
            lineCount++;
        }
        c = getc(pFile);
    }
    printf("Linecount = %d", lineCount);
    return lineCount;

    //check filesize and Lines

    int lineCount = checkLineCount(pFile);
    long int fileSize = checkFileSize(&pFile);

    printf("LineCount = %i\n", lineCount);
    printf("Filesize = %d\n", fileSize);

    fclose(pFile);

    /*
    struct dirent *de;

    DIR *pDir = opendir("..\\..\\ressources");
    if (pDir == NULL)
    {
        puts("Error, unable to read directory");
        exit(-1);
    }
    while ((de = readdir(pDir)) != NULL)
    {
        printf("Dir name %s\n", de->d_name);
    }
    closedir(pDir);
*/
}

int checkLineCount(FILE **pFile)
{
    int lineCount;
    char c = getc(pFile);
    while (c != EOF)
    {
        if (c == '\n')
        {
            lineCount++;
        }
        c = getc(pFile);
    }
    printf("Linecount = %d", lineCount);
    return lineCount;
}

long int checkFileSize(FILE **pFile)
{
    long int fileSize;
    FILE *tmp = *pFile;

    fseek(tmp, 0L, SEEK_END);
    int res = ftell(tmp);

    return fileSize;
}

int checkFile(char *p)
{
}