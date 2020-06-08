#ifndef _MY_STRUCTURE_H_
#define _MY_STRUCTURE_H_

// datastructure for the values read form the csv File 
// Data should be cleaded and without any problematic Values
typedef struct Data
{
    int index;
    int timeStampMS;
    int validationCheck;

    int gyro_X;
    int gyro_Y;
    int gyro_z;

    int acc_X;
    int acc_Y;
    int acc_Z;

    int mag_X;
    int mag_Y;
    int mag_Z;
    
}Data;

void createArray(Data *dataArray, int lineCount);

Data writeDataToStructureArray(char *buffer);


#endif