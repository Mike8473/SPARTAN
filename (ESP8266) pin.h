/* Biblioteka definicji pinów */
/* Mikołaj Jędrzejczak        */
/* 20.10.2020                 */

/* Pliki nagłówkowe */
#include <Arduino.h>
#include <ESP8266WiFi.h>

/* Definicje */
#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15

#define PRZOD D4
#define TYL D3
#define LEWO D2
#define PRAWO D1

/* Wi-Fi */
const char* SSID = "TOK-B8";
const char* PASS = "uwvw9954";

/* Blynk */
#define BLYNK_PRINT Serial
char auth[] = "3AG8OrjK4W-8UABPL3DeNeLSDqbmFLvb";
char ssid[] = "TOK-B8";
char pass[] = "uwvw9954";
