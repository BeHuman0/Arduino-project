//İLYAS ATALAY
// alev sensörü ile değer okuma.
void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensordegeri = analogRead(A0); // sensör değeri okundu.
  if(sensordegeri <= 800){
    Serial.print("sensör değeri= ");
    Serial.print(sensordegeri);
    Serial.print("  ");
    Serial.print("**Ateş algılandı!**");  /* 800'den küçük olunca ateş olduğu belirtiliyor */ 
  }
  else{
    Serial.print("sensör değeri= ");
    Serial.print(sensordegeri);
    Serial.print("  ");
    Serial.print("**Ateş yok**"); /* 800'den büyük olunca ateş olmadığı belirtiliyor */ 
    
  }
  delay(200);
  
}
