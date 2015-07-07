
// function to generate the right "phrase" based on the time

void displayTime(void) {

  // get time from the RTC
  DateTime thetime = RTC.now();

  // serial print current time
  /*
  Serial.print(thetime.year(), DEC);
  Serial.print('/');
  Serial.print(thetime.month(), DEC);
  Serial.print('/');
  Serial.print(thetime.day(), DEC);
  Serial.print(' ');
  Serial.print(thetime.hour(), DEC);
  Serial.print(':');
  Serial.print(thetime.minute(), DEC);
  Serial.print(':');
  Serial.print(thetime.second(), DEC);
  Serial.println();
  */

  // time we display the appropriate thetime.minute() counter
  if ((thetime.minute() > 4) && (thetime.minute() < 10)) {
    MFIVE;
    //Serial.print("five");
  }
  if ((thetime.minute() > 9) && (thetime.minute() < 15)) {
    MTEN;
    //Serial.print("ten");
  }
  if ((thetime.minute() > 14) && (thetime.minute() < 20)) {
    AQUARTER;
    //Serial.print("a quarter");
  }
  if ((thetime.minute() > 19) && (thetime.minute() < 25)) {
    TWENTY;
    //Serial.print("twenty");
  }
  if ((thetime.minute() > 24) && (thetime.minute() < 30)) {
    TWENTY;
    MFIVE;
    //Serial.print("twenty five");
  }
  if ((thetime.minute() > 29) && (thetime.minute() < 35)) {
    HALF;
    //Serial.print("half");
  }
  if ((thetime.minute() > 34) && (thetime.minute() < 40)) {
    TWENTY;
    MFIVE;
    //Serial.print("twenty five");
  }
  if ((thetime.minute() > 39) && (thetime.minute() < 45)) {
    TWENTY;
    //Serial.print("twenty");
  }
  if ((thetime.minute() > 44) && (thetime.minute() < 50)) {
    AQUARTER;
    //Serial.print("a quarter");
  }
  if ((thetime.minute() > 49) && (thetime.minute() < 55)) {
    MTEN;
    //Serial.print("ten");
  }
  if (thetime.minute() > 54) {
    MFIVE;
    //Serial.print("five");
  }

  if ((thetime.minute() < 5))
  {
    switch (thetime.hour()) {
      case 1:
      case 13:
        ONE;
        break;
      case 2:
      case 14:
        TWO;
        break;
      case 3:
      case 15:
        THREE;
        break;
      case 4:
      case 16:
        FOUR;
        break;
      case 5:
      case 17:
        FIVE;
        break;
      case 6:
      case 18:
        SIX;
        break;
      case 7:
      case 19:
        SEVEN;
        break;
      case 8:
      case 20:
        EIGHT;
        break;
      case 9:
      case 21:
        NINE;
        break;
      case 10:
      case 22:
        TEN;
        break;
      case 11:
      case 23:
        ELEVEN;
        break;
      case 0:
      case 12:
        TWELVE;
        break;
    }

  }
  else if ((thetime.minute() < 35) && (thetime.minute() > 4))
  {
    PAST;
    //Serial.print(" past ");
    switch (thetime.hour()) {
      case 1:
      case 13:
        ONE;
        break;
      case 2:
      case 14:
        TWO;
        break;
      case 3:
      case 15:
        THREE;
        break;
      case 4:
      case 16:
        FOUR;
        break;
      case 5:
      case 17:
        FIVE;
        break;
      case 6:
      case 18:
        SIX;
        break;
      case 7:
      case 19:
        SEVEN;
        break;
      case 8:
      case 20:
        EIGHT;
        break;
      case 9:
      case 21:
        NINE;
        break;
      case 10:
      case 22:
        TEN;
        break;
      case 11:
      case 23:
        ELEVEN;
        break;
      case 0:
      case 12:
        TWELVE;
        break;
    }
  }
  else
  {
    // if we are greater than 34 minutes past the hour then display
    // the next hour, as we will be displaying a 'to' sign
    TO;
    //Serial.print(" to ");
    switch (thetime.hour()) {
      case 1:
      case 13:
        TWO;
        break;
      case 14:
      case 2:
        THREE;
        break;
      case 15:
      case 3:
        FOUR;
        break;
      case 4:
      case 16:
        FIVE;
        break;
      case 5:
      case 17:
        SIX;
        break;
      case 6:
      case 18:
        SEVEN;
        break;
      case 7:
      case 19:
        EIGHT;
        break;
      case 8:
      case 20:
        NINE;
        break;
      case 9:
      case 21:
        TEN;
        break;
      case 10:
      case 22:
        ELEVEN;
        break;
      case 11:
      case 23:
        TWELVE;
        break;
      case 0:
      case 12:
        ONE;
        break;
    }
  }
  applyMask(); // apply phrase mask to colorshift function

}









