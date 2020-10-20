/* Autonomiczny łazik SPARTAN */
/* Mikołaj Jędrzejczak        */
/* 19.10.2020                 */

/* Biblioteki */
#include <Arduino.h>
#include "pin.h"

/* Zmienne */
uint8_t moc;

/* Główna funkcja */
void setup() {

  /* Inicjalizacja */
  // Silniki
  pinMode(SL_K, 1);
  pinMode(SP_K, 1);
  pinMode(SL_PMW, 1);
  pinMode(SP_PMW, 1);
 
 // Sygnały sterujące
  pinMode(SYGNAL_PRZ, 0);
  pinMode(SYGNAL_TYL, 0);
  pinMode(SYGNAL_LEWO, 0);
  pinMode(SYGNAL_PRAWO, 0);
  
}

/* Główna pętla */
void loop() {
  moc = analogRead(A5);
  while(digitalRead(SYGNAL_PRZ) == 1) PRZOD(moc);
  while(digitalRead(SYGNAL_TYL) == 1) TYL(moc);
  while(digitalRead(SYGNAL_LEWO) == 1) OBROT_L(moc);
  while(digitalRead(SYGNAL_PRAWO) == 1) OBROT_P(moc);
  STOP();
  }

