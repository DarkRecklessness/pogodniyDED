#include "esp32-hal-ledc.h" // библиотека ШИМа

#define FAN_COLLECTOR_PIN 16

//частота ШИМ
#define FREQUENCY 30000
//канал, на который назначим в дальнейшем ШИМ (от 0 до 16) (или до 15)
#define PWM_FAN_CHANNEL 0
//разрешение ШИМа (в битах)    
#define RESOLUTION 8 // при 8 2^8 = 256 (ШИМ сигнал от 0 до 256)



void changeFanSpeed(int power) { // Должна получить канал и значение силы в процентах
  if (power == 0) {
    ledcWrite(PWM_FAN_CHANNEL, 0);
  } else {
    int max_power = pow(2, RESOLUTION) - 1;
    ledcWrite(PWM_FAN_CHANNEL, max_power); // максимальная мощность для запуска
    delay(100);
    ledcWrite(PWM_FAN_CHANNEL, map(power, 1, 100, max_power / 2, max_power)); // для более корректной работы
  }
}



void setup() {
  Serial.begin(115200);
  ledcSetup(PWM_FAN_CHANNEL, FREQUENCY, RESOLUTION); // устанавливаем базовые параметры ШИМ
  ledcAttachPin(FAN_COLLECTOR_PIN, PWM_FAN_CHANNEL);
}

void loop() {
  changeFanSpeed(100);
  Serial.println("Enter data:");
  while (Serial.available() == 0) {    //wait for data available
    String inp = Serial.readString();  //read until timeout
    inp.trim();
    if (inp.toInt() != 0) {
      changeFanSpeed(inp.toInt());
    }
  }
}



