// 7 segment clock with ds 2321 rtc  # finall table clock 1.02
//~YATHARTH AGARWAL
// 24-JAN-2019
// ##############################################################################################################################

// libraries
#include "SevSeg.h"
#include <DS3231.h>

SevSeg sevseg; //Initiate a seven segment controller object
DS3231  rtc(SDA, SCL);
Time t;

int rgbr = A2;
int rgbb = A1;
int rgbg = A3;

int segA  = 3;
int segB  = 12;
int segC  = 7;
int segD  = 5;
int segE  = 4;
int segF  = 13;
int segG  = 8;
int segDP  = 6;
int pin1 = 2;
int pin2 = 10;
int pin3 = 11;
int pin4 = 9;
int r = 0;
//int but1 = A6; // rgb color change button
//const int tonePin = A0;

////#####################################################################################################################################
void cyan() {
  analogWrite(A1, 255); //cyan
  analogWrite(A2, 0);
  analogWrite(A3, 255);
}
void red () {
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
void blue () {
  analogWrite(A1, 255);
  analogWrite(A2, 0);
  analogWrite(A3, 0);
}
void yellow () {
  analogWrite(A1, 0);
  analogWrite(A2, 255);
  analogWrite(A3, 255);
}
void white () {
  analogWrite(A1, 255);
  analogWrite(A2, 255);
  analogWrite(A3, 255);
}
//###################################################################################################################################
void setup() {

  for ( int i = 2; i < 14; i++) {

    pinMode(i, OUTPUT);
  }
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
//  pinMode(A6, INPUT);

  // set initial color###############################################################################
  cyan();
  //##################################################################################################
  byte numDigits = 4; // number of digits
  byte digitPins[] = {2, 10, 11, 9};
  byte segmentPins[] = {3, 12, 7, 5, 4, 13, 8, 6};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);

  rtc.begin();

  // The following lines can be uncommented to set the date and time
//  rtc.setDOW(TUESDAY);     // Set Day-of-Week to SUNDAY
//  rtc.setTime(19,49,0);     // Set the time to 12:00:00 (24hr format)
//  rtc.setDate(9, 2, 2020);   // Set the date to January 1st, 2014
}
//#################################################################################################################################

int i = 0;

void loop() {
  //################################################################################################################
//  but1 = analogRead(A6);
//  if (i > 7) i = 0;
//  if  (but1 > 200) {
//
//    switch (i) {
//      case 0 : red();
//        i++;
//        tone(tonePin, 800, 170);
//        delay(170);
//        break;
//
//      case 1 : yellow();
//        i = i + 1;
//        tone(tonePin, 750, 170);
//        delay(170);
//        break;
//
//      case 2 : green();
//        i = i + 1;
//        tone(tonePin, 700, 170);
//        delay(170);
//        break;
//
//
//      case 3 : cyan();
//        i = i + 1;
//        tone(tonePin, 650, 170);
//        delay(170);
//        break;
//
//      case 4 : pink();
//        i = i + 1;
//        tone(tonePin, 600, 170);
//        delay(170);
//        break;
//
//      case 5 : blue();
//        i = i + 1;
//        tone(tonePin, 550, 170);
//        delay(170);
//        break;
//
//
//      case 6 : white();
//        i = i + 1;
//        tone(tonePin, 500, 170);
//        delay(170);
//        break;
//
//      case 7 :  analogWrite(A1, 0); //off
//        analogWrite(A2, 0);
//        analogWrite(A3, 0);
//        i = i + 1;
//        tone(tonePin, 450, 170);
//        delay(170);
//        break;
//
//    }
//
//  }
  //##############################################################################################################
  t = rtc.getTime();
  int secs = (t.sec);
  int hr = (t.hour);
  int mins = (t.min);

  if (secs == 0 & mins == 0 ) {
//    tone(tonePin, 800, 100);
    r = random(0, 123) ;
    int k = r % 5;
    switch (k) {
      case 0 : red();
        break;
      case 1 : blue();
        break;
      case 2 : green();
        break;
      case 3 : cyan();
        break;
      case 4 : pink();
        break;

    }
    r = 0;
  }


 if (secs % 2 == 0 ) {

    t = rtc.getTime();
    int hr = t.hour;
    int mins = t.min;
    int hours = hr * 100;
    int showtime = hours + mins;
    sevseg.setNumber(showtime);
    sevseg.refreshDisplay();

  }

  else if (secs % 2 == 1 ) {
    t = rtc.getTime();
    int hr = t.hour;
    int mins = t.min;
    int hours = hr * 100;
    int showtime = hours + mins;
    sevseg.setNumber(showtime, 2);
    sevseg.refreshDisplay();

  }
}
