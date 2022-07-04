#ifndef _UTILITIES_
#define _UTILITIES_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pregunta 5
#define RESISTENCIA 'R'
#define CAPACITANCIA 'C'

typedef struct n {
  float valor;
  char tipo;
  struct n *sgte;
} nodo;

typedef struct l {
  nodo *cabecera;
  nodo *centinela;
} lista;

void print_tubo(lista *l);
void print_componente(nodo *n);

#endif