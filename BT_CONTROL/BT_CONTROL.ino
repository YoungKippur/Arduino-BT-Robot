#include <SoftwareSerial.h>

SoftwareSerial miBT(10, 11);

int y;
int x;

void setup() {
  miBT.begin(9600);
}

void loop() {
  x = analogRead(A0);
  y = analogRead(A1);

  if (x > 1000) {
    miBT.write('E');
  }
  else if (x < 20) {
    miBT.write('C');
  }
  else if (y > 1000) {
    miBT.write('A');
  }
  else if (y < 20) {
    miBT.write('G');
  }
  else{
    miBT.write('B');
    }

}
