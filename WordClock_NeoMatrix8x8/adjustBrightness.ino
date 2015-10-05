
// change brightness based on the time of day.

void adjustBrightness() {

  // get time from the RTC
  //DateTime thetime = RTC.now();
  theTime = calculateTime(); // takes into account DST

  //change brightness if it's night time
  if (theTime.hour() < MORNINGCUTOFF || theTime.hour() > NIGHTCUTOFF) {
    matrix.setBrightness(NIGHTBRIGHTNESS);
  } else {
    matrix.setBrightness(DAYBRIGHTNESS);
  }
}
