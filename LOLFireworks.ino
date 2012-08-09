/*
An open-source fireworks display for Arduino with LoL Shield by Jimme P. Rodgers (http://jimmieprodgers.com/)
Code created by Ron Stoner (ronstoner.info)
 
This code is in the public domain.
*/

#include <Charliplexing.h>   //Imports the library, which needs to be
                             //Initialized in setup.
                           
int xpos, ypos;              //declare position variables
int maxheight;               //declare explosion point variable
int greyscale = 0;           //greyscale color 0-7
int frametime = 200;         //main timer for speed of animations
int exptype = 0;             //explosion type (there are 3)

void setup() { 
  LedSign::Init(GRAYSCALE);  //initializes a grayscale frame buffer
  xpos = random(1, 13);      //initial starting position (x)
  maxheight =  random (1,6); //randomize explosion point
  ypos = 8;                  //starting pos at bottom of screen (y)
}

void loop() {
LedSign::Set(xpos, ypos, 4);

if (ypos <=7 && ypos >= maxheight) {
 
  LedSign::Set(xpos, (ypos + 1), 2);       //draw tail piece 1 
 
  if (ypos <=6 && ypos >= maxheight) {
 
    LedSign::Set(xpos, (ypos + 2), 1);     //draw tail piece 2   
    LedSign::Set(xpos, (ypos + 3), 0);     //turn off remaining tail pieces
 
    if (ypos <= maxheight) {   

      for(int i = 2; i > 0; i--) {         //once trail hits maxheight, for loop to remove extra parts
       delay(frametime);
       LedSign::Set(xpos, (ypos + i), 0);  //turn off remaining tail pieces
      }

      for(int y = 3; y > 0; y--) {         //once tail is gone, do a nice face on the projectile
       delay(frametime);
       LedSign::Set(xpos, ypos, (y - 1));  //y is used as a grayscale value
      }

     exptype = random(1,4);                //randomize an explosion type
     delay(frametime * random(2,7));       //randomize a wait time
     switch(exptype) {                     //switch on the exptype variable
     case 1:
       //sparkly explosion
       LedSign::Set(xpos, ypos, 1); 
     
       delay(frametime/3);
       LedSign::Set(xpos, ypos, 3);  
     
       delay(frametime/3);
       LedSign::Set(xpos, ypos, 5);    

       delay(frametime/3);
       LedSign::Set(xpos, ypos, 7);    

       delay(frametime/3);
       LedSign::Set((xpos + 1), ypos, 1);  
       LedSign::Set((xpos - 1), ypos, 1);  
       LedSign::Set(xpos, (ypos + 1), 1);       
       LedSign::Set(xpos, (ypos - 1), 1);
     
       delay(frametime/3);
       LedSign::Set((xpos + 1), ypos, 3);  
       LedSign::Set((xpos - 1), ypos, 3);  
       LedSign::Set(xpos, (ypos + 1), 3);       
       LedSign::Set(xpos, (ypos - 1), 3);

       delay(frametime/3);
       LedSign::Set((xpos + 1), ypos, 5);  
       LedSign::Set((xpos - 1), ypos, 5);  
       LedSign::Set(xpos, (ypos + 1), 5);       
       LedSign::Set(xpos, (ypos - 1), 5);

       delay(frametime/3);
       LedSign::Set((xpos + 1), ypos, 7);  
       LedSign::Set((xpos - 1), ypos, 7);  
       LedSign::Set(xpos, (ypos + 1), 7);       
       LedSign::Set(xpos, (ypos - 1), 7);

      //fading sparkles
       for (int loopcounter = 8; loopcounter > 1; loopcounter--) {
         delay(frametime/2);
         LedSign::Set((xpos - 1), (ypos - 1), (loopcounter -1));  
         LedSign::Set((xpos - 1), ypos, 0);  
         LedSign::Set((xpos - 1), (ypos + 1), (loopcounter -1));  
         LedSign::Set(xpos, (ypos - 1), 0);  
         LedSign::Set(xpos, ypos, (loopcounter -1));  
         LedSign::Set(xpos, (ypos + 1), 0);  
         LedSign::Set((xpos + 1), (ypos - 1), (loopcounter -1));  
         LedSign::Set((xpos + 1), ypos, 0);  
         LedSign::Set((xpos + 1), (ypos + 1), (loopcounter -1));  

         delay(frametime/2);
         LedSign::Set((xpos - 1), (ypos - 1), 0);  
         LedSign::Set((xpos - 1), ypos, (loopcounter -1));  
         LedSign::Set((xpos - 1), (ypos + 1), 0);  
         LedSign::Set(xpos, (ypos - 1), (loopcounter -1));  
         LedSign::Set(xpos, ypos, 0);  
         LedSign::Set(xpos, (ypos + 1), (loopcounter -1));  
         LedSign::Set((xpos + 1), (ypos - 1), 0);  
         LedSign::Set((xpos + 1), ypos, (loopcounter -1));  
         LedSign::Set((xpos + 1), (ypos + 1), 0);      

         delay(frametime/2);
         LedSign::Set((xpos - 1), (ypos - 1), (loopcounter -1));  
         LedSign::Set((xpos - 1), ypos, 0);  
         LedSign::Set((xpos - 1), (ypos + 1), (loopcounter -1));  
         LedSign::Set(xpos, (ypos - 1), 0);  
         LedSign::Set(xpos, ypos, (loopcounter -1));  
         LedSign::Set(xpos, (ypos + 1), 0);  
         LedSign::Set((xpos + 1), (ypos - 1), (loopcounter -1));  
         LedSign::Set((xpos + 1), ypos, 0);  
         LedSign::Set((xpos + 1), (ypos + 1), (loopcounter -1));  

         delay(frametime/2);
         LedSign::Set((xpos - 1), (ypos - 1), 0);  
         LedSign::Set((xpos - 1), ypos, (loopcounter -1));  
         LedSign::Set((xpos - 1), (ypos + 1), 0);  
         LedSign::Set(xpos, (ypos - 1), (loopcounter -1));  
         LedSign::Set(xpos, ypos, 0);  
         LedSign::Set(xpos, (ypos + 1), (loopcounter -1));  
         LedSign::Set((xpos + 1), (ypos - 1), 0);  
         LedSign::Set((xpos + 1), ypos, (loopcounter -1));  
         LedSign::Set((xpos + 1), (ypos + 1), 0);      
       }

       //clean up the screen
       LedSign::Set((xpos - 1), (ypos - 1), 0);  
       LedSign::Set((xpos - 1), ypos, 0);  
       LedSign::Set((xpos - 1), (ypos + 1), 0);  
       LedSign::Set(xpos, (ypos - 1), 0);  
       LedSign::Set(xpos, ypos, 0);  
       LedSign::Set(xpos, (ypos + 1), 0);  
       LedSign::Set((xpos + 1), (ypos - 1), 0);  
       LedSign::Set((xpos + 1), ypos, 0);  
       LedSign::Set((xpos + 1), (ypos + 1), 0);  
       
       delay(frametime * random(2,7));  //wait
       break;
              
     case 2:
       //smooth boom       
       LedSign::Set(xpos, ypos, 1); 
     
       delay(frametime/3);
       LedSign::Set(xpos, ypos, 3);  
     
       delay(frametime/3);
       LedSign::Set(xpos, ypos, 5);    

       delay(frametime/3);
       LedSign::Set(xpos, ypos, 7);    

       delay(frametime/3);
       LedSign::Set((xpos + 1), ypos, 1);  
       LedSign::Set((xpos - 1), ypos, 1);  
       LedSign::Set(xpos, (ypos + 1), 1);       
       LedSign::Set(xpos, (ypos - 1), 1);
     
       delay(frametime/3);
       LedSign::Set((xpos + 1), ypos, 3);  
       LedSign::Set((xpos - 1), ypos, 3);  
       LedSign::Set(xpos, (ypos + 1), 3);       
       LedSign::Set(xpos, (ypos - 1), 3);

       delay(frametime/3);
       LedSign::Set((xpos + 1), ypos, 5);  
       LedSign::Set((xpos - 1), ypos, 5);  
       LedSign::Set(xpos, (ypos + 1), 5);       
       LedSign::Set(xpos, (ypos - 1), 5);

       delay(frametime/3);
       LedSign::Set((xpos + 1), ypos, 7);  
       LedSign::Set((xpos - 1), ypos, 7);  
       LedSign::Set(xpos, (ypos + 1), 7);       
       LedSign::Set(xpos, (ypos - 1), 7);

       delay(frametime/3);
       LedSign::Set((xpos + 1), ypos, 7);  
       LedSign::Set((xpos - 1), ypos, 7);  
       LedSign::Set(xpos, (ypos + 1), 7);       
       LedSign::Set(xpos, (ypos - 1), 7);
       LedSign::Set((xpos + 1), (ypos + 1), 3);  
       LedSign::Set((xpos + 1), (ypos - 1), 3);  
       LedSign::Set((xpos - 1), (ypos + 1), 3);
       LedSign::Set((xpos - 1), (ypos - 1), 3);    

       delay(frametime/3);
       LedSign::Set((xpos + 1), ypos, 7);  
       LedSign::Set((xpos - 1), ypos, 7);  
       LedSign::Set(xpos, (ypos + 1), 7);       
       LedSign::Set(xpos, (ypos - 1), 7);
       LedSign::Set((xpos + 1), (ypos + 1), 5);  
       LedSign::Set((xpos + 1), (ypos - 1), 5);  
       LedSign::Set((xpos - 1), (ypos + 1), 5);
       LedSign::Set((xpos - 1), (ypos - 1), 5);    

       delay(frametime/3);
       LedSign::Set((xpos + 1), ypos, 7);  
       LedSign::Set((xpos - 1), ypos, 7);  
       LedSign::Set(xpos, (ypos + 1), 7);       
       LedSign::Set(xpos, (ypos - 1), 7);
       LedSign::Set((xpos + 1), (ypos + 1), 7);  
       LedSign::Set((xpos + 1), (ypos - 1), 7);  
       LedSign::Set((xpos - 1), (ypos + 1), 7);
       LedSign::Set((xpos - 1), (ypos - 1), 7);    

       delay(frametime * 1.5);
       LedSign::Set((xpos + 1), ypos, 5);  
       LedSign::Set((xpos - 1), ypos, 5);  
       LedSign::Set(xpos, (ypos + 1), 5);       
       LedSign::Set(xpos, (ypos - 1), 5);
       LedSign::Set((xpos + 1), (ypos + 1), 5);  
       LedSign::Set((xpos + 1), (ypos - 1), 5);  
       LedSign::Set((xpos - 1), (ypos + 1), 5);
       LedSign::Set((xpos - 1), (ypos - 1), 5);    
       LedSign::Set(xpos, ypos, 5);    

       delay(frametime * 1.5);
       LedSign::Set((xpos + 1), ypos, 3);  
       LedSign::Set((xpos - 1), ypos, 3);  
       LedSign::Set(xpos, (ypos + 1), 3);       
       LedSign::Set(xpos, (ypos - 1), 3);
       LedSign::Set((xpos + 1), (ypos + 1), 3);  
       LedSign::Set((xpos + 1), (ypos - 1), 3);  
       LedSign::Set((xpos - 1), (ypos + 1), 3);
       LedSign::Set((xpos - 1), (ypos - 1), 3);
       LedSign::Set(xpos, ypos, 3);        

       delay(frametime * 1.5);
       LedSign::Set((xpos + 1), ypos, 1);  
       LedSign::Set((xpos - 1), ypos, 1);  
       LedSign::Set(xpos, (ypos + 1), 1);       
       LedSign::Set(xpos, (ypos - 1), 1);
       LedSign::Set((xpos + 1), (ypos + 1), 1);  
       LedSign::Set((xpos + 1), (ypos - 1), 1);  
       LedSign::Set((xpos - 1), (ypos + 1), 1);
       LedSign::Set((xpos - 1), (ypos - 1), 1);         
       LedSign::Set(xpos, ypos, 1);    

       delay(frametime * 1.5);
       LedSign::Set((xpos + 1), ypos, 0);  
       LedSign::Set((xpos - 1), ypos, 0);  
       LedSign::Set(xpos, (ypos + 1), 0);       
       LedSign::Set(xpos, (ypos - 1), 0);
       LedSign::Set((xpos + 1), (ypos + 1), 0);  
       LedSign::Set((xpos + 1), (ypos - 1), 0);  
       LedSign::Set((xpos - 1), (ypos + 1), 0);
       LedSign::Set((xpos - 1), (ypos - 1), 0);
       LedSign::Set(xpos, ypos, 0);  
     
       delay(frametime * random(2,7));  //wait
       break;
       
       case 3:
       //double rainbow all the way, across the sky - so intense
       LedSign::Set(xpos, ypos, 1); 
     
       delay(frametime/3);
       LedSign::Set(xpos, ypos, 3);  
     
       delay(frametime * 1.5);
       LedSign::Set(xpos, ypos, 1); 
       LedSign::Set((xpos - 1), (ypos - 1), 3);
       LedSign::Set((xpos + 1), (ypos - 1), 3);
       
       delay(frametime * 1.5);
       LedSign::Set(xpos, ypos, 0);  
       LedSign::Set((xpos - 1), (ypos - 1), 5);
       LedSign::Set((xpos + 1), (ypos - 1), 5);
       LedSign::Set((xpos - 1), ypos, 7);
       LedSign::Set((xpos + 1), ypos, 7);
       
       delay(frametime * 1.5);
       LedSign::Set((xpos - 1), (ypos - 1), 3);
       LedSign::Set((xpos + 1), (ypos - 1), 3);
       LedSign::Set((xpos - 1), ypos, 5);
       LedSign::Set((xpos + 1), ypos, 5);
       LedSign::Set((xpos - 1), (ypos +1), 7);
       LedSign::Set((xpos + 1), (ypos +1), 7);

       delay(frametime * 1.5);
       LedSign::Set((xpos - 1), (ypos - 1), 1);
       LedSign::Set((xpos + 1), (ypos - 1), 1);
       LedSign::Set((xpos - 1), ypos, 3);
       LedSign::Set((xpos + 1), ypos, 3);
       LedSign::Set((xpos - 1), (ypos +1), 5);
       LedSign::Set((xpos + 1), (ypos +1), 5);
       LedSign::Set((xpos - 1), (ypos +2), 7);
       LedSign::Set((xpos + 1), (ypos +2), 7);

       delay(frametime * 1.5);
       LedSign::Set((xpos - 1), (ypos - 1), 0);
       LedSign::Set((xpos + 1), (ypos - 1), 0);
       LedSign::Set((xpos - 1), ypos, 1);
       LedSign::Set((xpos + 1), ypos, 1);
       LedSign::Set((xpos - 1), (ypos +1), 3);
       LedSign::Set((xpos + 1), (ypos +1), 3);
       LedSign::Set((xpos - 1), (ypos +2), 5);
       LedSign::Set((xpos + 1), (ypos +2), 5);

       delay(frametime * 1.5);
       LedSign::Set((xpos - 1), ypos, 0);
       LedSign::Set((xpos + 1), ypos, 0);
       LedSign::Set((xpos - 1), (ypos +1), 1);
       LedSign::Set((xpos + 1), (ypos +1), 1);
       LedSign::Set((xpos - 1), (ypos +2), 3);
       LedSign::Set((xpos + 1), (ypos +2), 3);

       delay(frametime * 1.5);
       LedSign::Set((xpos - 1), (ypos +1), 0);
       LedSign::Set((xpos + 1), (ypos +1), 0);
       LedSign::Set((xpos - 1), (ypos +2), 1);
       LedSign::Set((xpos + 1), (ypos +2), 1);
       
       delay(frametime * 1.5);
       LedSign::Set((xpos - 1), (ypos +2), 0);
       LedSign::Set((xpos + 1), (ypos +2), 0);

       delay(frametime * random(2,7));  //wait
       break;
     }
    }
   }  
 }

if (ypos <= maxheight) { ypos = 9; xpos = random(1,13); maxheight = random(1,6); }  //reset the whole thing for the next projectile
ypos--;  //subtract y to move animation forward
delay(frametime); //delay frame update
}
