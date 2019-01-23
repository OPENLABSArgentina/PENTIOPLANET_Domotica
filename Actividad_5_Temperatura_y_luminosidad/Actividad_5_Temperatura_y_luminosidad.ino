//----------------------------------------------
//     Temperatura y luminosidad
//----------------------------------------------

const int luz_pin = A0;  //deino pin para el sensor de luz
const int temp_pin = A1;  //defino pin para el sensor de temperatura


const int temp_max = 26;  //defino valor maximo para la temperatura
const int luz_noche = 300;  //defino valor maximo para la luminosidad

const int led_luz = 12;  //defino led asociado a la luz
const int led_temp = 11;  //defino el led de alerta para la temperatura


void setup()
{
  //defino puerto serial para la comunicacion
  Serial.begin(9600);
  
  pinMode(led_temp, OUTPUT);
  pinMode(led_luz, OUTPUT);
}

void loop()
{
  //leo el valor del sensor de temperaturo y realizo la conversion a temp
  double temperatura = (3.3 * analogRead(temp_pin) * 100.0) / 1024;
  
  //leo la luminosidad
  int luminosidad=analogRead(luz_pin);

  //imprimo por  puerto serie
  Serial.print("Temp= ");
  Serial.print(temperatura);
  Serial.print(" Lum= ");
  Serial.println(luminosidad);

  //si el valor de temperatura es mayor, activo led
  if (temperatura> temp_max)
  {
    digitalWrite(led_temp, HIGH);
  }
  else
  {
    digitalWrite(led_temp, LOW);
  }
  
  //si valor de luminosidad es mayor al maximo, activa led
  if (luminosidad > luz_noche)
  {
    digitalWrite(led_luz, HIGH);
  }
  else
  {
    digitalWrite(led_luz, LOW);
  }

}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
