// fizzbuzz.ino
//
// This program implements FizzBuzz on an Arduino using LEDs.
// "Fizz" is represented by an LED on pin 13 and "Buzz" is represented by an LED on pin 12.

#define FIZZ 13  // Define FIZZ as pin 13
#define BUZZ 12  // Define BUZZ as pin 12

int count = 0;

void setup() {
    pinMode(FIZZ, OUTPUT); // Set pin 13 as an output
    pinMode(BUZZ, OUTPUT); // Set pin 12 as an output
}

void loop() {
    count++;  // Increment the counter

    // Check divisibility and update LEDs
    check(FIZZ, 3);  // Light up Fizz LED if divisible by 3
    check(BUZZ, 5);  // Light up Buzz LED if divisible by 5

    delay(1000);  // Wait for 1 second before next iteration

    // This just resets so the int doesn't overflow
    if (count > 30000) count = 1;
}

// Function to check divisibility and control LED state
void check(int led, int number) {
    if (count % number == 0) {
        digitalWrite(led, HIGH);  // Turn LED on if count is divisible
    } else {
        digitalWrite(led, LOW);   // Turn LED off otherwise
    }
}