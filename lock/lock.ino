// lock.ino
//
// Arduino-based lock system using two buttons and an LED indicator.
// Buttons are connected to digital pins 13 and 14.
// An LED is connected to pin 12 to indicate if the entered code is correct or incorrect.
// The correct code is defined in the CODE array before uploading the sketch.

#define OUT 11   // Output pin for LED indication
#define IN1 12   // Input pin for first button
#define IN2 13   // Input pin for second button

// Constants for array sizes
const int CODESIZE = 4;  // Number of digits in the code
const int PINSNUM = 2;   // Number of input buttons

// Predefined correct code sequence (0: IN1, 1: IN2)
const int CODE[CODESIZE] = {0, 1, 0, 0};

// Button input pins
const int PINS[PINSNUM] = {12, 13};

// Base pin number for button inputs
const int MINPIN = 12;

void setup() {
  pinMode(OUT, OUTPUT);  // Set LED pin as output
  digitalWrite(OUT, LOW); // Ensure LED is off at startup

  pinMode(IN1, INPUT);  // Set button 1 as input
  pinMode(IN2, INPUT);  // Set button 2 as input
}

void loop() {
  // Iterate through each digit of the code
  for (int i = 0; i < CODESIZE; i++) {
    while (true) {
      // Delay for the press of the button
      delay(1000);  
      
      // Check if correct button is pressed
      if (checkInputs(i)) {
        break;
      } else {
        i = -1;  // Reset code entry on incorrect input
      }
    }
  }

  // Indicate successful code entry
  digitalWrite(OUT, HIGH);

  // Keep LED on for 10 seconds before restarting
  delay(10000); 
}

// Function to check button inputs
bool checkInputs(int i) {
  for (int j = 0; j < PINSNUM; j++) {
    if (digitalRead(PINS[j]) == HIGH) {  // If a button is pressed
      
      if (PINS[j] - MINPIN == CODE[i]) {  // Check if it matches the expected code sequence
        blinkLEDRight(); // Indicate correct input
        return true;
      } else {
        blinkLEDWrong(); // Indicate incorrect input
        return false;
      }
    }
  }
}

// Function to blink LED for incorrect input
void blinkLEDWrong() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(OUT, HIGH);
    delay(250);
    digitalWrite(OUT, LOW);
    delay(250);
  }
}

// Function to blink LED for correct input
void blinkLEDRight() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(OUT, HIGH);
    delay(350);
    digitalWrite(OUT, LOW);
    delay(150);
  }
}
