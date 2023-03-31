#include "vector.h"

// Temos 64 unidades de distância (U.D.) para o papel completo
#define matrixLength 64

#define delayForDrawing 3000

/*
0: Sentido anti-horário
1: Sentido horário
*/
int motorDirection = 0;
// Temos 1 U.D. por segundo
float motorVelocity = 1;

float previousMotorPosition = 0;
float motorPosition = 0;
float previousMotorTime = 0;
float motorTime = 0;
float adjustForDrawingTime = 0;

int vectorPosition = 0;

void upgradePosition() {
  motorTime = (millis() / 1000.0) - adjustForDrawingTime;
  motorPosition = previousMotorPosition + (motorTime - previousMotorTime) * motorVelocity;

  previousMotorPosition = motorPosition;
  previousMotorTime = motorTime;
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  upgradePosition();
  Serial.println(String("Posição do motor: ") + String(motorPosition));

  if(motorPosition >= positionsX[vectorPosition]) {
    Serial.println("DESENHANDO...");
    Serial.println("");
    vectorPosition++;

    adjustForDrawingTime += delayForDrawing / 1000.0;
    delay(delayForDrawing);
  }
  if(vectorPosition == vectorLength) {
    while(1){}
  }

  delay(10);
}
