#include <LiquidCrystal.h>
#include <HCSR04.h>

int	trigPin = 2,
	echoPin = 3;
long	duration,
	cm,
	in;
bool toggleMeasureUnit = true;
/*  false is centimeter */
const int connections[6] = {12,11,5,4,3,2};
/*	[0] - RS - 12 [1] - EN - 11 [2] - D4 - 5 [3] - D5 - 4 [4] - D6 - 3 [5] - D7 - 2
	  LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7) */

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

void setup() {
	Serial.begin(9600);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	lcd.begin(16, 2);
	lcd.print("Loading..");
	delay(600);
}

void loop() {
	digitalWrite(trigPin, LOW);
	delayMicroseconds(5);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration / 2) / 29.1;
  in = (duration / 2) / 74;
  lcd.clear();
  lcd.print("distance: ");
  lcd.print(!toggleMeasureUnit? cm : in);
  lcd.setCursor(0, 1);
  lcd.print(!toggleMeasureUnit? "cm" : "inches");
  delay(500);
}
