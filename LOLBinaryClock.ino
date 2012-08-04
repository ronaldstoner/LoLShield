/*
An open-source binary clock for Arduino with LoL Shield
Adapted for LoL Shield by Ron Stoner (ronstoner.info)
Based on code from Rob Faludi (http://www.faludi.com) and Daniel Spillere Andrade (www.danielandrade.net)
 
This code is in the public domain.
*/

#include <Charliplexing.h> //Imports the library, which needs to be
                           //Initialized in setup.

int second=0, minute=37, hour=13; //start the time on 13:37:00
int munit,hunit,sunit,i;

void setup() { //set outputs and sinput
  // init the lol shield
  LedSign::Init();
}

void loop() {

static unsigned long lastTick = 0; // set up a local variable to hold the last time we moved forward one second
// (static variables are initialized once and keep their values between function calls)
// move forward one second every 1000 milliseconds

if (millis() - lastTick >= 1000) {
  lastTick = millis();
  second++;

}

// move forward one minute every 60 seconds
  if (second >= 60) {
  minute++;
  second = 0; // reset seconds to zero
}

// move forward one hour every 60 minutes
if (minute >=60) {
  hour++;
  minute = 0; // reset minutes to zero
}

if (hour >=24) {
  hour=0;
  minute = 0; // reset minutes to zero
}

  sunit = second%10; // sets the variable munit and hunit for the unit digits
  munit = minute%10;
  hunit = hour%10;

  //second units
  if(sunit == 1 || sunit == 3 || sunit == 5 || sunit == 7 || sunit == 9) {LedSign::Set(9, 5, 1);} else {LedSign::Set(9, 5, 0);}
  if(sunit == 2 || sunit == 3 || sunit == 6 || sunit == 7) {LedSign::Set(9, 4, 1);}  else {LedSign::Set(9, 4, 0);}
  if(sunit == 4 || sunit == 5 || sunit == 6 || sunit == 7) {LedSign::Set(9, 3, 1);}  else {LedSign::Set(9, 3, 0);}
  if(sunit == 8 || sunit == 9) {LedSign::Set(9, 2, 1);} else {LedSign::Set(9, 2, 0);}

  //seconds
  if((second >= 10 && second < 20) || (second >= 30 && second < 40) || (second >= 50 && second < 60)) {LedSign::Set(8, 5, 1);} else {LedSign::Set(8, 5, 0);}
  if(second >= 20 && second < 40)  {LedSign::Set(8, 4, 1);} else {LedSign::Set(8, 4, 0);}
  if(second >= 40 && second < 60) {LedSign::Set(8, 3, 1);} else {LedSign::Set(8, 3, 0);}

  //minute units
  if(munit == 1 || munit == 3 || munit == 5 || munit == 7 || munit == 9) {LedSign::Set(7, 5, 1);} else {LedSign::Set(7, 5, 0);}
  if(munit == 2 || munit == 3 || munit == 6 || munit == 7) {LedSign::Set(7, 4, 1);}  else {LedSign::Set(7, 4, 0);}
  if(munit == 4 || munit == 5 || munit == 6 || munit == 7) {LedSign::Set(7, 3, 1);}  else {LedSign::Set(7, 3, 0);}
  if(munit == 8 || munit == 9) {LedSign::Set(7, 2, 1);} else {LedSign::Set(7, 2, 0);}

  //minutes
  if((minute >= 10 && minute < 20) || (minute >= 30 && minute < 40) || (minute >= 50 && minute < 60)) {LedSign::Set(6, 5, 1);} else {LedSign::Set(6, 5, 0);}
  if(minute >= 20 && minute < 40)  {LedSign::Set(6, 4, 1);} else {LedSign::Set(6, 4, 0);}
  if(minute >= 40 && minute < 60) {LedSign::Set(6, 3, 1);} else {LedSign::Set(6, 3, 0);}

  //hour units
  if(hunit == 1 || hunit == 3 || hunit == 5 || hunit == 7 || hunit == 9) {LedSign::Set(5, 5, 1);} else {LedSign::Set(5, 5, 0);}
  if(hunit == 2 || hunit == 3 || hunit == 6 || hunit == 7) {LedSign::Set(5, 4, 1);} else {LedSign::Set(5, 4, 0);}
  if(hunit == 4 || hunit == 5 || hunit == 6 || hunit == 7) {LedSign::Set(5, 3, 1);} else {LedSign::Set(5, 3, 0);}
  if(hunit == 8 || hunit == 9) {LedSign::Set(5, 2, 1);} else {LedSign::Set(5, 2, 0);}

  //hour
  if(hour >= 10 && hour < 20)  {LedSign::Set(4, 5, 1);} else {LedSign::Set(4, 5, 0);}
  if(hour >= 20 && hour < 24)  {LedSign::Set(4, 4, 1);} else {LedSign::Set(4, 4, 0);}

  }
