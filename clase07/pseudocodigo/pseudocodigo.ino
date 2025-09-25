//pseudocodigo

// DECLARAR variables
// definir donde voy a guardar mi información
// qué información se va a utilizar

// ¿qué necesito para declarar una variable?
// el tipo de variable
// tipo de almacenamiento (número pequeño, número grande, sí o no, 
// palabra, caracter, etc)
// si tiene comas, debo usar float
// si son palabras, String
// si son sí o no: bool 
// es saludable inicializar las variables un algún número
//en general se hace antes del setup()

int contador = 0;
int pinLed = 9; //pin donde conectaría un led

int pinPot = A0; //pin donde hay un potenciómetro

int informacion = 0; //variable donde guardaré la información del mundo

void setup() {
  //inicializar, preparar lo que luego va a ser utilizado

  //inicializamos que queremos trabajar con el serial
  Serial.begin(9600)

  //decidimos sí los pines van a ser inputs o outputs
  // si escribo información hacia fuera, ¿dónde se escribe?
  pinMode(pinLed, OUTPUT)

  //recordad que los analogIn no deben ser inicializados como entradas

}

void loop() {
  
  // usar variable para guardar la información del mundo
  informacion = analogRead(A0);

  //ahora informacion conoce el mundo (en este caso, de 0 a 1023)

  //actualizar, administrar, operar, preguntar a la información que estoy recibiendo

  //es mayor o menor que otra cosa?
  // quiero que sea proporcional a otro rango?
  // quiero saber en qué lugar está?


  comparar();

  //finalmente, uso la información

  //por ejemplo, muestra el numero de contador en una pantallita
  display.pantallita(informacion)

  //o quiero que un led se prenda según la informacion
  digitalWrite(pin del led, informacion);
}

void comparar (){
  //quiero saber si es mayor o menor que un umbral
  int umbral = 100;
  if (informacion >= umbral){
    //haz algo

    //por ejemplo, hagamos que contador crezca de uno en 1
    contador = contador + 1;
  } else {
    //haz otra cosa

    //que el contador baje
    contador = contador - 1;
  }
}