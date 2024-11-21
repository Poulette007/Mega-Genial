#include "logiqueExec.h"
#include "dropSalt.h"
#include "constante.h"

/*void execute()
{
  // init color detector
  Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
  initColorSensor(tcs);

  bool isDone = false;

  while (!isDone)
  {
    bool color = isBlue(tcs);
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

    //lastDetectedLine = detectedLine;
    // lastColor = color;
  }
  delay(10);
  stopAll();
}*/

void execute()
{
  Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
  initColorSensor(tcs);

  bool color = isBlue(tcs);
  Serial.print("color: ");
  Serial.println(color);
  int compteur = 0;
  int nbDeBleu = 0;

  //int lastDetectedLine = 0;
  //int lastColor = 0;
  
  while (isLine() != 4)
  {

    color = isBlue(tcs);
    Serial.print("color: ");
    Serial.println(color);
    if (color == true)
    {
      Serial.println("Color Detected: blue");
      //dropSalt(1);
      // dispenserOn();
      compteur ++;
      nbDeBleu ++;
    }
    else if (color == false)
    {
      Serial.print("no color detected");
      //dropSalt(0);
      // dispenserOff();
      compteur ++;
    }

    if (compteur == 10 && nbDeBleu >= 8) {
      dropSalt(1);
      compteur = 0;
    }

    else if (compteur == 10 && nbDeBleu < 8) {
      dropSalt(0);
      compteur = 0;
    }

    // stopAll();
    //bool color = isBlue(tcs);

    int detectedLine = isLine();
    //Serial.println(detectedLine);

    if (detectedLine == 4)
    {
      stopAll();
      break;
    }

    if (detectedLine == 1)
    {
      MOTOR_SetSpeed(0, 0);
      MOTOR_SetSpeed(1, 0.1);
    }
    else if (detectedLine == 2)
    {
      MOTOR_SetSpeed(0, 0.1);
      MOTOR_SetSpeed(1, 0.1);
    }
    else if (detectedLine == 3)
    {
      MOTOR_SetSpeed(0, 0.1);
      MOTOR_SetSpeed(1, 0);
    }
    else if (detectedLine == 0)
    {
      MOTOR_SetSpeed(0, 0.1);
      MOTOR_SetSpeed(1, 0.1);
    }

    //lastDetectedLine = detectedLine;
    //lastColor = color;
  }
  stopAll();
}
