#include <stdlib.h>
#include <stdio.h>

/* estrucutra nodo para trabajar con listas enlazadas
int x es el dato a guardar. 
En general, los datos podrian ser varias variables de cualquier tipo 
(por ejemplo estructuras) */ 

struct node {   
  int x;
  struct node *next;
  };

int main(int argc, char* argv[]) {

  // esta es la forma de inicializar una lista vacia
  // la variable lista representa a la lista enlazada y apunta al primer nodo
  // cuando no hay nada a que apuntar lo asignamos al puntero vacio NULL
  struct node *lista = NULL;
  
  // agregamos "a mano" un nodo nodo1 al final de la lista enlazada
  // Recordar que nodo1->x es una abreviacion de (*nodo1).x
  struct node *nodo1 = (struct node *)malloc(sizeof(struct node));
  nodo1->x = 10; // seteamos el dato de nodo1
  nodo1->next = NULL; // el siguiente de nodo1 es NULL ya que queda al final de la lista
  lista = nodo1; // actualizamos lista a apuntar al primer nodo de la lista, es decir, nodo1

  // agregamos "a mano" otro nodo nodo2 al final de la lista enlazada
  struct node *nodo2 = (struct node *)malloc(sizeof(struct node));
  nodo2->x = 20; // seteamos el dato de nodo2
  nodo2->next = NULL; // el siguiente de nodo2 es NULL ya que queda al final de la lista
  nodo1->next = nodo2; // el siguiente nodo de nodo1 pasa a ser nodo2
  
  // imprimimos los datos de la lista
  //printf("%d ", lista->x);
  //printf("%d\n", lista->next->x);


  /* en general, para agregar un elemento al final de la lista necesitamos 
mantener un iterador que recorre los nodos (con un while) y
y deternos cuando estemos en el ultimo nodo, es decir, cuando next == NULL */

  // queremos insertar nodo3 con dato 30
  struct node *it = lista;
  while(it->next != NULL) {
    it = it->next;
  }
  struct node *nodo3 = (struct node *)malloc(sizeof(struct node));
  nodo3->x = 30;
  nodo3->next = NULL;
  it->next = nodo3;
  // IMPORTANTE: el while anterior falla si la lista es vacia, 
  // ya que lista->next arroja error
  // En el while de arriba asumimos que la lista es no vacia

  // Para hacer una insercion de un nodo en el caso mas general posible, 
  // debemos considerar el caso cuando la lista es vacia (ver ejemplo abajo)
  // Insertemos un nodo4 asumiendo que eventualmente la lista podria ser vacia

  if(lista == NULL) { // caso que la lista es vacia
    struct node *nodo4 = (struct node *)malloc(sizeof(struct node));
    nodo4->x = 40; 
    nodo4->next = NULL; 
    lista = nodo4; 
  }
  else { // caso que la lista no es vacia
    struct node *it2 = lista;
    while(it2->next != NULL) {
      it2 = it2->next;
    }
    struct node *nodo4 = (struct node *)malloc(sizeof(struct node));
    nodo4->x = 40;
    nodo4->next = NULL;
    it2->next = nodo4;
  }

  // para recorrer la lista hacemos simplemente un while 
  // hasta que el puntero actual sea NULL
  // A diferencia de la insercion, no es necesario detenerse cuando it->next == NULL, 
  // sino cuando it == NULL ya que no necesitamos actualizar ningun puntero

  // esta es la forma a "mano" de recorrer nuestra lista (imprimir los datos)
  //printf("%d ", lista->x);
  //printf("%d ", lista->next->x);
  //printf("%d ", lista->next->next->x);
  //printf("%d\n", lista->next->next->next->x);

  // esta es la forma general (y correcta) de imprimir los datos
  struct node *it3 = lista;
  while(it3 != NULL) {
    printf("%d ", it3->x);
    it3 = it3->next;
  }
  printf("\n");

  // para insertar un nodo en otro lugar que no sea el final de la lista
  // buscamos el nodo anterior a ese lugar y actualizamos los punteros como corresponde

  // Digamos que queremos insertar el dato 25, en la posicion que le corresponde 
  // (asumiendo que la lista esta ordenada)

  // Buscamos el primer nodo tal que el dato de next es >= a 25 (o NULL)
  struct node *it4 = lista;
  while(it4->next != NULL && it4->next->x < 25) {
    it4 = it4->next;
  }
  // sabemos que estamos en la posicion anterior donde debe ir el dato 25
  // insertamos el nodo nuevo
  struct node *nodo5 = (struct node *)malloc(sizeof(struct node));
  nodo5->x = 25;
  struct node *tmp = it4->next; // esto es clave, sino perdemos la referencia a next
  it4->next = nodo5;
  nodo5->next = tmp;

  // veamos el resultado
  it3 = lista;
  while(it3 != NULL) {
    printf("%d ", it3->x);
    it3 = it3->next;
  }
  printf("\n");

  // IMPORTANTE: si queremos insertar al principio hay que hacer algo ligeramente diferente, 
  // ya que no existe la "posicion anterior" a donde queremos insertar

  // supongamos que queremos insertar el dato 5 al principio (y asi la lista siga ordenada)
  struct node *nodo6 = (struct node *)malloc(sizeof(struct node));
  nodo6->x = 5;
  tmp = lista; // esto es clave, sino perdemos la referencia al primero nodo
  lista = nodo6;
  nodo6->next = tmp;

  // veamos el resultado
  it3 = lista;
  while(it3 != NULL) {
    printf("%d ", it3->x);
    it3 = it3->next;
  }
  printf("\n");

  // para borrar un elemento nos posicionamos en el nodo anterior y actualizamos los punteros
  // como corresponde. Importante liberar la memoria del nodo que estamos borrando (usando free)

  // Digamos que queremos borrar el elemento 25 (asumimos que esta)
  struct node *it5 = lista;
  while(it5->next != NULL && it5->next->x != 25) {
    it5 = it5->next;
  }
  tmp = it5->next; // esto es clave para no perder la direccion a la que aplicamos free
  it5->next = it5->next->next;
  free(tmp);

  // veamos el resultado
  it3 = lista;
  while(it3 != NULL) {
    printf("%d ", it3->x);
    it3 = it3->next;
  }
  printf("\n");

  // IMPORTANTE: en general hay que poner casos de bordes cuando no encontramos el elemento, 
  // es decir, al salir del while it5->next == NULL o queremos borrar el primer elemento 

  // Una forma de borrar alternativa es la siguiente
  // Digamos que queremos borrar el elemento 20 (asumimos que esta)
  struct node *it6 = lista;
  while(it6->next != NULL && it6->next->x != 20) {
    it6 = it6->next;
  }
  tmp = it6->next->next;
  free(it6->next);
  it6->next = tmp;

  // veamos el resultado
  it3 = lista;
  while(it3 != NULL) {
    printf("%d ", it3->x);
    it3 = it3->next;
  }
  printf("\n");
}
