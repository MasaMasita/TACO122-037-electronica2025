#define IN1  11
#define IN2  10
#define IN3  9
#define IN4  8

int steps_left = 4095;
boolean Direction = true;
int Steps = 0;

// --- Velocidad inicial ---
int velocidad = 3;   // ms entre pasos (1 = rápido, >10 = lento)

int Paso [8][4] =
{   
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
  Serial.println("Ingrese un número para cambiar la velocidad (ms entre pasos):");
}

void loop() {     
  // --- Leer velocidad desde Serial ---
  if (Serial.available() > 0) {
    int nuevaVel = Serial.parseInt();  // lee número enviado
    if (nuevaVel > 0 && nuevaVel < 50) {  // límites de seguridad
      velocidad = nuevaVel;
      Serial.print("Velocidad cambiada a: ");
      Serial.println(velocidad);
    }
    while (Serial.available() > 0) Serial.read(); // limpiar buffer
  }

  // --- Movimiento del motor ---
  while (steps_left > 0) {
    stepper();
    steps_left--;
    delay(velocidad);
  }
  
  delay(500);
  Direction = !Direction;
  steps_left = 4095;
}

void stepper() {
  digitalWrite(IN1, Paso[Steps][0]);
  digitalWrite(IN2, Paso[Steps][1]);
  digitalWrite(IN3, Paso[Steps][2]);
  digitalWrite(IN4, Paso[Steps][3]);
  SetDirection();
}

void SetDirection() {
  if (Direction)
    Steps++;
  else 
    Steps--; 
     
  Steps = (Steps + 8) % 8;   // 8 pasos de la tabla
}
