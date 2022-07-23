
#include <M5Stack.h>
#include "SensorFusion.h"


void setup() {
    M5.begin();
    M5.Power.begin();
    M5.Lcd.fillScreen(WHITE);
    delay(1000);
}

void loop() {
    M5.Lcd.fillTriangle(random(M5.Lcd.width() - 1), random(M5.Lcd.height() - 1),
                        random(M5.Lcd.width() - 1), random(M5.Lcd.height() - 1),
                        random(M5.Lcd.width() - 1), random(M5.Lcd.height() - 1),
                        random(0xfffe));

    M5.update();
}