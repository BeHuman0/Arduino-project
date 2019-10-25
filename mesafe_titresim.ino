int trigPin = 2; /* Sensorun trig pini Arduinonun 2 numaralı ayağına bağlandı */
int echoPin = 3;  /* Sensorun echo pini Arduinonun 3 numaralı ayağına bağlandı */
int butonPin =4;
 
long sure; /* süre ve uzaklık için değişken oluşturuldu. */
long uzaklik; 

void setup(){
  pinMode(10, OUTPUT); /* motor için gerekli pinler atandı. */
  pinMode(butonPin, INPUT);
  pinMode(trigPin, OUTPUT); /* trig pini çıkış olarak ayarlandı */
  pinMode(echoPin,INPUT); /* echo pini giriş olarak ayarlandı */
  Serial.begin(9600); /* Seri haberlesme baslatildi */
}
void loop()
{
  if(digitalRead(butonPin) == HIGH) {
  digitalWrite(trigPin, LOW); /* sensör pasif hale getirildi */
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); /* Sensore ses dalgasının üretmesi için emir verildi */
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  /* Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi */ 
  sure = pulseIn(echoPin, HIGH); /* ses dalgasının geri dönmesi için geçen sure ölçülüyor */
  uzaklik= sure /29.1/2; /* ölçülen sure uzaklığa çevriliyor */            
  if(uzaklik > 200)
  {
    uzaklik = 200; /* maksimum uzaklık 200 cm ayarlandı. */
  }
  
  if(uzaklik >= 20) 
  {
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(10,LOW);
  }
  if(uzaklik <= 15) 
  {
    digitalWrite(10, HIGH);
    delay(300);
    digitalWrite(10,LOW);
  }
  if(uzaklik <= 10)
  {
    digitalWrite(10, HIGH);
    delay(500);
    digitalWrite(10,LOW);
  }
  if(uzaklik <= 5) 
  {
    digitalWrite(10, HIGH);
 
  }
  Serial.print("Uzaklik ");  
  Serial.print(uzaklik);  /* hesaplanan uzaklık bilgisayara aktarılıyor */
  Serial.println(" CM olarak olculmustur.");  
  delay(50); 
  }
  else
  {
   Serial.println("Başlatmak için anahtarı açınız.");
  }
}
