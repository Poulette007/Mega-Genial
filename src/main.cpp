// include 
#include <Arduino.h>
#include <libRobus.h>


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

  logiqueLoop();
}

