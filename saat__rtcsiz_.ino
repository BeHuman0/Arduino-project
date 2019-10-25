//İLYAS ATALAY
// Rtc modül olmadan 4 digit 7 segment saat yapımı.
#include <TimerOne.h>             // arka planda sayaç kullanabilmek için kütüphane eklendi.
int a=6, b=7, c=9, d=10, e=11, f=5, g=4, dp=2, d1=13, d2=12, d3=3, d4=8; /* gerekli değişkenler oluşturuldu. */
void setup() { // giriş pinleri atandı.
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  digitalWrite(dp, LOW);
  Timer1.initialize(1000000);     //1 saniye tetiklenmesi
  Timer1.attachInterrupt(kontrolet); 
}
void rakamyaz(int rakam){        // rakamları kolay yazdırabbilmek için fonksiyon oluşturuldu.
  switch(rakam){                 // switch kullanılarak kolay seçim sağlandı.
    case 0:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    break;
    case 1:
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    break;
    case 2:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    break;
    case 3:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    break;
    case 4:
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
    case 5:
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
    case 6:
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
    case 7:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    break;
    case 8:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
    case 9:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
  }
}
int x =0;                   // sayaç olarak değişkenler oluşturuldu.
int y = 0;
int z = 0;
int q = 0;
void loop() {               // her bir digit ayrı ayrı aktif edildi. 
   digitalWrite(d4, LOW);
   digitalWrite(d3, LOW);
   digitalWrite(d2, LOW); 
   digitalWrite(d1,HIGH);
   rakamyaz(x);
   delay(5);                // 5 milisaniye ile yanım sönerek değerler değiştirildi. Burada karışıklık olmaması için interrupt kullanıldı.
   digitalWrite(d4, LOW);
   digitalWrite(d3,LOW);
   digitalWrite(d2,HIGH);
   digitalWrite(d1,LOW);
   rakamyaz(y);
   delay(5);
   digitalWrite(d4, LOW);
   digitalWrite(d3,HIGH);
   digitalWrite(d2,LOW);
   digitalWrite(d1,LOW);
   rakamyaz(z);
   delay(5);
   digitalWrite(d4, HIGH);
   digitalWrite(d3, LOW);
   digitalWrite(d2, LOW);
   digitalWrite(d1, LOW);
   rakamyaz(q);
   delay(5);
 }
 void kontrolet(){          // Sayaçlar ile rakamlar kontrol edildi ve saat gibi olması ayarlandı.
  x++;
  if(x > 9){
   digitalWrite(d4, LOW);
   digitalWrite(d3,LOW);
   digitalWrite(d2,HIGH);
   digitalWrite(d1,LOW);
   rakamyaz(y++);
  }
  if(y > 5){
   digitalWrite(d4, LOW);
   digitalWrite(d3,HIGH);
   digitalWrite(d2,LOW);
   digitalWrite(d1,LOW);
   rakamyaz(z++);
  }
  if(z > 9){
    digitalWrite(d4, HIGH);
    digitalWrite(d3, LOW);
    digitalWrite(d2, LOW);
    digitalWrite(d1, LOW);
    rakamyaz(q++);
  }
  if(x >9){   // sayaçlar fazla artması durumunda değerleri sıfırlanarak stabil duruma getirildi.
    x = 0;
  }
  if(y >5){
    y = 0;
  }
  if(z >9){
    z = 0;
  }
  if(q >5){
    q ==0;
  }
 }
  
  
