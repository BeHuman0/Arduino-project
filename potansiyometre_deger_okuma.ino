int veri;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
veri = analogRead(A0);
Serial.println((veri*5)/1023.0);
delay(250);
}
