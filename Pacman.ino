/*
  PacMan Animation Example for the LoL Shield

  Updated with Pac Man Animation by Ron Stoner (ronstoner.info)
  Based off the Basic LoL Shield Test example code written by jimmie rodgers (jimmieprodgers.com)

  This code is in the public domain.
*/

#include <avr/pgmspace.h>  //AVR library for writing to ROM
#include <Charliplexing.h> //Imports the library, which needs to be
                           //Initialized in setup.

int blinkdelay = 100;      //Sets the time each frame is shown

/*
The BitMap array is what contains the frame data. Each line is one full frame.
Since each number is 16 bits, we can easily fit all 14 LEDs per row into it.
The number is calculated by adding up all the bits, starting with lowest on
the left of each row. 18000 was chosen as the kill number, so make sure that
is at the end of the matrix, or the program will continue to read into memory.

Here PROGMEM is called, which stores the array into ROM, which leaves us
with our RAM. You cannot change the array during run-time, only when you
upload to the Arduino. You will need to pull it out of ROM, which is covered
below. If you want it to stay in RAM, just delete PROGMEM
*/
uint16_t BitMap[][9] PROGMEM = {
// Ghosts & Pacman
{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 8192, 8192, 8192, 8192, 8192, 8192, 0},
{ 0, 8192, 4096, 4096, 4096, 4096, 4096, 4096, 8192},
{ 8192, 4096, 2048, 10240, 10240, 2048, 2048, 2048, 12288},
{ 12288, 2048, 1024, 13312, 9216, 1024, 1024, 9216, 6144},
{ 14336, 1024, 512, 6656, 2560, 512, 512, 4608, 11264},
{ 15360, 512, 256, 11520, 2304, 256, 256, 2304, 13824},
{ 15872, 256, 128, 13952, 4736, 128, 128, 9344, 6912},
{ 16128, 128, 64, 6976, 4672, 64, 64, 4672, 11648},
{ 8064, 8256, 32, 3488, 1184, 32, 32, 2336, 14016},
{ 4032, 4128, 8208, 9936, 9360, 8208, 8208, 9360, 7008},
{ 2016, 2064, 4104, 4968, 4392, 4104, 4104, 4680, 3504},
{ 1008, 1032, 2052, 2484, 2340, 2052, 2052, 2340, 1752},
{ 504, 516, 1026, 1242, 1098, 1026, 1026, 1170, 876},
{ 252, 258, 8705, 8813, 8777, 8705, 8705, 8777, 438},
{ 126, 8321, 4352, 4406, 4370, 4352, 4352, 4388, 8411},
{ 8255, 4160, 2176, 10395, 2194, 2176, 2176, 2194, 12397},
{ 12319, 2080, 1088, 13389, 9289, 1088, 1088, 9289, 6198},
{ 14351, 1040, 544, 6694, 2594, 544, 544, 4644, 11291},
{ 15367, 520, 272, 11539, 2322, 272, 272, 2322, 13837},
{ 15875, 260, 136, 13961, 4744, 136, 136, 9353, 6918},
{ 16129, 130, 68, 6980, 4676, 68, 68, 4676, 11651},
{ 8064, 8257, 34, 3490, 1186, 34, 34, 2338, 14017},
{ 4032, 4128, 8209, 9937, 9361, 8209, 8209, 9361, 7008},
{ 2016, 2064, 4104, 4968, 4392, 4104, 4104, 4680, 3504},
{ 1008, 1032, 2052, 2484, 2340, 2052, 2052, 2340, 1752},
{ 504, 516, 1026, 1242, 1098, 1026, 1026, 1170, 876},
{ 252, 258, 8705, 8813, 8777, 8705, 8705, 8777, 438},
{ 126, 8321, 4352, 4406, 4370, 4352, 4352, 4388, 8411},
{ 8255, 4160, 2176, 10395, 2194, 2176, 2176, 2194, 12397},
{ 12319, 2080, 1088, 13389, 5188, 1088, 1088, 9289, 6198},
{ 14351, 1040, 544, 6694, 4644, 544, 544, 4644, 11291},
{ 15367, 520, 272, 11539, 9489, 272, 272, 2322, 13837},
{ 15875, 260, 136, 13961, 9353, 136, 136, 9353, 6918},
{ 16129, 130, 68, 6980, 2372, 68, 68, 4676, 11651},
{ 8064, 8257, 34, 3490, 2338, 34, 34, 2338, 14017},
{ 4032, 4128, 8209, 9937, 8785, 8209, 8209, 9361, 7008},
{ 2016, 2064, 4104, 4968, 4680, 4104, 4104, 4680, 3504},
{ 1008, 1032, 2052, 2484, 2196, 2052, 2052, 2340, 1752},
{ 504, 516, 1026, 1242, 1170, 1026, 1026, 1170, 876},
{ 252, 258, 513, 621, 549, 513, 513, 585, 438},
{ 126, 129, 256, 310, 292, 256, 256, 292, 219},
{ 63, 64, 128, 155, 137, 128, 128, 146, 109},
{ 31, 32, 64, 77, 73, 64, 64, 73, 54},
{ 15, 16, 32, 38, 34, 32, 32, 36, 27},
{ 7, 8, 16, 19, 18, 16, 16, 18, 13},
{ 3, 4, 8, 9, 9, 8, 8, 9, 6},
{ 1, 2, 4, 4, 4, 4, 4, 4, 3},
{ 0, 1, 2, 2, 2, 2, 2, 2, 1},
{ 0, 0, 8193, 1, 1, 1, 8193, 1, 0},
{ 0, 8192, 4096, 8192, 0, 8192, 4096, 8192, 0},
{ 8192, 4096, 2048, 2048, 12288, 2048, 2048, 4096, 8192},
{ 12288, 2048, 1024, 512, 1536, 512, 1024, 2048, 12288},
{ 14336, 1024, 512, 512, 3072, 512, 512, 1024, 14336},
{ 15360, 512, 256, 512, 3072, 512, 256, 512, 15360},
{ 7680, 8448, 128, 128, 768, 128, 128, 8448, 7680},
{ 3840, 4224, 8256, 32, 96, 32, 8256, 4224, 3840},
{ 1920, 2112, 4128, 8224, 8384, 8224, 4128, 2112, 1920},
{ 960, 1056, 2064, 4128, 4288, 4128, 2064, 1056, 960},
{ 480, 528, 1032, 2056, 2096, 2056, 1032, 528, 480},
{ 240, 264, 516, 1026, 1030, 1026, 516, 264, 240},
{ 120, 132, 258, 514, 524, 514, 258, 132, 120},
{ 60, 66, 129, 258, 268, 258, 129, 66, 60},
{ 30, 33, 64, 128, 131, 128, 64, 33, 30},
{ 15, 16, 32, 64, 65, 64, 32, 16, 15},
{ 7, 8, 16, 32, 32, 32, 16, 8, 7},
{ 3, 4, 8, 16, 16, 16, 8, 4, 3},
{ 1, 2, 4, 8, 8, 8, 4, 2, 1},
{ 0, 1, 2, 4, 4, 4, 2, 1, 0},
{ 0, 0, 1, 2, 2, 2, 1, 0, 0},
{ 0, 0, 0, 1, 1, 1, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
{18000}
};

void setup() {
  LedSign::Init();  //Initializes the screen
}
void loop() {
  DisplayBitMap();  //Displays the bitmap
}

void DisplayBitMap()
{
  boolean run=true;    //While this is true, the screen updates
  byte frame = 0;      //Frame counter
  byte line = 0;       //Row counter
  unsigned long data;  //Temporary storage of the row data

  while(run == true) {
    for(line = 0; line < 9; line++) {

      //Here we fetch data from program memory with a pointer.
      data = pgm_read_word_near (&BitMap[frame][line]);
      
      //Kills the loop if the kill number is found
      if (data==18000){
        run=false;
      }
      
      //This is where the bit-shifting happens to pull out
      //each LED from a row. If the bit is 1, then the LED
      //is turned on, otherwise it is turned off.
      else for (byte led=0; led<14; ++led) {
        if (data & (1<<led)) {
          LedSign::Set(led, line, 1);
        }
        else {
          LedSign::Set(led, line, 0);
        }
      }

    }
    
    //Delays the next update
    delay(blinkdelay);        
    frame++;  
  }
}
