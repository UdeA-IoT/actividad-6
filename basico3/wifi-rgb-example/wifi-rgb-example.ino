// Libraries
#include <ESP8266WiFi.h>

// IO pins
int redPin = D5;
int greenPin = D6;
int bluePin = D7;

// WiFi network
const char* ssid     = "your-ssid";
const char* password = "your-password";

void setup() {
  // Config I/O ports
  setup_IO();
  // Connect to network
  setup_WIFI();
  // Led Color green
  setLedColor(0, 255, 0);
  delay(1000);  
  Serial.println("Connected...");  
  // Delay 5 seconds
  delay(5000);
}

void setup_IO() {
  // Config pines as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Turn on the led with color red (No wifi connection)
  setLedColor(255, 0, 0); 
}

void setup_WIFI() {
  // Start serial
  Serial.begin(115200);
  delay(10);

  // Connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Turn on the led with color green (Wifi connection ok)  
  //setLedColor(0, 255, 0);
  // Get net info
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void setLedColor(int R, int G, int B) {
  analogWrite(redPin, R);
  analogWrite (greenPin, G);
  analogWrite (bluePin, B);
}

void loop() {
  setLedColor(0, 0, 0);
  delay(500);
  setLedColor(0, 0, 255);
  delay(500);
}