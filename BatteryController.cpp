#include "BatteryController.h"

BatteryController::BatteryController() {}

void BatteryController::checkBattery() {
    // Controleren of er USB-stroom aanwezig is
    bool usbPower = usbPowerPresent();

    // Lezen van het batterijniveau in millivolt
    uint16_t batteryLevel = readBatteryMillivolts();

    // Afdrukken van USB-Stroomstatus
    Serial.print(F("USB="));
    // Afdrukken 'Y' als er USB-stroom aanwezig is, anders 'N'
    Serial.print(usbPower ? 'Y' : 'N');
    // Afdrukken van batterijniveau label
    Serial.print(F(" B="));
    // Afdrukken van het batterijniveau
    Serial.print(batteryLevel);
    // Afdrukken van de eenheid (millivolt)
    Serial.println(F(" mV"));
}
