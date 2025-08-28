int potPin = A0;
//creamos una variable donde se va a guardar
//lo que mida nuestro potenciometro
//y lo inicializamos en 0
int valorPot = 0; 

void setup()
{
	Serial.begin(9600);  
}

void loop()
{
  //queremos que valorPot sea dependiente
  //de la lectura del potenciometro
  //que esta conectado en A0;
  	valorPot = analogRead(potPin);
  //para los Analog IN, no tengo que decir
  //que son INPUTS
	Serial.println(valorPot);
}