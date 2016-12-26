
int sensorPin = 0; //analog pin 0
int LEDPinArray [8] = {7,2,4,5,9,10,12,13}; //digital LED Pin Array  
int ledArraySize = 8;
int stepValue = 50; // blocks of 50
int baseValue = 75;  // where 1st block ends, 1st block starts at 0.

void setup(){
  Serial.begin(9600);
   for(int i = 0; i < 8; i++){
     pinMode(LEDPinArray[i],OUTPUT);
   }  
}

void turnOnRange(int irVal) { 
  for (int i=0; i < ledArraySize; i++) { 
     //  Serial.println(i);
     if (irVal >= baseValue) { // determine what block we are in  [0-75, 75-125, 125-175, ......] 
        int binValue = (irVal-baseValue)/stepValue+1;
//        Serial.println("binValue"... binValue);
          // for all values up to binValue in the LEDPinArray, turn them all ON.
          if (binValue < ledArraySize){
          for(int i = 0; i < binValue; i++){
             digitalWrite(LEDinArray[i], HIGH);
          }
          for(int i = binValue+1 ; i < 7; i++){
             digitalWrite(LEDinArray[i],  LOW);
          }
          } else if (binValue >=ledArraySize) {
            turnAllOn();
          }
          // for all values from bin Value <= 7, turn OFF
     } else if (irVal < baseValue) { 
        turnAllOff();
        Serial.println("IR Value < baseValue, turn all Off");
     }
  }
}


void loop(){
  int val = analogRead(sensorPin);
  //Serial.println(val);
//  turnOnRange(val);
  //just to slow down the output - remove if trying to catch an object passing by
  delay(5);
}


void turnAllOff() {  // turn all LEDs in array OFF
    for (int i=0; i < ledArraySize; i++) { 
     //  Serial.println(i);
       digitalWrite(LEDPinArray[i], LOW);
    }
    //Serial.println("ALL OFF");
}

void turnAllOn() {  // turn all LEDs in array ON
    for (int i=0; i < ledArraySize; i++) { 
    //    Serial.println(i);
       digitalWrite(LEDPinArray[i], HIGH);
    }
    //Serial.println("ALL ON");
}




/*  delay(500);
  turnAllOff();
  delay(500);
  turnAllOn();
*/

  
/*
 // 0 level
  if (val >= 75 && val < 125) { 
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
// 1 
  } else  if (val >= 125 && val < 175) { 
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
// 2
  } else  if (val >= 175 && val < 225) { 
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
// 3
  } else if (val >= 225 && val < 275)  { 
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
// 4
  } else if (val >= 275 && val < 325) { 
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
// 5
  } else if (val >= 325 && val < 375) { 
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
// 6
  } else if (val >= 375 && val < 425) { 
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, LOW);
// 7
} else if (val >= 425 && val < 475) { 
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
} else if (val >= 475) { 
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
    Serial.println("ALL ON");
}  else {  
  turnAllOff();
}

*/

