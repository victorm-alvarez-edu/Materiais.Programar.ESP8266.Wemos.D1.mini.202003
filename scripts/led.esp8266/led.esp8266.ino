/*
 * Encendido e apagado dun LED no pin D5
 * da placa ESP8266.
 * 
 */
 
// GPIO14: etiquetado en placa como D5
#define LED 14

// Tempo de espera
int tempo = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, LOW);
  Serial.println("LED off");
  delay(tempo);
  digitalWrite(LED, HIGH);
  Serial.println("LED on");
  delay(tempo);
}
