// Slamet Indriyanto
// DEMO 2: 1 tombol, 1 LED (toggle)
// Ditekan = LED nyala, dilepas tetap nyala, ditekan lagi = LED mati
// Tombol: pin 8 -> GND (pull-up internal) | LED: pin 9 (+ resistor 220 ohm)

const int TOMBOL = 8;
const int LED1 = 9;

bool statusLed = false;          // false = mati, true = nyala
bool tombolSebelumnya = HIGH;    // HIGH = tidak ditekan

// Mengembalikan true SEKALI saat tombol baru saja ditekan.
// Tanda & berarti variabel aslinya ikut berubah.
bool tombolDitekan(int pin, bool &sebelumnya) {
  bool sekarang = digitalRead(pin);
  bool hasil = (sebelumnya == HIGH && sekarang == LOW);
  if (sekarang != sebelumnya) delay(20);   // redam pantulan (debounce)
  sebelumnya = sekarang;
  return hasil;
}

void setup() {
  pinMode(TOMBOL, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
}

void loop() {
  if (tombolDitekan(TOMBOL, tombolSebelumnya)) {
    statusLed = !statusLed;            // balik status
    digitalWrite(LED1, statusLed);
  }
}
