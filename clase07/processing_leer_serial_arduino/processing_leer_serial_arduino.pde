import processing.serial.*;

Serial miPuerto;   // objeto para la conexión
String datos;      
int valor;

void setup() {
  size(400, 200);
  println(Serial.list());              // lista los puertos disponibles
  miPuerto = new Serial(this, "/dev/cu.usbmodem1101", 9600); 
  miPuerto.bufferUntil('\n');          // lee hasta salto de línea
}

void draw() {
  
  // en esta sección debería usar de alguna manera la variable "valor"
  background(200);
  fill(50);
  ellipse(width/2, height/2, valor,valor);    // dibuja una barra con el valor
}

void serialEvent(Serial miPuerto) {
  datos = miPuerto.readStringUntil('\n');  // lee la línea completa
  if (datos != null) {
    datos = trim(datos);                   // limpia espacios
    valor = int(datos);                    // convierte a número
  }
  println(valor);
}
