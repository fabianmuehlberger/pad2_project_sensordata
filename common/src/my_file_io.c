#include <stdio.h>
#include "my_file_io.h"

int my_file_io_Test()
{
    return 1;
}

void readFile()
{
    
}

void getFileName(char *fileName)
{
    do
    {
        scanf("%s", fileName);
    } while (getchar() != '\n');

}