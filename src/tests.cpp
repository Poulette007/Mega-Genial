//
// Created by Raphael on 2024-11-27.
//
#include "tests.h"
#include "constante.h"
#include "colorDetection.h"

void testSuiveurLigne() {
  Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
  initColorSensor(tcs);
  int compteurFin = 0;
  while (1) {
    int detectedLine = isLine();
    int i = 0;
    // Serial.println(detectedLine);

    if (detectedLine == 4) {
        compteurFin++;
        Serial.print("compteurFin: ");
        Serial.println(compteurFin);
      if (compteurFin >= 4) {
        stopAll();
        break;
      }
    }
    else
    {
      compteurFin = 0;
    }

    if (detectedLine == 1)
    {
      MOTOR_SetSpeed(0, 0);
      MOTOR_SetSpeed(1, MOTOR_SPEED);
    }
    else if (detectedLine == 2)
    {
      MOTOR_SetSpeed(0, MOTOR_SPEED);
      MOTOR_SetSpeed(1, MOTOR_SPEED);
    }
    else if (detectedLine == 3)
    {
      MOTOR_SetSpeed(0, MOTOR_SPEED);
      MOTOR_SetSpeed(1, 0);
    }
    else if (detectedLine == 0)
    {
      MOTOR_SetSpeed(0, MOTOR_SPEED);
      MOTOR_SetSpeed(1, MOTOR_SPEED);
    }
  }
  stopAll();
}
  int testColorDetection(Adafruit_TCS34725 tcs) {
    bool color = isBlue(tcs);
    Serial.print("color: ");
    Serial.println(color);
    while (1) {
      int detectedLine = isLine();
      if (color == true) {
        stopAll();
        return 0;
      }
      // Serial.println(detectedLine);

      if (detectedLine == 4)
      {
        stopAll();
        break;
      }

      if (detectedLine == 1)
      {
        MOTOR_SetSpeed(0, 0);
        MOTOR_SetSpeed(1, MOTOR_SPEED);
      }
      else if (detectedLine == 2)
      {
        MOTOR_SetSpeed(0, MOTOR_SPEED);
        MOTOR_SetSpeed(1, MOTOR_SPEED);
      }
      else if (detectedLine == 3)
      {
        MOTOR_SetSpeed(0, MOTOR_SPEED);
        MOTOR_SetSpeed(1, 0);
      }
      else if (detectedLine == 0)
      {
        MOTOR_SetSpeed(0, MOTOR_SPEED);
        MOTOR_SetSpeed(1, MOTOR_SPEED);
      }
    }
    stopAll();
    return 0;
  }