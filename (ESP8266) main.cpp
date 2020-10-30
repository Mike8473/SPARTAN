#include <Arduino.h>
#include <BlynkSimpleEsp8266.h>
#include "pin.h"

#define BLYNK_PRINT Serial
char auth[] = "3AG8OrjK4W-8UABPL3DeNeLSDqbmFLvb";
char ssid[] = "TOK-B8";
char pass[] = "uwvw9954";

BlynkTimer timer;

void myTimerEvent()
{
  uint16_t pomiar;
  pomiar = analogRead(LIGHT);
  Serial.println(pomiar);
  Blynk.virtualWrite(V5, pomiar);
}


void setup() {
  Serial.begin(9600);

  //Deklaracja pinów
  pinMode(PRZOD, 1);
  pinMode(TYL, 1);
  pinMode(LEWO, 1);
  pinMode(PRAWO, 1);
  pinMode(AUTO, 1);
  pinMode(Vplus, 1);
  pinMode(Vminus, 1);
  pinMode(LIGHT, 0);

  digitalWrite(PRZOD, 0);
  digitalWrite(TYL, 0);
  digitalWrite(LEWO, 0);
  digitalWrite(PRAWO, 0);

  // Blynk - komunikacja telfon -> NodeMCU
  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, myTimerEvent);
  
}

void loop() {
  Blynk.run();
  timer.run();
  

}
