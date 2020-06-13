#ifndef _MY_STRUCTURE_H_
#define _MY_STRUCTURE_H_

// datastructure for the values read form the csv File 
// Data should be cleaded and without any problematic Values
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


// Datastruture for converted Data 
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


//nachschauen ob noch benoetigt!!!!!
void createArray(Raw_Data *dataArray, int lineCount);

//nachschauen ob noch benoetigt!!!!!
Raw_Data writeDataToStructureArray(char *buffer);


#endif