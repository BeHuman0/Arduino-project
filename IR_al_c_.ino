//İLYAS ATALAY
//IR alıcı ve kumanda ile led kontrolü.

#include <IRremote.h>      //IR remote için gerekli kütüphane yüklendi.
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);   // IR alıcı sensörü giriş pini tanımlandı.
decode_results results;    // alınan  değer için result  oluşturuldu.

// Kumandanın tuşları gelen sinyale göre tanımlandı.
#define CH1 0xFFA25D
#define CH 0xFF629D
#define CH2 0xFFE21D
#define PREV 0xFF22DD
#define NEXT 0xFF02FD
#define PLAYPAUSE 0xFFC23D
#define VOL1 0xFFE01F
#define VOL2 0xFFA857
#define EQ 0xFF906F
#define BUTON0 0xFF6897
#define BUTON100 0xFF9867
#define BUTON200 0xFFB04F
#define BUTON1 0xFF30CF
#define BUTON2 0xFF18E7
#define BUTON3 0xFF7A85
#define BUTON4 0xFF10EF
#define BUTON5 0xFF38C7
#define BUTON6 0xFF5AA5
#define BUTON7 0xFF42BD
#define BUTON8 0xFF4AB5
#define BUTON9 0xFF52AD

int led1 = 10;            // Yakacağımız ledlerin pinleri tanımlandı.
int led2 = 11;
int led3 = 12;
int led4 = 13;
int ledler[4]={led1,led2,led3,led4};
int sayac =0;
void setup()
{                         // Çıkışlar atandı ve IR kullanımı başlatıldı. 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  irrecv.enableIRIn();
}
void loop() {
  if (irrecv.decode(&results))   // Veri aldıkça çalıştırması için ayarlandı.
  {
    if (results.value == BUTON1) /* 1.ledi açıp kapatır.*/
    {
      digitalWrite(led1, !digitalRead(led1));
      if (digitalRead(led1) == HIGH)
      {
        sayac++;
      }
      else
      {
        sayac--;
      }
    }
    if (results.value == BUTON2) /* 2. ledi açar kapatır.*/
    {
      digitalWrite(led2, !digitalRead(led2));
      if (digitalRead(led2) == HIGH)
      {
        sayac++;
      }
      else
      {
        sayac--;
      }
    }
    if (results.value == BUTON3)/*3. ledi açar kapatır. */
    {
      digitalWrite(led3, !digitalRead(led3));
      if (digitalRead(led3) == HIGH)
      {
        sayac++;
      }
      else
      {
        sayac--;
      }
    }
    if (results.value == BUTON4) /* 4. ledi açar kapatır. */
    {
      digitalWrite(led4, !digitalRead(led4));
      if (digitalRead(led4) == HIGH)
      {
        sayac++;
      }
      else
      {
        sayac--;
      }
    }
    if (results.value == BUTON0) /* Tüm ledleri kapatır.*/
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      sayac = 0;
    }
    if (results.value == BUTON5)/* Tüm ledleri yakar. */
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      sayac = 4;
    }
    if(results.value == BUTON6)/*soldan sağa ledleri yakar kapatır*/
    {
      for(int i=0;i<4;i++)
      {
        digitalWrite(ledler[i],!digitalRead(ledler[i]));
        delay(200);
        if(digitalRead(ledler[i]) == HIGH)
        {
          sayac=4; 
        }
        if(digitalRead(ledler[i]) == LOW)
        {
          sayac=0; 
        }
      }
    }
    if(results.value == BUTON7)/*sağdan sola ledleri yakar kapatır.*/
    {
      for(int i=4;i>=0;i--)
      {
        digitalWrite(ledler[i],!digitalRead(ledler[i]));
        delay(200);
        if(digitalRead(ledler[i]) == HIGH)
        {
          sayac=4; 
        }
        if(digitalRead(ledler[i]) == LOW)
        {
          sayac=0; 
        }
      }
    }
    if(results.value == BUTON8)8/*solsan sağa ledleri yakar sağdan sola kapatır.*/
    {
      for(int i=0;i<4;i++)
      {
        digitalWrite(ledler[i],!digitalRead(ledler[i]));
        delay(200);
      }
      for(int k=4; k>=0;k--){
        digitalWrite(ledler[k],!digitalRead(ledler[k]));
        delay(200);
      }       
    } 
    if (results.value == VOL2)/*bastıkça ledleri sırayla yakar.*/
    {
      digitalWrite(ledler[sayac], HIGH);
      sayac++;
      }
   if(results.value == VOL1)/*bastıkça ledleri sırayla söndürür.*/
    {
      digitalWrite(ledler[sayac],LOW);
      sayac--;
   }
   if(sayac == 4)/*led sıraları için oluşturulan sayac 4'e gelince sıfırlanır. */
   {
     sayac == 0;
   } 
   irrecv.resume(); /* tuş girişini devam ettirir. */
  }
}
