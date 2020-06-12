#ifndef _MY_STRUCTURE_H_
#define _MY_STRUCTURE_H_

//repl struct
typedef struct Raw_Data
{
    int index;
    int validationCheck;
    int timeStampMS;

    int acc_X;
    int acc_Y;
    int acc_Z;

    int gyro_X;
    int gyro_Y;
    int gyro_Z;

    int mag_X;
    int mag_Y;
    int mag_Z;

} Raw_Data;

typedef struct Clean_Data
{
    float gyroXangle;
    float gyroYangle;
    float gyroZangle;

    float AccYangle;
    float AccXangle;

    float CFangleX;
    float CFangleY;

} Clean_Data;



void printRawData(Raw_Data someData);

void printCleanData(Clean_Data c_data);

void changeAccAxis(Clean_Data *tmp);

void removeNewLineFromString(char *line);

void printDataToCleanData(Clean_Data data);

/*
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
*/
#endif