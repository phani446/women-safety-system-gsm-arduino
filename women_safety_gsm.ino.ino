#include <SoftwareSerial.h>

SoftwareSerial gsm(2, 3); // RX, TX

#define button1 4
#define button2 5
#define button3 6

#define redPin 9
#define greenPin 10
#define bluePin 8

String number1 = "+918096250515"; // Replace with Person 1 number
String number2 = "+917032936188"; // Replace with Person 2 number

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  gsm.begin(9600);
  Serial.begin(9600);
  delay(2000);
  Serial.println("GSM Emergency Call System Ready...");
  ledOff();
}

void loop() {
  if (digitalRead(button1) == LOW) {
    Serial.println("Calling Person 1...");
     setColor(0, 0, 255); //
    callNumber(number1);
    delay(1000);
  }

  if (digitalRead(button2) == LOW) {
    Serial.println("Calling Person 2...");
    setColor(0, 255, 0); // GREEN
    callNumber(number2);
    delay(1000);
  }

  if (digitalRead(button3) == LOW) {
    Serial.println("Cancelling Call...");
    setColor(255, 0, 0); // BLUE
    endCall();
    delay(1000);
  }
}

void callNumber(String number) {
  gsm.println("ATD" + number + ";");
  delay(1000);
}

void endCall() {
  gsm.println("ATH");
  delay(1000);
}

void setColor(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void ledOff() {
  setColor(0, 0, 0);
}
