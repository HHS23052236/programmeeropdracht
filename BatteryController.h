#ifndef BATTERY_CONTROLLER_H
#define BATTERY_CONTROLLER_H

#include <Zumo32U4.h>

// BatteryController voor de batterij
class BatteryController {
public:
    BatteryController();
    void checkBattery();
};

#endif // BATTERY_CONTROLLER_H
