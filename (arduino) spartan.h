/* Biblioteka do łazika SPARTAN */
/* Mikołaj Jędrzejczak          */
/* 19.10.2020                   */

/* Pliki nagłówkowe */
#include <Arduino.h>

/* Definicje */
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
#define Sygnal_V A5

/* Definicje funkcji */
uint8_t STOP( void );
uint8_t PRZOD( uint8_t moc );
uint8_t TYL( uint8_t moc );
uint8_t OBROT_L( uint8_t moc );
uint8_t OBROT_P( uint8_t moc );
//uint16_t POMIAR( void );
