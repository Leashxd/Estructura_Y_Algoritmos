#include "listas.h"

// funcion que entrega 1 si x1 es mayor que x2 segun el orden de las estructuras
// entrega 0 en caso contrario
// x1 > x2 si x1.c > x2.c o (x1.c = x2.c y x1.nombre > x2.nombre)
int mayor_que(ejemplo x1, ejemplo x2)
{
    if (x1.c > x2.c || (x1.c == x2.c && strcmp(x1.nombre, x2.nombre) > 0)) {
        return 1;      
    }
    return 0;
}

// inserta dato al final de la lista (permitimos repeticiones de datos)
void insertar_elemento(struct node **ref_lista, ejemplo dato)
{
    if (*ref_lista == NULL) { // caso lista vacia
        struct node *nuevo_nodo = (struct node *)malloc(sizeof(struct node));
        nuevo_nodo->x = dato; 
        nuevo_nodo->next = NULL; 
        *ref_lista = nuevo_nodo;  // aca es donde modificamos la variable lista
    }
    else { // caso lista no vacia
        struct node *lista = *ref_lista;
        struct node *it = lista;
        while(it->next != NULL) { // importante preguntar it->next != NULL y no it != NULL
            it = it->next;
        }
        struct node *nuevo_nodo = (struct node *)malloc(sizeof(struct node));
        nuevo_nodo->x = dato; 
        nuevo_nodo->next = NULL; 
        it->next = nuevo_nodo;
    }
}
    
// imprime la lista completa
void imprimir_lista(struct node *lista)
{
    // recorrido simple de la lista
    struct node *it = lista;
    while(it != NULL) {
        printf("%d %s\n", (it->x).c, (it->x).nombre);
        it = it->next;
    }
}

// funcion auxiliar
void swap(struct node *nodo1, struct node *nodo2)
{
    ejemplo tmp = nodo1->x;
    nodo1->x = nodo2->x;
    nodo2->x = tmp;
}

// ordena los datos de la lista (usa bubble sort)
void ordenar_lista(struct node *lista)
{
    if (lista == NULL) { // caso lista vacia
        return;
    }

    int swapped = 1; // indica si hubo algun swap
    struct node *it = lista;
    while(swapped == 1){
        swapped = 0;
        while (it->next != NULL){
            if(mayor_que(it->x, it->next->x) == 1) { // debemos hacer swap
                swap(it, it->next);
                swapped = 1;    
            }
            it = it->next;
        }
        it = lista; // inicializamos el iterador it
    }
}

// asumiendo que la lista esta ordenada, inserta el dato donde corresponde
void insertar_elemento_orden(struct node **ref_lista, ejemplo dato)
{
    if (*ref_lista == NULL) { // caso lista vacia
        struct node *nuevo_nodo = (struct node *)malloc(sizeof(struct node));
        nuevo_nodo->x = dato; 
        nuevo_nodo->next = NULL; 
        *ref_lista = nuevo_nodo; // aca modificamos la variable lista
        return;
    }

    if (mayor_que(dato, (*ref_lista)->x) == 0) { // caso hay que insertar al principio de la lista
        struct node *nuevo_nodo = (struct node *)malloc(sizeof(struct node));
        nuevo_nodo->x = dato;
        struct node *tmp = *ref_lista; 
        *ref_lista = nuevo_nodo; // aca modificamos la variable lista
        nuevo_nodo->next = tmp;
        return;
    }

    // caso general
    struct node *lista = *ref_lista;
    struct node *it = lista;
    // buscamos el primer nodo tal que el dato del siguiente nodo es >= dato de entrada
    while(it->next != NULL && mayor_que(dato, it->next->x) == 1) {
        it = it->next;
    }
   
    struct node *nuevo_nodo = (struct node *)malloc(sizeof(struct node));
    nuevo_nodo->x = dato;
    struct node *tmp = it->next; 
    it->next = nuevo_nodo;
    nuevo_nodo->next = tmp;
}
