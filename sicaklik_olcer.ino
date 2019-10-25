//İLYAS ATALAY
// LM35 ile sıcaklık ölçümü.

float sicaklik; /* Gerekli değişken oluşturuldu. */
void setup()
{
Serial.begin(9600);
}
void loop()
{
sicaklik = analogRead(A0);
sicaklik = sicaklik * 0.48828125;
Serial.print("SICAKLIK = ");
Serial.print(sicaklik);
Serial.println(" C");
delay(500);
}
