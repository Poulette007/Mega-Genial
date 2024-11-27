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
  long entryTime = 100000000;
  long exitTime = 100000000;

  // int lastDetectedLine = 0;
  // int lastColor = 0;
  while (isLine() != 4)
  {

    if (sonarCounter == 10)
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
      if (color) {
        onBlue = true;
      }
      else {
        onBlue = false;
      }
      lastState = false;
      sonarCounter = 0;
    }
    else
    {
      sonarCounter++;
      Serial.print("sonarCounter: ");
      Serial.println(sonarCounter);
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
        // dispenserOn();
        compteur++;
        nbDeBleu++;
      }
      else if (color == false)
      {
        Serial.println("no color detected");
        // dropSalt(0);
        // dispenserOff();
        compteur++;
      }

      if (compteur == 5 && nbDeBleu >= 3)
      {
        onBlue = true;
        Serial.print("compteur: ");
        Serial.println(compteur);
        Serial.print("nbDeBleu: ");
        Serial.println(nbDeBleu);
        compteur = 0;
        nbDeBleu = 0;
        //entryTime = millis();
      }

      else if (compteur == 5 && nbDeBleu < 3)
      {
        onBlue = false;
        Serial.print("compteur: ");
        Serial.println(compteur);
        Serial.print("nbDeBleu: ");
        Serial.println(nbDeBleu);
        compteur = 0;
        //exitTime = millis();
      }

      if (lastState == true && onBlue == true)
      {
        //dropSalt(1);
        Serial.println("is blue and was blue");
      }
      else if (lastState == false && onBlue == false)
      {
        //dropSalt(0);
        Serial.println("is not blue and was not blue");
      }
      else if (lastState == false && onBlue == true)
      {
        entryTime = millis();
        Serial.print("entryTime: ");
        Serial.println(entryTime);
        Serial.println("is blue and was not blue");
        //dropSalt(1);
      }
      else if (lastState == true && onBlue == false)
      {
        Serial.println("is not blue and was blue");
        //dropSalt(0);
        exitTime = millis();
        Serial.print("exitTime: ");
        Serial.println(exitTime);
      }
      lastState = onBlue;
      Serial.print("millis: ");
      Serial.println(millis());
      if (millis() >= entryTime + 1500) {
        dropSalt(1);
      }
      if (millis() >= exitTime + 2500) {
        dropSalt(0);
      }

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
