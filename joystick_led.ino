//İLYAS ATALAY
//Joystick ile led koltrolü.
int UD = 0;
int LR = 0;

/* Arduino çıkış pinleri */

int DWN = 13;
int UP = 12;
int LEFT = 11;
int RT = 10;

/*Arduino giriş pinleri */

int IUP=A0;
int ILR=A1;
int MID = 10; // 10 merkez olarak ayarlandı.
int LRMID = 0;
int UPMID = 0;

void setup(){ //Pinlerin giriş çıkışları atanıyor.
pinMode(DWN, OUTPUT);
pinMode(UP, OUTPUT);
pinMode(LEFT, OUTPUT);
pinMode(RT, OUTPUT);
digitalWrite(DWN, HIGH);
digitalWrite(UP, HIGH);
digitalWrite(LEFT, HIGH);
digitalWrite(RT, HIGH);

//merkez ayarı

LRMID = analogRead(ILR);
UPMID = analogRead(IUP); }

void loop(){
UD = analogRead(IUP);
LR = analogRead(ILR);

// Yukarı - Aşağı

if(UD < UPMID - MID){
digitalWrite(DWN, HIGH);
}
else{
digitalWrite(DWN, LOW);
}
if(UD > UPMID + MID)
{ digitalWrite(UP, HIGH);
}
else{
digitalWrite(UP, LOW);
} // Sol - Sağ
if(LR < LRMID - MID){
digitalWrite(LEFT, HIGH);
}
else{
digitalWrite(LEFT, LOW);
}

if(LR > LRMID + MID){
digitalWrite(RT, HIGH);
}
else{
digitalWrite(RT, LOW);
}
delay(50);
}
