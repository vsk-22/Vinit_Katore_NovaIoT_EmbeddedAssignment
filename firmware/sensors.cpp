#include "sensors.h"
#include "config.h"
#include <DHT.h>

DHT dht(DHT_PIN, DHT22);

void initSensors()
{
    dht.begin();
}

SensorData readSensors()
{
    SensorData data;

    data.temperature = dht.readTemperature();
    data.humidity = dht.readHumidity();

    data.valid = !(isnan(data.temperature) || isnan(data.humidity));

    return data;
}

SystemState classifyCondition(SensorData data)
{
    if(!data.valid)
        return CRITICAL;

    if(data.temperature >= NORMAL_TEMP_MIN &&
       data.temperature <= NORMAL_TEMP_MAX &&
       data.humidity >= NORMAL_HUM_MIN &&
       data.humidity <= NORMAL_HUM_MAX)
    {
        return NORMAL;
    }

    if(data.temperature < CRITICAL_TEMP_MIN ||
       data.temperature > CRITICAL_TEMP_MAX ||
       data.humidity < CRITICAL_HUM_MIN ||
       data.humidity > CRITICAL_HUM_MAX)
    {
        return CRITICAL;
    }

    return WARNING;
}