/* Autonomiczny łazik SPARTAN */
/* Mikołaj Jędrzejczak        */
/* 19.10.2020                 */

/* Biblioteki */
#include <Arduino.h>
#include "pin.h"

/* Zmienne */
uint16_t przeszkoda;

/* Główna funkcja */
void setup() {

  /* Inicjalizacja */
  // Silniki
  pinMode(SL_K, 1);
  pinMode(SP_K, 1);
  pinMode(SL_PMW, 1);
  pinMode(SP_PMW, 1);
  // Przyciski
  pinMode(PRZYCISK, 0);
  digitalWrite(PRZYCISK, 1);
 
  pinMode(SYGNAL_PRZ, 0);
}

/* Główna pętla */
void loop() {
  while(digitalRead(SYGNAL_PRZ) == 1) PRZOD(50);
  STOP();
  }

