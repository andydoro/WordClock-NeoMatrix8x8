 WORD CLOCK - NeoMatrix 8x8 Desktop Edition
================
 by Andy Doro & Dano Wall
 
Hardware:
 
 - Trinket Pro 5V (should work with other Arduino-compatibles with minor modifications)
 - DS1307 RTC breakout
 - NeoPixel NeoMatrix 8x8
 - 3D print of faceplate & enclosure
 
Software:
 
This code requires the following libraries:
 
 - RTClib https://github.com/adafruit/RTClib
 - Adafruit_GFX https://github.com/adafruit/Adafruit-GFX-Library
 - Adafruit_NeoPixel https://github.com/adafruit/Adafruit_NeoPixel
 - Adafruit_NeoMatrix https://github.com/adafruit/Adafruit_NeoMatrix


Wiring:

 - Solder DS1307 breakout to Trinket Pro, A2 to GND, A3 to PWR, A4 to SDA, A5 to SCL  
   If you leave off / clip the unused SQW pin on the RTC breakout, the breakout can sit right on top of the Trinket Pro for a compact design! It'll be difficult to reach the Trinket Pro reset button, but you can activate the bootloader by plugging in the USB.
 - Solder NeoMatrix 5V to Trinket 5V, GND to GND, DIN to Trinket Pro pin 8.
 
 
Construction:

 - NeoMatrix goes behind the faceplate. Mount Trinket Pro inside enclosure.
 
 
 The effect will be a word clock using the RGB LEDs for a color shift effect.
 
grid pattern:
 ```
 A T W E N T Y D
 Q U A R T E R Y
 F I V E H A L F
 D P A S T O R O
 F I V E I G H T
 S I X T H R E E
 T W E L E V E N
 F O U R N I N E
 ```
 
Acknowledgements:
  - Thanks Dano for faceplate / 3D models & project inspiration! https://github.com/danowall
 

