#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "my_validation.h"

int my_validation_Test()
{
    return 1;
}

int checkLineCount(char *name)
{
    int lineCount = 0;
    FILE *tmp = fopen(name, "r");
    char c = getc(tmp);
    while (c != EOF)
    {
        if (c == '\n')
        {
            lineCount++;
        }
        c = getc(tmp);
    }
    printf("LineCount = %d", lineCount);

    fclose(tmp);

    return lineCount;
}

int checkFileSize(char *name)
{
    int fileSize = 0;
    FILE *tmp = fopen(name, "r");

    fseek(tmp, 0L, SEEK_END);
    fileSize = ftell(tmp);

    printf("File Size = %d", fileSize);

    return fileSize;
}

//checks current directory, might be usefull to find files
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

int checkLineToken(char *fileLine)
{
    int lenght = strlen(fileLine);
    int tokenCount = 0;

    for (int i = 0; i < lenght; i++)
    {
        if (fileLine[i] == CSV_SEPERATION_TOKEN)
        {
            tokenCount++;
        }
    }
    //check for the right amount of ';' in the Line

    if (tokenCount < FILE_TOKEN_AMOUNT)
    {
        printf("test not passed\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int checkLineEnding(char *line)
{
    int lenght = strlen(line);
    if (line[lenght - 1] != '\n')
    {
        printf("no newline found\n");
        line[lenght -1] = '\n';
        line[lenght] = '\0';
        
        return 1;
    }
    if (line[lenght -1] == '\n')
    {
        return 0;
    }
}