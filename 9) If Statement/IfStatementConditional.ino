/*
 It reads state of potentiometer(analog input) and turns on LED
 only if the potentiometer goes above a certain threshold level. 
 It prints the analog value regardless of the level.

 The circuit connections are as follows:
 * Potentiometer connected to analog pin 0.
 * Center pin of potentiometer goes to analog pin.
 * Side pins of potentiometer go to +5V and ground.
 * LED connected from digital pin 13 to ground

*/

// These constants won't change
 const int analogPin = A0;    // Pin through which sensor is attached to
 const int ledPin = 13;       // Pin through which LED is attached to
 const int threshold = 400;   // An arbitrary threshold level that's in the range of analog input

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Initialize serial communications at rate of 9600 bauds
  Serial.begin(9600);
}

void loop() {
  // Read the value of the potentiometer
  int analogValue = analogRead(analogPin);

  // If the analog value is high enough, turn on the LED
  if (analogValue > threshold) {
    digitalWrite(ledPin, HIGH);
  }
  // If the analog value is not high enough, turn OFF the LED
  else {
    digitalWrite(ledPin, LOW);
  }

  // Prints analog value
  Serial.println(analogValue);
  
  // Delay in between reads for stability
  delay(1);        
}