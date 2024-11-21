//
// Created by Raphael on 2024-11-21.
//
#include "LibRobus.h"

void dropSalt(int isOn) {//si isOn est a 1 laisser le sel tomber, si a 0 empecher le sel tomber
    //setup
    int angleStop=50;
    int angleDrop=90;
    int servoSelected=0;
    int motorPin=11;
    pinMode(motorPin,OUTPUT);

    if(isOn == 1){
        digitalWrite(motorPin,HIGH); //moteur on
        delay(1000);
        SERVO_Enable(servoSelected);
        SERVO_SetAngle(servoSelected,angleDrop);   //Initialise l'angle du servo pour laisser le sel tomber
        delay(1000);
        SERVO_Disable(servoSelected);
    }
    if(isOn == 0){
        SERVO_Enable(servoSelected);
        SERVO_SetAngle(servoSelected,angleStop);  //Initialise l'angle du servo pour empecher le sel tomber
        delay(1000);
        SERVO_Disable(servoSelected);
        digitalWrite(motorPin,LOW); //moteur off
    }
}
  
