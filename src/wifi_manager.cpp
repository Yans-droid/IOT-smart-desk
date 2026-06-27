#include <Arduino.h>
#include "config.h"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>


#include "globals.h"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASSWORD;

void wifiBegin()
{
    WiFi.begin(ssid, pass);

    Blynk.config(auth);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }

    Blynk.connect();

    state.wifiConnected = WiFi.status() == WL_CONNECTED;
}

void wifiUpdate()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        state.wifiConnected = false;
        return;
    }

    state.wifiConnected = true;

    Blynk.run();
}

bool wifiConnected()
{
    return state.wifiConnected;
}