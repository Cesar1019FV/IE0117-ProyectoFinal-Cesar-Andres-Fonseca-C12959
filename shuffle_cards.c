//gcc 5.4.0
// Fig. 10.3: fig10_03.c
// Programa que realiza un shuffling de cartas 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

// definición de estructura de cartas                  
struct card {                                 
   const char *face;    
   const char *suit;   
};                          

typedef struct card Card;  

// prototipos
void fillDeck( Card * const wDeck, const char * wFace[], 
   const char * wSuit[] );
void shuffle( Card * const wDeck );
void deal( const Card * const wDeck );

int main( void )
{ 
   Card deck[ CARDS ]; // definir arreglo de cartas

   // inicializar arreglo de punteros
   const char *face[] = { "A", "Dos", "Tres", "Cuatro", "Cinco",
      "Seis", "Siete", "Ocho", "Nueve", "Diez",
      "J", "Q", "K"};

   
   const char *suit[] = { "Corazones", "Diamantes", "Tréboles", "Espadas"};

   srand( time( NULL ) ); //funcion de aleatoreidad

   fillDeck( deck, face, suit ); // cargar mazo de cartas
   shuffle( deck ); // pone mazo de cartas en aleatorio
   deal( deck ); // toas las 52 cartas
} // final del main

// colocar strings en estructuras de cartas
void fillDeck( Card * const wDeck, const char * wFace[], 
   const char * wSuit[] )
{ 
   size_t i; // counter

   // loop en wDeck
   for ( i = 0; i < CARDS; ++i ) { 
      wDeck[ i ].face = wFace[ i % FACES ];
      wDeck[ i ].suit = wSuit[ i / FACES ];
   } 
} 

// shuffle de las cartas
void shuffle( Card * const wDeck )
{ 
   size_t i; // counter
   size_t j; // variable que sostiene un valor cualquiera entre 0-51
   Card temp; // definir una estructura temporal para swapping de las cartas

  
   for ( i = 0; i < CARDS; ++i ) { 
      j = rand() % CARDS;
      temp = wDeck[ i ];      
      wDeck[ i ] = wDeck[ j ];
      wDeck[ j ] = temp;      
   }
} 

// repartir cartas
void deal( const Card * const wDeck )
{ 
   size_t i; // counter

   
   for ( i = 0; i < CARDS; ++i ) {
      printf( "%5s de %-8s%s", wDeck[ i ].face, wDeck[ i ].suit,
         ( i + 1 ) % 4? "  " : "\n" );
   } 
} 

