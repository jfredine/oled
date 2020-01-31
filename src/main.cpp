#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(128, 32, &Wire, -1);

void setup() {
#ifdef __AVR_ATmega328P__
    Wire.begin();
#else
    Wire.begin(D4, D5);
#endif

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ;  // Don't proceed, loop forever
    }

    // display Adafruit logo
    display.display();
}

void loop() {}