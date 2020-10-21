/* Autonomiczny łazik SPARTAN */
/* Mikołaj Jędrzejczak        */
/* 19.10.2020                 */

/* Biblioteki */
#include <Arduino.h>
#include "pin.h"

uint16_t moc;

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

  // Czujniki
  pinMode(TRIG_P, 1);
  pinMode(TRIG_T, 1);
  pinMode(ECHO_P, 0);
  pinMode(ECHO_P, 0);
  
}

/* Główna pętla */
void loop() 
{
  while(digitalRead(SYGNAL_AUTO) == 1)
  {
    Serial.print("POMIAR_1: ");
    Serial.print(POMIAR_P());
    Serial.println("");
    Serial.print("POMIAR_2: ");
    Serial.print(POMIAR_T());

    OBROT_P(100);
    delay(1000);
    STOP();

    Serial.println("");
    Serial.print("POMIAR_1: ");
    Serial.print(POMIAR_P());
    Serial.println("");
    Serial.print("POMIAR_2: ");
    Serial.print(POMIAR_T());
    Serial.println("");

    while(digitalRead(SYGNAL_AUTO) == 1){}
  }
  while(digitalRead(SYGNAL_AUTO) == 0)
  {
    moc = analogRead(A5);
    delay(50);
    Serial.println(moc);
    while(digitalRead(SYGNAL_PRZ) == 1) PRZOD(moc);
    while(digitalRead(SYGNAL_TYL) == 1) TYL(moc);
    while(digitalRead(SYGNAL_LEWO) == 1) OBROT_L(moc);
    while(digitalRead(SYGNAL_PRAWO) == 1) OBROT_P(moc);
    STOP();
  }

}
  
 

