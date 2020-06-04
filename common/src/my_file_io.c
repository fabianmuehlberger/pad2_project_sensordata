#include <stdio.h>
#include "my_file_io.h"



int my_file_io_Test()
{
    return 1;
}

void readFile()
{
    
}

void getUserInputStringFromConsole(char *fileName)
{
    do
    {
        scanf("%s", fileName);
    } while (getchar() != '\n');

}

//FUNKTIONEN


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