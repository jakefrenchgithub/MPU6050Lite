/*****************************************************************************************************/
/*!
  @file     MPU6050IMU.h
  Library by J. French https://github.com/jakefrenchgithub/, released to the public domain
  License: MIT, https://opensource.org/licenses/MIT

  This is a bare-bones library for interfacing with the MPU6050 Inertia Measurement Unit sensor
  The MPU6050 is a 6 DoF (degrees of freedom) or a six-axis IMU sensor, giving 6 output values:
  3x DoF for the accelerometer and 3x for the gyroscope, addressed over I2C.
  This library only gives accelerometer reading for the roll and pitch values for expediency,
  though may be expanded to give gyroscope data.



  Supporting documentation
  MPU6050 Register Map:
  https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf
  J. French, 10/7/20
*/
/*****************************************************************************************************/

#ifndef _MPU6050Lite_h
#define _MPU6050Lite_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif



class MPU6050Lite
{
public:
    void initialise(int add);
    void readRegisters();
    float roll();
    float pitch();

private:
    int _add;
    float _xa, _ya, _za, _roll, _pitch;
};

#endif