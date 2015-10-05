
// show colorshift through the phrase mask. for each NeoPixel either show a color or show nothing!
void applyMask() {

  for (byte i = 0; i < 64; i++) {
    boolean masker = bitRead(mask, 63 - i); // bitread is backwards because bitRead reads rightmost digits first. could have defined the word masks differently
    switch (masker) {
      case 0:
        matrix.setPixelColor(i, 0, 0, 0);
        break;
      case 1:
        matrix.setPixelColor(i, Wheel(((i * 256 / matrix.numPixels()) + j) & 255));
        //matrix.setPixelColor(i, WHITE);
        break;
    }
  }

  matrix.show(); // show it!
  delay(SHIFTDELAY);
  j++; // move the colors forward
  j = j % (256 * 5);

  // reset mask for next time
  mask = 0;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {

  WheelPos = 255 - WheelPos;
  uint32_t wheelColor;

  if (WheelPos < 85) {
    wheelColor = matrix.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    wheelColor = matrix.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
    WheelPos -= 170;
    wheelColor = matrix.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }

  // convert from 24-bit to 16-bit color - NeoMatrix requires 16-bit. perhaps there's a better way to do this.
  uint32_t bits = wheelColor;
  uint32_t blue = bits & 0x001F;     // 5 bits blue
  uint32_t green = bits & 0x07E0;    // 6 bits green
  uint32_t red = bits & 0xF800;      // 5 bits red

  // Return shifted bits with alpha set to 0xFF
  return (red << 8) | (green << 5) | (blue << 3) | 0xFF000000;
}


// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < matrix.numPixels(); i++) {
      matrix.setPixelColor(i, Wheel(((i * 256 / matrix.numPixels()) + j) & 255));
    }
    matrix.show();
    delay(wait);
  }
}

