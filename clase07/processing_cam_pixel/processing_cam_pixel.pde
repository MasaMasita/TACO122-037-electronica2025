import processing.video.*;

Capture cam;
int step = 30; // Tamaño del bloque

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
}

void draw() {
  if (cam.available()) cam.read();
  cam.loadPixels();
  background(0);

  for (int y = 0; y < cam.height; y += step) {
    for (int x = 0; x < cam.width; x += step) {
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
