#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "my_validation.h"
#include "my_file_io.h"

int my_validation_Test()
{
    return 1;
}

int checkLineCount(char *name)
{
    int lineCount = 0;

    FILE *tmp = NULL;
    tmp = openCSVFile(name, tmp, "r");

    char c = getc(tmp);
    while (c != EOF)
    {
        if (c == '\n')
        {
            lineCount++;
        }
        c = getc(tmp);
    }
    printf("LineCount = %d\n", lineCount);

    fclose(tmp);

    return lineCount;
}

int checkFileSize(char *name)
{
    int fileSize = 0;
    FILE *tmp = NULL; 

    tmp = openCSVFile(name, tmp, "r");

    fseek(tmp, 0L, SEEK_END);
    fileSize = ftell(tmp);

    printf("File Size = %d\n", fileSize);

    return fileSize;
}

//checks current directory, might be usefull to find files
// Nur notwendig wenn die benutzereingabe das durchsuchen der Ordnerstruktur vorsieht
/*
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
*/

int checkLineToken(char *fileLine)
{
    int lenght = strlen(fileLine);
    int tokenCount = 0;
    char csv_token[] = ";";

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

int checkLineEnding(char *line)
{
    int lenght = strlen(line);
    if (line[lenght - 1] != '\n')
    {
        line[lenght -1] = '\n';
        line[lenght] = '\0';
        
        return 1;
    }
    if (line[lenght -1] == '\n')
    {
        return 0;
    }
}

void writeErrorLog(char *errorLogFileName, int line, int errorCode, char *errorMassage)
{
    FILE *pWriteError = NULL;
    pWriteError = openCSVFile(errorLogFileName, pWriteError, "a" );

    fprintf(pWriteError, "LINE: %d  ERROR: %d  %s\n", line, errorCode, errorMassage);

    printf("Line %d written to errorlog", line);

    fclose(pWriteError);
}

int lineValidatonChecks(char *lineToValidate, int line, char *errorLogFileName)
{
    int checker = 0;
    char csv_token[] = ";";
        
    //check tokens
    if (checkLineToken(lineToValidate))
    {
        printf("Line %d: token validation not passed\n", line);
        checker = 1;
        writeErrorLog(errorLogFileName, line, checker, VALIDATION_TOKEN_ERR);
    }

    //check line endings
    if (checkLineEnding(lineToValidate))
    {
        printf("Line %d: lineending validation not passed\n", line);
        checker = 2;
        writeErrorLog(errorLogFileName, line, checker, VALIDATION_NEWLINE_ERR);
    }

    return checker;
}

