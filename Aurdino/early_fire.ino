//libraries 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> //For LCD crystal display

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Initializing Variables
int Le = 13; // led data pin
const int buzzer=14; // buzzer pin
char data; 

void setup()
{
    Serial.begin(9700);
    pinMode(Le,OUTPUT);
    pinMode(buzzer, OUTPUT);
    // Setting the LED and buzzer Off when program is executed.
    digitalWrite(Le,LOW);
    digitalWrite(buzzer,LOW);
}

void loop()
{
  //Serial connection
  while(Serial.available())
  {
    data = Serial.read(); //Serial read
  }

  //Receiving data from camera through serial communication.
  if(data == 'h') //if recieved character is f then turning on the led and buzzer for early fire detection.
  {
    digitalWrite(Le,HIGH);        // turn the LED on (HIGH is the voltage level)
    digitalWrite(buzzer, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);
    Serial.println("LED turned on");  
    lcd.begin();

    lcd.backlight();
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Fire Detected "); // To print in LCD display 
    
  }

  else 
  {                                 //if recieved character is not f then turning off the led and buzzer.
    digitalWrite(Le,LOW);        // turn the LED off (LOW is the voltage level)
    digitalWrite(buzzer, LOW);    // turn the LED off by making the voltage LOW
    delay(1000); 
    Serial.println("LED turned off");
    lcd.begin();

    lcd.backlight();
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("No Fire");       // To print in LCD display 
    
  }
}
