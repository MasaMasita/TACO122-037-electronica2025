int contador = 0;
int direccion = 1;
int tasa = 1;

void setup() {
  Serial.begin(9600); // velocidad del puerto serie (debe coincidir con Processing)
}

void loop() {

  contador = contador + tasa*direccion;

  if (contador > 100)
  {
    direccion = -1;
  } else if (contador < 1)
  {
    direccion = 1;
  }

  
  Serial.println(contador);        // envía el valor a Processing
  delay(100);                    // pequeña pausa
}
