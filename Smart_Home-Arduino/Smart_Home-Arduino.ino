//dht_sensor
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN A3     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

//smoke_sensor
int gasA0 = A2;
int sensorThreshold = 400;

//lcd_i2c_module
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//matrix keypad
#include <Keypad.h>

//Servo motor
#include <Servo.h>
Servo servo;
#define doorCloseAngle 40
#define doorOpenAngle 190
int servoPin = A1;

//LED lights
#define RED_LED 11
#define GREEN_LED 10

void setup()
{
  Serial.begin(9600);
  // lights init
  pinMode( RED_LED, OUTPUT);
  pinMode( GREEN_LED, OUTPUT);
  
  //Servo init
  servo.attach(servoPin);
  doorClose();

  //MQ or gas sensor  init
  pinMode(gasA0, INPUT);

  // DHT init
  dht.begin();

  // LCD init
  lcd.begin();
  lcd.backlight();
  lcdScrollPrint(3, 0, "Smart Home");
  lcdScrollPrint(2, 1, "Welcome Home");
}

void loop()
{
  // Wait a few seconds between measurements.
  //  delay(500);
  //  gasSensor();

  //  float h = getHumidity();
  //  float t = getTempC();
  //  float f = getTempF();

  //  matrixKeypad();

}
