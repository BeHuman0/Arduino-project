//İLYAS ATALAY
//Kapı giriş şifre sistemi.

#include <Keypad.h>                     //keypad kullanmak için gerekli kütüphane eklendi.

const byte satir = 4;                   //satır ve sutun sayıları belirlendi.
const byte sutun = 4;
char sifre[4]={'1','*','8','#'};        // bir şifre belirlendi.
char giris[4];                          // şifre girişi için dizi oluşturuldu.
int i=0;
char tus_takimi[satir][sutun] = {       //Tuş takımı oluşturuldu.
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte satir_pin[]={10,11,12,13};         // satır ve sutun pinleri girildi.
byte sutun_pin[]={9,8,7,6};

Keypad tuslar = Keypad(makeKeymap(tus_takimi),satir_pin,sutun_pin,satir,sutun); // keypad nesnesi ile keypadimiz oluşturuldu.

void setup() {
  Serial.begin(9600);
  Serial.print("4 haneli sifreyi giriniz:"); // şifre girdisi istendi.
}
void loop() {
  char tus=tuslar.getKey();           // getKey komutu ile tuşa basıldıkça tuşu çekicek.
  Serial.print(tus);
  if(tus){
      giris[i++] = tus;              // tuşa her basılışında giriş dizimize değeri atandı.
    }
    
  if(i == 4){
       delay(100);
       if(strncmp(sifre,giris,4)== 0){ //strncmp komutu ile stringlerin 4 elemanı karşılaştırıldı.
       Serial.println();
       Serial.println("Sifre dogru!kapı açılıyor..."); // esşit ise şifre doğru.
       i=0;
    }
    else
    {
     Serial.println();
     Serial.println("Sifre yanlis! Lütfen tekrar giriniz."); // değil ise şifre yanlış.
     i=0;
    }
  }
}  
