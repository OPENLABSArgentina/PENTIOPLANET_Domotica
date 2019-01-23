//----------------------------------------------
//     Cuidando las plantas
//----------------------------------------------

const int sensor_pin = A0;  //defino donde va el sensor de humedad

const int humedad_limite = 500;  //valor minimo a partir del cual activa

const int led_verde= 12;   //pin del led verde
const int led_rojo = 11;  //pin del led rojo
const int buzzer = 10;  //pin del buzzer

void setup()
{
  Serial.begin(9600);  //defino puerto serial
  
  pinMode(led_verde, OUTPUT);
  pinMode(led_rojo, OUTPUT);
   pinMode(buzzer, OUTPUT);
}

void loop()
{
  //leo el valor del sensor y lo cargo en variable
  int humedad=analogRead(sensor_pin);

  //imprimo por puerto serie
  Serial.print("Humedad= ");
  Serial.println(humedad);

   //si el valor de humedad mayor a humedad limite, emitir alarma
  if (humedad > humedad_limite)
  {
    digitalWrite(led_rojo, HIGH);
    digitalWrite(led_verde, LOW);
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(300);
  }
  //caso contrario no hace falta alarma
  else
  {
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_rojo, LOW);
  }

}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
