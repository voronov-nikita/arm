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

  // Открываем канал для приема данных (должен совпадать с каналом на передающей стороне)
  radio.openReadingPipe(1, 0xF0F0F0F0E1LL);  // Уникальный адрес для приема данных

  // Включаем приемник
  radio.startListening();
}

void loop() {
  Serial.print(".");
  // Проверяем наличие данных для приема
  if (radio.available()) {
    char message[32] = {0};  // Буфер для принятого сообщения
    radio.read(&message, sizeof(message));

    Serial.print("Принято сообщение: ");
    Serial.println(message);
  }
}
