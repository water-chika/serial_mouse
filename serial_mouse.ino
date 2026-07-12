enum device {
  sunmouse,
  stinger,
  print_value,
};

device device = print_value;

bool enabled = false;

void setup() {
  if (device == sunmouse) {
    Serial.begin(1200);
  }
  else if (device == stinger){
    Serial.begin(1200);
    char response[] = "\r\n0600520058C272";
    Serial.print(response);
    char buf[5] = {};
    Serial.readBytes(buf, 5);
    if (memcmp(buf, " E5E5", 5) == 0) {
      enabled = true;
    }
  }
  else if (device == print_value) {
    Serial.begin(9600);
  }
  while (!Serial);
}

int previous_x, previous_y, previous_z;

void loop() {
  int x = analogRead(A0); // x-axis
  int y = analogRead(A1); // y-axis
  int z = analogRead(A2); // z-axis
  
  if (device == sunmouse) {
    Serial.write(0x87);
    Serial.write((x-512)*128/512/10); // x-axis
    Serial.write(-(y-512)*128/512/10); // y-axis
    Serial.write((x-512)*128/512/10); // x-axis
    Serial.write(-(y-512)*128/512/10); // y-axis
  }
  else if (device == stinger){
    if (previous_x != x || previous_y != y) {
      int x_abs = (x-512)/(512/64);
      int y_abs = ((y-512)/(512/64));
      Serial.write(((y_abs>>5)&0x02) | ((x_abs>>31)&0x01)); // packet - 0
      Serial.write(x_abs&0x3f);
      Serial.write(y_abs&0x3f);
      Serial.write(0);

      previous_x = x;
      previous_y = y;
    }
  }
  else {
    Serial.print("x ");
    Serial.print(x);
    Serial.print("y ");
    Serial.print(y);
    Serial.print("z ");
    Serial.println(z);
  }
  delay(100);
}
