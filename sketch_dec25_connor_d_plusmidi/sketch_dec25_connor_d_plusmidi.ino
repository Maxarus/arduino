
//INIT VARIABLES
//LED
int sensorPin = 0; //analog pin 0
int LEDinArray [8] = {7,2,6,5,9,10,12,14}; //digital LED Pin Array  
int ledArraySize = 8; //len(LEDinArray);
int baseValue = 90; //start value
int stepValue = 75; //block size

//MIDI
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

byte note = 0; //The MIDI note value to be played
byte resetMIDI = 4; //Tied to VS1053 Reset line
byte ledPin = 13; //MIDI traffic inidicator
int  instrument = 27;


//********SETUP*********
void setup(){
 //LED
 Serial.begin(9600);
   for(int i = 0; i < ledArraySize; i++){
     pinMode(LEDinArray[i],OUTPUT);
   } 

 //MIDI
  //Setup soft serial for me serial monitor (useful for debugging)
 //Serial.begin(57600);
  // Setup soft serial for MIDI control
  mySerial.begin(31250);
  
  // Reset the VS1053 chip
  pinMode(resetMIDI, OUTPUT);
  digitalWrite(resetMIDI, LOW);
  delay(100);
  digitalWrite(resetMIDI, HIGH);
  delay(100);
}

//***********LOOP**********
void loop(){
  int val = analogRead(sensorPin);
  Serial.println(val);
  rangeFinder(val);
  
  //just to slow down the output - remove if trying to catch an object passing by
  delay(100);
  }

//************METHODS***********
//LED
  void rangeFinder(int irVal) {
    int binValue = 0;
    for (int i=0; i < ledArraySize; i++) {
      if (irVal >= baseValue){
        binValue = (irVal-baseValue)/stepValue+1;
        //play midi note binValue + 30
        note = 5*binValue + 27;
        noteOn(0, note, 20);
       
        
        for(int i = 0; i < binValue; i++){
           digitalWrite(LEDinArray[i], HIGH);
        }
        for(int i = binValue+1; i < ledArraySize; i++){
          digitalWrite(LEDinArray[i], LOW);
        }
      }
         else if (binValue >= ledArraySize) {
        turnAllOn();  //turns off all LED
                      //turn off all MIDI
      }
      else {
        turnAllOff();  //turns off all LED
                       //turn off all MIDI
      }
    }
  }

 void turnAllOn() {
    for(int i = 0; i < ledArraySize; i++){
      digitalWrite(LEDinArray[i], HIGH);
    }
 }

 void turnAllOff() {
    for(int i = 0; i < ledArraySize; i++){
      digitalWrite(LEDinArray[i], LOW);
    }
 }

 //MIDI
 //Send a MIDI note-on message.  Like pressing a piano key
//channel ranges from 0-15
void noteOn(byte channel, byte note, byte attack_velocity) {
  talkMIDI( (0x90 | channel), note, attack_velocity);
}

//Send a MIDI note-off message.  Like releasing a piano key
void noteOff(byte channel, byte note, byte release_velocity) {
  talkMIDI( (0x80 | channel), note, release_velocity);
}

//Plays a MIDI note. Doesn't check to see that cmd is greater than 127, or that data values are less than 127
void talkMIDI(byte cmd, byte data1, byte data2) {
  digitalWrite(ledPin, HIGH);
  mySerial.write(cmd);
  mySerial.write(data1);

  //Some commands only have one data byte. All cmds less than 0xBn have 2 data bytes 
  //(sort of: http://253.ccarh.org/handout/midiprotocol/)
  if( (cmd & 0xF0) <= 0xB0)
    mySerial.write(data2);

  digitalWrite(ledPin, LOW);
}

