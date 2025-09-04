# clase 05

### Pre apuntes para clase

revisar para pantalla oled
https://javl.github.io/image2cpp/

referentes: allison parrih ([texto](https://posts.decontextualize.com/queer-in-ai-2021/)) y nick montfort (Libro output: an anthology of computer-generated text), <https://poesiacero.cl/>, <https://martingubbins.cl/obra/>

<https://github.com/adafruit/Adafruit_SSD1306>

___

Código base para trabajar con pantallas OLED 0x96" i2c  (generado por chatgpt)

```cpp
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definir tamaño del display
#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64

// Dirección I2C típica (0x3C o 0x3D)
#define OLED_ADDR 0x3C  

// Crear objeto display
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire);

void setup() {
  // Iniciar la pantalla
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.begin(9600);
    Serial.println(F("No se encontró pantalla SSD1306"));
    for(;;); // se queda detenido
  }

  display.clearDisplay();             // limpiar buffer
  display.setTextSize(2);             // tamaño del texto
  display.setTextColor(SSD1306_WHITE);// color del texto
  display.setCursor(10, 25);          // posición (x,y)
  display.println("Hola mundo");      // escribir texto
  display.display();                  // mostrar en pantalla
}

void loop() {
  // nada que hacer en loop
}

```