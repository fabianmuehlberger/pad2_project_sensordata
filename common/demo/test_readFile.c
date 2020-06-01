#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "my_validation/my_validation.h"

#define FILEBUFFER 80
#define NAMELEN 40

int checkFile(char *p);

void checkDirectory();
void readFile();

int main(void)
{

    int pTimeStamp;

    int *ptr1, *ptr2, *ptr3;

    int accelerometer_X, accelerometer_Y, accelerometer_Z;
    int gyroscope_X, gyroscope_Y, gyroscope_Z;
    int magnetometer_X, magnetometer_Y, magnetometer_Z;

    char stringToken = ';';

    //help to count lines
    
    //check current Direktory
    checkDirectory();

    //open and close File
    readFile();

    
}

void readFile()
{
    char buffer[FILEBUFFER];
    char fileName[NAMELEN] = ".\\ressources\\test_data_short.csv";

    FILE *pFile;
    pFile = fopen(fileName, "r");
    if (pFile == NULL)
    {
        printf("ERROR could not open File???\n");
        exit(-1);
    }
    else
    {
        printf("File opened...\n");
    }

    int fileSize = 0;
    FILE *tmp = pFile;

    fseek(tmp, 0L, SEEK_END);
    fileSize = ftell(tmp);

    
    printf("File Size = %d\n", fileSize);


    //check Line Count of opened File
    int lineCount = checkLineCount(pFile);
    printf("LineCount = %i\n", lineCount);

    //checkl File Size of opened File
    fileSize = checkFileSize(pFile);
    printf("Filesize = %d\n", fileSize);

    

    while (fgets(buffer, FILEBUFFER, pFile) != NULL)
    {
        printf("%s", buffer);
    }


    fclose(pFile);
}


void checkDirectory()
{
    struct dirent *de;

    DIR *pDir = opendir(".\\ressources");
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
}