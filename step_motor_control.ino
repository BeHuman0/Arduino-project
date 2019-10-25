

const int motorPin1 = 8;
const int motorPin2 = 9;
const int motorPin3 = 10;
const int motorPin4 = 11;

int bekleme = 2;

void adim1() {
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(bekleme);
}

void adim2() {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(bekleme);
}

void adim3() {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW);
delay(bekleme);
}

void adim4() {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH);
delay(bekleme);
}

void setup() {

pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);

}

void loop() {

for (int i = 0; i < 512; i++) /* 2048 adım atıyor. 4 adım attırdığımız için 2048%4=512 */
{
adim1();
adim2();
adim3();
adim4();
}

for (int j = 0; j < 512; j++)
{
adim4();
adim3();
adim2();
adim1();
}

}
