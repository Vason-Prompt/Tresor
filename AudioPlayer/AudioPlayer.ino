#include "arduino_secrets.h"

/*
 * Preparing for this tutorial:
 * 1. Install Library DFRobotDFPlayerMini by DFRobot in library manager.
 * 2. Buy MicroSD card.
 * 3. Format MicroSD card.
 * 4. Put 3 recording in MircoSD card, named it "001.mp3", "002.mp3", "003.mp3"
 */
 
#include "mp3tf16p.h"

MP3Player mp3(10,11); //RX, TX

void setup(){
    Serial.begin(9600);
    // Initialize module
    mp3.initalize();
    // Play the song number 1 with loudest (30) sound.
    mp3.playTrackNumber(1, 30);
}

void loop(){
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
