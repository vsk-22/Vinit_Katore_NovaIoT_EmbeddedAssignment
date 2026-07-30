#ifndef CONFIG_H
#define CONFIG_H

#define DHT_PIN 4

#define GREEN_LED 16
#define YELLOW_LED 17
#define RED_LED 18

#define BUZZER_PIN 19

struct Configuration
{
    unsigned long samplingInterval;

    float normalTempMin;
    float normalTempMax;

    float normalHumMin;
    float normalHumMax;

    float criticalTempMin;
    float criticalTempMax;

    float criticalHumMin;
    float criticalHumMax;
};

extern Configuration config;

void initConfig();

Configuration getConfig();

void updateConfig(Configuration newConfig);

void resetConfig();

#endif