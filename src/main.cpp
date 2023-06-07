#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
/*Esto hay que chekearlo!!!!!!!!!!*/
#define FALSE 0
#define TRUE 1

#define puls 10


LiquidCrystal_I2C lcd(0x3F, 16, 2);

volatile int t = 0;
volatile int estado = 1;

volatile int contador = 0;


void lcd1(){
  lcd.setCursor(0,0);
  lcd.print("Cant de viajes: ");
}
void lcd2(){
  lcd.setCursor(0,0);
  lcd.print("El juego inicia");
  lcd.setCursor(0, 1);
  lcd.print("     en: ");
}
void lcd3(){
  lcd.setCursor(0, 0);
  lcd.print("    A JUGAR!    ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}
void lcd4(){
  lcd.setCursor(0, 0);
  lcd.print("  Felicidades!  ");
  lcd.setCursor(0, 1);
  lcd.print(" Fin del juego! ");
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Esto funciona");
  delay(1000);
  lcd.clear();

  pinMode(puls, INPUT);

  Timer1.initialize(1000);//1ms
  Timer1.attachInterrupt(contando);
}

void loop() {
  switch(estado){
    case 1: lcd1(); break;
    case 2: lcd2(); break;
    case 3: lcde3(); break;
  }
}
if(digitalRead(inicio) == HIGH){
  estado = 1;
}
else{
  estado = 2;
}
if(t <= 0){
  estado = 3;
}
else{
  estado = 2;
}
if(cantViajes != numViajes){
  estado = 3;
}
else{
  estado = 4;
}
if(f_finMensaje == FALSE){
  estado = 4;
}
else{
  estado = 1;
}
