# clase 03

Hoy dia vamos a ver:

- Arduino
- Tendremos que instalar la librería ch340

## Contenidos clase

Para subir imágenes:
- Creamos subcarpeta "imagenes" dentro de la Clase03 con un archivo placeholder borrar.txt
- Subimos una foto de un gato a esa carpeta
- Y llamamos en el README.md a la imagen con el siguiente código

```
![texto alternativo de imagen](ubicacion de foto.jpg)
//para ir a la carpeta es buena práctica incluir el ./ que significa "aquí"
![aquí hay dos gatos](./imagenes/gatos.jpg)
```

![aquí hay dos gatos](./imagenes/gatos.jpg)

### Arduino

- Descargamos Arduino IDE
- Driver CH340 para Arduinos Genéricos
  <https://www.geekfactory.mx/tutoriales-arduino/driver-ch340-para-arduino-chinos-o-genericos/>

Windows: <https://cdn.geekfactory.mx/drivers/CH341SER.EXE>

MAC: <https://cdn.geekfactory.mx/drivers/CH341SER_MAC.ZIP>

Linux: <https://cdn.geekfactory.mx/drivers/CH341SER_LINUX.ZIP>

- Código para encender y apagar el led con variables

```cpp
//vamos a crear una variable para decir
//donde esta el led
int ledPin = 13;
int tiempoOn = 200;
int tiempoOff = 100;

void setup()
{
  //Lo primero que debo hacer es saber si mis pines son 
  //outputs o inputs
  //El LED interno de Arduino UNO está conectado en la pata 13
  //entonces digamosle a Arduino que pin 13 sea un output
  //la sintaxis es 
  //pinMode(numeroDePin,INPUT u OUTPUT);
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  //para encender el led hay que "escribir" en él
  //se usa la funcion
  //digitalWrite(numeroDePin, estado0o1);
  digitalWrite(ledPin,HIGH);
  //con delay paralizamos el codigo por un tiempo
  //en milisegundos
  delay(tiempoOn);
  //APAGAMOS EL LED
  digitalWrite(ledPin,LOW);
  delay(tiempoOff);
  
}
```