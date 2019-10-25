#include <SPI.h>                          //SPI kütüphanemizi tanımlıyoruz.
#include <MFRC522.h>                      //MFRC522 kütüphanemizi tanımlıyoruz.
                       
int RST_PIN = 9;                          //RC522 modülü reset pinini tanımlıyoruz.
int SS_PIN = 10;                          //RC522 modülü chip select pinini tanımlıyoruz.
                              
MFRC522 rfid(SS_PIN, RST_PIN);            //RC522 modülü ayarlarını yapıyoruz.
byte ID[4] = {57,63,36,22};               //Yetkili kart ID'sini tanımlıyoruz. 
void setup() { 
  pinMode(6,OUTPUT);
  Serial.begin(9600);                     //Seri haberleşmeyi başlatıyoruz.
  SPI.begin();                            //SPI iletişimini başlatıyoruz.
  rfid.PCD_Init();                        //RC522 modülünü başlatıyoruz.
}
void loop() {
  if ( ! rfid.PICC_IsNewCardPresent())    //Yeni kartın okunmasını bekliyoruz.
    return;
  if ( ! rfid.PICC_ReadCardSerial())      //Kart okunmadığı zaman bekliyoruz.
    return;
  if (rfid.uid.uidByte[0] == ID[0] &&     //Okunan kart ID'si ile ID değişkenini karşılaştırıyoruz.
    rfid.uid.uidByte[1] == ID[1] && 
    rfid.uid.uidByte[2] == ID[2] && 
    rfid.uid.uidByte[3] == ID[3] ) {
        Serial.println("Kapi acildi");
        ekranaYazdir();
        for(int i=0;i<3;i++){
        tone(6,850);               
        delay(1000);
        noTone(6);                 
        delay(100);
        }
    }
    else{                                 //Yetkisiz girişte içerideki komutlar çalıştırılır.
      Serial.println("Yetkisiz Kart");
      ekranaYazdir();
    }
  rfid.PICC_HaltA();
}
void ekranaYazdir(){
  Serial.print("ID Numarasi: ");
  for(int sayac = 0; sayac < 4; sayac++){
    Serial.print(rfid.uid.uidByte[sayac]);
    Serial.print(" ");
  }
  Serial.println("");
}
