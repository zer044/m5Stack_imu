//****************************************************************************
//@file Imu.cpp
//@brief Imu library for M5Stack
//@details This class is used to read the IMU data and calculate the angles.
//****************************************************************************
#define M5STACK_MPU6886

#include "Imu.h"
using namespace imu_fusion;

Imu::Imu() : pitch_(0.0), roll_(0.0), yaw_(0.0), temperature_(0.0),
             ax_(0.0), ay_(0.0), az_(0.0), gx_(0.0), gy_(0.0), gz_(0.0)
{
    fusion = SF();
}

void Imu::begin()
{
    M5.begin();
    M5.IMU.Init();
}

void Imu::update()
{
    auto deltat = fusion.deltatUpdate(); //this have to be done before calling the fusion update

    M5.IMU.getGyroData(&gx_, &gy_, &gz_);
    M5.IMU.getAccelData(&ax_, &ay_, &az_);
    M5.IMU.getTempData(&temperature_);
    fusion.MahonyUpdate(gx_, gy_, gz_, ax_, ay_, az_, deltat);

    pitch_ = fusion.getPitch();
    roll_ = fusion.getRoll();    //you could also use getRollRadians() ecc
    yaw_ = fusion.getYaw();
}

float Imu::getPitch()
{
    return pitch_;
}

float Imu::getRoll()
{
    return roll_;
}

float Imu::getYaw()
{
    return yaw_;
}

float Imu::getTemperature()
{
    return temperature_;
}