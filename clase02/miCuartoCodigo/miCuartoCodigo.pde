//las variables se suelen crear
//antes del setup
int cantidad = 0;

void setup() {
  colorMode(HSB);
  //vamos a ajustar el tamaño del lienzo
  size(400, 600);
  //vamos a definir un color de fondo
  //si solo tiene 1 argumento, está en escala de grises
  
  //si quiero en RGB declaro los 3
  background(0,100,255);
  
  //el framerate es por defecto 60
  frameRate(10);
}

void draw() {
  //con el colordeFondo al inicio del draw borro el fondo
  background(mouseY,255,255);
  //y aqui ocurren otras cosas
  line(10, 200, 250, 100);
  line(30, 10, 300, 460);
  
  //para hacer un triangulo
  triangle(25,180,180,360,81, 360);
  
  //para hacer un triangulo con variables
  triangle(cantidad,180,180,360,81, 360);

  textSize(30);
  fill(0); //relleno de negro
  text("hola terricolas", 30, 500);

  //puedo actualizar cantidad de 1 en 1
  cantidad = cantidad + 10 ;

  println(cantidad);
  text("les envio "+ cantidad + " saludos", 30, 530);
  text(frameCount, 30, 550);
}

//SOBRE LAS PRIMITIVAS
//triangle(), rect(), quad(), ellipse(), and arc(). Squares are made with rect() and circles are made with ellipse().
