//----------------------------------------------
//     Detectando Intrusos
//----------------------------------------------

const int sensor=2;  //defino pin para el sensor
const int alarma=12;  //defino pin para el parlante

void setup() 
{
  pinMode(sensor,INPUT_PULLUP); //sensor como entrada
  pinMode(alarma,OUTPUT);  //parlante defino como salida
}

void loop()
{
  
  if(digitalRead(sensor)==HIGH)
  {
    digitalWrite(alarma,HIGH);
    delay(300);
    digitalWrite(alarma,LOW);
    delay(300);
  }
  else
  {
    digitalWrite(alarma,LOW);
  }
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
