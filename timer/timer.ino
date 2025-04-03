// clock.ino
//
// This program creates a binary timer using the Arduino Uno.

// Setup pins for timer (6 pins for seconds and minutes each)
const int PINS = 6;

// Define pins for seconds and minutes
const int PINSSECS[PINS] = {2, 3, 4, 5, 6, 7};
const int PINSMINS[PINS] = {8, 9, 10, 11, 12, 13};

// Multiples of two for binary conversion (in descending order)
const int MULTIPLESOFTWO[PINS] = {32, 16, 8, 4, 2, 1};

// Counter for the seconds passed
int counter = 0;

void setup() {
    // Set all the defined pins as outputs
    for (int i = 0; i < PINS; i++) {
        pinMode(PINSSECS[i], OUTPUT);
        pinMode(PINSMINS[i], OUTPUT);
    }
}

void loop() {
    counter++;
    drawNumber(counter);
    delay(1000); // Wait 1 second 

    // Resets the counter after an hour
    if (counter >= 60*60) {
        counter = 0;
    }
}

void drawNumber(int counter) {
    int mins = 0;
    int secs = counter % 60;

    if (counter >= 60) {
        mins = (counter - secs) / 60;
    }

    // Display seconds in binary
    for (int i = 0; i < PINS; i++) {
        if (secs >= MULTIPLESOFTWO[i]) {
            secs -= MULTIPLESOFTWO[i];
            digitalWrite(PINSSECS[i], HIGH);
        } else {
            digitalWrite(PINSSECS[i], LOW);
        }
    }

    // Display minutes in binary
    for (int i = 0; i < PINS; i++) {
        if (mins >= MULTIPLESOFTWO[i]) {
            mins -= MULTIPLESOFTWO[i];
            digitalWrite(PINSMINS[i], HIGH);
        } else {
            digitalWrite(PINSMINS[i], LOW);
        }
    }
}
