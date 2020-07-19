/*****************************************************************************************************/
/*!
  @file     MPU6050IMU.cpp
  Library by J. French https://github.com/jakefrenchgithub/, released to the public domain
/*****************************************************************************************************/

#include "MPU6050Lite.h"
#include <Wire.h>

void MPU6050Lite::initialise(int add)
{
	_add = add;
	Wire.beginTransmission(_add);               // begin, send the slave adress (in this case 0x68)
	Wire.write(0x6B);                           // make the reset (place a 0 into the 6B register)
	Wire.write(0);								// 
	Wire.endTransmission(true);                 //end the transmission
}



void MPU6050Lite::readRegisters()
{
	Wire.beginTransmission(_add);				// initialize transmission at I2C address _add 
	Wire.write(0x3B);							// start at register _reg
	Wire.endTransmission(false);				// keep connection active, don't restart
	Wire.requestFrom(0x68, 0x06, true);			// obtain 0x06 bytes of accelerometer data, starting at register ACCEL_XOUT
	_xa = Wire.read() << 8 | Wire.read();		// read registers: [3B, 3C] ACCEL_XOUT_HI, ACCEL_XOUT_LO
	_ya = Wire.read() << 8 | Wire.read();		// read registers: [3D, 3E] ACCEL_YOUT_HI, ACCEL_YOUT_LO 
	_za = Wire.read() << 8 | Wire.read();		// read registers: [3F, 40] ACCEL_ZOUT_HI, ACCEL_ZOUT_LO 
	_roll = atan2(_ya, _za);							// _roll in radians
	_pitch = atan2(-_xa, sqrt(_ya * _ya + _za * _za));	// _pitch in radians
}

float MPU6050Lite::roll()
{
	return _roll * RAD_TO_DEG;
}

float MPU6050Lite::pitch()
{
	return _pitch * RAD_TO_DEG;
}
