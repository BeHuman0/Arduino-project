//İLYAS ATALAY
//Bluetooth ile RGB led kontrolü.
int veri;
int led1 = 8;
int led2 = 9;
int led3 = 10;
void setup() 
{
 Serial.begin(9600); // seri haberleşme başlatıldı.
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT); 
}
void loop()
{
  if(Serial.available()>0){ // veri geldiği zaman veri okuyacak.
    veri = Serial.read();
  }
  // girilen değere göre farklı led kombinasyonlarını devreye sokar.
   if(veri == '1'){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3,LOW);
    delay(500);
  }
   else if(veri == '2'){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(500);
  }
  else if(veri == '3'){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(500);
  }
    else if(veri == '4'){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(500);
  }
  else if(veri == '5'){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(500);
  }
  else if(veri == '6'){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(500);
  }
  else if(veri == '7'){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(500);
  }
  else{ //geçersiz değer girince ledleri söndürüyor ve uyarıyor.
    Serial.println("Lütfen geçerli bir seçim yapınız.");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(1000);  
  } 
} 
