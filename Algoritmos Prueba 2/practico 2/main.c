#include "utilities.h"
#if pregunta == 1
#include "pregunta_1.h"
#elif pregunta == 2
#include "pregunta_2.h"
#elif pregunta == 3
#include "pregunta_3.h"
#elif pregunta == 4
#include "pregunta_4.h"
#elif pregunta == 5
#include "pregunta_5.h"
#endif
int main(int argc, char* argv[]) {
#if pregunta == 1
  lista* tubo = crear_tubo();
  print_tubo(tubo);
#elif pregunta == 2
  lista l;
  l.cabecera = NULL;
  l.centinela = NULL;
  insertar_resistencia(1.0, &l);
  insertar_resistencia(5.0, &l);
  insertar_resistencia(3.0, &l);
  printf(
      "\nInserto 3 resistencias en el tubo vacío: La primera es de 1.0, la "
      "segunda es de 5.0 y la tercera es de 3.0\n\n ");
  print_tubo(&l);

  nodo n;
  n.tipo = CAPACITANCIA;
  n.valor = 4.5;
  n.sgte = NULL;
  l.cabecera = &n;
  l.centinela = &n;
  insertar_resistencia(1.0, &l);
  insertar_resistencia(5.0, &l);
  insertar_resistencia(3.0, &l);
  printf(
      "\nInserto 3 resistencias en el tubo que contiene una capacitancia de "
      "valor 4.5: La primera es de 1.0, la segunda es de 5.0 y la tercera es "
      "de 3.0\n\n ");
  print_tubo(&l);
#elif pregunta == 3
  lista l;
  l.cabecera = NULL;
  l.centinela = NULL;
  insertar_capacitancia(1.0, &l);
  insertar_capacitancia(5.0, &l);
  insertar_capacitancia(3.0, &l);
  printf(
      "\nInserto 3 capacitancias en el tubo vacío: La primera es de 1.0, la "
      "segunda es de 5.0 y la tercera es de 3.0\n\n ");
  print_tubo(&l);

  nodo n;
  n.tipo = RESISTENCIA;
  n.valor = 4.5;
  n.sgte = NULL;
  l.cabecera = &n;
  l.centinela = &n;
  insertar_capacitancia(1.0, &l);
  insertar_capacitancia(5.0, &l);
  insertar_capacitancia(3.0, &l);
  printf(
      "\nInserto 3 capacitancias en el tubo que contiene una resistencia de "
      "valor 4.5: La primera es de 1.0, la segunda es de 5.0 y la tercera es "
      "de 3.0\n\n ");
  print_tubo(&l);
#elif pregunta == 4
  lista l;
  nodo n1, n2, n3, n4, n5, n6;
  n1.tipo = RESISTENCIA;
  n1.valor = 1.0;
  n2.tipo = RESISTENCIA;
  n2.valor = 2.0;
  n3.tipo = RESISTENCIA;
  n3.valor = 3.0;
  n4.tipo = RESISTENCIA;
  n4.valor = 4.0;
  n5.tipo = CAPACITANCIA;
  n5.valor = 5.0;
  n6.tipo = CAPACITANCIA;
  n6.valor = 6.0;

  l.cabecera = &n1;
  n1.sgte = &n2;
  n2.sgte = &n3;
  n3.sgte = &n4;
  n4.sgte = &n5;
  n5.sgte = &n6;
  n6.sgte = NULL;
  l.centinela = &n6;

  print_tubo(&l);

  int num_resistencias = contar_componentes(RESISTENCIA, &l);
  int num_capacitancias = contar_componentes(CAPACITANCIA, &l);

  printf("El número de resistencias encontradas en el tubo es de %i\n",
         num_resistencias);
  printf("El número de capacitancias encontradas en el tubo es de %i\n",
         num_capacitancias);

#elif pregunta == 5
  lista l;
  nodo n1, n2, n3, n4, n5, n6;
  n1.tipo = RESISTENCIA;
  n1.valor = 1.0;
  n2.tipo = RESISTENCIA;
  n2.valor = 2.0;
  n3.tipo = RESISTENCIA;
  n3.valor = 3.0;
  n4.tipo = RESISTENCIA;
  n4.valor = 4.0;
  n5.tipo = CAPACITANCIA;
  n5.valor = 5.0;
  n6.tipo = CAPACITANCIA;
  n6.valor = 6.0;

  l.cabecera = &n1;
  n1.sgte = &n2;
  n2.sgte = &n3;
  n3.sgte = &n4;
  n4.sgte = &n5;
  n5.sgte = &n6;
  n6.sgte = NULL;
  l.centinela = &n6;

  print_tubo(&l);

  nodo* aux = eliminar_componente(3.0, RESISTENCIA, &l);
  printf("\nIntentando eliminar resistencia con valor 3\n");
  if (aux == NULL) {
    printf("Resistencia no encontrada\n");
  } else {
    printf("Resistencia eliminada\n\n");
  }
  print_tubo(&l);

  aux = eliminar_componente(6.0, CAPACITANCIA, &l);
  printf("\nIntentando eliminar capacitancia con valor 6\n");
  if (aux == NULL) {
    printf("Capacitancia no encontrada\n");
  } else {
    printf("Capacitancia eliminada\n\n");
  }
  print_tubo(&l);


#endif

  return 0;
}