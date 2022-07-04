#include "queue_stack.h"

// crea una cola vacia
queue *create_queue()
{
    queue *out = (queue *)malloc(sizeof(queue));
    out->head = NULL;
    out->back = NULL;

    return out;
}

// inserta un elemento a la cola (permitimos repeticiones)
void push_queue(queue *Q, int valor)
{
  if (Q->head == NULL) {
    struct node *nuevo_nodo = (struct node *)malloc(sizeof(struct node));
    nuevo_nodo->x = valor;
    nuevo_nodo->next = NULL;
    Q->head = nuevo_nodo;
    Q->back = nuevo_nodo;
  }
  else {
    struct node *nuevo_nodo = (struct node *)malloc(sizeof(struct node));
    nuevo_nodo->x = valor;
    nuevo_nodo->next = NULL;
    Q->back->next = nuevo_nodo;
    Q->back = nuevo_nodo;
  } 
}

// entrega el siguiente elemento de la cola
int pop_queue(queue *Q) 
{
  int out;
  if (Q->head == NULL) {
    return -1;
  }
  else {
    struct node *tmp = Q->head->next;
    out = Q->head->x;
    free(Q->head);
    Q->head = tmp;
  }

  if (Q->head == NULL) {
    Q->back = NULL;
  }

  return out;
  
}

// imprimir cola
void print_queue(queue *Q)
{
  printf("Cola: ");
  struct node *it = Q->head;
  while(it != NULL) {
    printf("%d ", it->x);
    it =it->next;
  }
  printf("\n");
}

// crea una pila vacia
stack *create_stack()
{
    stack *out = (stack *)malloc(sizeof(stack));
    out->head = NULL;

    return out;
}

// inserta un elemento a la pila (permitimos repeticiones)
void push_stack(stack *S, int valor)
{
  struct node *nuevo_nodo = (struct node *)malloc(sizeof(struct node));
  nuevo_nodo->x = valor;
  struct node *tmp = S->head;
  S->head = nuevo_nodo;
  nuevo_nodo->next = tmp;
}

// entrega el siguiente elemento de la pila
int pop_stack(stack *S) 
{
  int out;
  if (S->head == NULL) {
    return -1;
  }
  else {
    struct node *tmp = S->head->next;
    out = S->head->x;
    free(S->head);
    S->head = tmp;
  }

  return out;
}

// imprimir pila
void print_stack(stack *S)
{
  printf("Pila: ");
  struct node *it = S->head;
  while(it != NULL) {
    printf("%d ", it->x);
    it =it->next;
  }
  printf("\n");
}


