int potPin = A0;
int ledPin = 7;
int valorPot = 0; 
int potMapeado = 0;
//variable para controlar el tiempo de parpadeo
int tiempoParpadeo = 100;

void setup()
{
  	//pin 7 va a ser una salida
  	pinMode(ledPin,OUTPUT);
	Serial.begin(9600);  
}

void loop()
{

  	valorPot = analogRead(potPin);
  	//cambiamos la velocidad de parpadeo
  //de 100 a 2000 ms
  	potMapeado = map(valorPot,0,1023,100,2000);
  
  //vamos a usar para controlar el tiempo, potMapeado
  
  tiempoParpadeo = potMapeado;
  
  	//vamos a hacer el blink aquí
  	digitalWrite(ledPin, HIGH);
  	delay(tiempoParpadeo);
  	digitalWrite(ledPin, LOW);
  	delay(tiempoParpadeo);

	Serial.println(tiempoParpadeo);
}