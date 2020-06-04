#include <stdio.h>
#include <stdlib.h>
#include "my_structure.h"

void createArray(Data *dataArray, int lineCount)
{
    Data *tmp = malloc(lineCount * sizeof(Data));
    if (tmp == NULL)
    {
        printf("NO MEMORY ALLOCATED");
        exit(-1);
    }
    dataArray = tmp;
}
