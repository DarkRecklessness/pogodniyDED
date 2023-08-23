#define TEMP_PIN 34 //https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/

int temperature;

void setup() {
  pinMode(TEMP_PIN, INPUT);
}

void loop() {
  temperature = analogRead(TEMP_PIN);
  temperature = temperature*5.0/1024; // перевод в вольты
  temperature = temperature*100 - 273.15; // в градусы Цельсия
}
