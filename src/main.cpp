#include <Arduino.h>

#include "display.h"
#include "wifi_manager.h"

void setup()
{
    displayBegin();
    displayBoot();

    wifiBegin();
}

void loop()
{
    wifiUpdate();

    displayUpdate();
}