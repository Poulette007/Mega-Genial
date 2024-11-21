//
// Created by Raph on 2024-11-12.
//
#include "colorDetection.h"

#define redValue 38
#define greenValue 77
#define blueValue 124

void initColorSensor(Adafruit_TCS34725 tcs)
{
    Serial.begin(9600);
    tcs.begin();
    if (!tcs.begin())
    {
        Serial.println("Error initializing TCS34725");
        //while (1) {
          //  delay(1000);
        //}
    }
}

bool isBlue(Adafruit_TCS34725 tcs)
{
    uint16_t r, g, b, clear;
    tcs.getRawData(&r, &g, &b, &clear);

    int red = (float)r / clear * 255.0;
    int green = (float)g / clear * 255.0;
    int blue = (float)b / clear * 255.0;
    int delta = 6;

    // Serial.println();
    // Serial.print("r: ");
    // Serial.println(red);
    // Serial.print("g: ");
    // Serial.println(green);
    // Serial.print("b: ");
    // Serial.println(blue);

    bool color = false;

    if (abs(red - redValue) < delta && abs(blue - blueValue) < delta && abs(green - greenValue) < delta)
    {
        //Serial.print("Color Detected: blue");
        color = true;
    }
    else {
        //Serial.println("no color detected");
    }

    return color;
}
