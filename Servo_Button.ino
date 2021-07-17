//This is importing the servo library which can control servo motors
#include <Servo.h>

//This is defining a servo_1 as the type servo
Servo servo_1;


//these are the pins for the input from the two buttons
const int _ButtonCW = 2;
const int _ButtonCCW = 3;

//bcws = button clock wise state, bccws = button counter clock wise state
int _bcws = 0;
int _bccws = 0;

//this variable is for the current position of the servo, this is continuosly 
//updated
int pos = 0;

//this is the pin that will give output to the servo
const int servoOutput = 9;


int degrees = 0;
void setup() {
  servo_1.attach(servoPin);

  pinMode(_ButtonCW, INPUT);
  pinMode(_ButtonCCW, INPUT);

  servo_1.write(pos);
}
void loop() {
  //this is getting 
  _bcws = digitalRead(_ButtonCW);
  _bccws = digitalRead(_ButtonCCW);

  if (_bcws == HIGH) {

    servo_1.write(pos+30);
    pos += 30;
    delay(1000);
  } else if (_bccws == HIGH) {

    servo_1.write(pos-=30);
    pos -= 30;
    delay(1000);
  }
  
}
