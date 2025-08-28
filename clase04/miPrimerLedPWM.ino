#include <Arduino.h>

int ledPin = 9;
int potPin = A0;
int valorPot = 0; 
int potMapeado = 0;

//para escribir valores "grises" en el led
int intensidadLed = 0;

void setup()
{
  	pinMode(ledPin, OUTPUT);
  	Serial.begin(9600);
}

void loop()
{
  	valorPot = analogRead(potPin);
  	//vamos a mapear de 0-1023 a 0-255
  	potMapeado = map(valorPot,0,1023,0,255);
  	intensidadLed = potMapeado;

  	//para escribir en analogo en un led
  	analogWrite(ledPin, intensidadLed);
  	Serial.println(intensidadLed);

}