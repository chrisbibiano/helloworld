#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>

#if (SSD1306_LCDHEIGHT != 64)
    #error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// OLED display TWI address
#define OLED_ADDR   0x3C
#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

SoftwareSerial mySerial(8,9); //RX,TX

char inChar;

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
    if (inChar=='\r'){
      display.clearDisplay();
      display.setCursor(0, 0);
    }
    else
      display.print(inChar);
  
    mySerial.print(inChar);
    display.display();
  }
}



