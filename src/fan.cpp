#include <Arduino.h>

#include "config.h"
#include "globals.h"

void fanBegin()
{
    pinMode(FAN_PIN, OUTPUT);
    digitalWrite(FAN_PIN, LOW);
}

void fanUpdate()
{
    digitalWrite(FAN_PIN, state.fanOn ? HIGH : LOW);
}