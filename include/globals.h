#pragma once

enum LampMode {

    MODE_OFF,

    MODE_READING,

    MODE_FOCUS,

    MODE_BREAK

};

struct SystemState{

    LampMode mode;

    bool lampOn;

    bool fanOn;

    bool autoMode;

    bool motion;

    bool wifiConnected;

    float temperature;

    float humidity;

};

extern SystemState state;