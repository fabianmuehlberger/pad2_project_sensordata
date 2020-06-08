#include <stdio.h>
#include <stdlib.h>
#include "my_file_io.h"



int my_file_io_Test()
{
    return 1;
}

void writeErrorLog(int line, int errorCode, char *errorMassage)
{
    FILE *pWriteError;
    pWriteError = fopen(".//ressources//error_log.csv", "a");
    if (pWriteError == NULL)
    {
        printf("ERROR could not open error log");
        exit(-1);
    }

    fprintf(pWriteError, "LINE: %d  ERROR: %d  %s\n", line, errorCode, errorMassage);

    printf("Line %d written to errorlog", line);

    fclose(pWriteError);
}

void getUserInputStringFromConsole(char *fileName)
{
    do
    {
        scanf("%s", fileName);
    } while (getchar() != '\n');
}

void printHelp()
{
    printf("\nHauptmenu: (Auswahl treffen)\n"
           "p: Messpunkte printen\n"
           "h: Hauptmenu\n"
           "e: exit\n");
}

void printData()
{
    printf("printsData\n");
}