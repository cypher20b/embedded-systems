/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
int speed1 = 9;
int speed2 = 10;
int speed3 = 11;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);
  pinMode(speed3, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1);        // 
  switch (buttonState) {
    case 1:
      digitalWrite(speed1, HIGH);
      digitalWrite(speed2, LOW);
      digitalWrite(speed3, LOW);
      break;
    case 2:
      digitalWrite(speed1, LOW);
      digitalWrite(speed2, HIGH);
      digitalWrite(speed3, LOW);
      break;
    case 3:
      digitalWrite(speed1, LOW);
      digitalWrite(speed2, LOW);
      digitalWrite(speed3, HIGH);
      break;
    default:
      // if nothing else matches, do the default
      // default is optional
    break;
  }
}
