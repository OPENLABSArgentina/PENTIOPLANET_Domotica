//----------------------------------------------
//            Clave de acceso
//----------------------------------------------

#include <Wire.h>    //defino librerias necesarias para el LCD
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>  //defino libreria para el teclado

LiquidCrystal_I2C lcd(0x3D, 16, 2);  //defino direccion y tipo de LCD

const byte fila = 4;   
const byte columna = 4; 

char hexaKeys[fila][columna] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'F', '0', 'E', 'D'}
};

byte filaPins[fila] =     {9, 8, 7, 6}; 
byte columnaPins[columna] = {5, 4, 3, 2};

byte clave[4]={'2','5','8','0'};
byte aux_clave[4]={0,0,0,0};
int cont=0;

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), filaPins, columnaPins, fila, columna);

void setup()
{
  Serial.begin(9600);

   lcd.init();       //inicializo el LCD
  lcd.backlight();  //activo luz de la pantalla

  
}

void loop()
{
  char customKey = customKeypad.getKey();

   lcd.setCursor(0,0);
   lcd.print("   Ingrese la   "); 
   lcd.setCursor(0,1);
   lcd.print("  Contrasenhia  "); 
   
  if (customKey)
  {
    Serial.println(customKey);
    aux_clave[cont]=customKey;
    cont++;
  }
  if(cont==4)
  {
    if((clave[0]==aux_clave[0])and(clave[1]==aux_clave[1])and(clave[2]==aux_clave[2])and(clave[3]==aux_clave[3]))
    {
      Serial.println("Acceso Permitido");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("    Correcto    "); 
      lcd.setCursor(0,1);
      lcd.print("Acceso Permitido"); 
      delay(2000);
    }
    else
    {
      Serial.println("Acceso Denegado");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("   Incorrecto   "); 
      lcd.setCursor(0,1);
      lcd.print("Acceso Denegado "); 
      delay(2000);
    }
    cont=0;
  }
}
