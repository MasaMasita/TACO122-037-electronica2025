float xPos;   // posición horizontal del triángulo
float vel = 3; // velocidad

void setup() {
  size(600, 400);
  colorMode(HSB, 360, 100, 100); // Modo HSB
  textAlign(CENTER, CENTER);
  textSize(24);
  xPos = 150; // posición inicial
}

void draw() {
  // Fondo HSB: hue según mouseY
  float hueValue = map(mouseY, 0, height, 0, 360);
  background(hueValue, 100, 100);
  
  // Texto principal
  fill(0);
  text("hola terricolas", width/2, 50);
  
  // Texto repetido según frameCount
  int numSaludos = frameCount % 20;
  for (int i = 0; i < numSaludos; i++) {
    text("saludo " + (i+1), width/2, 80 + i * 20);
  }
  
  // Líneas cruzadas
  stroke(0);
  line(0, 0, width, height);
  line(width, 0, 0, height);
  
  // Dibujar triángulo
  noFill();
  stroke(0);
  triangle(xPos, 300, xPos + 100, 300, xPos + 50, 200);
  
  // Mover triángulo
  xPos += vel;
  
  // Rebotar en bordes
  if (xPos < 0 || xPos + 100 > width) {
    vel *= -1;
  }
}
