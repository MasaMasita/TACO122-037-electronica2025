int ledPin = 7;
int potPin = A0;
int valorPot = 0; 
int potMapeado = 0;

int intervalo = 1000;
bool estadoLed = 0;

unsigned long tiempoActual = 0;
unsigned long tiempoAnterior = 0;

void setup()
{
  	pinMode(ledPin, OUTPUT);
  	Serial.begin(9600);
}

void loop()
{
	tiempoActual = millis();
  
  	valorPot = analogRead(potPin);
  	potMapeado = map(valorPot,0,1023,100,2000);
  	intervalo = potMapeado;
  
  //se declara if(condición >, <, ==, !=) { loquetengapasar; }
  if (tiempoActual - tiempoAnterior > intervalo){
    estadoLed = !estadoLed; //estadoLed cambia a su opuesto
    Serial.println("Se cumplio la condicion");
  	tiempoAnterior = tiempoActual;
  }
  
  //escribo en el led su estado (si es 0 o 1)
  digitalWrite(ledPin, estadoLed);
  Serial.println(intervalo);

}