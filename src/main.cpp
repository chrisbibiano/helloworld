#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// OLED display TWI address
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(-1);

char inChar;
String OLed_String;

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void testscrolltext(void);


void setup() {

  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Serial up and running.");
 
}

void loop() {

 if (Serial.available()){
  inChar=Serial.read();
  Serial.print(inChar);
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



