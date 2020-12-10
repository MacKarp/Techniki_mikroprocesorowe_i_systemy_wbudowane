#include <Keypad.h>

const int ROW_NUM = 4; // ilosc wierszy kalwiatury
const int COLUMN_NUM = 4; // ilosc kolumn klawiatury

// mapowanie klawiszy klawiatury:
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

#define zielony_led 11 // pin zielonego leda
#define czerwony_led 12 // pin czerwonego leda

byte pin_row[ROW_NUM] = {9, 8, 7, 6}; // piny podlaczonych wierszy klawiatury
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; // piny podlaczonych wkolumn klawiatury

Keypad keypad = Keypad( makeKeymap(keys), pin_row, pin_column, ROW_NUM, COLUMN_NUM ); //tworzenie mapy klawiatury

String haslo;
String wczytane_haslo;

void setup() {
  Serial.begin(9600);
  wczytane_haslo.reserve(32); // rezerwuje miejsce w pamieci na haslo

  Serial.setTimeout(1000); // oczekuje 1000ms na dane z portu szeregowego
  haslo = Serial.readString(); // pobiera haslo z portu szeregowego

  pinMode(zielony_led, OUTPUT); // koniguracja pinu
  pinMode(czerwony_led, OUTPUT); // konfiguracja pinu

  digitalWrite(zielony_led, LOW); // wylacznie diody zielonej
  digitalWrite(czerwony_led, HIGH); // zalacza diode
}

void loop() {
  char key = keypad.getKey(); //pobieranie znaku wcisnietego przycisku

  if (key) {
    if (key == '*') { //po nacisnieciu * czysci haslo
      digitalWrite(zielony_led, LOW); // wylacznie diody zielonej
      wczytane_haslo = ""; // czysci haslo w pamieci
      digitalWrite(czerwony_led, HIGH); // zalacza diode czerwona
    } else if (key == '#') {
      if (haslo == wczytane_haslo) { // porownanie haslo, jesli poprawne to:
        digitalWrite(czerwony_led, LOW); // wylaczna diode czerwona
        digitalWrite(zielony_led, HIGH); // zalacza diode zielona
      } else
        wczytane_haslo = wczytane_haslo + key; // dodaje wczytany znak do zmiennej
    }
  }
}
