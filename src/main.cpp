// include 
#include <Arduino.h>
#include <dropSalt.h>
#include <libRobus.h>
#include <logiqueExec.h>
#define LEFT 0
#define RIGHT 1
#define FRONT 2
#define REAR 3

bool isDebug = false;
// ne pas toucher, laisser sur false, utiliser la fonction error
bool isError = false;



void beep(int time, int delayTime) {
  AX_BuzzerON();
  delay(time);
  AX_BuzzerOFF();
  delay(delayTime);
}

void error(String msg) {
  isError = true;
  Serial.println("#########################-- ERROR --#########################");
  Serial.print("message: ");
  Serial.println(msg);
  beep(300, 300);
  beep(300, 300);
  beep(300, 300);
  while (isError) {
    delay(100);
    Serial.println("ERROR");
  }
  
  // call fonction stopAll() eteindre capteur important
}

float division(int premier, int second){
  if(second == 0){
    String message = "impossible de diviser: " + (String)premier + " par : " + (String)second;  
    error(message);
  }

  return premier / second;
}

void logiqueLoop(){

}

void debugLoop() {
  
}

void setup() {
  Serial.begin(9600);
  BoardInit();
  if(isDebug) {
    Serial.println("Debug");
  }
}


void loop() {
  if (isError) {
    return;
  }

  if (isDebug) {
    debugLoop();
  }
  if (ROBUS_IsBumper(LEFT)) {
    //MOTOR_SetSpeed(1,0.5);
    //MOTOR_SetSpeed(0,0.5);
    delay(10);
    Serial.println("Bumper gauche");
    execute();

    //isLine();
  }

  //logiqueLoop();
  /*if (ROBUS_IsBumper(LEFT)) {
    Serial.println("Bumper gauche");
    int isOn = 1;
    dropSalt(isOn);
  }*/

}

