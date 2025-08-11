#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define sensor_pin A0 // Define the analog pin connected to the sensor

int sensor_value; // Variable to store the value read from the sensor
int ntu;          // Variable to store the calculated NTU value

void setup() {
  pinMode(sensor_pin, INPUT); // Set the sensor pin as input
  
  lcd.begin(16, 2); // Initialize the LCD (16 columns x 2 rows)
  
  lcd.setCursor(0, 0);
  lcd.print(" Welcome To ");
  
  lcd.setCursor(0, 1);
  lcd.print("Turbidity Sensor");
  
  delay(3000); // Display welcome message for 3 seconds
  lcd.clear();
}

void loop() {
  // Read the value from the turbidity sensor
  sensor_value = analogRead(sensor_pin);
  
  // Limit sensor reading to a maximum of 208
  if (sensor_value > 208) {
    sensor_value = 208;
  }
  
  // Map the sensor reading to NTU values (0–300 range)
  ntu = map(sensor_value, 0, 208, 300, 0);
  
  // Display NTU value
  lcd.setCursor(0, 0);
  lcd.print("Turbidity: ");
  lcd.print(ntu);
  lcd.print(" "); // Clear extra characters from previous readings
  
  // Display water quality message based on NTU value
  lcd.setCursor(0, 1);
  if (ntu >= 200) {
    lcd.print("Water Very Clean   ");
  } else if (ntu >= 150 && ntu < 300) {
    lcd.print("Water Clean        ");
  } else if (ntu >= 100 && ntu < 150) {
    lcd.print("Water Slightly Dirty");
  } else if (ntu >= 50 && ntu < 100) {
    lcd.print("Water Dirty        ");
  } else {
    lcd.print("Water Very Dirty   ");
  }
  
  delay(1000); // Wait 1 second before the next reading
}

🧪 How to Get the Output
Install Arduino IDE
Download from: https://www.arduino.cc/en/software

Connect Your Arduino
Use a USB cable to connect Arduino to your computer.

Upload the Code

Open Arduino IDE

Paste the code above

Select Tools → Board → Arduino Uno

Select Tools → Port → [Your Arduino Port]

Click Upload

Observe the LCD Output

The LCD will display NTU: <value>

If value ≤ 298 NTU, water is CLEAN

If value > 298 NTU, water is DIRTY


