//Importamos las bibliotecas


#include <stdio.h>
#include <stdlib.h>

//creamos la lista enlazada

//generamos la estructura de la lista
typedef struct nodo{
    char *first_name;
    int *danger_category;
    float *attack_prob;
    struct nodo *sig;
}Mensaje;

//generamos la lista
Mensaje *Lista_Mensaje(Mensaje *Lista){
    Lista=NULL;
    return Lista;
}
