/*
  Greyscale Smooth Fading Example for the LoL Shield

  Written by Ronald Stoner (ronstoner.info)
  Based off greyscale example code written by jimmie rodgers (jimmieprodgers.com)

  This code is in the public domain.
*/

#include "Charliplexing.h"  //initializes the LoL Sheild library

int xPosition = 0;          //x position 0-13
int yPosition = 0;          //y position 0-8
int frameCounter = 0;       //used to find when the frame has filled up (126 leds)
int greyscale = 1;          //greyscale color 0-7
int scrollSpeed = 125;      //delay between frames
int loopcounter = 1;        //loop counter for greyscale incrimentation
int reverse = 0;            //reverse bit

void setup()                // run once, when the sketch starts
{
  LedSign::Init(GRAYSCALE); //initializes a grayscale frame buffer
}

void loop()                 // run over and over again
{ 
  //If the frame counter is full, then it delays for scrollSpeed.
  if(frameCounter == 126){
    delay(scrollSpeed);
    frameCounter=0;
  }
  
  //if row fills up, advance y row by 1
  if(xPosition == 14)yPosition++;

  //once row completes, either subtract or add to loopcounter
  if(xPosition > 13 & reverse == 0)loopcounter++;
  if(xPosition > 13 & reverse == 1)loopcounter--;
  
  //reset row number once column filled
  if(xPosition > 13)xPosition=0;
  
  //at the end of the frame, it starts from the begining again
  if(yPosition > 8)yPosition=0;

  //set point at which reverse bit is set
  //in testing, I find a min of 1 and max 5 of gives a nice fade,
  //anything greater than that seems to be choppy or not as smooth.
  //feel free to play around with the values
  if(loopcounter > 5)reverse=1; 
  if(loopcounter == 1)reverse=0;

  greyscale = loopcounter;
  
  //sends the current x, y, and color to the frame, one LED at a time
  LedSign::Set(xPosition, yPosition, greyscale);
   
  //the counters are at the end of the loop, which will advance everything
  //for the next frame
  xPosition++;
  frameCounter++;
}
