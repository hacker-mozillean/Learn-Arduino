/*
 Time Check: It gets the time from Linux via Bridge then parses 
 out hours, minutes and seconds for Arduino using an Arduino Yún.
*/

#include <Process.h>
// The process used to get the date
Process date;                 

int hours, minutes, seconds;  

// We need an impossible value for comparison
int lastSecond = -1;          

void setup() {
  Bridge.begin();        // Initialize Bridge
  Serial.begin(9600);    // Initialize serial

  while (!Serial); // Waiting for Serial Monitor to open
  
  Serial.println("Time Check");  // Title of sketch

  // Run an initial date process. It should return hh:mm:ss 
  if (!date.running()) {
    date.begin("date");
    date.addParameter("+%T");
    date.run();
  }
}

void loop() {

  if (lastSecond != seconds) { // if a second has passed
    // Printing the time
    if (hours <= 9) {
      Serial.print("0");  // Adjusts for 0-9
    }
	Serial.print(hours);
    
	Serial.print(":");
    if (minutes <= 9) {
      Serial.print("0");  // Adjusts for 0-9
    }
    Serial.print(minutes);
    
	Serial.print(":");
    if (seconds <= 9) {
      Serial.print("0");  // Adjusts for 0-9
    }
    Serial.println(seconds);

    // Restarting the date process
    if (!date.running()) {
      date.begin("date");
      date.addParameter("+%T");
      date.run();
    }
  }

  //If there's a result from the date process, parse it
  while (date.available() > 0) {
    // Get the result of the date process (should be hh:mm:ss)
    String timeString = date.readString();

    // Find the colons position
    int firstColon = timeString.indexOf(":");
    int secondColon = timeString.lastIndexOf(":");

    //Getting the substrings for hour, minute & second
    String hourString = timeString.substring(0, firstColon);
    String minString  = timeString.substring(firstColon + 1, secondColon);
    String secString  = timeString.substring(secondColon + 1);

    // Converting to the integers & saving the previous second
    hours = hourString.toInt();
    minutes = minString.toInt();
	
    // Saving for performing time comparison
	lastSecond = seconds;          
    seconds = secString.toInt();
  }
}