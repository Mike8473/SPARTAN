/* Program sterowania łazikiem SPARTAN */
/* Mikołaj Jędrzejczak                 */
/* 20.10.2020                          */

/* Biblioteki */
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "pin.h"

void setup() {
  /* Inicjalizacja */
  // Blynk - komunikacja telfon -> NodeMCU
  Blynk.begin(auth, ssid, pass);
  pinMode(PRZOD, 1);
  digitalWrite(PRZOD, 0);

  pinMode(TYL, 1);
  digitalWrite(TYL, 0);

  pinMode(PRAWO, 1);
  digitalWrite(PRAWO, 0);

  pinMode(LEWO, 1);
  digitalWrite(LEWO, 0);

  // Wi-Fi
  WiFi.begin(SSID, PASS);
  while( WiFi.status() != WL_CONNECTED)
  {

  }
  

 
}

void loop() {
  Blynk.run();
}
