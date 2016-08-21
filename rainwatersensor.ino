/* Analog input receiver.

Used for rain water sensor. Modified after getting inputs on this from the net.

To use: Connect the Rain water sensor first to the Arduino.
- sprinkle water on the sensor plate - to see the readings on the Serial monitor
- run water on sensor plate - to see rain water warnings, 
- Soak sensor plate - to see the flood message on the serial monitor.

*/

// lowest and highest sensor readings:
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);  
}
void loop() {
  // read the sensor on analog A0:
    int sensorReading = analogRead(A0);
  //DBG :Serial.println ( sensorReading );
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
    int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  // range value:
  switch (range) {
 case 0:    // Sensor getting wet
    Serial.println("Flood");
    break;
 case 1:    // Sensor getting wet
    Serial.println("Rain Warning");
    break;
 case 2:   
    Serial.println("Not Raining");
    break;
  }
  delay(100);  // delay between reads
}
