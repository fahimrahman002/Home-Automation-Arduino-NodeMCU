//dht_sensor
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN A3     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

//smoke_sensor
int gasA0 = A2;
int sensorThreshold = 200;

//lcd_i2c_module
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//matrix keypad
#include <Keypad.h>

//Servo motor
#include <Servo.h>
Servo servo;
#define doorCloseAngle 50
#define doorOpenAngle 150
int servoPin = A1;

//LED lights
#define RED_LED 11
#define GREEN_LED 10

//Buzzer
int buzzer = 13;
unsigned long humTempDelay = 0;
unsigned long passInputDelay = 0;
bool passInputDetect = false;

float prevHum = 0;
float prevTemp = 0;
bool gasDetected = false;

void setup()
{
  Serial.begin(9600);

  //Buzzer
  pinMode(buzzer , OUTPUT);
  alarmOff();

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
  lcdPrint("Smart Home", "Welcome Home");
  delay(1000);
}

void loop()
{

  matrixKeypad();
  if (passInputDetect == true && (millis() - passInputDelay >= 10000)) {
    passInputDetect = false;
  }
  if (passInputDetect == false) {
    gasDetected = gasSensor();
    if (gasDetected == true) {
      lcdPrint("Gas Detected","Fix it quickly");
      alarmTone();
    } else {
      alarmOff();
      printHumTemp();
    }
  }
}
