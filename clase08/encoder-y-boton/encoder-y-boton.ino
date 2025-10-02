
// This example checks the state of the rotary encoder in the loop() function.
// The current position and direction is printed on output when changed.

// Hardware setup:
// Attach a rotary encoder with output pins to
// * A2 and A3 on Arduino UNO.
// * D5 and D6 on ESP8266 board (e.g. NodeMCU).
// Swap the pins when direction is detected wrong.
// The common contact should be attached to ground.

//#include <Arduino.h>
#include <RotaryEncoder.h>

//Definimos que existe ARDUINO_AVR_UNO
#define ARDUINO_AVR_UNO

//creo variable donde envío el número a processing
int valorAEnviar = 0;

//para usar un boton
int botonPin = 4;
bool estadoBoton = 0;

#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_NANO_EVERY)
// Example for Arduino UNO with input signals on pin 2 and 3
#define PIN_IN1 2
#define PIN_IN2 3

#elif defined(ESP8266)
// Example for ESP8266 NodeMCU with input signals on pin D5 and D6
#define PIN_IN1 D5
#define PIN_IN2 D6

#endif

// Setup a RotaryEncoder with 4 steps per latch for the 2 signal input pins:
// RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::FOUR3);

// Setup a RotaryEncoder with 2 steps per latch for the 2 signal input pins:
RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::TWO03);


void setup()
{
  //para mi boton
  pinMode(botonPin, INPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("SimplePollRotator example for the RotaryEncoder library.");
} // setup()


// Read the current position of the encoder and print out when changed.
void loop()
{
  //averiguo el estado del botón y lo guardo en una variable
  //naturalmente está en "1", si aprieto cambia a "0"
  //si pongo una exclamación antes, invierto el comportamiento
  estadoBoton = !digitalRead(botonPin);

  //definiendola como static, hacemos que sea local (solo dentro del loop)
  //y SOLO la primera vez parte en 0
  static int pos = 0;
  //Esta función es la más importante de la biblioteca
  encoder.tick();

  int newPos = encoder.getPosition();
  if (pos != newPos) {
    // Serial.print("pos:");
    // Serial.print(newPos);
    // Serial.print(" dir:");
    // Serial.println((int)(encoder.getDirection()));
    pos = newPos;
  } // if

  //siempre valorAEnviar va a ser newPos
  valorAEnviar=newPos;
  Serial.print(estadoBoton);
  Serial.print (" ");
  Serial.println(valorAEnviar);

} // loop ()

// The End

