// blinking.ino
//
// This program alternates two LEDs connected to pins 12 and 13.
// Each LED turns on for 1 second while the other turns off, creating a blinking effect.

#define LEDU 13  // Define LEDU as pin 13
#define LEDD 12  // Define LEDD as pin 12

// The setup() function runs once when the Arduino is powered on or reset.
void setup() {
  // Configure the LED pins as outputs so we can control them
  pinMode(LEDU, OUTPUT);
  pinMode(LEDD, OUTPUT);
}

// The loop() function runs continuously after setup() has completed.
void loop() {
  // Turn LEDU on (HIGH) and LEDD off (LOW)
  digitalWrite(LEDU, HIGH);  // Set LEDU to ON
  digitalWrite(LEDD, LOW);   // Set LEDD to OFF
  
  // Wait 1 second (1000 milliseconds)
  delay(1000);
  
  digitalWrite(LEDU, LOW);   // Set LEDU to OFF
  digitalWrite(LEDD, HIGH);  // Set LEDD to ON
  
  // Wait 1 second (1000 milliseconds) before repeating loop
  delay(1000);
}