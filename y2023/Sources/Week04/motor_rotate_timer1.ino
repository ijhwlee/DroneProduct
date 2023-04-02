#include <TimerOne.h>

const int fan_pin = 9;
int Speed = 0;
int scale = 1;
void setup() {
    Timer1.initialize();
    Timer1.pwm(fan_pin, 0);
    setFrq(50);
    delay(2000);
    //Speed = 75;
    //Timer1.setPwmDuty(fan_pin, Speed);
}

void setFrq(int frq) {
  scale = frq;
  Timer1.setPeriod(1000000/frq); //20000us = 20ms -> 50Hz
}

void loop() {
  Speed = analogRead(A0);
  Speed = map(Speed, 0, 1023, 0, 2*scale);
  //Speed = 70;
  Serial.println(Speed);
  //Speed = Speed + 10;
  //if (Speed > 102) {
  //  Speed = 0;
  //}
  Timer1.setPwmDuty(fan_pin, Speed);
  delay(2000);
}
