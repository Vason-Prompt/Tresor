/*
 * Preparing for this tutorial:
 * 1. Install Library DFRobotDFPlayerMini by DFRobot in library manager.
 * 2. Buy MicroSD card.
 * 3. Format MicroSD card.
 * 4. Put recording in MircoSD card, named it "001.mp3", "002.mp3", "003.mp3",...
 * 
 * The order of song are as follow:
 *       / Part 1 / Part 2 / Part 3 / Title
 * Story0/      1 /      2 /      3 /     4
 * Story1/      5 /      6 /      7 /     8
 * Story2/      9 /     10 /     11 /    12
 * Story3/     13 /     14 /     15 /    16
 */
 
#include "mp3tf16p.h"

// MP3
MP3Player mp3(10,11); //RX, TX

// Story
int story = 0; //0-3

// Button
int buttonPart1Pin = 2;
int buttonPart2Pin = 3;
int buttonPart3Pin = 4;

int buttonChangeStoryPin = 5;


// Volume
int volume = 30; //sound volume, 30 is the loudest

void setup(){
    Serial.begin(9600);
    // Initialize module
    mp3.initialize();
    // Initialize button
    pinMode(buttonPart1Pin, INPUT);
    pinMode(buttonPart2Pin, INPUT);
    pinMode(buttonPart3Pin, INPUT);
    pinMode(buttonChangeStoryPin, INPUT);
}

void loop(){
    // If button change story is select is pressed
    if(digitalRead(buttonChangeStoryPin) == HIGH)
    {
      // Go to next story
      story = (story + 1) % 4;
      // Play title of story
      // Play the song number (story * 4) + 4 with predefined volume.
      mp3.playTrackNumber((story * 4) + 4, volume);
      while(digitalRead(buttonChangeStoryPin) == HIGH)
      {
        // while user are holding button, stuck in the loop until digital read is low
        delay(1);  
      }
    }

    // If button part 1 is pressed
    if(digitalRead(buttonPart1Pin) == HIGH)
    {
      // Play part 1
      // Play the song number (story * 4) + 1 with loudest (30) sound.
      mp3.playTrackNumber((story * 4) + 1, 30);
      while(digitalRead(buttonPart1Pin) == HIGH)
      {
        // while user are holding button, stuck in the loop until digital read is low
        delay(1);  
      } 
    }

    // If button part 2 is pressed
    if(digitalRead(buttonPart2Pin) == HIGH)
    {
      // Play part 2
      // Play the song number (story * 4) + 2 with loudest (30) sound.
      mp3.playTrackNumber((story * 4) + 2, 30);
      while(digitalRead(buttonPart2Pin) == HIGH)
      {
        // while user are holding button, stuck in the loop until digital read is low
        delay(1);  
      } 
    }

    // If button part 3 is pressed
    if(digitalRead(buttonPart3Pin) == HIGH)
    {
      // Play part 3
      // Play the song number (story * 4) + 3 with loudest (30) sound.
      mp3.playTrackNumber((story * 4) + 3, 30);
      while(digitalRead(buttonPart3Pin) == HIGH)
      {
        // while user are holding button, stuck in the loop until digital read is low
        delay(1);  
      } 
    }
    
    mp3.serialPrintStatus(MP3_ALL_MESSAGE);
}

/* Troubleshoot 
 * Compile Errors
 * * Check library DFRobotDFPlayerMini is installed.
 * * Check library mp3tf16p.h is installed.
 *
 * Error Message from the MP3 Player
 * * Make sure your wiring is good.
 * * Check wiring of pin 10 and 11 (is it reversed?)
 *
 * No Error Message - No sound
 * * Check file number is correct.
 * * Check if serial monitor is set baud rate to 9600
 * * Check the speaker.
 * * Unplug and re-plug the USB port.
 */
