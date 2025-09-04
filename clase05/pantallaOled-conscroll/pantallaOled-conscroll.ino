#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definir tamaño del display
#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64

// Dirección I2C típica (0x3C o 0x3D)
#define OLED_ADDR 0x3C  

// Crear objeto display
Adafruit_SSD1306 pantallita(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire);

//creamos una variable que me guarde la posicion vertical
int posicionVertical = 0;

void setup() {
  // Iniciar la pantalla
  if(!pantallita.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.begin(9600);
    Serial.println(F("No se encontró pantalla SSD1306"));
    for(;;); // se queda detenido
  }

  
}

void loop() {

  //hacemos que posicion vertical cambie en 1
  posicionVertical++;

  pantallita.clearDisplay();             // limpiar buffer
  pantallita.setTextSize(1);             // tamaño del texto
  pantallita.setTextColor(SSD1306_WHITE);// color del texto

  //el componente vertical de la posicion dependa de posicionVertical
  pantallita.setCursor(ANCHO_PANTALLA/2, posicionVertical);          // posición (x,y)
  pantallita.println("holitas");      // escribir texto
  pantallita.display();                  // mostrar en pantalla

  //si es mayor al alto de la pantalla, que se resetee
  if (posicionVertical > ALTO_PANTALLA){
    posicionVertical = 0;
  }

  delay(100);
}
