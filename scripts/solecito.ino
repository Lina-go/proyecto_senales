
// Import required libraries
#ifdef ESP32
  #include <WiFi.h>
  #include <ESPAsyncWebServer.h>
  #include <SPIFFS.h>
#else
  #include <Arduino.h>
  #include <ESP8266WiFi.h>
  #include <Hash.h>
  #include <ESPAsyncTCP.h>
  #include <ESPAsyncWebServer.h>
  #include <FS.h>
#endif
#include <Wire.h>

// Replace with your network credentials
const char* ssid = "iPhone de Veronica";
const char* password = "987654321";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

String readA0() {
  // Read temperature as Celsius (the default)
  float t = analogRead(A0);
  if (isnan(t)) {    
    Serial.println("Failed to read from sensor!");
    return "";
  }
  else {
    Serial.println(t);
    return String(t);
  }
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  
  // Initialize SPIFFS
  if(!SPIFFS.begin()){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  // Print ESP8266 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index1.html");
  });
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readA0().c_str());
  });
 
  // Start server
  server.begin();
}
 
void loop(){
  
}
