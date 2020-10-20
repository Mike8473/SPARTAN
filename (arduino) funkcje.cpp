/* Autonomiczny łazik SPARTAN */
/* Mikołaj Jędrzejczak        */
/* 19.10.2020                 */

#include <Arduino.h>
#include "pin.h"

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

uint8_t OBROT( uint8_t PK, uint8_t PPMW, uint8_t LK, uint8_t LPMW )
{
    digitalWrite(SP_K, PK);
    digitalWrite(SL_K, LK);
    analogWrite(SP_PMW ,PPMW);
    analogWrite(SL_PMW ,LPMW);
}

/*uint16_t POMIAR( void )
{
    uint32_t czas, dystans;
 
  digitalWrite(TRIG, 0);
  delayMicroseconds(2);
  digitalWrite(TRIG, 1);
  delayMicroseconds(10);
  digitalWrite(TRIG, 0);
 
  czas = pulseIn(ECHO, HIGH);
  dystans = czas / 58;

  delay(50);
 
  return dystans;
}*/
