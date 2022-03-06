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

//led_lights
RED_LED = 11;
GREEN_LED = 10;

void setup()
{
  Serial.begin(9600);
  // lights init
  pinMode( RED_LED, OUTPUT);
  pinMode( GREEN_LED, OUTPUT);
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

  matrixKeypad();
}
