void setup() {
  
  Serial.begin(9600);

  pinMode(9, OUTPUT);
} 

void loop() {
  
  int thermValue = analogRead(A0);
  int potValue = analogRead(A1);
  
  int heaterPower = map(potValue, 0, 1023, 0, 255);
  
  analogWrite(9, heaterPower);

  // time, potentiometer, thermistor
  Serial.print(millis());
  Serial.print(',');
  Serial.print(potValue);
  Serial.print(',');
  Serial.println(thermValue);
  
  // Delay 
  delay(200);
}
