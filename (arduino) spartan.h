/* Biblioteka do łazika SPARTAN */
/* Mikołaj Jędrzejczak          */
/* 19.10.2020                   */

/* Pliki nagłówkowe */ /* Biblioteki */
#include <Arduino.h>

/* Definicje */ /* Jest to poprawna konstrukacja kodu, jednak dobrą praktyką jest opisywanie w komentarzach co jest za co odpowiedzialne i jak działa */
#define SL_K 4
#define SL_PMW 5
#define SP_K 9
#define SP_PMW 6
#define PRZYCISK 2

// NodeMCU -> Ardunio
// jPrzy budowaniu opisu połączeń dobrą praktyką jest np coś takiego
#define SYGNAL_PRZ 7 // NodeMCU -> Arduino - jesli wysylasz cos do arduino
#define SYGNAL_TYL 8 // NodeMCU <-> Arduino - gdy komunikacja jest w obie strony
#define SYGNAL_LEWO 12 // NodeMCU <- Arduino - gdy scigasz dane do Noda
#define SYGNAL_PRAWO 13


/* Definicje funkcji */
uint8_t STOP( void );
uint8_t PRZOD( uint8_t moc ); // przy używanych wielkościach w komentarzu pisze się jednostki w jakich się posługuje w projekcie
uint8_t TYL( uint8_t moc );
uint8_t OBROT( uint8_t PK, uint8_t PPMW, uint8_t LK, uint8_t LPMW );
uint16_t POMIAR( void );
