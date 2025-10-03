String palabra1 = "soy un encoder";

String poema[] = {
"Luz parpadea ya",  
"tengo hambre de pizza hoy",  
"la silla cruje"
};

int contador = 0;
int cualLinea = 0;

//int tiempoCambio = 1000;

void setup() {
  size(300, 600);
  colorMode(HSB, 360, 100, 100, 100);

  textSize(20);
  fill(0, 100, 0, 100);
  textAlign(CENTER);
}

void draw() {
  if (frameCount%120 == 0){
    contador++;
  }
    
  cualLinea = contador%3;
  background(frameCount%360, 50, 100, 100);

  fill(360-frameCount%360, 50, 100, 100);
  text(poema[cualLinea], width/2, height/2);
  
}
