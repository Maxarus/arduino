
int sensorPin = 0; //analog pin 0
int ledPin0 = 13; // digital pin 0
int ledPin1 = 12; // digital pin 1
int ledPin2 = 11; // digital pin 2
int ledPin3 = 10; // digital pin 3


void setup(){
  Serial.begin(9600);
   pinMode(ledPin0, OUTPUT);
   pinMode(ledPin1, OUTPUT);
}

void loop(){
  int val = analogRead(sensorPin);
  Serial.println(val);
 
  if (val > 100 && val < 200) { 
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, LOW);
  } else if (val > 200) { 
    digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin1, HIGH);
  }  else {  
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin0, LOW);
  }
  //just to slow down the output - remove if trying to catch an object passing by
  delay(5);

}
