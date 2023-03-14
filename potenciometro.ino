const int ledRojo = 7;
const int ledAzul = 5;
const int ledVerde = 6;
const int pb1 = 2;
const int pb2 = 3;
const int pb3 = 4;
int potpin = A2;
int val=0;



void setup() {
  // Configuración de los pines
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(pb1, INPUT_PULLUP);
  pinMode(pb2, INPUT_PULLUP);
  pinMode(pb3, INPUT_PULLUP);
  Serial.begin(9600); // Inicia la comunicación serial
}

void loop() {
  // Lee el estado de los pushbuttons y enciende los leds correspondientes
  if (digitalRead(pb1) == LOW) {
    digitalWrite(ledRojo, HIGH);
  } else {
    digitalWrite(ledRojo, LOW);
  }
  if (digitalRead(pb2) == LOW) {
    digitalWrite(ledAzul, HIGH);
  } else {
    digitalWrite(ledAzul, LOW);
  }
  if (digitalRead(pb3) == LOW) {
    digitalWrite(ledVerde, HIGH);
  } else {
    digitalWrite(ledVerde, LOW);
  }
  val = analogRead(A2);
  int medida = map(val,0, 1023, 0, 100);
  Serial.write(medida);
  delay(50);
}

