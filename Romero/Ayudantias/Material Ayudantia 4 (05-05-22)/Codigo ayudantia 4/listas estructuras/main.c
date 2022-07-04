#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main(int argc, char* argv[]) {
  
  // puede probar las funciones que quiera de listas.h

  // creamos una lista vacia
  struct node *lista = NULL;

  // leemos las estructuras del archivo "prueba.txt"
  // mantenemos la lista ordenada
  FILE *fp = fopen("prueba.txt", "r");
  char line[1000];
  ejemplo aux;
  while (fgets(line, 1000, fp) != NULL) {
    strcpy(aux.nombre, strtok(line, ","));
    aux.c = atoi(strtok(NULL, ","));
    insertar_elemento_orden(&lista, aux);
  }
  fclose(fp);

  imprimir_lista(lista);

  // seteamos lista a ser vacia nuevamente
  lista = NULL;

  // leemos las estructuras del archivo "prueba.txt"
  // insertamos en el orden que vienen en el archivo y luego ordenamos
  fp = fopen("prueba.txt", "r");
  while (fgets(line, 1000, fp) != NULL) {
    strcpy(aux.nombre, strtok(line, ","));
    aux.c = atoi(strtok(NULL, ","));
    insertar_elemento(&lista, aux);
  }
  fclose(fp);

  imprimir_lista(lista);

  ordenar_lista(lista);

  imprimir_lista(lista);

}
