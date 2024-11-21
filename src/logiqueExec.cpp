#include "logiqueExec.h"
#include "dropSalt.h"
#include "constante.h"

void execute()
{
  // init color detector
  Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
  initColorSensor(tcs);

  bool isDone = false;

  while (!isDone)
  {
    int color = isBlue(tcs);
    if (color == true)
    {
      int isOn=1;
      dropSalt(isOn);
      // dispenserOn();
    }
    else if (color == false)
    {
      int isOn=0;
      dropSalt(isOn);
      // dispenserOff();
    }

    int detectedLine = isLine();
    Serial.println(detectedLine);

    if (detectedLine == 4)
    {
      isDone = true;
    }

    if (detectedLine == LEFT_LINE)
    {
      MOTOR_SetSpeed(0, 0);
      MOTOR_SetSpeed(1, MOTOR_SPEED);
    }
    else if (detectedLine == CENTER_LINE)
    {
      MOTOR_SetSpeed(0, MOTOR_SPEED);
      MOTOR_SetSpeed(1, MOTOR_SPEED);
    }
    else if (detectedLine == RIGHT_LINE)
    {
      MOTOR_SetSpeed(0, MOTOR_SPEED);
      MOTOR_SetSpeed(1, 0);
    }
    else if (!detectedLine)
    {
      MOTOR_SetSpeed(0, MOTOR_SPEED);
      MOTOR_SetSpeed(1, MOTOR_SPEED);
    }

    // lastDetectedLine = detectedLine;
    // lastColor = color;
  }
  delay(10);
  stopAll();
}