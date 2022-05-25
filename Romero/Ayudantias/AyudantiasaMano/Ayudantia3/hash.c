#include "hash.h"


void insertar_sondeolineal(int *tabla, int N, int key){


    //capturar la funcion de hash
    int i = key % N ;
    //Encontramos la primera casilla vacia
    //Mientras la casilla no sea vacia
    while(tabla[i]!= -1){
        // en caso de que ya me encontre con la llave, no tenemos que hacer nada
        if(tabla[i]==key){
            return;
        }
            //sondeo lineal, es circular, si llegamos la ultima pos, Volvemos al inicio
            i = (i + 1 ) % N;
  
    }
    //insertamos la llave cuando la casilla sea vacia
    tabla[i] = key;
}

int buscar_sondeolineal(int *tabla, int N, int key){
    //capturar la funcion de hash
    int i = key % N ;
    //Encontramos la primera casilla vacia
    //Mientras la casilla no sea vacia
    while(tabla[i]!= -1){
        // en caso de que ya me encontre con la llave, devuelvo la llave
        if(tabla[i]==key){
            return i;
        }
            //sondeo lineal, es circular, si llegamos la ultima pos, Volvemos al inicio
            i = (i + 1 ) % N;
  
    }
    //si no encontramos el valor quiere decir que salimos del while
    //entonces retornamos -1
    return -1;
}

void imprimir_tabla_sondeolineal(int *tabla, int N){


    for(int i=0; i<N ;i++){
        printf("%d\n",tabla[i]);
    }
}

//Encadenamiento


void insertar_encadenamiento(struct node **tabla, int N, int key){
    //aplicamos la funcion de hash
    int i =  key % N;
    //definimos un iterador 
    struct node *it = tabla[i];

    //OTRO CASO BORDE
            //Si la lista es vacia
    if(tabla[i] == NULL){
        //quiero insertar la llave en la tabla i
        //inserto el nodo
        struct node *nuevo_nodo = (struct node*)malloc(sizeof(struct node));
        //el nuevo valor del nodo, lo que insertamos
        nuevo_nodo -> x =key;
        //entonces el siguiente es NULL, porque es el ultimo
        nuevo_nodo-> next =NULL; 
        //Nuestra tabla i queda como nuevo nodo -el primero-
        tabla[i] = nuevo_nodo;

    }
    //Si no es vacia, ejecutamos
    else{
        //si la lista es de valor 1 y el valor que ingresamos ya esta en la lista
        //notamos que nos saltamos el while, so
        if(it->x == key){
            return;
        }//contemplamos el caso borde

        

        //queremos iterar hasta el final
        //entonces queremos llegar al ultimo valor para poder llegar al null
        //so
        while(it->next != NULL){
            if(it->x == key){
                return;
            }
            //pregnuntamos si el proximo valor es nulo
            it = it->next;
        }
        //cuando salgo del while, tenemos claro el it que apunta el nodo /NULL
        struct node *nuevo_nodo = (struct node*)malloc(sizeof(struct node));
        //el nuevo valor del nodo, lo que insertamos
        nuevo_nodo -> x =key;
        //entonces el siguiente es NULL, porque es el ultimo
        nuevo_nodo-> next =NULL; 
        //el iterador apunta al siguiente nodo
        it -> next =nuevo_nodo;
    }
} 


int buscar_encadenamiento(struct node **tabla, int N, int key){

  //aplicamos la funcion de hash
    int i =  key % N;
    //definimos un iterador 
    struct node *it = tabla[i];
    //queremos recorrer solo la lista que esta en it
    while(it != NULL){
        //es it == a key?
        if(it->x == key){
            return i;
        }//Pasamos al siguiente iteracion
        it = it-> next;
    }
    //si no esta el valor entregamos un menos 1
    return -1;
}

void imprimir_tabla_encadenamiento(struct node **tabla, int N){
    for(int i = 0 ; i<N;i++ ){
        struct node *it = tabla[i];

        while(it != NULL){
        printf("%d",it->x);
        it= it->next;   
        }
    printf("\n");
    }
}