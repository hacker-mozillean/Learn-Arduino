/*
 This example demonstrates the use of  while() statements.

 While pushbutton is pressed, the sketch runs calibration routine. The sensor readings
 during while loop defines minimum and maximum of expected values from photo resistor.

 NOTE: This is variation on the calibrate example.

 The circuit connections are as follows:
 * Photo resistor connected from +5V to analog in pin 0
 * 10K resistor connected from ground to analog in pin 0
 * LED connected from digital pin 9 to ground through 220 ohm resistor
 * Pushbutton attached from pin 2 to +5V
 * 10K resistor attached from pin 2 to ground

*/

// These constants won't change:
const int sensorPin = A2;       // Pin through which the sensor is attached 
const int ledPin = 9;           // Pin through which the LED is attached 
const int indicatorLedPin = 13; // Pin through which the built-in LED is attached
const int buttonPin = 2;        // Pin through which the button is attached


// These variables will change
int sensorMin = 1023;  // minimum sensor value
int sensorMax = 0;     // maximum sensor value
int sensorValue = 0;   // the sensor value


void setup() {
  // Set LED pins as outputs and the switch pin as input
  pinMode(indicatorLedPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // While button is pressed, take calibration readings
  while (digitalRead(buttonPin) == HIGH) {
    calibrate();
  }
  
  // Signal the end of the calibration period
  digitalWrite(indicatorLedPin, LOW);

  // Read the sensor values
  sensorValue = analogRead(sensorPin);

  // Apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // In case sensor value is outside the range seen during calibration, calibrate it
  sensorValue = constrain(sensorValue, 0, 255);

  // Fade the LED using the calibrated value
  analogWrite(ledPin, sensorValue);
}

void calibrate() {
  // Turn on the indicator LED to indicate that calibration is happening
  digitalWrite(indicatorLedPin, HIGH);
  
  // Read the sensor values
  sensorValue = analogRead(sensorPin);

  // Record the maximum sensor value
  if (sensorValue > sensorMax) {
    sensorMax = sensorValue;
  }

  // Record the minimum sensor value
  if (sensorValue < sensorMin) {
    sensorMin = sensorValue;
  }
}