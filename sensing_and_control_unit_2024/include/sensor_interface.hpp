#ifndef SENSOR_INTERFACE_HPP
#define SENSOR_INTERFACE_HPP

#include <mpu6050.hpp>

#include "Adafruit_FXOS8700.h"
#include "MS5837.h"
#include "sensor_math.hpp"
#include <Adafruit_HMC5883_U.h>


#define MS5837_ADDR 0x76
#define MPU6050_ADDRESS 0x68

void initializeIMU();
void initializeDepthSensor();
void callUpdateOffset(bool& calib_status);
void updateIMUReadings(float& ax, float& ay, float& az, float& gx, float& gy,
                       float& gz, float& mx, float& my, float& mz);
void updateDepthSensorReadings(float& depth);

extern MPU6050 gyro;
extern Adafruit_HMC5883_Unified mag;
extern MS5837 depth_sensor;
#endif  // SENSOR_INTERFACE_HPP