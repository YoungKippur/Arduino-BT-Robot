#include <SoftwareSerial.h>

#define PIN_LED 4

#define MOTD_ADELANTE 9
#define MOTD_ATRAS 8
#define MOTI_ADELANTE 10
#define MOTI_ATRAS 11
#define MOTD_PWM 5
#define MOTI_PWM 6
#define POT 120

SoftwareSerial miBT (2, 3);
int leer;

void setup() {
  Serial.begin(9600);
  miBT.begin(9600);

  pinMode(PIN_LED, OUTPUT);

  pinMode(MOTD_ADELANTE, OUTPUT);
  pinMode(MOTD_ATRAS, OUTPUT);
  pinMode(MOTI_ADELANTE, OUTPUT);
  pinMode(MOTI_ATRAS, OUTPUT);
  pinMode(MOTD_PWM, OUTPUT);
  pinMode(MOTI_PWM, OUTPUT);
}

void loop() {
  if (miBT.available()) {
    leer = miBT.read();
    Serial.write(leer); // lee BT y envia a Arduino

    if (leer == 'A') {
      adelante();
    }

    if (leer == 'B') {
      frenar();
    }

    if (leer == 'C') {
      izquierda();
    }

    if (leer == 'D') {
      frenar();
    }

    if (leer == 'E') {
      derecha();
    }

    if (leer == 'F') {
      frenar();
    }

    if (leer == 'G') {
      atras();
    }

    if (leer == 'H') {
      frenar();
    }

    if (leer == 'I') {
      ON();
    }

    if (leer == 'J') {
      OFF();
    }
  }
}

void ON() {
  digitalWrite(PIN_LED, HIGH);
}

void OFF() {
  digitalWrite(PIN_LED, LOW);
}

void adelante() {
  digitalWrite(MOTI_ADELANTE, HIGH);
  digitalWrite(MOTI_ATRAS, LOW);
  analogWrite(MOTI_PWM, POT);

  digitalWrite(MOTD_ADELANTE, HIGH);
  digitalWrite(MOTD_ATRAS, LOW);
  analogWrite(MOTD_PWM, POT);
}

void izquierda() {
  digitalWrite(MOTI_ADELANTE, LOW);
  digitalWrite(MOTI_ATRAS, HIGH);
  analogWrite(MOTI_PWM, POT);

  digitalWrite(MOTD_ADELANTE, HIGH);
  digitalWrite(MOTD_ATRAS, LOW);
  analogWrite(MOTD_PWM, POT);
}

void derecha() {
  digitalWrite(MOTI_ADELANTE, HIGH);
  digitalWrite(MOTI_ATRAS, LOW);
  analogWrite(MOTI_PWM, POT);

  digitalWrite(MOTD_ADELANTE, LOW);
  digitalWrite(MOTD_ATRAS, HIGH);
  analogWrite(MOTD_PWM, POT);
}

void atras() {
  digitalWrite(MOTI_ADELANTE, LOW);
  digitalWrite(MOTI_ATRAS, HIGH);
  analogWrite(MOTI_PWM, POT);

  digitalWrite(MOTD_ADELANTE, LOW);
  digitalWrite(MOTD_ATRAS, HIGH);
  analogWrite(MOTD_PWM, POT);
}

void frenar() {
  digitalWrite(MOTI_ADELANTE, LOW);
  digitalWrite(MOTI_ATRAS, LOW);
  analogWrite(MOTI_PWM, POT);

  digitalWrite(MOTD_ADELANTE, LOW);
  digitalWrite(MOTD_ATRAS, LOW);
  analogWrite(MOTD_PWM, POT);
}
