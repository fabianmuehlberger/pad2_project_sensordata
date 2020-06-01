/*
TEST PROGRAM TO CHECK IF THE DATASTUCTURE IN MY_STRUCTURE.H IS WORKING PROPERLY
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_structure.h"



int main(void)
{
    int fileLines = 10;

    Data array[fileLines];

    for (int i = 0; i < fileLines; i++)
    {
        array[i].timeStampS = i;
    }

    for (int i = 0; i < fileLines; i++)
    {
        printf("array Timestamp = %d\n", array[i].timeStampS);
    }
    
    return 0;
}