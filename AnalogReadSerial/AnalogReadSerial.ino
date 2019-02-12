int LDRpin = A0;
int LEDpin =9;
int LedCalibration = 4;
int max_value = 100;
int min_value = 10000;

void setup() {
 
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);
  pinMode(LedCalibration, OUTPUT);
  digitalWrite(LedCalibration, HIGH);
  unsigned long start = millis();
  while (millis() - start < 5000) {
    int value = analogRead(LDRpin);
    if(value < min_value)min_value = value;
    if(value > max_value)max_value = value;
  }
  digitalWrite(LedCalibration, LOW);
 
  
}


void loop() {
 
  int sensorValue = analogRead(A0);
  int ledValue = map(sensorValue, min_value, max_value, 0, 255);
  analogWrite (LEDpin, ledValue);
 
  Serial.print(sensorValue);
  Serial.print(", ");
  Serial.print(ledValue);
  Serial.print(", ");
  Serial.print(min_value);
  Serial.print(", ");
  Serial.println(max_value);
  delay(1);        
}
