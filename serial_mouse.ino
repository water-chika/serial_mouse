
void setup() {
  Serial.begin(1200);
}

void loop() {
  int x = analogRead(A0); // x-axis
  int y = analogRead(A1); // y-axis
  int z = analogRead(A2); // z-axis
  Serial.write(0x87);
  Serial.write((x-512)*128/512/10); // x-axis
  Serial.write(-(y-512)*128/512/10); // y-axis
  Serial.write((x-512)*128/512/10); // x-axis
  Serial.write(-(y-512)*128/512/10); // y-axis
  delay(100);
}
