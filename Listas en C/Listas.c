
//Importamos las bibliotecas

#include <stdio.h>
#include <stdlib.h>


/* 
    Una lista enlazada es una coleecion de strucuturas autoreferenciadas, a las cuales se les llama nodos

    Con este tipo de listas podemos guardar y modificar datos en ejecucion, otra gran ventaja reside en que no necesitamos saber 
    el largo de la lista, esta puede construirse hasta que se necesite.


    Una lista, tiene un puntero, el cual estara apuntando a una estructura del mismo tipo

 */
// asi pues

//creamos la estrucutura nodo
typedef struct nodo{
    //esta tiene un nombre
    char *nombre;
    // une la strctura de tipo nodo con otra del mismo tipo
    //entonces, si existe otro elemento en la misma lista, utilizaremos la linea siguiente para poder
    //crear una estructura como esta para que se autoreferencie.
    struct nodo *sig;
}Libro;


/* El rol del typedef es que nos permite colocarle un 'Sobrenombre' a nuestra estructura llamada nodo
Entonces podemos referenciar a LIBRO para poder agregar elementos en los nodos

¿Que es un nodo?
    Un nodo es una estructura que se crea con memoria dinamica

*/


//Genereamos la lista
//nos devuelve UN PUNTERO de tipo LIBRO, este tipo perfectamente podria ser un INT o un STRING para otros efectos
/* 
Libro > tipo de variable
*lista libro > puntero que queremos obtener ¿Pero de donde queremos obtener el puntero? de una Lista ¿QUe tipo? Libro
 */
Libro *Lista_Libro(Libro *Lista){
    //Le decimos que el valor de la lista es NULO
    Lista = NULL;
    //Que nos devuelva lista
    return Lista;
}

//Imprimimos los valores de la lista en el main
int main(){

    //llamamos a la funcion con un apuntador de tipo libro al que llamamos lista la cual llama a la funcion listalibro con el parametro LISTA
    Libro *Lista = Lista_Libro(Lista);
    printf("%p\n", Lista);
    return 0;
}

/* Notamos que nos imprime un 0x0 esto quiere decir que la lista esta vacia */