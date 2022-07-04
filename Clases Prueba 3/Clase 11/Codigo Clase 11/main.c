#include <stdio.h>
#include "avl.h"

int main()
{
  // creamos un AVL vacio
  struct node *root = NULL;

  // en el caso del AVL al insertar el root siempre puede cambiar (por las rotaciones)
  // importante siempre escribir root = insert(root, data)
  root = insert(root, 2);
  root = insert(root, 5);
  root = insert(root, 10);
  root = insert(root, 11);
  root = insert(root, 20);
  root = insert(root, 32);
  root = insert(root, 44);
  root = insert(root, 50);

  show_nodes_preorder(root); // notar que el arbol queda balanceado
  printf("\n");
  show_nodes_inorder(root);
  printf("\n");

  // la altura queda 4 en vez de 8 (caso no balanceado)
  printf("%d\n", root->height);  

  return 0;
}

