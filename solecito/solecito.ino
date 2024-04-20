
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
const char* ssid = "5-701";
const char* password = "naviquer159";

#define touch 13

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

String readPin() {
  // Read value from touch PIN
  float value = analogRead(pin_touch) * (5.0 / 1023.0);
  if (isnan(value)) {
    Serial.println("Failed to read from pin A0!");
    return "";
  } else {
    Serial.println(value);
    return String(value);
  }
}

void setup() {
  // Serial port for debugging purposes
  Serial.begin(115200);

  // Set touch PIN as input
  pinMode(pin_touch, INPUT_PULLUP);

  // Initialize SPIFFS
  if (!SPIFFS.begin()) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  } else {
    Serial.println("SPIFFS is working");
  }

  // Check if pagina_en_vivo.html is loaded
  if (!SPIFFS.exists("/pagina_en_vivo.html")) {
    Serial.println("pagina_en_vivo.html is not loaded on the ESP8266");
  } else {
    Serial.println("pagina_en_vivo.html is loaded on the ESP8266");
  }

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting to WiFi..");
    switch (WiFi.status()) {
      case WL_NO_SSID_AVAIL:
        Serial.println("No SSID available");
        break;
      case WL_CONNECT_FAILED:
        Serial.println("Connection failed");
        break;
      case WL_DISCONNECTED:
        Serial.println("Disconnected");
        break;
      default:
        Serial.println("Unknown error");
        break;
    }
  }
  // Print ESP8266 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  //server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    //request->send(SPIFFS, "/pagina_en_vivo.html", "text/html");
  //});
  server.on("/ECG", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send_P(200, "text/plain", readPin().c_str());
  });

  // Start server
  server.begin();
}

void loop() {
}
