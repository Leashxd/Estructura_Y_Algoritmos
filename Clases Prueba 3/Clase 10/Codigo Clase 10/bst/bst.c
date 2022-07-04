#include "bst.h"

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

// inserta el dato data al arbol binario de busqueda
// retorna la nueva raiz del arbol
struct node *insert(struct node *node, int data)
{
    if (node == NULL) { // caso arbol vacio
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = data;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;
    }

    // caso en que el arbol es no vacio
    // en este caso la raiz es la misma, por eso hacemos "return node;" al final
    // llamamos recursivamente al metodo insert ya sea al lado izquierdo o derecho
    // actualizamos el hijo correpondiente con la nueva raiz obtenida
    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else {
        node->right = insert(node->right, data);
    }

    return node;
}

// busca el dato data en el arbol binario de busqueda
// retorna el primer nodo que se encuentra con el dato, o
// si el dato no esta se retorna NULL
struct node *search(struct node *root, int data)
{
    // caso base: ya sea root es NULL, es decir, el dato no esta, o
    // el dato esta en root. En cualquier caso hay que retornar root
    if(root == NULL || root->data == data) {
        return root;
    }

    // hacemos la busqueda ya sea a la izquierda o a la derecha, 
    // y retornamos lo obtenido
    if(data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// funcion auxiliar: entrega el nodo con el valor minimo
// (el de mas a la izquierda)
struct node *minValueNode(struct node *node) 
{
    struct node *it = node;
    while (it && it->left != NULL) {
        it = it->left;
    }
    return it;
}

// funcion auxiliar: entrega el nodo con el valor maximo
// (el de mas a la derecha)
struct node *maxValueNode(struct node *node)
{
    struct node *it = node;
    while (it && it->right != NULL) {
        it = it->right;
    }
    return it;
}

// elimina el primer nodo con dato igual a data
// retorna la nueva raiz del arbol
struct node *delete(struct node *root, int data)
{
    if (root == NULL) { // caso arbol vacio
        return root;
    }

    if (data < root->data) {
        root->left = delete(root->left, data);
    }
    else if (data > root->data) {
        root->right = delete(root->right, data);
    }
    // caso que data == root->data (hay que eliminar root)
    else { 
        // cubre caso root sin hijos, o solo con hijo derecho
        if (root->left ==  NULL) { 
            struct node *temp = root->right;
            free(root);
            return temp;
        } 
        // cubre caso root con solo hijo izquierdo
        else if (root->right ==  NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // caso que root tiene los dos hijos

        // buscamos el nodo con valor minimo del subarbol derecho
        struct node *temp = minValueNode(root->right);
        // struct node *temp = maxValueNode(root->left); // otra opcion 
        root->data = temp->data; // cambiamos el dato del root
        root->right = delete(root->right, temp->data); // eliminamos el duplicado
    }
    
    return root;
}



