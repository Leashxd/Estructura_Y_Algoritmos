#include "listas.h"

int main(int argc, char* argv[]) {
  
  // creamos una lista vacia
  struct node *lista = NULL;
  // arreglo de prueba
  int elementos[12] = {3,78,4,8,2,98,55,32,67,12,11,20};

  // puede probar las funciones que quiera de listas.h

  
  for (int i=0; i<12; i++) {
    insertar_elemento_orden(&lista, elementos[i]);
  }

  imprimir_lista(lista);

  //borrar_elemento(&lista, 55);
  //borrar_elemento(&lista, 2);
  //borrar_elemento(&lista, 4);

  //imprimir_lista(lista);

  /*
  for (int i=0; i<12; i++) {
    insertar_elemento(&lista, elementos[i]);
  }

  imprimir_lista(lista);

  ordenar_lista(lista);

  imprimir_lista(lista);
  */


}
