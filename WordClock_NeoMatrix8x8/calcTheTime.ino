
/*
 *  Function to figure out if we're in Daylight Saving Time, then adding an hour if we are in DST.
 *  adapted from nseidle
 *  https://github.com/nseidle/Daylight_Savings_Time_Example/blob/master/Daylight_Savings_Time_Example.ino
 *
 *  This algorithm is programmed to observe Daylight Saving Time in the United States, where as of the time of writing  DST is observed
 *  between the second Sunday in March and the first Sunday in November. The rules for DST vary by country and territory.
 *  https://en.wikipedia.org/wiki/Daylight_saving_time_by_country
 *
 *  If you're in a territory which observes DST differently this code will need to be modified. If you're lucky enough to not observe DST 
 *  then much of this code can be commented out!
 *
 *  This method doesn't check whether its 2am or not when the time change officially occurs. This could be more accurate at the expense of being more complicated.
 *  
 */

DateTime calcTheTime() {

  DateTime RTCTime = RTC.now();

  byte DoW = day_of_week(RTCTime.year(), RTCTime.month(), RTCTime.day()); //Get the day of the week. 0 = Sunday, 6 = Saturday
  int previousSunday = RTCTime.day() - DoW;

  boolean dst = false; //Assume we're not in DST
  if (RTCTime.month() > 3 && RTCTime.month() < 11) dst = true; //DST is happening!

  //In March, we are DST if our previous Sunday was on or after the 8th.
  if (RTCTime.month() == 3)
  {
    if (previousSunday >= 8) dst = true;
  }
  //In November we must be before the first Sunday to be dst.
  //That means the previous Sunday must be before the 1st.
  if (RTCTime.month() == 11)
  {
    if (previousSunday <= 0) dst = true;
  }

  if (dst == true) {
    theTime = RTCTime.unixtime() + 3600;  // add 1 hour or 3600 seconds to the time
  }

  Serial.print(theTime.year(), DEC);
  Serial.print('/');
  Serial.print(theTime.month(), DEC);
  Serial.print('/');
  Serial.print(theTime.day(), DEC);
  Serial.print(' ');
  Serial.print(theTime.hour(), DEC);
  Serial.print(':');
  Serial.print(theTime.minute(), DEC);
  Serial.print(':');
  Serial.print(theTime.second(), DEC);
  Serial.println();

  return theTime;
}


//Given the current year/month/day
//Returns 0 (Sunday) through 6 (Saturday) for the day of the week
//From: http://en.wikipedia.org/wiki/Calculating_the_day_of_the_week
//This function assumes the month from the caller is 1-12
char day_of_week(int year, int month, int day)
{
  //Devised by Tomohiko Sakamoto in 1993, it is accurate for any Gregorian date:
  static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4  };
  year -= month < 3;
  return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}
