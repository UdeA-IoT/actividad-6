#include <ESP8266WiFi.h>

#define SSID "nombre-red"
#define PASSWORD  "clave-red"

const char* ssid     = SSID;
const char* password = PASSWORD;

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(ssid, password);

  Serial.print("Conectando");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Conectado, dirección IP: ");
  Serial.println(WiFi.localIP());
}

void loop() { }
