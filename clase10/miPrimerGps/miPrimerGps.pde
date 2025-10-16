Table recorridoGabi; //creamos una instancia de la clase Tabla, con el recorrido de Gabi

//variables para recorrer la tabla
int contadorX = 0;
int contadorY = 0;

//donde voy a ubicar cada coordenada
float posicionX = 0;
float posicionY = 0;

float posicionXMap = 0;
float posicionYMap = 0;

int direccionX = 1; // si es 1 avanza, si es -1 retrocede
int direccionY = 1; //

void setup(){
  size(300,300);
  background(255);
  
  //"header" dice que ignore la primera fila
  recorridoGabi = loadTable("hojaProcesada.csv", "header");
  
  //esta funcion me dice cuantas filas hay
  print("filas y columnas: ");
  print(recorridoGabi.getRowCount());
  print(" y ");
  println(recorridoGabi.getColumnCount());
  
  //para saber que valores hay una una fila específica
  print("en la celda (0,0) está el valor: ");
  println(recorridoGabi.getFloat(0,0));
  
  print("en la celda (0,1) está el valor: ");
  println(recorridoGabi.getFloat(0,1));
}

void draw(){
  background(255);
  
  contadorX = contadorX + 1 * direccionX; //incrementa contadorX en 1
  contadorY = contadorY + 1 * direccionY; //incrementa contadorY en 1
  
  //actualizar posicionX e Y según la tabla y el contador
  posicionX = recorridoGabi.getFloat(contadorX,1);
  posicionY = recorridoGabi.getFloat(contadorY,0);
  
  //remapeamos la variable posicion
  posicionXMap = map(posicionX,0,100,0 + 20, width - 20);
  posicionYMap = map(posicionY,0,100,height -20 , 0 + 20);
  
  //vamos a intentar desplegar la imagen de manera estática
  circle(posicionXMap, posicionYMap, 2);

  if (contadorX >= recorridoGabi.getRowCount()-1){
    direccionX = -1;
  }
  if (contadorY >= recorridoGabi.getRowCount()-1){
    direccionY = -1;
  }
  
  if (contadorX <= 0){
    direccionX = 1;
  }
  if (contadorY <= 0){
    direccionY = 1;
  }
  
}
