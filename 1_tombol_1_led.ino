// Slamet Indriyanto
// DEMO 1: 1 tombol, 1 LED
// Ditekan = LED nyala, dilepas = LED mati
// Tombol: pin 8 -> GND (pull-up internal) | LED: pin 9 (+ resistor 220 ohm)

const int TOMBOL = 8;
const int LED1 = 9;

void setup() {
  pinMode(TOMBOL, INPUT_PULLUP);  // pull-up internal aktif
  pinMode(LED1, OUTPUT);
}

void loop() {
  if (digitalRead(TOMBOL) == LOW) {   // LOW = tombol ditekan
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }
}
