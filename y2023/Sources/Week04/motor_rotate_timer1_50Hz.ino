#include <TimerOne.h>

const int fan_pin = 9;
int Speed = 0;
int scale = 1;
void setup() {
    Timer1.initialize();
    Timer1.pwm(fan_pin, 0);
    setFrq(20);
    //scale = 1;
    //Timer1.setPeriod(20000/scale); //20000us = 20ms -> 50Hz
    //scale = 2;
    //Timer1.setPeriod(10000/scale); //10000us = 10ms -> 100Hz
    //scale = 10;
    //Timer1.setPeriod(20000/scale); //2000us = 2ms -> 500Hz
    //scale = 20;
    //Timer1.setPeriod(20000/scale); //2000us = 2ms -> 500Hz
    //scale = 50;
    //Timer1.setPeriod(20000/scale); //2000us = 2ms -> 500Hz
    //Timer1.setPwmDuty(fan_pin, 51); // 1ms/20ms = 5% duty, 1/20*1023 = 51, minimum speed
    //Timer1.setPwmDuty(fan_pin, 102); // 2ms/20ms = 10% duty, 2/20*1023 = 102, maximum speed 
    Serial.begin(9600); // open the serial port
    Serial.println("Program begin...");
    //Keyboard.begin();
    delay(3000);
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