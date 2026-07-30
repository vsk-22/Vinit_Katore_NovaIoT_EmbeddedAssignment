#include "display.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void initDisplay()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        while (true);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.display();
}

void displayStatus(SensorData data, SystemState state)
{
    display.clearDisplay();

    display.setCursor(0, 0);
    display.println("FleetGuard Monitor");

    display.setCursor(0, 15);
    display.print("Temp : ");
    display.print(data.temperature);
    display.println(" C");

    display.setCursor(0, 30);
    display.print("Hum  : ");
    display.print(data.humidity);
    display.println(" %");

    display.setCursor(0, 45);
    display.print("State: ");

    switch (state)
    {
        case NORMAL:
            display.println("NORMAL");
            break;

        case WARNING:
            display.println("WARNING");
            break;

        case CRITICAL:
            display.println("CRITICAL");
            break;
    }

    display.display();
}