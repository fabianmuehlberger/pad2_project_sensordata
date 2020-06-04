#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_validation.h"
#include "my_structure.h"
#include "my_file_io.h"
#include "my_helpers.h"

//void readFile(char *fileName);

int lineValidatonChecks(char *lineToValidate, int line);

void removeNewLine(char *line);

int main(void)
{
    printf("WELCOME TO TEST_READFILE.C\n");

    char fileName[NAMELEN];
    char fileNameAndPath[NAMELEN];

    getUserInputStringFromConsole(fileName);

    //options for concating the folder path to the filename (LINUX, WIN format)
    //strcpy(fileNameAndPath, ".\\\\ressources\\\\");
    strcpy(fileNameAndPath, ".//ressources//");

    strcat(fileNameAndPath, fileName);
    strcat(fileNameAndPath, ".csv");
    printf("fileAndPath = %s\n", fileNameAndPath);

    //check Line Count of opened File
    int lineCount = checkLineCount(fileNameAndPath);

    //checkl File Size of opened File
    int fileSize = checkFileSize(fileNameAndPath);

    //open and close File
    readFile(fileNameAndPath);
}

// !when finished! put this funktion in my_file_io
void readFile(char *fileName)
{
    char buffer[FILEBUFFER];
    FILE *pFile;

    pFile = fopen(fileName, "r");
    if (pFile == NULL)
    {
        printf("ERROR could not open source File???\n");
        exit(-1);
    }
    else
    {
        printf("File opened...\n");
    }

    FILE *pWriteFile;
    pWriteFile = fopen(".//ressources//destination.csv", "w+");
    if (pWriteFile == NULL)
    {
        printf("ERROR could not open destination File???\n");
    }
    
    int validationcheck = 0;
    int lines = 1;
    //print the values of the file
    while (fgets(buffer, FILEBUFFER, pFile) != NULL)
    {

        if (lineValidatonChecks(buffer, lines))
        {
            printf("Line %d:  Data validation not passed", lines);
            validationcheck = 1;
        }
        
        removeNewLine(buffer);

        fprintf(pWriteFile, "%d;%s;%d\n", lines, buffer, validationcheck);

        validationcheck = 0;
        lines++;
    }
    printf("End of READFILE\n");

    fclose(pFile);
    fclose(pWriteFile);
}


int lineValidatonChecks(char *lineToValidate, int line)
{
    int checker = 0;
    //check tokens
    if (checkLineToken(lineToValidate))
    {
        printf("Line %d: tokenvalidation not passed", line);
        checker = 1;
    }

    //check line endings
    if (checkLineEnding(lineToValidate))
    {
        printf("Line %d: lineendingValidation not passed", line);
        checker = 1;
    }
    
    return checker;
}
/*
void removeNewLine(char *line)
{
    int new_line = strlen(line) - 1;
    if (line[new_line] == '\n')
    {
        line[new_line] = '\0';
    }
}
*/