char rx_byte = 0;
String rx_str = "";
boolean not_number = false;
int result;

void serialInput() {
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();
    if ((rx_byte >= '0') && (rx_byte <= '9')) {
      rx_str += rx_byte;
    }
    else if (rx_byte == '\n') {
      // end of string
      if (not_number) {
        Serial.println("Not a number");
      }
      else {
        result = rx_str.toInt();
        servo.write(result);
        Serial.println(result);
      }
      not_number = false;         // reset flag
      rx_str = "";                // clear the string for reuse
    }
    else {
      // non-number character received
      not_number = true;    // flag a non-number
    }
  }
}
