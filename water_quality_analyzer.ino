#include <LiquidCrystal.h> 

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
#define sensor_pin A0 

int read_ADC;
int ntu;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Water Quality");
  lcd.setCursor(0, 1);
  lcd.print("Analyzer");
  delay(2000);
  lcd.clear();
}

void loop() {
  read_ADC = analogRead(sensor_pin);

  // Limit ADC value to avoid out-of-range readings
  if (read_ADC > 208) read_ADC = 208;

  // Map ADC value to NTU range
  ntu = map(read_ADC, 0, 208, 300, 0);

  lcd.setCursor(0, 0);
  lcd.print("Turbidity: ");
  lcd.print(ntu);
  lcd.print("  ");

  lcd.setCursor(0, 1);
  if (ntu < 10)            lcd.print("Water Very Clean");
  else if (ntu < 30)       lcd.print("Water Norm Clean");
  else                     lcd.print("Water Very Dirty");

  delay(200);
}
