#include <stdio.h>
#include <stdlib.h>

// estructura para nodos de arboles binarios
struct node {
  int data;
  struct node *left;
  struct node *right;
};

// muestra los nodos inorder (I, R, D)
void show_nodes_inorder(struct node *root);
// muestra los nodos preorder (R, I, D)
void show_nodes_preorder(struct node *root);
// muestra los nodos postorder (I, D, R)
void show_nodes_postorder(struct node *root);

// inserta el dato data al arbol binario de busqueda
// retorna la nueva raiz del arbol
struct node *insert(struct node *node, int data);

// busca el dato data en el arbol binario de busqueda
// retorna el primer nodo que se encuentra con el dato, o
// si el dato no esta se retorna NULL
struct node *search(struct node *root, int data);

// funcion auxiliar: entrega el nodo con el valor minimo
// (el de mas a la izquierda)
struct node *minValueNode(struct node *node); 

// funcion auxiliar: entrega el nodo con el valor maximo
// (el de mas a la derecha)
struct node *maxValueNode(struct node *node); 

// elimina el primer nodo con dato igual a data
// retorna la nueva raiz del arbol
struct node *delete(struct node *root, int data);


