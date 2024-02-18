#include <SPI.h>
#include <RF24.h>

// Указываем пины для подключения модуля nRF24L01
const int cePin = 9;
const int csPin = 10;

// Создаем объект RF24 для работы с модулем
RF24 radio(cePin, csPin);

void setup() {
  Serial.begin(9600);

  // Инициализируем модуль nRF24L01
  radio.begin();

  // Открываем канал для передачи данных (должен совпадать с каналом на приемной стороне)
  radio.openWritingPipe(0xF0F0F0F0E1LL);  // Уникальный адрес для передачи данных
}

void loop() {
  // Отправляем сообщение
  const char* message = "Hello, Arduino!";
  radio.write(message, strlen(message));

  Serial.println("Сообщение отправлено!");

  delay(1000);  // Пауза между отправками
}
