#ifndef _MY_STRUCTURE_H_
#define _MY_STRUCTURE_H_

// datastructure for the values read form the csv File 
// Data should be cleaded and without any problematic Values
typedef struct Data
{
    int index;
    int timeStampS;
    int timeStampMS;
    int value1;
    int value2;
    int value3;
    int value4;
    int value5;
    int value6;
    
}Data;

void createArray(Data *dataArray, int lineCount);


#endif