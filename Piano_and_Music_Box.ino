// Project:      Arduino Piano & Music Box
// Course:       Intro to IoT for Electronics (PBL)
// Author:       Kyle Miller

//──────────── Libraries ─────────────────────────────────────────────────────────────────────────────
#include "pitches.h"        // Contains the frequency values of all notes

//──────────── Pin Definitions ───────────────────────────────────────────────────────────────────────
#define buzzerPin 9
#define button7Pin 8
#define button6Pin 7
#define button5Pin 6
#define button4Pin 5
#define button3Pin 4
#define button2Pin 3
#define button1Pin 2
bool currentMode = false;  // Declare and set currentMode to false

//──────────── 1st Function ──────────────────────────────────────────────────────────────────────────
void buttonLogic (void){                        // Button Logic for a C Major scale
  // To use a different scale, change the note (NOTE_XX) values of the buttons below
  if ((digitalRead(button1Pin))==LOW){          // Button 1 (left-most)
    tone(buzzerPin, NOTE_C3);                   // Play note C3 (130.81 Hz)
  }
  else if ((digitalRead(button2Pin))==LOW){     // Button 2
    tone(buzzerPin, NOTE_D3);                   // Play note D3 (146.83 Hz)
  }
  else if ((digitalRead(button3Pin))==LOW){     // Button 3
    tone(buzzerPin, NOTE_E3);                   // Play note E3 (164.81 Hz)
  }
  else if ((digitalRead(button4Pin))==LOW){     // Button 4 (middle)
    tone(buzzerPin, NOTE_F3);                   // Play note F3 (174.61 Hz)
  }
  else if ((digitalRead(button5Pin))==LOW){     // Button 5
    tone(buzzerPin, NOTE_G3);                   // Play note G3 (196.00 Hz)
  }
  else if ((digitalRead(button6Pin))==LOW){     // Button 6
    tone(buzzerPin, NOTE_A3);                   // Play note A3 (220.00 Hz)
  }
  else if ((digitalRead(button7Pin))==LOW){     // Button 7 (right-most)
    tone(buzzerPin, NOTE_B3);                   // Play note B3 (246.94 Hz)
  }
  else {                                        // If no buttons are pressed
    noTone(buzzerPin);                          // Silence
  }
}

//──────────── 2nd Function ──────────────────────────────────────────────────────────────────────────
void modeSelect (void){                         // Mode Select Function
  delay(50);                                    // Wait before reading pin 1, for voltage to stabilize
  if ((digitalRead(button1Pin))==LOW){          // If button 1 is held at startup...
    currentMode = true;                         // Set currentMode to true (Music Box mode)
  }
  else if ((digitalRead(button1Pin))==HIGH){    // If button 1 is NOT pressed at startup...
    currentMode = false;                        // Keep currentMode = false (Piano mode)
  }
}

//──────────── 3rd Function ──────────────────────────────────────────────────────────────────────────
void songHappyBirthday (void){                  // Happy Birthday song
  // Phrase 1: "Hap-py Birth-day to you"
  tone(buzzerPin, NOTE_C4); delay(200);         // Hap-
  noTone(buzzerPin);        delay(50);          // tiny gap
  
  tone(buzzerPin, NOTE_C4); delay(200);         // -py
  noTone(buzzerPin);        delay(50);
  
  tone(buzzerPin, NOTE_D4); delay(400);         // Birth-
  noTone(buzzerPin);        delay(50);
  
  tone(buzzerPin, NOTE_C4); delay(400);         // -day
  noTone(buzzerPin);        delay(50);
  
  tone(buzzerPin, NOTE_F4); delay(400);         // to...
  noTone(buzzerPin);        delay(50);
  
  tone(buzzerPin, NOTE_E4); delay(800);         // you!
  noTone(buzzerPin);

  // Phrase 2: "Hap-py Birth-day to you"
  tone(buzzerPin, NOTE_C4); delay(200);         // Hap-
  noTone(buzzerPin);        delay(50);          // tiny gap
  
  tone(buzzerPin, NOTE_C4); delay(200);         // -py
  noTone(buzzerPin);        delay(50);
  
  tone(buzzerPin, NOTE_D4); delay(400);         // Birth-
  noTone(buzzerPin);        delay(50);
  
  tone(buzzerPin, NOTE_C4); delay(400);         // -day
  noTone(buzzerPin);        delay(50);
  
  tone(buzzerPin, NOTE_G4); delay(400);         // to...
  noTone(buzzerPin);        delay(50);
  
  tone(buzzerPin, NOTE_F4); delay(800);         // you!
  noTone(buzzerPin);

  // Phrase 3: "Hap-py Birth-day dear [Name]"
  tone(buzzerPin, NOTE_C4); delay(200);         // Hap-
  noTone(buzzerPin);        delay(50);
  
  tone(buzzerPin, NOTE_C4); delay(200);         // -py
  noTone(buzzerPin);        delay(50);
  
  tone(buzzerPin, NOTE_C5); delay(400);         // Birth-
  noTone(buzzerPin);        delay(50);
  
  tone(buzzerPin, NOTE_A4); delay(400);         // -day
  noTone(buzzerPin);        delay(50);
  
  tone(buzzerPin, NOTE_F4); delay(400);         // dear
  noTone(buzzerPin);        delay(50);
  
  tone(buzzerPin, NOTE_E4); delay(400);         // [Na-
  noTone(buzzerPin);        delay(50);
  
  tone(buzzerPin, NOTE_D4); delay(800);         // -me]
  noTone(buzzerPin);        delay(50);

  // Phrase 4: "Hap-py Birth-day to you!"
  tone(buzzerPin, NOTE_AS4); delay(200);        // Hap- (B-flat (or A-sharp))
  noTone(buzzerPin);         delay(50);
  
  tone(buzzerPin, NOTE_AS4); delay(200);        // -py
  noTone(buzzerPin);         delay(50);
  
  tone(buzzerPin, NOTE_A4);  delay(400);        // Birth-
  noTone(buzzerPin);         delay(50);
  
  tone(buzzerPin, NOTE_F4);  delay(400);        // -day
  noTone(buzzerPin);         delay(50);
  
  tone(buzzerPin, NOTE_G4);  delay(400);        // to...
  noTone(buzzerPin);         delay(50);
  
  tone(buzzerPin, NOTE_F4);  delay(800);        // you!
  noTone(buzzerPin);         delay(2000);       // Long pause at the end
}

void setup() {
  pinMode(buzzerPin, OUTPUT);                   // Set pin 9 as output
  pinMode(button7Pin, INPUT_PULLUP);            // Set pin 8 as input with internal pull-up resistor
  pinMode(button6Pin, INPUT_PULLUP);            // Set pin 7 as input with internal pull-up resistor
  pinMode(button5Pin, INPUT_PULLUP);            // Set pin 6 as input with internal pull-up resistor
  pinMode(button4Pin, INPUT_PULLUP);            // Set pin 5 as input with internal pull-up resistor
  pinMode(button3Pin, INPUT_PULLUP);            // Set pin 4 as input with internal pull-up resistor
  pinMode(button2Pin, INPUT_PULLUP);            // Set pin 3 as input with internal pull-up resistor
  pinMode(button1Pin, INPUT_PULLUP);            // Set pin 2 as input with internal pull-up resistor
  modeSelect();                                 // Run modeSelect once at startup, to set the "Mode"
}

void loop() {
  if (currentMode==true){                       // If currentMode is true, enter "Music Box" Mode
    songHappyBirthday();
  }
  else if (currentMode==false){                 // If currentMode is false, enter "Piano" Mode
    buttonLogic();
  }
}
