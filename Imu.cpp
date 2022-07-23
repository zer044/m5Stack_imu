//****************************************************************************
//@file Imu.cpp
//@brief Imu library for M5Stack
//@details This class is used to read the IMU data and calculate the angles.
//****************************************************************************

#include "Imu.h"

using namespace imu_fusion;

Imu::Imu() : pitch_(0.0), roll_(0.0), yaw_(0.0), temperature_(0.0),
             ax_(0.0), ay_(0.0), az_(0.0), gx_(0.0), gy_(0.0), gz_(0.0)
{
    fusion = SF();
    fusion.begin();
}