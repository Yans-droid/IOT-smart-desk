#include <Arduino.h>

#include "fan.h"
#include "display.h"
#include "wifi_manager.h"
#include "led.h"
#include "sensor_manager.h"



void setup()
{
    displayBegin();
    displayBoot();

    ledBegin();

    sensorBegin();
    fanBegin();


    wifiBegin();

}

void loop()
{
    wifiUpdate();

    sensorUpdate();

    ledUpdate();

    fanUpdate();

    displayUpdate();
}