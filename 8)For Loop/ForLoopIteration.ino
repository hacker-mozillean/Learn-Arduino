/*
 This For Loop Iteration demonstrates use of for() loop.
 It lights multiple LEDs in sequence, then in reverse.

 The circuit connection are as follows:
 * LEDs from pins 2 through 7 to ground

*/

int timer = 100;           // The higher the number, the slower the timing.

void setup() {
  // Use for loop to initialize each pin as an output
  for (int thisPin = 2; thisPin < 8; thisPin++) {
	pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  // Looping from the lowest pin to the highest
  for (int thisPin = 2; thisPin < 8; thisPin++) {

  // Turning the pin on
  digitalWrite(thisPin, HIGH);
  delay(timer);

  // Turning the pin off
  digitalWrite(thisPin, LOW);
  
  } //End of for loop

  // Looping from highest pin to the lowest
  for (int thisPin = 7; thisPin >= 2; thisPin--) {
    // Turning the pin on
    digitalWrite(thisPin, HIGH);
    delay(timer);
	
    // Turning the pin off
    digitalWrite(thisPin, LOW);
  }
}