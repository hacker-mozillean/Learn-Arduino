/*
  This program reads an analog input on pin 0, prints the result to the serial monitor.
  The graphical representation is available using Serial Plotter (Tools > Serial Plotter menu)
  Attach the center pin of potentiometer to pin A0 and the outside pins to +5V and ground.

*/

// The setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600); // Serial communication initialized at 9600 bits per second:
}

// the loop routine runs over and over again forever:
void loop() {
  
  int sensorValue = analogRead(A0); // Read input on analog pin 0
  Serial.println(sensorValue); // Print out the value you read
  delay(1); // Delay in between read cycle for visibility
}
