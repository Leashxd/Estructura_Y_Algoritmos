#include <stdio.h>
#include<stdlib.h>

typedef struct nodo{
    char *nombre;
    struct nodo *sig;

}Libro;

Libro *Lista_Libro(Libro *Lista){
    Lista=NULL;
    return Lista;
}

//Creamos una funcion para agregar elementos
Libro *AgregarLibro(Libro *Lista, char *nombre){
    Libro *nuevoLibro, *aux;
    //debemos reservar memoria suficiente para este nuevo libro
    //para ello dedicamos un malloc de tipo Libro, con el tamaño que tiene la estructura
    nuevoLibro = (Libro*)malloc(sizeof(Libro));
    //Nuevo libro le debe asignar a nombre lo que tenga nombre en el momento (Guardar nuevo libro )
    nuevoLibro -> nombre = nombre;
    //como creamos un nuevo libro entonces tiene que apuntar apuntar a otra estructura para el siguiente dato
    //el cual necesariamente tiene que ser null, la siguiente casilla debe estar vacia
    //no puedo generar datos de la nada
    nuevoLibro -> sig =NULL;
    //Preguntamos el estado de la lista, en este caso si
    if (Lista==NULL){
        //si la lista esta vacia, vamos aposicionar que nuevolibro sea el primer valor
        // esto es para el primer elemento
        Lista=nuevoLibro;
    }else{
    //por lo tanto el resto de elementos pertenecen al else
    //asi generaremos una var auxiliar para asignar nuevos elementos
    //Referenciamos auxiliar con lista
        aux=Lista;
        //auxiliar[LISTA] no esta vacia quiere decir que tiene el valor anterior
        while(aux->sig != NULL){
            aux = aux -> sig;
            //entonces pasamos al siguiente
        }
        aux->sig = nuevoLibro;


    }
    return Lista;
}


int main(){
    Libro *Lista = Lista_Libro(Lista);
    Lista=AgregarLibro(Lista,"Estructura Me Tiene Mal");
    Lista=AgregarLibro(Lista,"Estructura Me Tiene Mal");
    Lista=AgregarLibro(Lista,"Estructura Me Tiene Mal");
    Lista=AgregarLibro(Lista,"Estructura Me Tiene Mal");
    // imprimimos los valores de la lista
    int i =0;
    while(Lista != NULL){
        //Mostramos el primer valor
        printf("%s\n", Lista->nombre);
        //Lista obtiene el siguiente valor
        Lista = Lista->sig;
        i++;
    }
    printf("La lista tiene %i valores",i);
    
    return 0;
}