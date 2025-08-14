//las variables son números o datos
//se crean definiendo siempre primero el TIPO de variable
//el tipo de variables es un contenedor
//Por ej: me compro un chicle en el super -> me basta con un bolsillo
//para llevarmelo

//Si me compro 20 planchas de mdf de 320x120cm -> necesito un flete

//para crear caracteres uso la variable de tipo char
//una variable guarda una información
//en nuestro ejemplo dela compra del super sería
//bolsillo chicle = bigtime;
//cada vez que pregunta por chicle, el programa me devuelve bigtime
//sabiendo que ocupa el espacio de un bolsillo

//la sintaxis de los char nos obliga a que no haya espacio
//y que esté entre comilla simple ' ' 
char letra = 'a'; 

//para los numeros existen otros tipos de variable
//int para numeros enteros

//el TIPO de variable se declara SOLO UNA VEZ
int gato = 8;
int alonso = 12;
int lasuma = 0;

//existe un segundo tipo de variable numerica
//float es un numero de punto flotante, o sea tiene comas
float notaGato = 6.1;

//uno puede convertir float en int
int notaGatoEntera = 0;

//con la FUNCION int() le quito los decimales a un número
notaGatoEntera = int(notaGato);

lasuma = gato*2;
lasuma = gato + alonso;
println(notaGatoEntera); //salto de linea mas facil
print("\n"); //salto de linea dificil
println(); //salto de linea facil
print(lasuma);


//para hacer mensajes complejos
//para imprimir "la nota de gato es 6.1"

println();
print("la nota de gato es " + notaGato); //tambien puedo incluir variables
