#include <LiquidCrystal.h>
// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define sensor_pin A0 // Define the digital pin connected to the sensor
int sensor_value; // Variable to store the digital value read from the sensor
int ntu; // Variable to store the calculated NTU value
void setup() {
 pinMode(sensor_pin, INPUT); // Set the sensor pin as an input
 lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
 lcd.setCursor(0, 0);
 lcd.print(" Welcome To ");
 lcd.setCursor(0, 1);
 lcd.print("Turbidity Sensor");
 delay(3000); // Display the welcome message for 3 seconds
 lcd.clear();
}
void loop() {
 sensor_value = analogRead(sensor_pin); // Read the digital value from the 
sensor
 if(sensor_value>208)sensor_value=208;
 ntu = map(sensor_value, 0, 208, 300, 0); 
 // Interpret the digital signal
 // Assuming HIGH means high turbidity and LOW means low turbidity
 /*if (sensor_value == HIGH) {
 ntu = 100; // Example value for high turbidity
 } else {
 ntu = 10; // Example value for low turbidity
 }*/
 // Display the turbidity value on the LCD
10
 lcd.setCursor(0, 0);
 lcd.print("Turbidity: ");
 lcd.print(ntu);
 lcd.print(" "); // Clear any leftover characters from previous prints
 // Display the water quality message
 lcd.setCursor(0, 1);
 if (ntu >= 200) {
 lcd.print("Water Very Clean");
} else if (ntu >= 150 && ntu < 200) {
 lcd.print("Water Clean");
} else if (ntu >= 100 && ntu < 150) {
 lcd.print("Water Slightly Dirty");
} else if (ntu >= 50 && ntu < 100) {
 lcd.print("Water Dirty");
} else {
 lcd.print("Water Very Dirty");
}
 delay(1000); // Wait for 1 second before the next reading
}
