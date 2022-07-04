#include <stdio.h>
#include "busqueda.h"

int main() 
{
  // arreglo y elemento a buscar de prueba
  int arreglo[9] = {10,20,30,40,50,60,70,80,90};  
  int x = 66;
  
  //printf("Busqueda Lineal\n");
  //printf("La posicion de %d en el arreglo es %d\n", x, linear_search(arreglo, 9, x));
  printf("Busqueda Binaria\n");
  printf("La posicion de %d en el arreglo es %d\n", x, binary_search(arreglo, 9, x));
}