﻿/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

// I2C device class (I2Cdev) demonstration Arduino sketch for MPU6050 class using DMP (MotionApps v2.0)
// 6/21/2012 by Jeff Rowberg <jeff@rowberg.net>
// Updates should (hopefully) always be available at https://github.com/jrowberg/i2cdevlib
//
// Changelog:
//      2013-05-08 - added seamless Fastwire support
//                 - added note about gyro calibration
//      2012-06-21 - added note about Arduino 1.0.1 + Leonardo compatibility error
//      2012-06-20 - improved FIFO overflow handling and simplified read process
//      2012-06-19 - completely rearranged DMP initialization code and simplification
//      2012-06-13 - pull gyro and accel data from FIFO packet instead of reading directly
//      2012-06-09 - fix broken FIFO read sequence and change interrupt detection to RISING
//      2012-06-05 - add gravity-compensated initial reference frame acceleration output
//                 - add 3D math helper file to DMP6 example sketch
//                 - add Euler output and Yaw/Pitch/Roll output formats
//      2012-06-04 - remove accel offset clearing for better results (thanks Sungon Lee)
//      2012-06-01 - fixed gyro sensitivity to be 2000 deg/sec instead of 250
//      2012-05-30 - basic DMP initialization working

/* ============================================
I2Cdev device library code is placed under the MIT license
Copyright (c) 2012 Jeff Rowberg

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
void setup();
void loop();
//Enable Bluetooth


#include "SoftwareSerial.h"
SoftwareSerial bt_Serial(2, 3);
char bt_buffer;
int bt_availability;

void setup() {
	bt_Serial.begin(9600);
	Serial.begin(115200);
	//Serial.println(F("\nSend any character to begin DMP programming and demo: "));
	//while (bt_Serial.available() && bt_Serial.read()); // empty buffer
	//while (!bt_Serial.available());                 // wait for data
	//while (bt_Serial.available() && bt_Serial.read()); // empty buffer again
	bt_Serial.println("Hello from Arduino");
	Serial.println(F("InitializingBluetooth..."));
		
}


// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
	//while (bt_Serial.available() && bt_Serial.read()); // empty buffer
	//while (!bt_Serial.available());                 // wait for data
	//while (bt_Serial.available() && bt_Serial.read()); // empty buffer again
	//
	//bt_buffer = (bt_Serial.read());
	//bt_Serial.println(bt_buffer);

	// if text arrived in from bt_Serial serial...	
	if(bt_Serial.available())
	{
		bt_Serial.println("bt_Serial AVAILABLE");

		bt_buffer = (bt_Serial.read());
		if (bt_buffer=='W')
		{
			digitalWrite(13, HIGH);
			bt_Serial.println("LED on");
		}
		if (bt_buffer=='S')
		{
			digitalWrite(13, LOW);
			bt_Serial.println("LED off");
		}
		if (bt_buffer=='?')
		{
			bt_Serial.println("Send '1' to turn LED on");
			bt_Serial.println("Send '2' to turn LED on");
		}
		// you can add more "if" statements with other characters to add more commands
	}

}
