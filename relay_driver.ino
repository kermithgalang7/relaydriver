void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial.println();
  Serial.println("Relay Driver");

  pinMode(LED_BUILTIN, OUTPUT);
}

int sensorValue; 

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second

  sensorValue = analogRead(A0);
  Serial.print("Sensor Value : ");
  Serial.println(sensorValue);

  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second  
}
