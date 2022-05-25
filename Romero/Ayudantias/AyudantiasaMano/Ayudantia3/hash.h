#include <stdio.h>
#include <stdlib.h>

// hash con sondeo lineal (usamos funcion h(k) = k mod N)
void insertar_sondeolineal(int *tabla, int N, int key);
int buscar_sondeolineal(int *tabla, int N, int key);
void imprimir_tabla_sondeolineal(int *tabla, int N);


// hash con encadenamiento separado (usamos funcion h(k) = k mod N)

// estructura nodo para trabajar con listas enlazadas
struct node {
  int x;
  struct node *next;
};

// aca tabla es un arreglo de punteros a nodos, es decir, es un puntero a puntero a nodos
void insertar_encadenamiento(struct node **tabla, int N, int key);
int buscar_encadenamiento(struct node **tabla, int N, int key);
void imprimir_tabla_encadenamiento(struct node **tabla, int N);