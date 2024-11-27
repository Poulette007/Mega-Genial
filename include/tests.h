//
// Created by Raphael on 2024-11-27.
//

#ifndef TESTS_H
#define TESTS_H
#include "colorDetection.h"
#include "suivageLigne.h"
#include "dropSalt.h"
#include "constante.h"
#include "capteurSonar.h"

void testSuiveurLigne();
int  testColorDetection(Adafruit_TCS34725 tcs);
void testDropSalt();
void testCapteurSonar();

#endif //TESTS_H
