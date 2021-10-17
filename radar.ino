// İLYAS ATALAY 16.07.2019
// Basit radar sistemi ve sesli uyarı.

#include <Servo.h> // servo kütüphanesi eklendi.
const int trigPin = 10; /* mesafe sensörü için değişkenler oluşturuldu. */
const int echoPin = 11;
 int alarm = 9; /* buzzer için pin atayalım */
long duration;
int distance;
Servo myServo; /* servo için nesne oluşturuldu. */

void setup() {
    pinMode(alarm,OUTPUT);
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT);
    Serial.begin(9600); /* seri haberleşmeyi başlatalım. */
    myServo.attach(12); /* servonun bağlı olduğu pin belirtildi. */
}
void loop() { 
    // ilk döngüde servo 15 dereceden 165 dereceye dönerken mesafe hesaplanarak ekrana yazdırıldı.
    for(int i = 15; i <= 165; i++){
        myServo.write(i);
        delay(30);
        distance = calculateDistance();
        Serial.print(i); 
        Serial.print(","); 
        Serial.print(distance);
        Serial.print("."); 
        Serial.println("");
        if (distance != 0){
        tone(alarm, 880);
        delay(20);
        noTone(alarm);  
        }
        
    }

    // ikinci döngüde servo 165 dereceden 15 dereceye dönerken mesafe hesaplanarak ekrana yazdırıldı.
    for(int i = 165; i > 15; i--){ 
        myServo.write(i);
        delay(30);
        distance = calculateDistance();
        Serial.print(i);
        Serial.print(",");
        Serial.print(distance);
        Serial.print(".");
        Serial.println("");
         if (distance != 0){
        tone(alarm, 880);
        delay(20);
        noTone(alarm);
         } 
    }
}

int calculateDistance(){ // mesafe sensörü ile sesin geri geliş hızı kullanılarak mesafe ölçüldü.
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
  
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);/* sesin geri dönme zamanını ölçüyor. */
    distance = duration*0.034/2; /* pulse zamanına göre mesafe ses hızı ile hesaplandı.  */
    return distance;
}
