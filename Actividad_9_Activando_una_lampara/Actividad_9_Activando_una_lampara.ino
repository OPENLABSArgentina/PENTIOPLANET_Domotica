//----------------------------------------------
//         Activando una lampara a 220
//----------------------------------------------

#include <Wire.h>    //declaro librerias necesarios para el LCD
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3D, 16, 2);  //defino direccion y tipo de lcd

const int pulsador = 2;  //defino pin donde va conectado el pulsador
const int pin_rele = 12;  //defino donde va conectado el rele


void setup()
{
  lcd.init();   //inicializo rele
  lcd.backlight();  //activo luz del rele

  pinMode(pulsador, INPUT_PULLUP);  //defino pulsador como entrada
  pinMode(pin_rele, OUTPUT);   //defino pin rele como salida

}

void loop()
{
  if (digitalRead(pulsador) == LOW)  //si el boton esta pulsado
  {
    lcd.setCursor(0, 0);            //borro pantalla
    lcd.print("Sistema Domotico");  //imprimo texto en fila superior
    lcd.setCursor(0, 1);
    lcd.print("Rele= Activado  ");  //imprimo texto en fila inferior
    digitalWrite(pin_rele, LOW);    //activo el rele
    delay(100);
  }

  else
  {
    lcd.setCursor(0, 0);             //borro pantalla
    lcd.print("Sistema Domotico");   //imprimo texto en fila superior
    lcd.setCursor(0, 1);
    lcd.print("Rele=Desactivado");   //imprimo texto en fila inferior
    digitalWrite(pin_rele, HIGH);   //desactivo el rele
    delay(100);
  }
}
