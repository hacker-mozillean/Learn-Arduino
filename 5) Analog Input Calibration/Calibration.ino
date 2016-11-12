/*
  Calibration is the method for calibrating sensor input. The sensor
  readings during first five seconds of the sketch execution defines
  minimum and maximum of the expected values attached to sensor pin.

 Note: The sensor min and maximum initial values may seem backwards.
 Initially, you set the minimum high and listen for anything lower, 
 saving it as the new minimum. Similarly, you set the maximum low & 
 listen for anything higher as the new maximum.

 The circuit connections are as follows:
 * Analog sensor (potentiometer will do) attached to analog input 0
 * LED attached from digital pin 9 to ground

 */

// The constraints defined as constants won't change:
const int sensorPin = A0;    // Pin through which sensor is attached to
const int ledPin = 9;        // Pin through which LED is attached to

// These are the variables used 
int sensorValue = 0;         // Initial sensor value
int sensorMin = 1023;        // Minimum sensor value
int sensorMax = 0;           // Maximum sensor value


void setup() {
  // Turn on LED to signal the starting of calibration period
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // Calibrate during first five seconds
  while (millis() < 5000) {
	sensorValue = analogRead(sensorPin);

    // Recording the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // Recording the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  
  }//End of whlle loop

  // Signal the end of calibration period
  digitalWrite(13, LOW);
}

void loop() {
  // Read the sensor value
  sensorValue = analogRead(sensorPin);

  // Apply the calibration to sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // In case sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);

  // Fade LED using calibrated values
  analogWrite(ledPin, sensorValue);
}