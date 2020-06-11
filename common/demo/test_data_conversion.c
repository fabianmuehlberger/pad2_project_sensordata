#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGLEN 256

typedef struct Data
{
    int index;
    int validationCheck;
    int timeStampMS;

    int acc_X;
    int acc_Y;
    int acc_Z;

    int gyro_X;
    int gyro_Y;
    int gyro_z;

    int mag_X;
    int mag_Y;
    int mag_Z;

} Data;

Data writeDataToStructureArray(char *buffer);

void printSomeData(Data someData);

void printAnoterString(char *anotherString);

int main(void)
{
    char string[STRINGLEN];

    char *pEnd;
    char *curser;

    Data somedata;

    char anotherString[10] = "ffffff4";
    curser = anotherString;

    strcpy(string, "1;0;5;0;fffffff4;569;ffffffea;ffffffd9;fffffff5;0000019c;0000004b;fffffb8c");

    printf("string = %s\n", string);
    printf("anotherString = %s\n", anotherString);

    //CONVERSION:

    somedata = writeDataToStructureArray(string);

    printSomeData(somedata);
    return 0;
}
void printAnoterString(char *anotherString)
{
    char *curser;
    curser = anotherString;

    long int number;

    number = strtol(curser, NULL, 16);

    printf("%lu", number);
}

Data writeDataToStructureArray(char *buffer)
{
    Data tmpData;

    char *curser;
    char seperator[] = ";";

    curser = strtok(buffer, seperator);
    tmpData.index = atof(curser);

    curser = strtok(NULL, seperator);
    tmpData.validationCheck = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.timeStampMS = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.acc_X = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.acc_Y = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.acc_Z = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.gyro_X = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.gyro_Y = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.gyro_z = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.mag_X = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.mag_Y = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.mag_Z = (int)strtol(curser, NULL, 16);

    return tmpData;
}

void printSomeData(Data someData)
{
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
           someData.index,
           someData.validationCheck,
           someData.timeStampMS,
           someData.acc_X,
           someData.acc_Y,
           someData.acc_Z,
           someData.gyro_X,
           someData.gyro_Y,
           someData.gyro_z,
           someData.mag_X,
           someData.mag_Y,
           someData.mag_Z);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#define DT 0.02

typedef struct Data
{
    int index;
    int validationCheck;
    int timeStampMS;

    float acc_X;
    float acc_Y;
    float acc_Z;

    float gyro_X;
    float gyro_Y;
    float gyro_Z;

    float mag_X;
    float mag_Y;
    float mag_Z;

} Data;

Data writeDataToStructureArray(char *buffer);

void printSomeData(Data someData);

Data dataConversion(int raw_acc[], int raw_gyro[] int raw_magn[]);

int main(void)
{
    printf("Start of main\n");

    char string[200];

    strcpy(string, "1;0;00000005;fffffff3;ffffffe7;0000056e;ffffffee;ffffffdd;fffffff7;000001e8;000000e8;fffffba4");

    Data somedata;

    somedata = writeDataToStructureArray(string);
    printSomeData(somedata);

}

Data writeDataToStructureArray(char *buffer)
{
    Data tmpData;

    int index;
    int timeStamp;
    int validationCheck;

    int acc[3];
    int gyro[3];
    int magn[3];

    char *curser;
    char seperator[] = ";";

    curser = strtok(buffer, seperator);
    tmpData.index = atof(curser);

    curser = strtok(NULL, seperator);
    validationCheck = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    timeStamp = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    acc[0] = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    acc[1] = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    acc[2] = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    gyro[0] = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    gyro[1] = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    gyro[2] = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    magn[0] = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    magn[1] = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    magn[2] = (int)strtol(curser, NULL, 16);

    dataConversion(acc, gyro, magn);

    return tmpData;
}

//Calculate the angles from the gyro
Data dataConversion(int raw_acc[], int raw_gyro[] int raw_magn[])
{
    Data someData;

    someData.gyro_X += raw_gyro[1] * DT;
    someData.gyro_Y += raw_gyro[2] * DT;
    someData.gyro_Z += raw_gyro[3] * DT;
    return someData;
}

void printSomeData(Data someData)
{
    printf("\nIndex: %li\nValid: %li\n\n Time: %li\n acc_x: %li\n acc_y: %li\n acc_z: %li\n\n gyro_x: %li\n gyro_y: %li\n gyro_z:%li\n\n mag_x: %li\n mag_y: %li\n mag_z: %li\n",
           someData.index,
           someData.validationCheck,
           someData.timeStampMS,
           someData.acc_X,
           someData.acc_Y,
           someData.acc_Z,
           someData.gyro_X,
           someData.gyro_Y,
           someData.gyro_Z,
           someData.mag_X,
           someData.mag_Y,
           someData.mag_Z);
}