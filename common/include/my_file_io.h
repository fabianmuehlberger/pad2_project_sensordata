#ifndef _MY_FILE_IO_H_
#define _MY_FILE_IO_H_

#include "my_structure.h"

//DEFINES 
#define RELATIVE_FILEPATH_TO_DATA "..//..//ressources//"
#define CSV_FILE_
#define ENDING ".csv"

// test of my_file_io
int my_file_io_Test();

FILE *openCSVFile(char *fileName, FILE *pFile, char *mode);

Raw_Data readRawDataFromCSV(char *buffer);

void writeToCleanDataCSV(Clean_Data tmp, char *FileName_CleanData);


// _MY_FILE_IO_H_
#endif  
