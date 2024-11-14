//
// Created by Raph on 2024-11-12.
//

#ifndef SUIVAGELIGNE_H
#define SUIVAGELIGNE_H
#include "Adafruit_TCS34725.h"
#include <Arduino.h>
#include <LibRobus.h>
#include "Adafruit_I2CDevice.h"
#include "Adafruit_BusIO_Register.h"
void followLine (Adafruit_TCS34725 tcs);
void stopAll();
int isLine();

#endif //SUIVAGELIGNE_H
