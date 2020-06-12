//this programm checks every library in the project and runns a test function incuded int the libraries

#include <stdio.h>
#include "my_graphics.h"
#include "my_file_io.h"
#include "my_validation.h"
#include "my_structure.h"
#define FILEBUFFER 200 
#define NAMELEN 40

Raw_Data readRawDataFromCSV(char *buffer);
Clean_Data dataConversion(Raw_Data rawData);


int main(void)
{
    printf("Start of main\n");

    Raw_Data dataPoint;
    Clean_Data theData;

    char sourceFileName[NAMELEN] = "source.csv";
    char rawFileName[NAMELEN] = "destination.csv";
    char cleanFileName[NAMELEN] = "cleanData.csv";

    readSourceFile(sourceFileName);

	readRawDataFromCSV(rawFileName);

    theData = dataConversion(dataPoint);

    printRawData(dataPoint);
    printCleanData(theData);    
}