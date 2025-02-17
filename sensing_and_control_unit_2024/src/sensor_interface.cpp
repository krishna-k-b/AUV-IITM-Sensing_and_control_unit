// #include "sensor_interface.hpp"

// #include "config.hpp"

// void initializeIMU() {
//   mag.begin();
//   gyro.begin();
//   gyro.setAccelerometerRange(ACCELERO_METER_RANGE_2);
//   gyro.setGyroscopeRange(GYROSCOPE_RANGE_250);
//   gyro.setSampleRateDivider(0);
//   gyro.disableSleepMode();
// }

// void initializeDepthSensor() {
//   bool depth_sensor_status = depth_sensor.init();
//   // depth_sensor.setModel(MS5837::MS5837_30BA);
//   depth_sensor.setFluidDensity(997);  // kg/m^3 (freshwater, 1029 for seawater)
// }

// void updateIMUReadings(float& ax, float& ay, float& az, float& gx, float& gy,
//                        float& gz, float& mx, float& my, float& mz) {
//   sensors_event_t mag_event;
//   mag.getEvent(&mag_event);
//   float Ax, Ay, Gx, Gy;
//   gyro.getSensorsReadings(Ax, Ay, az, Gx, Gy, gz);
//   // ax = -Ay / G;
//   // ay = Ax / G;
//   // az = az / G;
//   // gx = -Gy;
//   // gy = Gx;

//   ax = -Ay / G;
//   ay = Ax / G;
//   az = az / G;
//   gx = -Gy;
//   gy = Gx;

//   mx = mag_event.magnetic.x;
//   my = mag_event.magnetic.y;
//   mz = mag_event.magnetic.z;
// }

// void callUpdateOffset(bool& calibration_mode) {
//   if (calibration_mode) {
//     updateOffset(gyro);
//   }
// }
// // calibration_status(){
// //   bool calibration_mode = calibration_status.data;
// // void updateDepthSensorReadings(float& depth) {
// //   depth_sensor.read();
// //   depth = depth_sensor.depth();
// // }
// // id setCalibrationMode(bool &calib_status){
// //   bool calibration_mode = calib_status;
// // }
// // }



#include "sensor_interface.hpp"

#include "config.hpp"

void initializeIMU() {
  mag.begin();
  gyro.begin();
  gyro.setAccelerometerRange(ACCELERO_METER_RANGE_2);
  gyro.setGyroscopeRange(GYROSCOPE_RANGE_250);
  gyro.setSampleRateDivider(0);
  gyro.disableSleepMode();
}

void initializeDepthSensor() {
  bool depth_sensor_status = depth_sensor.init();
  // depth_sensor.setModel(MS5837::MS5837_30BA);
  depth_sensor.setFluidDensity(997);  // kg/m^3 (freshwater, 1029 for seawater)
}

void updateIMUReadings(float& ax, float& ay, float& az, float& gx, float& gy,
                       float& gz, float& mx, float& my, float& mz) {
  sensors_event_t mag_event;
  mag.getEvent(&mag_event);
  float Ax, Ay, Gx, Gy;
  gyro.getSensorsReadings(Ax, Ay, az, Gx, Gy, gz);
  // ax = -Ay / G;
  // ay = Ax / G;
  // az = az / G;
  // gx = -Gy;
  // gy = Gx;

  ax = -Ay / G;
  ay = Ax / G;
  az = az / G;
  gx = -Gy;
  gy = Gx;

  mx = mag_event.magnetic.x;
  my = mag_event.magnetic.y;
  mz = mag_event.magnetic.z;
}

void callUpdateOffset(bool& calibration_mode) {
  if (calibration_mode) {
    updateOffset(gyro);
  }
}
// calibration_status(){
//   bool calibration_mode = calibration_status.data;
// void updateDepthSensorReadings(float& depth) {
//   depth_sensor.read();
//   depth = depth_sensor.depth();
// }
// id setCalibrationMode(bool &calib_status){
//   bool calibration_mode = calib_status;
// }
// }