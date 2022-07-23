//****************************************************************************
//@file Imu.h
//@brief Imu library for M5Stack
//@details This class is used to read the IMU data and calculate the angles.
//****************************************************************************

#ifndef Imu_h
#define Imu_h

#include <M5Stack.h>
#include "SensorFusion.h"

namespace imu_fusion
{
    class Imu
    {
        public:
        Imu();
        void begin();
        void update();
        float getPitch();
        float getRoll();
        float getYaw();
        float getTemperature();

        private:
        //IMU variables
        float pitch_;
        float roll_;
        float yaw_;
        float temperature_;

        //IMU state variables
        float ax_;
        float ay_;
        float az_;
        float gx_;
        float gy_;
        float gz_;

        SF fusion;
    };
}


#endif