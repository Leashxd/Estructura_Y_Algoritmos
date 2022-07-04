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

// estructura para la cola (queue)
typedef struct {
  struct node *head;
  struct node *back;
  } queue;

// crea una cola vacia
queue *create_queue();

// inserta un elemento a la cola (permitimos repeticiones)
void push_queue(queue *Q, int valor);


// entrega el siguiente elemento de la cola
int pop_queue(queue *Q);


// imprimir cola
void print_queue(queue *Q);



// estructura para la pila (stack)
typedef struct {
  struct node *head;
  } stack;

// crea una pila vacia
stack *create_stack();

// inserta un elemento a la pila (permitimos repeticiones)
void push_stack(stack *S, int valor);


// entrega el siguiente elemento de la pila
int pop_stack(stack *S) ;

// imprimir pila
void print_stack(stack *S);


