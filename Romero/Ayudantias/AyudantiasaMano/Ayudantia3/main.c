#include <stdio.h>
#include <string.h>
#include "hash.h"

#define TABLE_SIZE 10

int main(int argc, char *argv[]) 
{
  if (strcmp(argv[1], "sondeo lineal") == 0) {
    int tabla[TABLE_SIZE];

    for (int i=0; i < TABLE_SIZE; i++) {
      tabla[i] = -1;
    }

    int key;
    printf("Ingrese numero a insertar: ");
    scanf("%d", &key);

    while(key != -1) {
      insertar_sondeolineal(tabla, TABLE_SIZE, key);
      imprimir_tabla_sondeolineal(tabla, TABLE_SIZE); 
      printf("\n");
      printf("Ingrese numero a insertar: ");
      scanf("%d", &key);
    }  

    printf("Ingrese numero a buscar: ");
    scanf("%d", &key);

    while(key != -1) {
      printf("%d\n", buscar_sondeolineal(tabla, TABLE_SIZE, key));
      printf("Ingrese numero a buscar: ");
      scanf("%d", &key);
    } 
  }
  if (strcmp(argv[1], "encadenamiento") == 0) {
    struct node *tabla[TABLE_SIZE];

    for (int i=0; i < TABLE_SIZE; i++) {
      tabla[i] = NULL;
    }

    int key;
    printf("Ingrese numero a insertar: ");
    scanf("%d", &key);

    while(key != -1) {
      insertar_encadenamiento(tabla, TABLE_SIZE, key);
      imprimir_tabla_encadenamiento(tabla, TABLE_SIZE); 
      printf("\n");
      printf("Ingrese numero a insertar: ");
      scanf("%d", &key);
    } 

    printf("Ingrese numero a buscar: ");
    scanf("%d", &key);

    while(key != -1) {
      printf("%d\n", buscar_encadenamiento(tabla, TABLE_SIZE, key));
      printf("Ingrese numero a buscar: ");
      scanf("%d", &key);
    } 
  }
}