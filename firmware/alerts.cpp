#include "alerts.h"
#include "config.h"
#include <Wire.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128,64,&Wire,-1);

void initAlerts()
{
    pinMode(GREEN_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    display.begin(SSD1306_SWITCHCAPVCC,0x3C);
    display.clearDisplay();
    display.display();
}

void updateAlerts(SystemState state)
{
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    switch(state)
    {
        case NORMAL:
            digitalWrite(GREEN_LED,HIGH);
            break;

        case WARNING:
            digitalWrite(YELLOW_LED,HIGH);
            break;

        case CRITICAL:
            digitalWrite(RED_LED,HIGH);
            digitalWrite(BUZZER_PIN,HIGH);
            break;
    }
}

void displayStatus(SensorData data, SystemState state)
{
    display.clearDisplay();

    display.setCursor(0,0);
    display.print("Temp: ");
    display.print(data.temperature);

    display.setCursor(0,15);
    display.print("Hum: ");
    display.print(data.humidity);

    display.setCursor(0,30);

    if(state==NORMAL)
        display.print("NORMAL");

    else if(state==WARNING)
        display.print("WARNING");

    else
        display.print("CRITICAL");

    display.display();
}