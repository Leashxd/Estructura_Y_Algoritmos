#include "utilities.h"

void print_tubo(lista *l) {
  nodo *tmp = l->cabecera;
  printf("cabecera ");
  if (tmp == NULL) {
    printf("--||\ncentinela--||\n");
  } else {
    while (tmp != NULL) {
      printf("<-> ");
      print_componente(tmp);
      tmp = tmp->sgte;
    }
    printf("<-> centinela\n");
  }
  
  if (l->cabecera == NULL) {
    printf("cabecera: null"); 
  }
  else {
    printf("cabecera: %f (%c)", l->cabecera->valor, l->cabecera->tipo); 
  }

  if (l->centinela == NULL) {
    printf("\tcentinela: null\n"); 
  }
  else {
    printf("\tcentinela: %f (%c)\n", l->centinela->valor, l->centinela->tipo); 
  }
  
}

void print_componente(nodo *n) { printf("%f (%c) ", n->valor, n->tipo); }