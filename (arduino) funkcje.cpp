/* Autonomiczny łazik SPARTAN */
/* Mikołaj Jędrzejczak        */
/* 19.10.2020                 */

#include <Arduino.h>
#include "pin.h"

/* Zmienne */

uint8_t zwrot;
uint16_t wynik_P1, wynik_T1, wynik_P2, wynik_T2;

/* Funkcje */
uint8_t STOP( void )
{
    analogWrite(SL_PMW, 0);
    analogWrite(SP_PMW, 0);
}

uint8_t PRZOD( uint8_t moc )
{
   digitalWrite(SL_K, 1);
   digitalWrite(SP_K, 1);
   analogWrite(SL_PMW, moc);
   analogWrite(SP_PMW, moc);

}

uint8_t TYL( uint8_t moc )
{
   digitalWrite(SL_K, 0);
   digitalWrite(SP_K, 0);
   analogWrite(SL_PMW, moc);
   analogWrite(SP_PMW, moc);

}

uint8_t OBROT_L( uint8_t moc )
{
    digitalWrite(SL_K, 0);
    digitalWrite(SP_K, 1);
    analogWrite(SL_PMW, moc);
    analogWrite(SP_PMW, moc);
}

uint8_t OBROT_P( uint8_t moc )
{
    digitalWrite(SL_K, 1);
    digitalWrite(SP_K, 0);
    analogWrite(SL_PMW, moc);
    analogWrite(SP_PMW, moc);
}

uint16_t POMIAR_P( void )
{
    uint32_t czas, dystans;
 
  digitalWrite(TRIG_P, 0);
  delayMicroseconds(2);
  digitalWrite(TRIG_P, 1);
  delayMicroseconds(10);
  digitalWrite(TRIG_P, 0);
  digitalWrite(ECHO_P, HIGH);

  
  czas = pulseIn(ECHO_P, HIGH);
  dystans = czas /58;

  delay(50);

  return dystans;
}

uint16_t POMIAR_T( void )
{
    long czas, dystans;
 
  digitalWrite(TRIG_T, 0);
  delayMicroseconds(2);
  digitalWrite(TRIG_T, 1);
  delayMicroseconds(10);
  digitalWrite(TRIG_P, 0);
  digitalWrite(ECHO_T, 1);

 
  czas = pulseIn(ECHO_T, 1);
  dystans = czas / 58;

  delay(50);
 
  return dystans;
}

uint8_t OBLICZ( void )
{
    if(wynik_P1 >= wynik_P2)
    {
        if(wynik_T1 >= wynik_T2)
        {
            if(wynik_T1 >= wynik_P1) zwrot = 1;
            if(wynik_T1 <= wynik_P1) zwrot = 2;
        }
        if(wynik_T1 <= wynik_T2)
        {
            if(wynik_T2 >= wynik_P1) zwrot = 3;
            if(wynik_T2 <= wynik_P1) zwrot = 4;
        }
    }
    if(wynik_P1 <= wynik_P2)
    {
        if(wynik_T1 >= wynik_T2)
        {
            if(wynik_T1 >= wynik_P2) zwrot = 5;
            if(wynik_T1 <= wynik_P2) zwrot = 6;
        }
        if(wynik_T1 >= wynik_T2)
        {
            if(wynik_T2 >= wynik_P2) zwrot = 7;
            if(wynik_T2 <= wynik_P2) zwrot = 8;
        }
    }

    if(zwrot == 1 | zwrot == 2 | zwrot == 4 | zwrot == 5)
    {
        OBROT_P(100);
    } 

}
