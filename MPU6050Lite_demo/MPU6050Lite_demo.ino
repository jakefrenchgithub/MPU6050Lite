#include <MPU6050Lite.h>

float roll, pitch;

MPU6050Lite acc;

void setup() {
  Serial.begin(9600);
  acc.initialise(0x68);
}

void loop() {
  acc.readRegisters();
  roll = acc.roll();
  pitch = acc.pitch();
  Serial.print(roll); Serial.print("\t"); Serial.println(pitch); 
  delay(100);
}