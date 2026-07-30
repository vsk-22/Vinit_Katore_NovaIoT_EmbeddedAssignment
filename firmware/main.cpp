#include "config.h"
#include "sensors.h"
#include "alerts.h"
#include "logger.h"

void setup()
{
    Serial.begin(115200);

    initSensors();
    initAlerts();
    initLogger();

    Serial.println("FleetGuard Smart Monitoring System Started");
}

void loop()
{
    SensorData data = readSensors();

    SystemState state = classifyCondition(data);

    updateAlerts(state);

    displayStatus(data, state);

    logEvent(data, state);

    delay(SAMPLING_INTERVAL);
}