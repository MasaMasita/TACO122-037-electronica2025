// Declare an array without explicitly choosing a size (the compiler
      // counts the elements and creates an array of the appropriate size):
      //int myPins[] = {2, 4, 8, 3, 6, 4};

//un array siempre debe tener el mismo tipo de variable dentro
int numerosLost[] = {4, 8, 15, 16, 23, 42};


void setup() {
  Serial.begin(9600);
  //para usar la variable en un array
  //debo ir a buscarlo con nombreArray[indice]

  //Serial.println(numerosLost[0]);
  //Serial.println(numerosLost[1]);
  //Serial.println(numerosLost[2]);
  //Serial.println(numerosLost[3]);
  //Serial.println(numerosLost[4]);
  //Serial.println(numerosLost[5]);

  

  //evitamos este tedio usando un ciclo for
  //para declarar un ciclo for, tenemos que tener claras 3 cosas
  //1. donde inicia ->  0 -> Para esto se crea una variable local
  //2. donde termina (condición de salida -> 5
  //3. cómo varía -> de 1 en 1

  Serial.println("empezando ciclo for");
  for (int i = 0; i <= 5; i++ ){
    Serial.print("i vale ");
    Serial.print(i);
    Serial.print(" so ");
    Serial.println(numerosLost[i]);
    delay(1000);
  }
  Serial.println("salí del ciclo for");

}

void loop() {
  // put your main code here, to run repeatedly:

}
