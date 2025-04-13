#include <LiquidCrystal.h>
#include <DHT.h>

#define redled 8
#define greenled 9
#define dhtpin 13
#define dhttype DHT11
DHT dht(dhtpin, dhttype);
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hello");
  lcd.setCursor(0, 1);
  lcd.print("There");
  lcd.cursor();

  dht.begin();

  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  digitalWrite(redled, LOW);
  digitalWrite(greenled, LOW);
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(h) || isnan(t)){
    lcd.setCursor(0,0);
    lcd.print("DHT11 FAILED");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Wilgot.:");
  lcd.print(h);
  lcd.print(" %");

  lcd.setCursor(0, 1);
  lcd.print("Temp.  :");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C");

  if (t >= 24.0){
    digitalWrite(redled, HIGH);
  }

  if (t <= 20.0){
    digitalWrite(redled, HIGH);
  }

  if (h >= 60.0){
    digitalWrite(greenled, HIGH);
  }
  else {
    delay(50);
    digitalWrite(greenled, HIGH);
    delay(50);
    digitalWrite(greenled, LOW);
  }

}
