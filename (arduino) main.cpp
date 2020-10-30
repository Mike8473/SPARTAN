/* Autonomiczny łazik SPARTAN */
/* Mikołaj Jędrzejczak        */
/* 19.10.2020                 */

/* Biblioteki */
#include <Arduino.h>
#include "spartan.h"

/* Zmienne globalne */
uint8_t moc = 50;

/* Główna funkcja */
void setup() 
{
  /* Inicjalizacja */

  // UART - Do testów
  Serial.begin(9600);
  Serial.println(" ");

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
  pinMode(SYGNAL_AUTO, 0);
  pinMode(SYGNAL_Vplus, 0);
  pinMode(SYGNAL_Vminus, 0);

  // Czujniki
  pinMode(TRIG_P, 1);
  pinMode(TRIG_T, 1);
  pinMode(ECHO_P, 0);
  pinMode(ECHO_T, 0);
  
}

/* Główna pętla */
void loop() 
{

  uint8_t kierunek = 1;

  while(digitalRead(SYGNAL_AUTO) == 1)
  {
    if(kierunek == 1)
    {
      PRZOD(100);
      if(POMIAR_P() <= 15)
      {
        STOP();
        kierunek = CZUJNIKI(1);
        delay(50);
      }
    }

    if(kierunek == 0)
    {
      TYL(100);
      if(POMIAR_T() <= 15)
      {
        STOP();
       kierunek = CZUJNIKI(0);
       delay(50);
      }
      
    }

   delay(50);
  }

  while(digitalRead(SYGNAL_AUTO) == 0)
  {
    if(digitalRead(SYGNAL_Vplus) == 1) moc = moc + 20;
    while(digitalRead(SYGNAL_Vplus) == 1){}
    if(digitalRead(SYGNAL_Vminus) == 1) moc = moc - 20;
    while(digitalRead(SYGNAL_Vminus) == 1){}
    Serial.println(moc);
    while(digitalRead(SYGNAL_PRZ) == 1) PRZOD(moc);
    while(digitalRead(SYGNAL_TYL) == 1) TYL(moc);
    while(digitalRead(SYGNAL_LEWO) == 1) OBROT_L(moc);
    while(digitalRead(SYGNAL_PRAWO) == 1) OBROT_P(moc);
    STOP();
    delay(50);
  }

}
  
 

