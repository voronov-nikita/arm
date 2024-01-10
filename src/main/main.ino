#include "MPU6050.h"
MPU6050 mpu;

// Переменные для хранения предыдущего положения датчика
int16_t prevAz = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  mpu.initialize();

  mpu.CalibrateAccel(5);
  mpu.CalibrateGyro(5);
}

void loop() {
  int16_t ax = mpu.getAccelerationX();  // ускорение по оси X
  int16_t ay = mpu.getAccelerationY();  // ускорение по оси Y
  int16_t az = mpu.getRotationZ();  // ускорение по оси Z

  // Выводим значения ускорений по всем осям
  Serial.print("Accel X: ");
  Serial.print(ax);
  Serial.print("\tAccel Y: ");
  Serial.print(ay);
  Serial.print("\tAccel Z: ");
  Serial.println(az);


  // Сохраняем текущее значение ускорения по оси Z для следующей итерации
  prevAz = az;

  delay(300);
}
