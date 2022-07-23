
#include <M5Stack.h>
#undef min

 #include "Imu.h"
 #include <string>
 #include <sstream>

 using namespace imu_fusion;
 auto imu = Imu();

void disco()
{
    M5.Lcd.fillScreen(WHITE);
    delay(500);
    M5.Lcd.fillScreen(RED);
    delay(500);
    M5.Lcd.fillScreen(GREEN);
    delay(500);
    M5.Lcd.fillScreen(BLUE);
    delay(500);
    M5.Lcd.fillScreen(BLACK);
    delay(500);
}

void setup() {
    M5.begin();
    M5.Power.begin();
    M5.Lcd.fillScreen(WHITE);
    delay(500);
    M5.Lcd.fillScreen(RED);
    delay(500);
    M5.Lcd.fillScreen(GREEN);
    delay(500);
    M5.Lcd.fillScreen(BLUE);
    delay(500);
    M5.Lcd.fillScreen(BLACK);
    delay(500);
    imu.begin();
}

void loop() {

    float roll, pitch, yaw;
    M5.IMU.getAhrsData(&roll, &pitch, &yaw);

    if(millis() % 25 == 0)
    {
    M5.Lcd.clearDisplay();
    //Draw a circle on the display depending on the roll, pitch and yaw
    int x = M5.Lcd.width() / 2;
    int y = M5.Lcd.height() / 2;

    //pos as ratio of roll from -90 to 90
    x = x + static_cast<int>(x*roll / 90.0);
    y = y + static_cast<int>(x*pitch / 90.0);
    M5.Lcd.drawCircle(x, y, 10, BLUE);

    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(RED);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.print("Roll: ");
    M5.Lcd.print(roll);
    M5.Lcd.setTextColor(GREEN);
    M5.Lcd.setCursor(0, 20);
    M5.Lcd.print("Pitch: ");
    M5.Lcd.print(pitch);
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.setCursor(0, 40);
    M5.Lcd.print("Yaw: ");
    M5.Lcd.print(yaw);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setCursor(0, 60);
    //Draw new x, y 
    M5.Lcd.print("X: ");
    M5.Lcd.print(x);
    M5.Lcd.setCursor(0, 80);
    M5.Lcd.print("Y: ");
    M5.Lcd.print(y);
    vTaskDelay(1);
    }
}