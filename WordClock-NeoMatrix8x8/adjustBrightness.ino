
// change brightness based on the time of day.

void adjustBrightness() {

  // get time from the RTC
  DateTime time = RTC.now();


  //change brightness if it's night time
  if (time.hour() < MORNINGCUTOFF || time.hour() > NIGHTCUTOFF) {
    matrix.setBrightness(NIGHTBRIGHTNESS);
  } else {
    matrix.setBrightness(DAYBRIGHTNESS);
  }

}
