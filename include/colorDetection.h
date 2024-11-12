//
// Created by Raph on 2024-11-12.
//

#ifndef COLORDETECTION_H
#define COLORDETECTION_H
#include "Adafruit_TCS34725.h"
#include <Arduino.h>
//#include "Adafruit_I2CDevice.h"
//#include "Adafruit_BusIO_Register.h"
#include <LibRobus.h>
void initColorSensor(Adafruit_TCS34725 tcs);
bool isBlue (Adafruit_TCS34725 tcs);
#endif //COLORDETECTION_H
