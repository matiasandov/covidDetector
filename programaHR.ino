#include <Wire.h>
#include "MAX30105.h"

//----------------este es el bueno---------
MAX30105 particleSensor;
uint32_t redBuffer;
uint32_t irBuffer;
int hrBuffer;
String dataToSend;
int sensorHR;
long milis;
void setup() {
  Serial.begin(9600); // initialize serial communication at 115200 bits per second:
  dataToSend.reserve(100);
  sensorHR=0;
  // Initialize sensor

}

void loop() {
  
   hrBuffer = analogRead(sensorHR);
   milis=millis();
   dataToSend="HR:";
   dataToSend+=hrBuffer;
   dataToSend+=";ML:";
   dataToSend+=milis;
  
   Serial.println(dataToSend);
   //Serial.println(hrBuffer);
}
