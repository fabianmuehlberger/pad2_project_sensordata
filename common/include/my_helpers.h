#ifndef _MY_HELPERS_H_
#define _MY_HELPERS_H_

#include "my_structure.h"
#include "sensor_config.h"

// returns a string. 
char getStringFromStdin(char *name);

// returns a int 
int getIntFromStdin(int *value);

// returns a char * 
char getCharFromStdin(char *c);

void removeNewLineFromString(char *line);

void getUserInputStringFromConsole(char *fileName);

void allocateMemoryForRawDataArray(Raw_Data *tmp);

void allocateMemoryForCleanDataArray(Clean_Data *tmp);

void changeAccAxis(Clean_Data *tmp);

Clean_Data convertRawToClean(Raw_Data rawData);

void printHelp();

#endif