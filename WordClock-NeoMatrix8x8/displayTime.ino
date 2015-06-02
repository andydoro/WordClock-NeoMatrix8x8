
// function to generate the right "phrase" based on the time

void displayTime(void) {

  // get time from the RTC
  DateTime time = RTC.now();


  //DateTime time;
  // serial print current time
  /*
  Serial.print(time.year(), DEC);
  Serial.print('/');
  Serial.print(time.month(), DEC);
  Serial.print('/');
  Serial.print(time.day(), DEC);
  Serial.print(' ');
  Serial.print(time.hour(), DEC);
  Serial.print(':');
  Serial.print(time.minute(), DEC);
  Serial.print(':');
  Serial.print(time.second(), DEC);
  Serial.println();
  */
  // turn everything off
  //matrix.fillScreen(0);
  //topMask = 0;
  //bottomMask = 0;

  // time we display the appropriate time.minute() counter
  if ((time.minute() > 4) && (time.minute() < 10)) {
    MFIVE;
    //Serial.print("five");
  }
  if ((time.minute() > 9) && (time.minute() < 15)) {
    MTEN;
    //Serial.print("ten");
  }
  if ((time.minute() > 14) && (time.minute() < 20)) {
    AQUARTER;
    //Serial.print("a quarter");
  }
  if ((time.minute() > 19) && (time.minute() < 25)) {
    TWENTY;
    //Serial.print("twenty");
  }
  if ((time.minute() > 24) && (time.minute() < 30)) {
    TWENTY;
    MFIVE;
    //Serial.print("twenty five");
  }
  if ((time.minute() > 29) && (time.minute() < 35)) {
    HALF;
    //Serial.print("half");
  }
  if ((time.minute() > 34) && (time.minute() < 40)) {
    TWENTY;
    MFIVE;
    //Serial.print("twenty five");
  }
  if ((time.minute() > 39) && (time.minute() < 45)) {
    TWENTY;
    //Serial.print("twenty");
  }
  if ((time.minute() > 44) && (time.minute() < 50)) {
    AQUARTER;
    //Serial.print("a quarter");
  }
  if ((time.minute() > 49) && (time.minute() < 55)) {
    MTEN;
    //Serial.print("ten");
  }
  if (time.minute() > 54) {
    MFIVE;
    //Serial.print("five");
  }

  if ((time.minute() < 5))
  {
    switch (time.hour()) {
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
    //OCLOCK;
  }
  else if ((time.minute() < 35) && (time.minute() > 4))
  {
    PAST;
    //Serial.print(" past ");
    switch (time.hour()) {
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
    switch (time.hour()) {
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









