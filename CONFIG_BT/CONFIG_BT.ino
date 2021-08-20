#include <SoftwareSerial.h>

// Use AT Comands

SoftwareSerial miBT(3, 2);

void setup() {

  Serial.begin(9600);
  Serial.println("listo");
  miBT.begin(9600); 
}

void loop() {
  if (miBT.available()) {
    Serial.write(miBT.read());
  }
  if (Serial.available()) {
    miBT.write(Serial.read());
  }
}
