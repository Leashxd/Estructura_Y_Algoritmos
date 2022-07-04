#include <stdio.h>
#include "bst.h"

int main()
{
  struct node *root = NULL;

  root = insert(root, 10);
  insert(root, 5);
  insert(root, 15);
  insert(root, 11);
  insert(root, 20);
  insert(root, 3);
  insert(root, 6);
  insert(root, 13);

/*
  show_nodes_inorder(root);
  printf("\n");

  struct node *out = search(root, 12);
  if (out == NULL) {
    printf("El dato no esta\n");
  }
  else {
    printf("%d\n", out->data);
  }
  */
  
  show_nodes_inorder(root);
  printf("\n");

  root = delete(root, 10);
  root = delete(root, 12);
  root = delete(root, 6);

  show_nodes_inorder(root);
  printf("\n");

  return 0;
}

