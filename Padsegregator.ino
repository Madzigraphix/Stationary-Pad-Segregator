#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

// Ultrasonic pins
const int trigPin = 9;
const int echoPin = 10;

// Motor driver pins
const int IN1 = 7;
const int IN2 = 6;
const int ENA = 5;

// Distance thresholds (adjust during calibration)
int triggerDistance = 15;   // pad detected
int clearDistance = 18;     // chamber empty

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("PAD SEGREGATOR");
  lcd.setCursor(0,1);
  lcd.print("SYSTEM WELCOME");
  delay(3000);

  lcd.clear();
}

void loop()
{
  int distance = readDistance();

  // IDLE STATE
  if(distance > triggerDistance)
  {
    lcd.setCursor(0,0);
    lcd.print("PLACE SANITARY ");
    lcd.setCursor(0,1);
    lcd.print("PAD IN THE HOLE");
    delay(500);
  }

  // PAD DETECTED
  if(distance <= triggerDistance)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SHREDDING PAD");

    // Start motor
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA,200);

    // Keep shredding until chamber empty
    while(true)
    {
      distance = readDistance();

      if(distance > clearDistance)
      {
        delay(800); // confirm empty
        if(readDistance() > clearDistance)
        break;
      }

      delay(200);
    }

    // Stop motor
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    analogWrite(ENA,0);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("HOLD COMBUSTION");
    lcd.setCursor(0,1);
    lcd.print("BUTTON 10 SECS");

    delay(5000);

    lcd.clear();
  }
}


// Stable ultrasonic reading function
int readDistance()
{
  int total = 0;

  for(int i=0;i<3;i++)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH, 30000);

    int distance = duration * 0.034 / 2;

    total += distance;

    delay(50);
  }

  return total / 3;
}