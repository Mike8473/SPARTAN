
/* Biblioteki */
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "pin.h"

void setup() {
 

  // Blynk - komunikacja telfon -> NodeMCU
  pinMode(PRZOD, 1);
  digitalWrite(PRZOD, 0);
  pinMode(TYL, 1);
  digitalWrite(PRZOD, 0);
  pinMode(LEWO, 1);
  digitalWrite(PRZOD, 0);
  pinMode(PRAWO, 1);
  digitalWrite(PRZOD, 0);
  pinMode(AUTO, 1);
  Blynk.begin(auth, ssid, pass);

  // Wi-Fi
  WiFi.begin(SSID, PASS);
  pinMode(LED, 1);
  while( WiFi.status() != WL_CONNECTED)
  {
  digitalWrite(LED, 1);
  delay(100);
  digitalWrite(LED, 0);
  delay(100);
  }
}

void loop() {
  Blynk.run();
  if(WiFi.status() == WL_CONNECTED) digitalWrite(LED, 0);
  else digitalWrite(LED, 1);
}
