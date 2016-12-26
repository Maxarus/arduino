
int sensorPin = 0; //analog pin 0
int LEDinArray [8] = {1,2,4,5,9,10,12,13} //digital LED Pin Array  
int ledPin0 = 1; // digital pin 0
int ledPin1 = 2; // digital pin 1
int ledPin2 = 4; // digital pin 2
int ledPin3 = 5; // digital pin 3
int ledPin4 = 9; // digital pin 4
int ledPin5 = 10; // digital pin 5
int ledPin6 = 12; // digital pin 6
int ledPin7 = 13; // digital pin 7


void setup(){
  Serial.begin(9600);
  int i;
   for(i = 0, i < 8, i++){
     pinMode(LEDinArray[i],OUTPUT);
   } 
}

void loop(){
  int val = analogRead(sensorPin);
  Serial.println(val);

  digitalWrite(

 // 0 =distance - 50
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

// all off
    digitalWrite(int i; for(i = 0, i < 8, i++) LEDinArray[i]
  } //end
