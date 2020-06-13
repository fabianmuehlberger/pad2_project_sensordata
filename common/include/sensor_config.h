#ifndef _SENSOR_CONFIG_H_
#define _SENSOR_CONFIG_H_

// gyroscope
#define _CTRL_REG4 0b00111000
#define _CTRL_REG1_G 0b10111000
#define _ORIENT_CFG_G 0b10111000

// accelerometer
#define _CTRL_REG5_XL 0b00111000
#define _CTRL_REG6_XL 0b00101000

// magnetometer
#define _CTRL_REG1_M 0b10011100
#define _CTRL_REG2_M 0b01000000
#define _CTRL_REG3_M 0b00000000
#define _CTRL_REG4_M 0b00000000


#define DT 0.02 // [s/loop] loop period. 20ms
#define AA 0.97 // complementary filter constant

#define A_GAIN 0.0573 // [deg/LSB]
#define G_GAIN 0.070  // [deg/s/LSB]
#define RAD_TO_DEG 57.29578
#define M_PI 3.14159265358979323846


#endif