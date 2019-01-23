//----------------------------------------------
//     Activando luces desde la PC
//----------------------------------------------

const int led_verde = 12;  //defino pin led verde
const int led_amarillo = 11;   //defino pin led amarillo
const int led_rojo = 10;   //defino pin rojo

void setup()
{
  //inicializo puerto serial
  Serial.begin(9600);

  //defino los pines como salida
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_rojo, OUTPUT);

}

void loop()
{
  //chequeo si hay informacion en el puerto serial
  if (Serial.available()>0)
  {
    //leo el valor y lo cargo con en variable
    int lectura = Serial.read();

    //el el switch analizo la letra que nos llega por serial
    switch (lectura)
    {
      case 'a':  //caso 'a' prendo led amarillo
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarillo, HIGH);
        digitalWrite(led_rojo, LOW);
        Serial.println("Amarillo Activado");
        break;

      case 'v': //caso 'v' prendo led verde
        digitalWrite(led_verde, HIGH);
        digitalWrite(led_amarillo, LOW);
        digitalWrite(led_rojo, LOW);
        Serial.println("Verde Activado");
        break;

      case 'r': //caso 'r' prendo led rojo
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarillo, LOW);
        digitalWrite(led_rojo, HIGH);
        Serial.println("Rojo Activado");
        break;

      default :  //cualquier otro caso 
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarillo, LOW);
        digitalWrite(led_rojo, LOW);
        Serial.println("Todos Apagados");
        break;
    }
    lectura = Serial.read();
  }

}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
