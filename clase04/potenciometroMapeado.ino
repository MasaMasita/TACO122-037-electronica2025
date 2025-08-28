int potPin = A0;

int valorPot = 0; 

//vamos a guardar la variable del nuevo
//rango del potenciometro
int potMapeado = 0;

void setup()
{
	Serial.begin(9600);  
}

void loop()
{

  	valorPot = analogRead(potPin);
  	//guardamos el mapeo en la variable potMapeado
  //con la función map(); que funciona así 
  //map(valorAConvertir, minimoInicial,maximoInicial,minimoFinal,maximoFinal);
  	potMapeado = map(valorPot,0,1023,0,100);

	Serial.println(potMapeado);
}