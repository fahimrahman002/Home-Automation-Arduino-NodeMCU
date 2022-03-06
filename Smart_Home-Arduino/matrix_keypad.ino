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

void openDoor() {
  if (keyPressCount == 4) {
    bool flag = false;
    for (int i = 0; i < 4; i++) {
      if (passwordInput[i] != password[i]) {
        Serial.println("Not matched");
        keyPressCount = 0;
        return;
      }
    }

    Serial.println("Door opening");
    keyPressCount = 0;


  } else {
    Serial.println(keyPressCount);
    Serial.println("You have to put 4 digit password");
  }
}

void storePassword(char key) {
  passwordInput[keyPressCount] = key;
  keyPressCount++;
  if(keyPressCount==5)keyPressCount=0;
}
void matrixKeypad() {
  char key = keypad.getKey();
  if (key) {
    switch (key) {
      case 'D':
        openDoor();
        break;
      case 'C':
        clearPassword();
        break;
      default:
        storePassword(key);
    }
    Serial.println(key);
  }
}
