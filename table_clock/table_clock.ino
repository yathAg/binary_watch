// 7 segment clock with ds 2321 rtc
//~YATHARTH AGARWAL
// 24-JAN-2019

#include "SevSeg.h"
#include "RTClib.h"

SevSeg sevseg;
RTC_DS3231 rtc;
DateTime now;

// int rgbr = A2;
// int rgbb = A1;
// int rgbg = A3;

// int segA = 3;
// int segB = 12;
// int segC = 7;
// int segD = 5;
// int segE = 4;
// int segF = 13;
// int segG = 8;
// int segDP = 6;
// int pin1 = 2;
// int pin2 = 10;
// int pin3 = 11;
// int pin4 = 9;

void cyan() {
  analogWrite(A1, 255);  // cyan
  analogWrite(A2, 0);
  analogWrite(A3, 255);
}
void red() {
  analogWrite(A1, 0);
  analogWrite(A2, 255);
  analogWrite(A3, 0);
}
void pink() {
  analogWrite(A1, 255);
  analogWrite(A2, 255);
  analogWrite(A3, 0);
}
void green() {
  analogWrite(A1, 0);
  analogWrite(A2, 0);
  analogWrite(A3, 255);
}
void blue() {
  analogWrite(A1, 255);
  analogWrite(A2, 0);
  analogWrite(A3, 0);
}
void yellow() {
  analogWrite(A1, 0);
  analogWrite(A2, 255);
  analogWrite(A3, 255);
}
void white() {
  analogWrite(A1, 255);
  analogWrite(A2, 255);
  analogWrite(A3, 255);
}

void setup() {

  for (int i = 2; i < 14; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);

  cyan();  // set initial color

  byte numDigits = 4;  // number of digits
  byte digitPins[] = { 2, 10, 11, 9 };
  byte segmentPins[] = { 3, 12, 7, 5, 4, 13, 8, 6 };
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);

  rtc.begin();

  // The following lines can be uncommented to set the date and time
  //rtc.adjust(DateTime(2023, 8, 10, 2, 27, 0));  // year, month, day, hour, minute, second
}

int r = 0;
void loop() {
  now = rtc.now();
  if ((now.second() + now.minute()) == 0) {
    r = random(0, 123);
    int k = r % 5;
    switch (k) {
      case 0:
        red();
        break;
      case 1:
        blue();
        break;
      case 2:
        green();
        break;
      case 3:
        cyan();
        break;
      case 4:
        pink();
        break;
    }
    r = 0;
  }

  if ((now.second() % 2) == 0) {
    now = rtc.now();
    int showtime = (now.hour() * 100) + now.minute();
    sevseg.setNumber(showtime);
    sevseg.refreshDisplay();
  }

  else if ((now.second() % 2) == 1) {
    now = rtc.now();
    int showtime = (now.hour() * 100) + now.minute();
    sevseg.setNumber(showtime, 2);
    sevseg.refreshDisplay();
  }
}
