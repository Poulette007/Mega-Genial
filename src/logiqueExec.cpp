#include "logiqueExec.h"
#include "dropSalt.h"
#include "constante.h"
#include "capteurSonar.h"

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
  bool onBlue = false;
  bool lastState = false;
  bool color = isBlue(tcs);
  Serial.print("color: ");
  Serial.println(color);
  int compteur = 0;
  int nbDeBleu = 0;
  int sonarCounter = 0;
  bool objectDetected = false;

  // int lastDetectedLine = 0;
  // int lastColor = 0;
  while (isLine() != 4)
  {

    if (sonarCounter == 3)
    {
      Serial.println("##################################################################");
      Serial.println("##################################################################");
      Serial.println("##################################################################");
      if (isObjectInFront())
      {
        int isObjectInFrontVar = 0;
        stopAll();
        dropSalt(0);
        Serial.println("Sonar Detect in execute");
        while (isObjectInFrontVar <= 5)
        {
          delay(250);
          if (!isObjectInFront())
          {
            isObjectInFrontVar ++;
          }else{
            isObjectInFrontVar = 0;
          }
        }
        
        
      }
      sonarCounter = 0;
    }
    else
    {
      sonarCounter++;
    }

    if (1)
    {
      color = isBlue(tcs);
      Serial.print("color: ");
      Serial.println(color);

      if (color == true)
      {
        Serial.println("Color Detected: blue");
        // dropSalt(1);
        //  dispenserOn();
        compteur++;
        nbDeBleu++;
      }
      else if (color == false)
      {
        Serial.println("no color detected");
        // dropSalt(0);
        //  dispenserOff();
        compteur++;
      }

      if (compteur == 10 && nbDeBleu >= 6)
      {
        onBlue = true;
        Serial.print("compteur: ");
        Serial.println(compteur);
        Serial.print("nbDeBleu: ");
        Serial.println(nbDeBleu);
        compteur = 0;
        nbDeBleu = 0;
      }

      else if (compteur == 10 && nbDeBleu < 6)
      {
        onBlue = false;
        Serial.print("compteur: ");
        Serial.println(compteur);
        Serial.print("nbDeBleu: ");
        Serial.println(nbDeBleu);
        compteur = 0;
      }

      if (lastState == true && onBlue == true)
      {
        Serial.println("is blue and was blue");
      }
      else if (lastState == false && onBlue == false)
      {
        Serial.println("is not blue and was not blue");
      }
      else if (lastState == false && onBlue == true)
      {
        Serial.println("is blue and was not blue");
        dropSalt(1);
      }
      else if (lastState == true && onBlue == false)
      {
        Serial.println("is not blue and was blue");
        dropSalt(0);
      }

      lastState = onBlue;

      // stopAll();

      int detectedLine = isLine();
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

      // lastDetectedLine = detectedLine;
      // lastColor = color;
    }
    else
    {
      stopAll();
    }
  }
  stopAll();
}
