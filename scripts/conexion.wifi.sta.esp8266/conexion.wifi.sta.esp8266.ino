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

// WiFi móbil
#define MAX_INTENTOS 50
#define WIFI_SSID "ssd"
#define WIFI_PASS "pass"

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

// Función que se encarga de xestionar a conexión á rede
void conectarWiFi() {
  WiFi.mode(WIFI_STA);  // Indica modo Station (conexión a outro dispositivo)
  WiFi.disconnect();    // Desconecta unha posible conexión previa
  WiFi.begin(WIFI_SSID, WIFI_PASS); // Inicia a conexión 
  Serial.print("\n\nAgardando pola WiFi ");
  int contador = 0;  // Comproba estado da conexión e fai varias tentativas
  while(WiFi.status() != WL_CONNECTED and contador < MAX_INTENTOS) {
    contador++;
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  // Informa do estado da conexión e IP en caso de éxito
  if(contador < MAX_INTENTOS) {
    Serial.print("Conectado á WiFi coa IP: "); Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("Non se puido conectar á WiFi");
  }
  Serial.print("\n\n\n");
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
