/*
  Blinking: Turns on an LED on for one sec & then off for other second continously.
  Most Arduinos have an on-board LED, attached to digital pin 13. 
*/

// The setup function runs once when you press reset or power the board
void setup() {
  pinMode(13, OUTPUT); // Initializing digital pin 13 as an output.
}

// The loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // Turn the LED on by making the voltage HIGH
  delay(1000);              // Wait for a second
  digitalWrite(13, LOW);    // Turn the LED off by making the voltage LOW
  delay(1000);              // Wait for next second
}