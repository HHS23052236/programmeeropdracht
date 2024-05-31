#include <Wire.h>
#include <Zumo32U4.h>

// De Serial1 verbinding wordt hier verklaard naar xbee
#define xbee Serial1 

class BuzzerController {
private:
    Zumo32U4Buzzer buzzer;

public:
    BuzzerController() {
        // Constructor om een melodie te spelen bij initiatie
        buzzer.play(F("l8 cdefgab>c"));
    }
};

class LedController {
public:
    LedController();

    }
    void startLed() {
      ledYellow(1);
      delay(1000);
      ledYellow(0);
      delay(1000);
    }
};

class BatteryController {
public:
    BatteryController();

    }

    void checkBattery() {
        // Controleren of er USB-stroom aanwezig is
        bool usbPower = usbPowerPresent();

        // Lezen van het batterijniveau in millivolt
        uint16_t batteryLevel = readBatteryMillivolts();

        // Afdrukken van USB-Stroomstatus
        xbee.print(F("USB="));
        // Afdrukken 'Y' als er USB-stroom aanwezig is, anders 'N'
        xbee.print(usbPower ? 'Y' : 'N');
        // Afdrukken van batterijniveau label
        xbee.print(F(" B="));
        // Afdrukken van het batterijniveau
        xbee.print(batteryLevel);
        // Afdrukken van de eenheid (millivolt)
        xbee.println(F(" mV"));
    }
};

BuzzerController buzzerController;
LedController ledController;
BatteryController batteryController;

void setup() {
    LedController.startLed();
}

void loop() {
    // Check de batterijstatus en print naar xbee
    batteryController.checkBattery();
    
    // 2 seconden delay voordat de bovenstaande loop code opnieuw wordt uitgevoerd
    delay(2000);
}