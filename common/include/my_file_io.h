#ifndef _MY_FILE_IO_H_
#define _MY_FILE_IO_H_

//DEFINES 
#define FILEBUFFER 200 
#define NAMELEN 40
#define RELATIVE_FILEPATH_TO_DATA ".//ressources//"
#define CSV_FILE_ENDING ".csv"

// test of my_file_io
int my_file_io_Test();

void getUserInputStringFromConsole(char *fileName);

void readFile();


void printHelp();

void printData();

// _MY_FILE_IO_H_
#endif  