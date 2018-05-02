#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(8,9); //RX,TX

// OLED display TWI address
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(-1);

char inChar;
String OLed_String;

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


void setup() {

  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  
  // Open serial communications and wait for port to open:
  mySerial.begin(9600);

}


void loop() {

 if (mySerial.available()){
    inChar=mySerial.read();
    mySerial.print(inChar);
    if (inChar!='\r'){
      OLed_String+=inChar;
      display.setCursor(0, 0);
      display.print(OLed_String);
    }
    else{
      display.clearDisplay();
      OLed_String="";
    }
    display.display();
  }

}



