//----------------------------------------------
//            Luz Automática
//----------------------------------------------

const int sensor=2;  //definimos el sensor
const int luz=12;    //la luz definimos en el pin 12

void setup() 
{
  pinMode(sensor,INPUT);
  pinMode(luz,OUTPUT);
}

void loop()
{

  if(digitalRead(sensor)==HIGH)
  {
    digitalWrite(luz,HIGH);
  }
  else
  {
    digitalWrite(luz,LOW);
  }
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
