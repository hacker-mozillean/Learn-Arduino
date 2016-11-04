/*
 Fade: The LED on pin 9 can be made to fade using the analogWrite() function.

 The analogWrite() function uses PWM, the pin used can be changed. 
 PWM pins are identified with "~" sign, like ~3, ~5, ~10 and ~11.
 */

int led = 9;           // It is the PWM pin, the LED is attached to
int brightness = 0;    // How bright the LED would be?
int fadeAmount = 5;    // How many points to fade the LED by?

// This setup routine runs once, when you press reset
void setup() {
  pinMode(led, OUTPUT); // Declaring pin 9 sa output
}

// This loop routine runs over and over again forever
void loop() {
  // Setting the brightness of pin 9(i.e. the LED pin 9)
  analogWrite(led, brightness);

  // Changing the brightness level in next time by the Fade Amount
  brightness = brightness + fadeAmount;

  // Reversing the direction of fading at the ends of fade
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  
  // Wait for 30 milliseconds to see the dimming effect
  delay(30);
}