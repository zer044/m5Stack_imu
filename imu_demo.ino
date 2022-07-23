
#include <M5Stack.h>
#include "SensorFusion.h"
#include "Imu.h"
#include <string>

auto imu = Imu();

void setup() {
    Serial.begin(115200);
    imu.begin();

    M5.begin();
    M5.Power.begin();
    M5.Lcd.fillScreen(WHITE);
    M5.Imu.begin();
    delay(1000);
}

void loop() {
    imu.update();

    auto roll = imu.getRoll();
    auto pitch = imu.getPitch();
    auto yaw = imu.getYaw();
    auto temperature = imu.getTemperature();

    std::string eulers = "Roll: " + std::to_string(roll) + " Pitch: " + std::to_string(pitch) + " Yaw: " + std::to_string(yaw);

    M5.Lcd.setTextColor(BLACK);
    M5.Lcd.setCursor(0, 10);
    M5.Lcd.printf(eulers.c_str(), 10, 10);
    M5.update();
}