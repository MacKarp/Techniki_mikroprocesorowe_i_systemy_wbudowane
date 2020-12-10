#include <LiquidCrystal.h>
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

byte pin_row[ROW_NUM] = {4, 5, 6, 7}; // piny podlaczonych wierszy klawiatury
byte pin_column[COLUMN_NUM] = {0, 1, 1, 3}; // piny podlaczonych wkolumn klawiatury

Keypad keypad = Keypad( makeKeymap(keys), pin_row, pin_column, ROW_NUM, COLUMN_NUM ); //tworzenie mapy klawiatury

LiquidCrystal lcd(8, 9, 10, 11, 12, 13); // konfiguracja pinow wyswietlacza lcd

// zmienne
long Liczba1, Liczba2, LiczbaWynik;
char key, akcja;
boolean rowna_sie = false;

void setup() {
  lcd.begin(16, 2); // inicjalizacja wyswietlacza lcd
}

void loop() {

  key = keypad.getKey(); // wczytanie wcisnietego klawisza

  if (key != NO_KEY) // jesli wcisniety klawisz to..
    obslugaKlawiatury(); // przejdz do funkcji obslugi klawiatury

  if (rowna_sie == true) // jesli rowna_sie (wcisniety klawisz #) to...
    obliczWynik(); // przejdz do funkcji obliczajacej wynik

  wyswietlWynik(); // przejdz do funkcji wyswietlajacej wynik na ekranie lcd
}

// funkcja obslugujaca klawiature
void obslugaKlawiatury()
{
  lcd.clear(); //czyszczenie ekranu

  if (key == '0') // jesli wcisniety klawisz 0 to...
  {
    if (LiczbaWynik == 0)
      LiczbaWynik = 0;
    else
      LiczbaWynik = (LiczbaWynik * 10) + 0; // w przypadku kolejnego nacisniecia
  }

  if (key == '1') // jesli wcisniety klawisz 1 to...
  {
    if (LiczbaWynik == 0)
      LiczbaWynik = 1;
    else
      LiczbaWynik = (LiczbaWynik * 10) + 1; // w przypadku kolejnego nacisniecia
  }

  if (key == '2') //jesli wcisniety klawisz 2 to...
  {
    if (LiczbaWynik == 0)
      LiczbaWynik = 2;
    else
      LiczbaWynik = (LiczbaWynik * 10) + 2; // w przypadku kolejnego nacisniecia
  }

  if (key == '3') //jesli wcisniety klawisz 3 to...
  {
    if (LiczbaWynik == 0)
      LiczbaWynik = 3;
    else
      LiczbaWynik = (LiczbaWynik * 10) + 3; // w przypadku kolejnego nacisniecia
  }

  if (key == '4') //jesli wcisniety klawisz 4 to...
  {
    if (LiczbaWynik == 0)
      LiczbaWynik = 4;
    else
      LiczbaWynik = (LiczbaWynik * 10) + 4; // w przypadku kolejnego nacisniecia
  }

  if (key == '5') //jesli wcisniety klawisz 5 to...
  {
    if (LiczbaWynik == 0)
      LiczbaWynik = 5;
    else
      LiczbaWynik = (LiczbaWynik * 10) + 5; // w przypadku kolejnego nacisniecia
  }

  if (key == '6') //jesli wcisniety klawisz 6 to...
  {
    if (LiczbaWynik == 0)
      LiczbaWynik = 6;
    else
      LiczbaWynik = (LiczbaWynik * 10) + 6; // w przypadku kolejnego nacisniecia
  }

  if (key == '7') //jesli wcisniety klawisz 7 to...
  {
    if (LiczbaWynik == 0)
      LiczbaWynik = 7;
    else
      LiczbaWynik = (LiczbaWynik * 10) + 7; // w przypadku kolejnego nacisniecia
  }

  if (key == '8') //jesli wcisniety klawisz 8 to...
  {
    if (LiczbaWynik == 0)
      LiczbaWynik = 8;
    else
      LiczbaWynik = (LiczbaWynik * 10) + 8; // w przypadku kolejnego nacisniecia
  }

  if (key == '9') //jesli wcisniety klawisz 9 to...
  {
    if (LiczbaWynik == 0)
      LiczbaWynik = 9;
    else
      LiczbaWynik = (LiczbaWynik * 10) + 9; // w przypadku kolejnego nacisniecia
  }

  if (key == '*') // jesli wcisnięty klawisz * to wyzeruj..
  {
    LiczbaWynik = Liczba1 = Liczba2 = 0;
    rowna_sie = false;
  }

  if (key == '#') // jesli wcisniety klawisz # to ustaw zmienna do obliczenia wyniku...
  {
    Liczba2 = LiczbaWynik;
    rowna_sie = true;
  }

  if (key == 'A' || key == 'B' || key == 'C' || key == 'D') //jesli wcisniety klawisz A, B, C lub D to..
  {
    Liczba1 = LiczbaWynik;
    LiczbaWynik = 0;

    if (key == 'A') // jesli wcisnieto klawisz A to...
    {
      akcja = '+'; // ustaw akcje na dodawanie
    }
    if (key == 'B') // jesli wcisnieto klawisz B to...
    {
      akcja = '-'; // ustaw akcje na odejmowanie
    }
    if (key == 'C') // jesli wcisnieto klawisz C to...
    {
      akcja = '*'; // ustaw akcje na mnozenie
    }
    if (key == 'D') // jesli wcisnieto klawisz D to...
    {
      akcja = '/'; // ustaw akcje na dzielenie
    }

    delay(100); // poczekaj 100ms
  }

}

// funkcja obliczajaca wynik
void obliczWynik()
{
  if (akcja == '+') // Jesli dodawanie to...
    LiczbaWynik = Liczba1 + Liczba2;

  if (akcja == '-') // Jesli odejmowanie to...
    LiczbaWynik = Liczba1 - Liczba2;

  if (akcja == '*') // Jesli mnozenie to...
    LiczbaWynik = Liczba1 * Liczba2;

  if (akcja == '/') // Jesli dzielenie to...
    LiczbaWynik = Liczba1 / Liczba2;
}

// funkcja wyswietlajaca wynik
void wyswietlWynik()
{
  lcd.setCursor(0, 0);   // ustawia kursor na poczatku pierwszej linii

  // wyswietla na ekranie
  lcd.print(Liczba1);
  lcd.print(akcja);
  lcd.print(Liczba2);

  if (rowna_sie == true)
  {
    // wyswietla wynik
    lcd.print(" =");
    lcd.print(LiczbaWynik);
  }

  lcd.setCursor(0, 1);   // ustawia kursor na poczatku drugiej linii
  lcd.print(LiczbaWynik); // wysietla wprowadzane liczby
}
