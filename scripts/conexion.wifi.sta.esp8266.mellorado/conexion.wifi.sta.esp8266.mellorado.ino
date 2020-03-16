/*
 * Programa para probar as funcións da librería ESP8266WiFI.h.
 * 
 * O módulo ESP8266 tentará conectarse á rede previamente establecida
 * nun dispositivo móbil coa SSID: 'ssid' e chave: 'pass'.
 * En caso de conseguir conectarse á rede, comunica a IP pola saída
 * serie e fará escintilar un LED cunha frecuencia dada. En caso de 
 * non consegir conectarse á rede, fai intentos por nun número máximo 
 * de veces, superados estes, comunica o feito pola saía serie e 
 * fai escintilar o LED con frecuencia doble (metade de tempo aceso).
 * 
 * Non fai control de posible perda de conexión á WiFi. A función
 * delay() pode ocasionar a perda de conexión de rede debido á
 * imposibilidade de executar ningunha operación de rede até rematar
 * a espera. Haberá que ter isto en conta para scripst máis 'operativos'.
 * 
 */
 
#include <ESP8266WiFi.h>
#include "config.h"  // Arquivo local para configuración de rede
#include "toolsWiFi.hpp" // Biblioteca local para funcións de rede

// Pins datos
// GPIO14: D5
#define LED 14

int tempo = 500;
bool conectado = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  conectarWiFi();
}

void loop() {
  if(conectado) escintila(tempo);
  else escintila(tempo/10);
}

// Función que encende e apaga o LED cunha
// frecuencia determianda pola variable 'espera'
void escintila(int espera) {
  digitalWrite(LED, HIGH);
  delay(espera);
  digitalWrite(LED, LOW);
  delay(espera);
}
