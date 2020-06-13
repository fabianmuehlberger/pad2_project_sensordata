#include <stdio.h>
#include "my_graphics.h"
#include "my_structure.h"

int my_graphics_Test()
{
    return 1;
}

void printRawData(Raw_Data data)
{
    printf("\nAccelleration:\nX: %i\nY: %i\nZ: %i\n\nGyroscope:\nX: %i\nY: %i\nZ: %i\n\nMagnetometer:\nX: %i\nY:%i\nZ: %i\n",
           data.acc_X, data.acc_Y, data.acc_Z,
           data.gyro_X, data.gyro_Y, data.gyro_Z,
           data.mag_X, data.mag_Y, data.mag_Z);
}

void printCleanData(Clean_Data data)
{
    printf("\nGyroscope:\nX: %f\nY: %f\nZ: %f\n\nAccelleration:\nX: %f\nY: %f\nZ: %f\n\nCFangle:\nX: %f\nY: %f\n\n",
           data.gyroXangle, data.gyroYangle, data.gyroZangle,
           data.AccXangle, data.AccYangle,
           data.CFangleX, data.CFangleY);
}
