//----------------------------------------------
//         Agregando Interfaz
//----------------------------------------------

#include <Wire.h>    //defino librerias necesarias para el LCD
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3D, 16, 2);  //defino dirección y tipo de LCD

const int pulsador_luz = 2;  //pin donde va conectado el pulzasor luz
const int pulsador_temp = 3; //pin donde va conectado el pulzasor temp
const int sensor_luz = A0;   //pin donde va conectado el sensor luz
const int sensor_temp = A1;  //pin donde va conectado el sensor de temp

void setup()
{
  lcd.init();       //inicializo el LCD
  lcd.backlight();  //activo luz de la pantalla

  pinMode(pulsador_temp, INPUT_PULLUP);  //defino pulsador como entrada
  pinMode(pulsador_luz, INPUT_PULLUP);   //defino pulsador como entrada

  lcd.setCursor(0, 0);  //me ubica a partir de donde vamos a imprimir
  lcd.print(" Presione Boton ");   //imprimo texto en parte superior
  lcd.setCursor(0, 1);
  lcd.print(" P1=Luz P2=Temp ");   //imprimo texto en parte inferior

}

void loop()
{
  int auxiliar_luz = analogRead(sensor_luz);  //leo sensor de luz
  int valor_luz = map(auxiliar_luz, 0, 1023, 0, 100);  //convierto la entrada en valores de porcentaje

  int auxiliar_temp = analogRead(sensor_temp);  //leo sensor de temperatura
  int valor_temperatura = (3.3 * auxiliar_temp * 100.0) / 1024;  //convierto el valor leido en grados C

  if (digitalRead(pulsador_luz) == LOW)  //si boton luz, entonces muestro el valor del sensor
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sistema Domotico");
    lcd.setCursor(4, 1);
    lcd.print("Luz=");
    lcd.print(valor_luz);
    delay(100);
  }

  if (digitalRead(pulsador_temp) == LOW)  //si boton temp, entonces muestro el valor del sensor
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sistema Domotico");
    lcd.setCursor(4, 1);
    lcd.print("Temp=");
    lcd.print(valor_temperatura);
    delay(100);
  }


}
