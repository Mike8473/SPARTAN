/* Biblioteka do łazika SPARTAN */
/* Mikołaj Jędrzejczak          */
/* 19.10.2020                   */

/* Pliki nagłówkowe */
#include <Arduino.h>
#include "Adafruit_MCP23008.h"

/* Definicje */
// Nakładka
#define SL_K 4
#define SL_PMW 5
#define SP_K 9
#define SP_PMW 6
#define PRZYCISK 2

// NodeMCU -> Ardunio
#define SYGNAL_PRZ 7
#define SYGNAL_TYL 8
#define SYGNAL_LEWO 12
#define SYGNAL_PRAWO 13
#define SYGNAL_AUTO A4
#define SYGNAL_Vplus A5
#define SYGNAL_Vminus 11

// Pomiary
#define TRIG_T A1
#define ECHO_T A0
#define TRIG_P A2
#define ECHO_P A3

/* Definicje funkcji */
uint8_t STOP( void );
uint8_t PRZOD( uint8_t moc );
uint8_t TYL( uint8_t moc );
uint8_t OBROT_L( uint8_t moc );
uint8_t OBROT_P( uint8_t moc );
uint16_t POMIAR_P( void );
uint16_t POMIAR_T( void );
uint8_t CZUJNIKI( uint8_t kierunek );
uint8_t DRGANIA( void );
