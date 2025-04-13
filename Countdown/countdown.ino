#include "Arduino_LED_Matrix.h"
#include "countdown.h" //plik powstały na stronie internetowej do animacji macierzy led
ArduinoLEDMatrix matrix;

#define buzz 9
#define led 8
#define butt 7

void setup() {
  // poniżej załadowałem sekwencje i przypisałem logiczną wartość do pinów
  matrix.begin();
  matrix.loadSequence(countdown1);

  pinMode(butt, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);

  digitalWrite(led, LOW);

  
}

void loop() {

  if (digitalRead(butt) == LOW){
    digitalWrite(led, LOW);
    delay(1000);
    matrix.play(true); // rozpoczęcie sekwencji
    digitalWrite(buzz, HIGH); // jeszcze nie wiem jak zrobić pętlę iteracyjną, więc zadziałałem ctrl+c/ctrl+v; buzzer zmienia swój stan logiczny przez 10 sekund
    delay(100);
    digitalWrite(buzz, LOW);
    delay(900);
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(900);
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(900);
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(900);
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(900);
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(900);
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(900);
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(900);
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(900);
    digitalWrite(buzz, HIGH);
    matrix.play(false); //koniec powtarzania sekwencji, musi być wpisany w tym miejscu, bo inaczej matryca led zaczyna nową sekwencje
    delay(100);
    digitalWrite(buzz, LOW);
    delay(1000);
    digitalWrite(led, HIGH);
    
  }
}
