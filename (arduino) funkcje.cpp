/* Autonomiczny łazik SPARTAN */
/* Mikołaj Jędrzejczak        */
/* 19.10.2020                 */

#include <Arduino.h>
#include "spartan.h"

/* Zmienne */

uint16_t zwrot;
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
  digitalWrite(TRIG_T, 0);
  digitalWrite(ECHO_T, 1);

 
  czas = pulseIn(ECHO_T, 1);
  dystans = czas / 58;

  delay(50);
 
  return dystans;
}

uint8_t CZUJNIKI( uint8_t kierunek )
{
    if(kierunek == 1) wynik_P1 = POMIAR_P();
    else wynik_P1 = 0;
    if(kierunek == 0 ) wynik_T1 = POMIAR_T();
    else wynik_T1 = 0;
    delay(50);

    OBROT_P(100);
    delay(425);
    STOP();
    delay(400);

    wynik_P2 = POMIAR_P();
    wynik_T2 = POMIAR_T();

    Serial.println(" POMIAR X:");
    Serial.println("Przód: ");
    Serial.println(wynik_P1);
    Serial.println("Tył: ");
    Serial.println(wynik_T1);

    Serial.println(" POMIAR Y:");
    Serial.println("Przód: ");
    Serial.println(wynik_P2);
    Serial.println("Tył: ");
    Serial.println(wynik_T2);

    // Wybierz największy wynik
    if(wynik_P1 >= wynik_P2)
    {
        if(wynik_T1 >= wynik_T2)
        {
            if(wynik_T1 >= wynik_P1) zwrot = wynik_T1;
            if(wynik_T1 <= wynik_P1) zwrot = wynik_P1;
        }
        if(wynik_T1 <= wynik_T2)
        {
            if(wynik_T2 >= wynik_P1) zwrot = wynik_T2;
            if(wynik_T2 <= wynik_P1) zwrot = wynik_P1;
        }
    }
    if(wynik_P1 <= wynik_P2)
    {
        if(wynik_T1 >= wynik_T2)
        {
            if(wynik_T1 >= wynik_P2) zwrot = wynik_T1;
            if(wynik_T1 <= wynik_P2) zwrot = wynik_P2;
        }
        if(wynik_T1 <= wynik_T2)
        {
            if(wynik_T2 >= wynik_P2) zwrot = wynik_T2;
            if(wynik_T2 <= wynik_P2) zwrot = wynik_P2;
        }
    }
    // Zapisz go w zmiennej [zwrot]

    Serial.println(" Największa wartość: ");
    Serial.println(zwrot);

    // Odpowiednio się ustaw
    if(zwrot == wynik_P1 || zwrot == wynik_T1)
    {
        OBROT_L(100);
        delay(400);
        STOP();
        delay(250);

    }

    // Zwróć kierunek jazdy - Przód/Tył
    if(zwrot == wynik_P1) return 1;
    if(zwrot == wynik_T1) return 0;
    if(zwrot == wynik_P2) return 1;
    if(zwrot == wynik_T2) return 0;


}
