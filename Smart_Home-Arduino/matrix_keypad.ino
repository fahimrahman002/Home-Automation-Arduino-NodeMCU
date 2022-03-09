const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
char passwordInput[5];
char password[4] = {'2', '5', '8', '0'};
int keyPressCount = 0;

void clearPassword() {
  keyPressCount = 0;
}

void checkPassword() {
  if (keyPressCount == 4) {
    for (int i = 0; i < 4; i++) {
      if (passwordInput[i] != password[i]) {
        lcdPrint("Passowrd Input:","Wrong password");
        Serial.println("Wrong password");
        alarmOn();
        keyPressCount = 0;
        return;
      }
    }
    doorOpen();
    passInputDetect = false;
    keyPressCount = 0;
  } else {
    //    Serial.println(keyPressCount);
    //    Serial.println();
    lcdPrint("Passowrd Input:","Put 4 digit pass");
  }
}

void storePassword(char key) {
  passwordInput[keyPressCount] = key;
  keyPressCount++;
  if (keyPressCount == 5)keyPressCount = 0;
}
void showPassword() {
  lcd.clear();
  String password = "";
  for (int i = 0; i < keyPressCount; i++) {
    password = password + passwordInput[i];
  }
  lcdPrint("Password Input:",password);
}
void matrixKeypad() {
  char key = keypad.getKey();
  if (key) {
    passInputDetect = true;
    alarmOff();
    switch (key) {
      case 'D':
        checkPassword();
        break;
      case 'C':
        clearPassword();
        break;
      default:
        storePassword(key);
    }
    passInputDelay = millis();
    showPassword();
    Serial.println(key);
  }
}
