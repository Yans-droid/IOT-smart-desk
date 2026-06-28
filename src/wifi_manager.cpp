#include <Arduino.h>
#include "config.h"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>


#include "globals.h"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASSWORD;

BLYNK_WRITE(V8)
{
    int mode = param.asInt();

    switch(mode)
    {
        case 0:
            state.mode = MODE_OFF;
            break;

        case 1:
            state.mode = MODE_READING;
            break;

        case 2:
            state.mode = MODE_FOCUS;
            break;

        case 3:
            state.mode = MODE_BREAK;
            break;
    }
}
BLYNK_WRITE(V1)
{
    state.fanOn = param.asInt();

    Serial.print("V1 = ");
    Serial.println(state.fanOn);

}

void wifiBegin()
{
    WiFi.begin(ssid, pass);

    Blynk.config(auth);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }

    Blynk.connect();
    Blynk.syncVirtual(V1);
    Blynk.syncVirtual(V8);

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
    Blynk.virtualWrite(V2, state.temperature);

    Blynk.virtualWrite(V7, state.motion);
}

bool wifiConnected()
{
    return state.wifiConnected;
}