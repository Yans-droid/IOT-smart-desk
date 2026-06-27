#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "config.h"
#include "globals.h"

Adafruit_SSD1306 display(
SCREEN_WIDTH,
SCREEN_HEIGHT,
&Wire,
-1
);

void displayBegin(){

    Wire.begin(OLED_SDA,OLED_SCL);

    display.begin(SSD1306_SWITCHCAPVCC,OLED_ADDR);

    display.clearDisplay();

    display.display();

}

void displayBoot(){

    display.clearDisplay();

    display.setTextSize(2);

    display.setTextColor(SSD1306_WHITE);

    display.setCursor(8,10);

    display.println("SMART");

    display.println("STUDY");

    display.println("LAMP");

    display.display();

    delay(2000);

}

void displayUpdate(){

    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0,0);

    display.println("SMART STUDY");

    display.drawLine(0,10,127,10,SSD1306_WHITE);

    display.setCursor(0,16);

    switch(state.mode){

        case MODE_READING:
            display.println("Mode : Reading");
        break;

        case MODE_FOCUS:
            display.println("Mode : Focus");
        break;

        case MODE_BREAK:
            display.println("Mode : Break");
        break;

        case MODE_OFF:
            display.println("Mode : Off");
        break;

    }

    display.setCursor(0,30);

    display.print("Temp : ");

    display.print(state.temperature);

    display.println(" C");

    display.print("Hum  : ");

    display.print(state.humidity);

    display.println(" %");
    display.print("WiFi : ");

if(state.wifiConnected)
    display.println("Connected");
else
    display.println("Disconnected");


    display.display();

}