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

void setup() {
  // Iniciar la pantalla
  if(!pantallita.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.begin(9600);
    Serial.println(F("No se encontró pantalla SSD1306"));
    for(;;); // se queda detenido
  }

  pantallita.clearDisplay();             // limpiar buffer
  pantallita.setTextSize(1);             // tamaño del texto
  pantallita.setTextColor(SSD1306_WHITE);// color del texto
  pantallita.setCursor(ANCHO_PANTALLA/2, 25);          // posición (x,y)
  pantallita.println("holitas");      // escribir texto
  pantallita.display();                  // mostrar en pantalla
}

void loop() {
  // nada que hacer en loop
}
