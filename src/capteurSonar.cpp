#include "capteurSonar.h"
#include "constante.h"
#include "libRobus.h"

const int CM_PER_MU_SEC = 58.2;
int change = 0;

// Get Sonar Value retourn the distance between the closet objet and the capteur
// need a delay of minimum 250ms between each call
float GetSonarValue() {
    float duree = 0;
    float distance = 0;
    if (change % 2)
    {
        digitalWrite(PIN_SONAR_TRIG, LOW);
        delayMicroseconds(2);
        digitalWrite(PIN_SONAR_TRIG, HIGH);
        delayMicroseconds(10);
        digitalWrite(PIN_SONAR_TRIG, LOW);
        duree = pulseIn(PIN_SONAR_ECHO, HIGH, 25000);
    }
    else
    {
        digitalWrite(PIN_SONAR_TRIG_2, LOW);
        delayMicroseconds(2);
        digitalWrite(PIN_SONAR_TRIG_2, HIGH);
        delayMicroseconds(10);
        digitalWrite(PIN_SONAR_TRIG_2, LOW);
        duree = pulseIn(PIN_SONAR_ECHO_2, HIGH, 25000);
    }
    
    distance = duree / CM_PER_MU_SEC;
    //Serial.print("Capteur ");
    //Serial.print(change % 2);
    //Serial.print(" Distance: ");
    change++;
    return distance;
}
// is Object In Front return true if there is a abject between max and min
// min and max can be adjuste in constante.cpp
bool isObjectInFront() {
    int distance = GetSonarValue();
    if (distance >= PIN_SONAR_MIN_DIST && distance <= PIN_SONAR_MAX_DIST) {
        Serial.println("Object in front");
        return true;
    }
    else {
        Serial.println("No object in front");
        return false;
    }
}
