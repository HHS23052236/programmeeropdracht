#include <Wire.h>
#include "BuzzerController.h"
#include "LedController.h"
#include "BatteryController.h"

// De Serial1 verbinding wordt hier verklaard naar xbee
#define xbee Serial1

BuzzerController buzzerController;
LedController ledController;
BatteryController batteryController;

void setup() {
    xbee.begin(9600);
    ledController.startLed();
}

void loop() {
    // Check de batterijstatus en print naar xbee
    batteryController.checkBattery();
    
    // 2 seconden delay voordat de bovenstaande loop code opnieuw wordt uitgevoerd
    delay(2000);
}
