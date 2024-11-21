//
// Created by Raph on 2024-11-12.
//
#include "suivageLigne.h"
#include "colorDetection.h"

void stopAll()
{
    MOTOR_SetSpeed(0,0);
    MOTOR_SetSpeed(1,0);
}

int isLine()
{
    // Serial.print("A10: ");
    // Serial.println(analogRead(A10));
    // Serial.print("A9: ");
    // Serial.println(analogRead(A9));
    // Serial.print("A8: ");
    // Serial.println(analogRead(A8));
    //delay(100);
    if (analogRead(A10) > 300 && analogRead(A9) > 300 && analogRead(A8) > 300)
    {
        return 4;

    }
    if (analogRead(A8) > 300)
    {
        // Serial.println(analogRead(A8));
        return 3;
    }
    if (analogRead(A9) > 300)
    {
        // Serial.println(analogRead(A9));
        return 2;
    }
    if (analogRead(A10) > 300)
    {
        // Serial.println(analogRead(A10));
        return 1;
    }
    return 0;
}



// void followLine(Adafruit_TCS34725 tcs)
// {
//     //int lastDetectedLine = 0;
//     //int lastColor = 0;
//     while (isLine() != 4 /*||(!(lastColor == 1 || lastColor == 2 || lastColor == 3 || lastColor == 4))*/)
//     {
//
//         // stopAll();
//         int color = isBlue(tcs);
//         if (color == true)
//         {
//             //dispenserOn();
//         }
//         else if (color == false){
//             //dispenserOff();
//         }
//
//         int detectedLine = isLine();
//         Serial.println(detectedLine);
//
//         if (detectedLine == 4)
//         {
//             stopAll();
//             break;
//         }
//
//         if (detectedLine == 1)
//         {
//             MOTOR_SetSpeed(0, 0);
//             MOTOR_SetSpeed(1, 0.2);
//         }
//         else if (detectedLine == 2)
//         {
//             MOTOR_SetSpeed(0, 0.2);
//             MOTOR_SetSpeed(1, 0.2);
//         }
//         else if (detectedLine == 3)
//         {
//             MOTOR_SetSpeed(0, 0.2);
//             MOTOR_SetSpeed(1, 0);
//         }
//         else if (!detectedLine)
//         {
//             MOTOR_SetSpeed(0, 0.2);
//             MOTOR_SetSpeed(1, 0.2);
//         }
//
//         //lastDetectedLine = detectedLine;
//         //lastColor = color;
//     }
//     stopAll();
// }


