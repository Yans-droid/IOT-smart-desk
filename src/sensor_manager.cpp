#include <Arduino.h>
#include <DHT.h>

#include "config.h"
#include "globals.h"

DHT dht(DHT_PIN, DHT_TYPE);

void sensorBegin()
{
    dht.begin();

    pinMode(PIR_PIN, INPUT);
}

void sensorUpdate()
{
    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (!isnan(t))
        state.temperature = t;

    if (!isnan(h))
        state.humidity = h;

    state.motion = digitalRead(PIR_PIN);
}