
#include <SPI.h>
#include "RF24.h"
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

// обьект гироскоп-акселрометра
MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

// массив данных, который мы будем отправлять
// всего там будет 3 числа
int data[3];

// обьект NRF модуля
RF24 radio(9,10);

// создаем канал для обмена данными по радио
const uint64_t pipe = 0xE8E8F0F0E1LL;


void setup(){
  Wire.begin();
  // подключаем MPU
  mpu.initialize();
  // подключаем NRF
  radio.begin();
  // открываем соединение на этом канале
  radio.openWritingPipe(pipe);
}

void loop(){
  
  // получаем значения акселерометра и гироскопа
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // заполняем массив данных
  data[0] = map(ax, -17000, 17000, 300, 400 );
  data[1] = map(ay, -17000, 17000, 100, 200);
  data[2] = map(az, -17000, 17000, 100, 200);  

  // отправляем по радио каналу массив данных
  radio.write(data, sizeof(data));
}
