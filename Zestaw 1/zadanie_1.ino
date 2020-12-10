#include <LiquidCrystal.h>
LiquidCrystal lcd(6, 7, 8, 9, 10, 11); // konfiguracja pinow dla wyswietlacza lcd

#define echoPin 12 // pin echo dla czujnikia odleglosci 
#define trigPin 13 // pin triger dla czujnikia odleglosci 
#define czerwony_led 5 // pin diody led
#define zolty_led 4 // pin diody led
#define zielony_led 3 // pin diody led

// zmienne:
long czas_sygnalu;
int odleglosc;


void setup() {
  // konfiguracja pinow
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(czerwony_led, OUTPUT);
  pinMode(zolty_led, OUTPUT);
  pinMode(zielony_led, OUTPUT);

  lcd.begin(16, 2); // inicjalizacja wyswietlacza lcd
}
void loop() {
  // aktywacja pomiaru odleglosci
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // odebranie czasu trwania pulsu
  czas_sygnalu = pulseIn(echoPin, HIGH);
  // obliczenie odleglosci w cm
  odleglosc = (czas_sygnalu / 2) / 29.1;

  // ustawienie kursora i wypisanie wartosci odleglosci w cm
  lcd.setCursor(0, 0);
  lcd.print("Odleglosc: ");
  lcd.print(odleglosc);
  lcd.println(" cm");

  if (odleglosc > 100) // jesli odleglosc wieksza niz 100cm to...
  {
    digitalWrite(zielony_led, HIGH); // zalacza zielonego leda
  } else {
    digitalWrite(zielony_led, LOW); // w przeciwnym wypadku go wylacza
  }

  if (odleglosc >= 40 || odleglosc <= 100) // jesli odleglosc miedzy 40cm a 100cm to...
  {
    digitalWrite(zolty_led, HIGH);  // zalacza zoltego leda
  } else {
    digitalWrite(zolty_led, LOW);// w przeciwnym wypadku go wylacza
  }

  if (odleglosc < 40) // jesli odleglosc mniejsza niz 40cm to...
  {
    digitalWrite(czerwony_led, HIGH); // zalacza czerwonego leda
  } else {
    digitalWrite(czerwony_led, LOW); // w przeciwnym wypadku go wylacza
  }
}
