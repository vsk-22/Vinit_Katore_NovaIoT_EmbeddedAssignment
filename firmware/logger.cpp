#include "logger.h"

void initLogger()
{
    Serial.println("Logger Initialized");
}

void logEvent(SensorData data, SystemState state)
{
    Serial.print("Temperature: ");
    Serial.print(data.temperature);

    Serial.print(" C  Humidity: ");
    Serial.print(data.humidity);

    Serial.print("%  State: ");

    switch(state)
    {
        case NORMAL:
            Serial.println("NORMAL");
            break;

        case WARNING:
            Serial.println("WARNING");
            break;

        case CRITICAL:
            Serial.println("CRITICAL");
            break;
    }
}