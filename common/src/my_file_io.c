#include <stdio.h>
#include <stdlib.h>
#include "my_file_io.h"
#include "my_structure.h"
#include "my_validation.h"

int my_file_io_Test()
{
    return 1;
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
