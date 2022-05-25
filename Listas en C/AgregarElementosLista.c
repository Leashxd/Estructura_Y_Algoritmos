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
    Libro *nuevoLibro;
    //debemos reservar memoria suficiente para este nuevo libro
    //para ello dedicamos un malloc de tipo Libro, con el tamaño que tiene la estructura
    nuevoLibro = (Libro*)malloc(sizeof(Libro));
    //Nuevo libro le debe asignar a nombre lo que tenga nombre en el momento (Guardar nuevo libro )
    nuevoLibro -> nombre = nombre;
    //como creamos un nuevo libro entonces tiene que apuntar apuntar a otra estructura para el siguiente dato
    nuevoLibro -> sig =NULL;
    //Preguntamos el estado de la lista, en este caso si
    if (Lista==NULL){
        //si la lista esta vacia, vamos aposicionar que nuevolibro sea el primer valor
        // esto es para el primer elemento
        Lista=nuevoLibro;
    }else{
    //por lo tanto el resto de elementos pertenecen al else


    }
    return Lista;
}


int main(){
    Libro *Lista = Lista_Libro(Lista);
    Lista=AgregarLibro(Lista,"Estructura Me Tiene Mal");
    //Imprimimos el nombre que traiga la lista
    printf("%s\n",Lista->nombre);
    //el valor siguiente, esperamos que nos entregue un 0x0
    printf("%p\n",Lista->sig);
    return 0;
}