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

int main()
{
    // creamos un arbol binario vacio
    struct node *root = NULL;

    // agregamos manualmente algunos nodos al arbol binario
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = 3;
    tmp->left = NULL;
    tmp->right = NULL;

    root = tmp;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = 5;
    tmp->left = NULL;
    tmp->right = NULL;

    root->left = tmp;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = 1;
    tmp->left = NULL;
    tmp->right = NULL;

    root->right = tmp;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = 4;
    tmp->left = NULL;
    tmp->right = NULL;

    root->left->right = tmp;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = 2;
    tmp->left = NULL;
    tmp->right = NULL;

    root->right->left = tmp;

    // aplicamos los recorridos
    printf("inorder");
    show_nodes_inorder(root);
    printf("\n");
    printf("preorder ");
    show_nodes_preorder(root);
    printf("\n");
    printf("postorder ");
    show_nodes_postorder(root);
    printf("\n");

    return 0;
}

// muestra los nodos inorder (I, R, D)
void show_nodes_inorder(struct node *root)
{
    if (root == NULL) {
        return;
    }
    show_nodes_inorder(root->left);
    printf("%d ", root->data);
    show_nodes_inorder(root->right);

}

// muestra los nodos preorder (R, I, D)
void show_nodes_preorder(struct node *root)
{
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    show_nodes_preorder(root->left);
    show_nodes_preorder(root->right);

}

// muestra los nodos postorder (I, D, R)
void show_nodes_postorder(struct node *root)
{
    if (root == NULL) {
        return;
    }
    show_nodes_postorder(root->left);
    show_nodes_postorder(root->right);
    printf("%d ", root->data);

}