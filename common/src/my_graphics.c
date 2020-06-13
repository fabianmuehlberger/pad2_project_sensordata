#include <stdio.h>
#include "my_graphics.h"
#include "my_structure.h"

int my_graphics_Test()
{
    return 1;
}

void help()
{
    printf("-1- Option one\n");
    printf("-2- Option two\n");
    printf("-3- Option three\n");
}

void printRawData(Raw_Data data)
{
    printf("Acc: %i %i %i  | Gyro: %i %i %i  | Magn: %i %i %i\n",
           data.acc_X, data.acc_Y, data.acc_Z,
           data.gyro_X, data.gyro_Y, data.gyro_Z,
           data.mag_X, data.mag_Y, data.mag_Z);
}

void printCleanData(Clean_Data data)
{
    printf("Gyro: %f %f %f  | Acc: %f %f   | CFangle: %f %f \n",
           data.gyroXangle, data.gyroYangle, data.gyroZangle,
           data.AccXangle, data.AccYangle,
           data.CFangleX, data.CFangleY);
}
