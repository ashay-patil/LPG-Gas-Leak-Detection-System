#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);


int sensor = A0;
int buzz = 13;
int fan = 9;


void setup() {
  // put your setup code here, to run once:
  pinMode(sensor,INPUT);
  pinMode(buzz,OUTPUT);
  pinMode(fan,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(sensor));
  //lcd.clear();
  if(analogRead(sensor)>=700){
    digitalWrite(buzz,HIGH);
    digitalWrite(fan,LOW);
    lcd.setCursor(0,0);
    lcd.print("GAS LEAKED !");
    delay(3000);
  }
  else{
    digitalWrite(buzz,LOW);
    digitalWrite(fan,HIGH);
    lcd.setCursor(0,0);
    lcd.print("NO GAS leak");
    //delay(3000);
  }
}
