#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_validation.h"
#include "my_structure.h"
#include "my_file_io.h"

void openFile(char *fileName);

void readFile(char *fileName);

void createArray(FILE *dataArray, int lineCount);

int checkLineToken(char *fileLine);

int main(void)
{
    printf("WELCOME TO TEST_READFILE.C\n");

    char fileName[NAMELEN];
    char fileNameAndPath[NAMELEN];

    getUserInputStringFromConsole(fileName);
    //strcpy(fileNameAndPath, ".\\\\ressources\\\\");

    strcat(fileNameAndPath, fileName);
    printf("fileAndPath = %s\n", fileNameAndPath);

    //char fileName[NAMELEN] = ".\\ressources\\test_data_short.csv";

    char stringToken = ';';

    //check Line Count of opened File
    int lineCount = checkLineCount(fileNameAndPath);
    printf("LineCount = %i\n", lineCount);

    //checkl File Size of opened File
    int fileSize = checkFileSize(fileNameAndPath);
    printf("Filesize = %d\n", fileSize);

    //open and close File
    readFile(fileNameAndPath);
}

// !when finished! put this funktion in my_file_io
void readFile(char *fileName)
{
    char buffer[FILEBUFFER];
    FILE *pFile;
    openFile(pFile);

    //print the values of the file
    while (fgets(buffer, FILEBUFFER, pFile) != NULL)
    {
        checkLineToken(buffer);
        printf("%s", buffer);
    }

    fclose(pFile);
}

// !when finished with readfile()! put this function in my_file_io
void openFile(char *fileName)
{

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
}

// !when finished!, put this funktion in my_file_io
void createArray(FILE *dataArray, int lineCount)
{
    Data *tmp = malloc(lineCount * sizeof(Data));
    if (tmp == NULL)
    {
        printf("NO MEMORY ALLOCATED");
        exit(-1);
    }
    dataArray = tmp;
}

// !when finished! put this funktion in my_validation
int checkLineToken(char *fileLine)
{
    int lenght = strlen(fileLine);
    int tokenCount = 0;

    for (int i = 0; i < lenght; i++)
    {
        if (fileLine[i] == ';')
        {
            tokenCount++;
        }
    }
    //check for the right amount of ';' in the Line
    if (tokenCount < FILE_TOKEN_AMOUNT)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}