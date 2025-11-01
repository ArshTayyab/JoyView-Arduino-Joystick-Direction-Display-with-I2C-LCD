#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address (0x27 or 0x3F are common)
LiquidCrystal_I2C lcd(0x27, 16, 2);

int VRx = A0;
int VRy = A1;
int SW = 2;

int xPos;
int yPos;
int buttonState;

void setup() {
  lcd.init();         // Initialize LCD
  lcd.backlight();    // Turn on backlight
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  xPos = analogRead(VRx);
  yPos = analogRead(VRy);
  buttonState = digitalRead(SW);

  String direction;

  if (xPos > 800) {
    direction = "LEFT";
  } else if (xPos < 200) {
    direction = "RIGHT";
  } else if (yPos > 800) {
    direction = "UP";
  } else if (yPos < 200) {
    direction = "DOWN";
  } else if (buttonState == LOW) {
    direction = "BUTTON";
  } else {
    direction = "CENTER";
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Joystick:");
  lcd.setCursor(0, 1);
  lcd.print(direction);

  delay(200);
}
