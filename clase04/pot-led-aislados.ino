#include <Arduino.h>

int potPin = A0;
int ledPin = 7;
int valorPot = 0; 
int potMapeado = 0;

void setup()
{
  	//pin 7 va a ser una salida
  	pinMode(ledPin,OUTPUT);
	Serial.begin(9600);  
}

void loop()
{

  	valorPot = analogRead(potPin);
  	//guardamos el mapeo en la variable potMapeado
  //con la función map(); que funciona así 
  //map(valorAConvertir, minimoInicial,maximoInicial,minimoFinal,maximoFinal);
  	potMapeado = map(valorPot,0,1023,0,100);
  
  	//vamos a hacer el blink aquí
  	digitalWrite(ledPin, HIGH);
  	delay(1000);
  	digitalWrite(ledPin, LOW);
  	delay(1000);


	Serial.println(potMapeado);
}