import processing.video.*;

Capture cam;
PFont font;

// caracteres ordenados de "vacío" a "denso". Cámbialos por letras si quieres.
String charset = " wittgenstein";
int step = 16; // tamaño de celda (px). Aumenta para mejor rendimiento, reduce para más detalle.

void setup() {
  size(640, 480);
  // listamos cámaras (útil para debug)
  // ...
String[] cameras = Capture.list();
if (cameras.length == 0) {
  println("No se detectaron cámaras. Intentando por defecto...");
  cam = new Capture(this, width, height);
} else {
  println("Cámaras disponibles:");
  for (int i = 0; i < cameras.length; i++) println(i + ": " + cameras[i]);
  // ✅ Versión compatible con Processing 4:
  cam = new Capture(this, cameras[0]);
}
cam.start();


  font = createFont("Courier", 16); // mono para mejor alineación
  textFont(font);
  textAlign(LEFT, TOP);
  textSize(step);
  noStroke();
  background(0);
}

void draw() {
  if (cam == null) return;
  if (cam.available()) cam.read();
  cam.loadPixels();

  background(0);

  // Recorremos la imagen en una grilla
  for (int y = 0; y < cam.height; y += step) {
    for (int x = 0; x < cam.width; x += step) {
      int idx = x + y * cam.width;
      color c = cam.pixels[idx];

      // calculamos luminancia aproximada (0..255)
      float r = red(c);
      float g = green(c);
      float b = blue(c);
      float lum = 0.2126*r + 0.7152*g + 0.0722*b;

      // mapear luminancia a un índice en charset (inverso: oscuro -> caracteres densos)
      int ci = int(map(lum, 0, 255, charset.length()-1, 0));
      ci = constrain(ci, 0, charset.length()-1);
      char ch = charset.charAt(ci);

      // pintar usando el color original (o usa fill(lum) para grayscale)
      //fill(c);
      // opcional: variar tamaño con la luminosidad
      //textSize(map(lum, 0, 255, step*1.5, step*0.5));
      text(ch, x, y);
    }
  }
}
