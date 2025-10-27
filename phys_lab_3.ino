void setup() {
   
  
  Serial.begin(9600);

  // The heater resistor will be controlled by a PWM pin.
  pinMode(9, OUTPUT);
}

// The loop() function runs over and over so whatever is contained
// therein will be repeated while the Arduino is on. 

void loop() {
  
  // The function analogRead() will
  // read the input on analog pins:
  // A0 for the thermistor, A1 for the potentiometer
  
  int thermValue = analogRead(A0);
  int potValue = analogRead(A1);
  
  // Map potentiometer reading (0–1023) to PWM range (0–255)
  
  int heaterPower = map(potValue, 0, 1023, 0, 255);
  
  // Write the PWM signal to the heater control pin
  
  analogWrite(9, heaterPower);
  
  // Add time to the serial output and print values separated by commas:
  // time, potentiometer, thermistor
  
  Serial.print(millis());
  Serial.print(',');
  Serial.print(potValue);
  Serial.print(',');
  Serial.println(thermValue);
  
  // Delay for 200 milliseconds between each loop
  
  delay(200);
}
