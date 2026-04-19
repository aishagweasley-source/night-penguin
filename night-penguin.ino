#include <Servo.h>

// creates a servo object
Servo servo1;  
Servo servo2;

// setting up constant pin nnumbers
const int buttonPin1 = 2;
const int buttonPin2 = 3;

// initial position for servo
int pos = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  // setting up baud rate

// attaches the servo to that pin
servo1.attach(A0);
servo2.attach(A1);

// setting pinmode buttons to be inputs
pinMode(buttonPin1, INPUT_PULLUP);    // b. we use "INPUT_PULLUP" to enable the resistor inside the button, so.. 
pinMode(buttonPin2, INPUT_PULLUP);   //  so..  its LOW when being pressed and HIGH when it is not pressed.
}

void loop() {
  // put your main code here, to run repeatedly:

// b. reading the button pins
int buttonState1 = digitalRead(buttonPin1);
int buttonState2 = digitalRead(buttonPin2);

Serial.println(buttonState1);
Serial.println(buttonState2);
delay(100);

if (buttonState1 == LOW) {
  for (pos = 0; pos <= 180; pos += 1) {
    servo1.write(pos);
    delay(15); }

    for (pos = 180; pos >= 0; pos -=1) {
      servo1.write(pos);
      delay(15);
    }
  } 


if (buttonState2 == LOW) {
  for (pos = 0; pos <= 180; pos += 1) {
    servo2.write(pos); 
    delay(15); }

    for (pos = 180; pos >= 0; pos -= 1) {
      servo2.write(pos);
      delay(15);
    }
  } 
 }


// i think i should make specific functions so the code will be more tidy 
