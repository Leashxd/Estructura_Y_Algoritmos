#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// estructura que almacena los datos
typedef struct {   
  char nombre[100];
  int c;
  } ejemplo;

// funcion que entrega 1 si x1 es mayor que x2 segun el orden de las estructuras
// entrega 0 en caso contrario
// x1 > x2 si x1.c > x2.c o (x1.c = x2.c y x1.nombre > x2.nombre)
int mayor_que(ejemplo x1, ejemplo x2);

/* estructura nodo para trabajar con listas enlazadas
la estructura ejemplo x es el dato a guardar. */ 

struct node {   
  ejemplo x;
  struct node *next;
  };

/* OJO: las funciones insertar_elemento, insertar_elemento_orden
deben modificar la lista por lo cual el parametro es un puntero a la lista, 
es decir, una variable de tipo struct node **ref_lista */ 

// inserta dato al final de la lista (permitimos repeticiones de datos)
void insertar_elemento(struct node **ref_lista, ejemplo dato);

// imprime la lista completa
void imprimir_lista(struct node *lista);

// funcion auxiliar
void swap(struct node *nodo1, struct node *nodo2);

// ordena los datos de la lista (usa bubble sort)
void ordenar_lista(struct node *lista);

// asumiendo que la lista esta ordenada, inserta el dato donde corresponde
void insertar_elemento_orden(struct node **ref_lista, ejemplo dato);
