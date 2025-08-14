//para hacer una linea en processing, utilizo una funcion
//llamada line, donde debo decir
//la coordenada x e y de un extremo, y la coordenada del otro
//se declara line(x1,y1,x2,y2);
line(10,20,80,60);
line(30,80,35,5);

//vamos a ajustar el tamaño del lienzo
size(400,600);

//vamos a definir un color de fondo
//si solo tiene 1 argumento, está en escala de grises
background(200);

//si quiero que las lineas aparezcan adelante,
//debo crearlas despues de pintar el fondo
line(10,200,250,100);
line(30,10,300,460);

//para incluir texto EN EL CANVAS
//se utiliza la funcion text()
//cuyos argumentos son texto, posicionX y posiciónY

//para ajustar el tamaño del texto
//DEBO hacerlo antes de escribir con textSize(tamaño)
textSize(30);
fill(0); //relleno de negro
text("saludos terricolas",150,500);
