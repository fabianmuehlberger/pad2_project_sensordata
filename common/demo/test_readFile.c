#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_validation.h"
#include "my_structure.h"
#include "my_file_io.h"
#include "my_helpers.h"

//void readSourceCSVFile(char *fileName);

int lineValidatonChecks(char *lineToValidate, int line);

void writeErrorLog(int line, int errorCode, char *errorMassage);

int main(void)
{
    printf("WELCOME TO TEST_READFILE.C\n");

    char fileName[NAMELEN];
    char fileNameAndPath[] = RELATIVE_FILEPATH_TO_DATA;

    getUserInputStringFromConsole(fileName);

    //options for concating the folder path to the filename (LINUX, WIN format)
    //strcpy(fileNameAndPath, ".\\\\ressources\\\\");
    //strcpy(fileNameAndPath, ".//ressources//");

    strcat(fileNameAndPath, fileName);
    strcat(fileNameAndPath, CSV_FILE_ENDING);
    printf("fileAndPath = %s\n", fileNameAndPath);

    //check Line Count of opened File
    int lineCount = checkLineCount(fileNameAndPath);

    //checkl File Size of opened File
    int fileSize = checkFileSize(fileNameAndPath);

    //open and close File
    readSourceCSVFile(fileNameAndPath);
}

// !when finished! put this funktion in my_file_io
void readSourceCSVFile(char *fileName)
{
    char buffer[FILEBUFFER];
    FILE *pFile;

    pFile = fopen(fileName, "r");
    if (pFile == NULL)
    {
        printf("ERROR could not open source File\n");
        exit(-1);
    }
    else
    {
        printf("File opened...\n");
    }

    FILE *pWriteFile;
    pWriteFile = fopen("..//..//ressources//destination.csv", "w+");
    if (pWriteFile == NULL)
    {
        printf("ERROR could not open destination File\n");
    }
    
    int validationcheck = 0;
    int lines = 1;
    //print the values of the file
    while (fgets(buffer, FILEBUFFER, pFile) != NULL)
    {
        if (lineValidatonChecks(buffer, lines))
        {
            validationcheck = 1;
        }
        
        removeNewLineFromString(buffer);

        fprintf(pWriteFile, "%d;%s;%d\n", lines, buffer, validationcheck);

        validationcheck = 0;
        lines++;
    }
    printf("\nEnd of READFILE\n");

    fclose(pFile);
    fclose(pWriteFile);
}




