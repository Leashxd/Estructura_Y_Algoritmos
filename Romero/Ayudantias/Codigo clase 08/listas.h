#include <stdlib.h>
#include <stdio.h>

/* estructura nodo para trabajar con listas enlazadas
int x es el dato a guardar. 
En general, los datos podrian ser varias variables de cualquier tipo 
(por ejemplo estructuras) */ 

struct node {   
  int x;
  struct node *next;
  };

/* OJO: las funciones insertar_elemento, borrar_elemento e insertar_elemento_orden
deben modificar la lista por lo cual el parametro es un puntero a la lista, 
es decir, una variable de tipo struct node **ref_lista */ 

// inserta dato valor al final de la lista (permitimos repeticiones de datos)
void insertar_elemento(struct node **ref_lista, int valor);

// borra dato valor de la lista (si es que esta) 
// (si hay repeticiones borra la primera ocurrencia de valor)
void borrar_elemento(struct node **ref_lista, int valor);

// imprime la lista completa
void imprimir_lista(struct node *lista);

// funcion auxiliar
void swap(struct node *nodo1, struct node *nodo2);

// ordena los datos de la lista (usa bubble sort)
void ordenar_lista(struct node *lista);

// asumiendo que la lista esta ordenada, inserta el dato valor donde corresponde
void insertar_elemento_orden(struct node **ref_lista, int valor);
