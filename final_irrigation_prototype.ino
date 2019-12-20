//----------PROTOTYPE_AUTOMATED_IRRIGATION_SYSTEM---------//
#include <DHT.h>//DHT11SENSOR LIBRERY
#include <Keypad.h>//KEYPAD LIBRERY
#include<LiquidCrystal.h>//LCD LIBRERY
LiquidCrystal lcd(4 ,5, 6, 7, 8, 9);//LCD CONNECTIONS
//START KEYPAD CONNECTION
const int r1=13;
const int r2=12;
const int r3=11;
const int r4=10;
const int c1=3;
const int c2=2;
const int c3=1;
//END KEYPAD CONNECTION
void alphkeypad();//KEYPAD FUNCTION
void match();//COMPARING FUNCTION
#define DHTPIN A5 // DHT11 CONNECT TO A3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int SENSE= 1; // Soil Sensor input at Analog PIN A1
int value= 0;
//START OF CROP DATABASE
int cropdatabase[8][5]={
{35,25,90,75,30},//rice
{30,27,90,70,30},//jute
{35,24,85,65,30},//pulses
{35,24,80,60,30},//wheat
{35,24,80,65,30},//silk
{35,19,85,60,30},//vegetables
{27,21,90,70,30},//sugarcane
{20,12,70,60,30} //tea
};
//END OF CROP DATABASE
int k,j,m,p;
char a;
int cropselect[8]={0,0,0,0,0,0,0,0};//ARRAY FOR SELECTING CROP

//SETUP ARDUINO
void setup()
{
lcd.begin(16 , 2);
lcd.setCursor(0, 0);
lcd.print("WELCOME TO PPP");
lcd.setCursor(0,1);
lcd.print("IRRIG. SYSTEM");
delay(5000);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("SUBMITTED BY--");
lcd.setCursor(0,1);
lcd.print("AEIE & EE DEPT");
delay(5000);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("UNDER MR.C.DUTTA");
lcd.setCursor(0,1);
lcd.print("& DR.D.SARKAR");
delay(5000);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("SOIL CHOSEN FROM");
lcd.setCursor(0,1);
lcd.print("KEYPAD ----");
delay(5000);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("SOIL MENU");
lcd.setCursor(0,1);
lcd.print("LOADING......");
delay(5000);
lcd.setCursor(0, 0);
lcd.clear();
lcd.print("1:ALLUV 2:LOAMY");
lcd.setCursor(0,1 );
lcd.print("3:BLACK 4:LATERC");
delay(2000);
pinMode(r1,OUTPUT);
pinMode(r2,OUTPUT);
pinMode(r3,OUTPUT);
pinMode(r4,OUTPUT);
pinMode(c1,INPUT);
pinMode(c2,INPUT);pinMode(c3,INPUT);
dht.begin();
}

//ARDUINO LOOP FUNCTION
void loop()
{
int i=0;
lcd.setCursor(0, 0);
alphkeypad();
int h = dht.readHumidity();
int t = dht.readTemperature();
lcd.setCursor(0, 0);
lcd.print("Temp:");
lcd.print(t);
lcd.print("C");
delay(100);
lcd.setCursor(9,0);
lcd.print(" RH:");
lcd.print(h);
delay(100);
value= analogRead(SENSE);
value= value/10;
lcd.setCursor(0,3);
lcd.print("SMois:");
lcd.print(value);
delay(9000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("SUITABLE CROPS..");
delay(3000);
lcd.clear();
lcd.setCursor(0,0);
match();
delay(10000);lcd.clear();
lcd.setCursor(0, 0);
lcd.print("PRESS *");
lcd.setCursor(0,1);
lcd.print("TO PRESET MENU");
delay(5000);
}

//KEYPAD FUNCTION
void alphkeypad()
{
a='a';
while(a!='c')
{
digitalWrite(c1,HIGH);
digitalWrite(c2,HIGH);
digitalWrite(c3,HIGH);
digitalWrite(r1,LOW);
digitalWrite(r2,HIGH);
digitalWrite(r3,HIGH);
digitalWrite(r4,HIGH);
if(digitalRead(c1)==LOW)
{
lcd.clear();
lcd.print("ALLUVIAL SOIL");
delay(2000);
a='c';
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("CROPS FOR ALLUV SOIL");
lcd.setCursor(0,1 );
lcd.print("RICE,JUTE&PULSES");
delay(6000);
lcd.clear();
lcd.print("CURR. CLIMATE....");
delay(4000);
lcd.clear();
}
digitalWrite(r1,LOW);
digitalWrite(r2,HIGH);
digitalWrite(r3,HIGH);
digitalWrite(r4,HIGH);
if(digitalRead(c2)==LOW){
lcd.clear();
lcd.print("LOAMY SOIL");
delay(500);
a='c';
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("CROPS FOR LOAMY SOIL");
lcd.setCursor(0,1 );
lcd.print("SILK,VEGE.&WHEAT");
delay(6000);
lcd.clear();
lcd.print("CURR. CLIMATE....");
delay(4000);
lcd.clear();
}
digitalWrite(r1,LOW);
digitalWrite(r2,HIGH);
digitalWrite(r3,HIGH);
digitalWrite(r4,HIGH);
if(digitalRead(c3)==LOW)
{
lcd.clear();
lcd.print("BLACK SOIL");
delay(500);
a='c';
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("CROPS FOR BLACK SOIL");
lcd.setCursor(0, 1);
lcd.print(" SUGARCANE");
delay(6000);
lcd.clear();
lcd.print("CURR. CLIMATE....");
delay(4000);
lcd.clear();
}
digitalWrite(r1,HIGH);
digitalWrite(r2,LOW);
digitalWrite(r3,HIGH);
digitalWrite(r4,HIGH);
if(digitalRead(c1)==LOW){
lcd.clear();
lcd.print("LATERICTIC SOIL");
delay(500);
a='c';
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("CROPS FOR LAT. SOIL");
lcd.setCursor(0, 1);
lcd.print(" TEA");
delay(6000);
lcd.clear();
lcd.print("CURR. CLIMATE....");
delay(4000);
lcd.clear();
}
digitalWrite(r1,HIGH);
digitalWrite(r2,HIGH);
digitalWrite(r3,HIGH);
digitalWrite(r4,LOW);
if(digitalRead(c1)==LOW)
{
lcd.clear();
lcd.print("PLEASE WAIT....");
delay(500);
lcd.setCursor(0, 0);
lcd.clear();
lcd.print("1:ALLUV 2:LOAMY");
lcd.setCursor(0,1 );
lcd.print("3:BLACK 4:LATERC");
a='c';
}
}
}

//COMPARING FUNCTION
void match()
{
int t = dht.readTemperature();
int h = dht.readHumidity();
for(k=0;k<8;k++)
{
p=0;for(j=0;j<5;j++)
{
switch(j)
{
case 0:if(t<=cropdatabase[k][j])
{
p=p+1;
}
break;
case 1:if(t>=cropdatabase[k][j])
{
p=p+1;
}
break;
case 2:if(h<=cropdatabase[k][j])
{
p=p+1;
}
case 3:if(h>=cropdatabase[k][j])
{
p=p+1;
}
break;
case 4:if(value<=cropdatabase[k][j])
{
p=p+1;
}
break;
}
}
if(p==5)
{
cropselect[k]=1;
}
else
{
cropselect[k]=0;
}
}
if(cropselect[0]==0 && cropselect[1]==0 && cropselect[2]==0 &&
cropselect[3]==0 && cropselect[4]==0 && cropselect[5]==0 &&
cropselect[6]==0 && cropselect[7]==0){
lcd.setCursor(0,0);
lcd.print("NOT MATCHED...");
delay(5000);
lcd.clear();
}
else
{
for(m=0;m<8;m++)
{
if(cropselect[m]==1)
{
if(m==0)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("RICE");
delay(5000);
}
if(m==1)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("JUTE");
delay(5000);
}
if(m==2)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PULSE");
delay(5000);
}
if(m==3)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("WHEAT");
delay(5000);
}
if(m==4)
{
lcd.clear();
lcd.setCursor(0,0);lcd.print("SILK");
delay(5000);
}
if(m==5)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("VEGETABLES");
delay(5000);
}
if(m==6)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("SUGARCANE");
delay(5000);
}
if(m==7)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("TEA");
delay(5000);
}
}
}
}
}

