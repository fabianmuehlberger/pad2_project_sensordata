#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_validation.h"
#include "my_structure.h"
#include "my_file_io.h"

void readFile(char *fileName);

int main(void)
{
    printf("WELCOME TO TEST_READFILE.C\n");
/*
    char fileName[NAMELEN];
    char fileNameAndPath[NAMELEN];

    getUserInputStringFromConsole(fileName);
    strcpy(fileNameAndPath, ".\\\\ressources\\\\");

    strcat(fileNameAndPath, fileName);
    printf("filename = %s\n", fileNameAndPath);
*/

    char fileName[NAMELEN] = ".\\ressources\\test_data_short.csv";

    char stringToken = ';';

    //help to count lines
    
    //check current Direktory
    //checkDirectory();

    //open and close File
    readFile(fileName);

    
}

void readFile(char *fileName)
{
    char buffer[FILEBUFFER];
    

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

    //check Line Count of opened File
    int lineCount = checkLineCount(fileName);
    printf("LineCount = %i\n", lineCount);

    //checkl File Size of opened File
    int fileSize = checkFileSize(fileName);
    printf("Filesize = %d\n", fileSize);


    //print the values of the file 
    while (fgets(buffer, FILEBUFFER, pFile) != NULL)
    {
        printf("%s", buffer);
    }


    fclose(pFile);
}

