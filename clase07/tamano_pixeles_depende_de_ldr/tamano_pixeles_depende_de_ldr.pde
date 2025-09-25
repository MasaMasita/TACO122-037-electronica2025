import processing.video.*;
import processing.serial.*;

Capture cam;
int step = 50; // Tamaño del bloque

//variables que tienen con Serial
Serial miPuerto;   // objeto para la conexión
String datos;      
int valor;

void setup() {
  size(640, 480);
  String[] cameras = Capture.list();
  if (cameras.length == 0) {
    println("No se detectaron cámaras.");
    exit();
  } else {
    cam = new Capture(this, cameras[0]); // Para Processing 4
    cam.start();
  }
  textAlign(CENTER, CENTER);
  textSize(10);
  noStroke();
  
  //Imprime nombres puertos usb Serial disponibles
    println(Serial.list());              // lista los puertos disponibles
  // acá deberíamos poner el puerto donde está conectado el arduino
  //////////////
  miPuerto = new Serial(this, "/dev/cu.usbmodem11301", 9600);
  /////////////
  miPuerto.bufferUntil('\n');          // lee hasta salto de línea

}

void draw() {
  if (cam.available()) cam.read();
  cam.loadPixels();
  background(0);

  for (int y = 0; y < cam.height; y += step) {
    for (int x = 0; x < cam.width; x += step) {
      //acá hacemos que el tamaño de los px
      //dependa del valor recibido desde Arduino
      step = valor/10;
      int index = x + y * cam.width;
      color c = cam.pixels[index];

      // Calcular brillo (0–100 en Processing)
      float b = brightness(c);

      // Fondo en escala de grises
      fill(b);
      rect(x, y, step, step);

      // Texto: blanco en bloques oscuros, negro en bloques claros
      fill(b < 50 ? 255 : 0);
      text(int(b),x+step/2,y + step/2);
    }
  }
}

void serialEvent(Serial miPuerto) {
  datos = miPuerto.readStringUntil('\n');  // lee la línea completa
  if (datos != null) {
    datos = trim(datos);                   // limpia espacios
    valor = int(datos);                    // convierte a número
  }
  println(valor);

}
