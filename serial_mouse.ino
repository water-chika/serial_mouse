
void setup() {
  Serial.begin(1200);
}

void loop() {
  Serial.write(0x87);
  Serial.write(0x02);
  Serial.write(0x02);
  Serial.write(0x02);
  Serial.write(0x02);
  delay(100);
}
