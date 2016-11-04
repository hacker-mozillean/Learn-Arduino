/*
 The switch statement allows to choose among set of discrete
 values of variable. It's like series of if statements.

 To see this sketch in action, open the serial monitor in well-lit
 room and move your hand gradually down over the sensor.

 The circuit connections are as follows:
 * Photoresistor from analog in 0 to +5V
 * 10K resistor from analog in 0 to ground

 */

// These constants won't change. They are lowest and highest readings obtained from sensor:
const int sensorMin = 0;      // Sensor minimum, discovered through experiment
const int sensorMax = 600;    // Sensor maximum, discovered through experiment

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the sensor values
  int sensorReading = analogRead(A0);

  // Map sensor range to a range of four options:
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  // Doing something different depending on the range values
  switch (range) {
    case 0:    // Your hand is on the sensor
      Serial.println("dark");
      break;
	  
    case 1:    // Your hand is close to the sensor
      Serial.println("dim");
      break;
	  
    case 2:    // Your hand is a few inches from the sensor
      Serial.println("medium");
      break;
	  
    case 3:    // your hand is nowhere near the sensor
      Serial.println("bright");
      break;
  }
  
  delay(1);        // delay in between reads for stability
}