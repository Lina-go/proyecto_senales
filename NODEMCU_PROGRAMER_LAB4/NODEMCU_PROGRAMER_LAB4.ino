#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h>
#include <Wire.h>

// Replace with your network credentials
const char* ssid = "RAFA CORONADO_2.4GHz";
const char* password = "2326101026";

//#define pin_lectura 15
 
ESP8266WebServer server(5005);  // Create a webserver object that listens for HTTP request on port 5005

String readPin() {
  // Read value from PIN
  //float reading_sensor = analogRead(pin_lectura);
  //float voltage_sensor = reading_sensor * (3.3/(pow(2,10)-1));
  float voltage_sensor =  random(1023)*(3.3/(pow(2,10)-1));

  if (isnan(voltage_sensor)) {
    Serial.println("Failed to read from pin!");
    return "";
  } else {
    Serial.println(voltage_sensor);
    return String(voltage_sensor);
  }
}
 
void setup() {
 
  Serial.begin(115200);
  //pinMode(pin_lectura, INPUT_PULLUP);
  randomSeed(1);
  delay(1000);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, []() { // Si se recibe una petición GET a la raíz del servidor, se ejecuta la función
    server.sendHeader("Access-Control-Allow-Origin", "*"); 
    server.sendHeader("Access-Control-Allow-Methods", "GET"); // Podemos poder POST, etc 
    server.send(200, "text/plain", readPin());
    });
  
  server.begin();                  // Start the HTTP Server
}
 
void loop() {
   server.handleClient();            // Handle any incoming client requests
   delay(10);
}