
#include "puntajes.h"
#include "reglas.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int opcion = 0;

  printf("Bienvenido a Gin Rummy");

  do {

    printf("\nSeleccione una opcion: \n1.Comenzar nuevo juego\n2.Reglas del "
           "Juego\n3.Mejores puntuaciones\n4.Salir del juego\n");
    scanf("%d", &opcion);

    switch (opcion) {

    case 1:

      break;
    case 2:
      reglas();
      break;
    case 3:
      // Se recomienda, aqui ingresar la funcion puntajes(char[],int) para hacer las pruebas de la funcionalidadPuntajes
      printf("[Jugador]   [Cantidad de intentos]\n");
      ordenamiento();
      break;

    case 4:
      exit(-1);
      break;

    default:
      printf("Digite una opcion valida");
      break;
    }
  } while (opcion != 4);
  return 0;
}
