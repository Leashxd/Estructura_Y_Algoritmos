//Importamos las bibliotecas


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BSIZE 1024
#define tamano_hash 5

//definimos los atributos de la lista
struct nodo{
    char first_name[100];
    float attack_prob;
    //no agregamos danger_category dado que es el tamaño del hash
    //autoreferenciamos la lista para que sea 'lista'
    struct nodo *sig;

};
// a leercsv le otorgamos los argumentos que ingresamos en consola
//y la tabla hash
int leer_csv(char *argv[], struct nodo **Hash){
    //almacenamos el nombre dek archivo csv
    char *ruta_archivo = argv[1];
    FILE *archivo = fopen(ruta_archivo,"r");

    //utilizamos variables para leer el csv
    int contador_celda=0;
    int contador_danger3 =0;
    char buffer[BSIZE]; //variable auxiliar apra leer el largo de una fila
    int i=0;//variables auxiliares para leer el csv

    
    //En caso de que no podamos leer el archivo, un simple caso borde
    if(archivo == NULL){
        perror("No es posible abrir el archivo, revise su formato y/o directiorio");
        exit(1);
    }

    //Para leer el csv, esto esta explicado en las tareas anteriores
    int danger_category=0; // inicializamos en 0, entonces cada vez que entre cambia. Nos ayuda a filtrar por la variable en cuestion
    while(fgets(buffer, BSIZE, archivo)){


        if(i==0){//saltamos la primera fila dado que son los nombres de las columnas
            i++;
            continue;
        }

        contador_celda=0;
        char *celda = strtok(buffer,",");       //para separar la cadena por cada ',' que encuentre.
        
        //creamos un nuevo nodo cada vez que se itera, del tamaño suficiente, esto se logra autoreferenciando 
        //queremos que me guarde un espacio de memoria del tamaño del struct de nodo
        struct nodo *nuevonodo = (struct nodo *)malloc(sizeof(struct nodo));

        //Entonces filtramos., tenemos 3 columnas, la interseccion fila columna le llamaremos celda
        for(contador_celda=0;contador_celda<3; contador_celda++){

            if(contador_celda == 0){//first.name
                //A diferencia de la tarea anterior no trabajamos con un array
                //entonces tenemos que copiar al fistname del struct el firstname
                //el cual se extrae de celda
                strcpy(nuevonodo->first_name,celda);
            }
            

            if(contador_celda == 1){//danger category
                danger_category = atoi(celda);
            }
            if(contador_celda== 2){//attack prob

                //entonces el attack_prob del nuevo nodo tendra el valor del string de la celda 2
                //sin embargo, convertimos este string a float, dado que es una attack_prob
                nuevonodo -> attack_prob = atof(celda);
                
                //si el valor existe y no comienza con un 0
                if(strlen(celda)==1 && celda[0] != '0'){
                    //filtramos
                        if(danger_category==4 || danger_category==5){
                        //Si el valor existe, y este es distitnot de 0 y este pertenece a danger 4 o 5, lo colocamos al inicio de la lista
                        nuevonodo -> attack_prob = 100;
                        }                
                        else{
                            if(danger_category==1 || danger_category==2 || danger_category==3){
                                //por el contrario, si el valor existe, y pertenece al danger category 1 o 2, lo mandamos al final de la lista
                                nuevonodo -> attack_prob = -1;

                            }
                        }           
                }      
            }
            celda = strtok(NULL, ",");             // solo para separar luego de terminar la lectura de la fila
        }//se cierra el ciclo for
            if(danger_category == 3 && nuevonodo -> attack_prob != -1 ){
                //en el caso que danger category sea 3 y que el attack prob del nuevo nodo no tenga los valores anteriormente atribuidos
                //creamos un contador para dangercategory el cual nos dira que tantos elementos estan en esat situacion
                contador_danger3++;
            }
            //ahora que hemos creado nodos para clasificar segun attack_prob dado danger category
            //nos toca meterlo a una funcion de hashing
            //la cual estara se ejecutara durante cada ciclo
            //es decirm que para el ciclo 1, se decide para el nodo que toque en la iteracion donde debe ir
            
            //generamos un iterador que nos ayudara en el proceso para asignar los valores de Hash
            

            //Antes de generar el hash, debemos crear los casos bordes
            //En el caso que la lista este vacia
            //debemos bajar la funcion de hash opr cada iteracion del while
            danger_category= danger_category-1;
            if(Hash[danger_category] == NULL){
                //si esta vacia quiere decir que el header es null
                //queremos que el valor siguiente a header sea null para meter
                //algun valor a 1 que su direccion este en header
                nuevonodo->sig = NULL;
                //Ya que el nuevo nodo paso al siguiente valor 
                // el nuevo nodo necesariamente tiene que ser null
                //entonces en este el hash en la posicion de dangercategory quedara como nuevonodo
                Hash[danger_category] = nuevonodo;

            }
            else{//si Hash no esta vacia
                //comprobamos que el iterador y el valor actual de attack prob sean distintos
                struct nodo *it =Hash[danger_category];
                if(nuevonodo->attack_prob > it->attack_prob ){
                    //si lo son y el del nuevo nodo es mayor, iteramos
                    nuevonodo->sig=it;
                    Hash[danger_category] = nuevonodo;
                    //Es el mismo proceso que se realiza al comprobar que los datos no sean nulos.
                }
                else{
                    //Debemos definir la iteracion de it dado que esta debe recorrerse
                    //entonces esta mientras no sea nula puede iterar
                    //mientras no sea null y el los attack probability sean distintos
                    while (it -> sig != NULL && (nuevonodo->attack_prob < it-> sig -> attack_prob)){
                        
                        //iteramos
                        it = it ->sig;
                        
                    }
                     
                    //luego de iterar el siguiente nodo de nuestro nuevo nodo sera el siguiente nodo del iterador
                    nuevonodo -> sig = it->sig;
                    //Y reasignamos el suigiente del iterador al nuevo nodo, una forma similar de comprenderlo es lo mismo que se
                    //utiliza para resolver los NULL pero estamos reemplazando los NULLS por un nuevo nodo
                    it -> sig = nuevonodo;
                }
            }
            i++;
    }//cierra el primer while


    //cerramos el archivo luego de almacenar todo
    fclose(archivo);
    //nos interesa retornar las flas del csv y el numero de atributos que fueron a parar al contador con danger 3
    //descontamos del i la fila con los nombres de las columnas.
    return(i-1,contador_danger3);

    
}//cierra leer csv




void ordenamiento(struct nodo *Hash[], int contador_danger3){
    //metodo dedicado unicamente a ordenar el caso donde danger category es = 3
    //dado que tenemos la lista de valores con danger category = 3 debemos crear una sublista para
    //poder ordenar esos valores dentro de la tabla hash

    //definimos el iterador enfocado donde queremos trabajar
    struct nodo *it = Hash[2]; 
    //trabamos unicamente en el bucket 2 dado que queremos sub ordenar la lista que creamos en ese bucket
    // se entiende que cuando hablamos sobre bucket 2 hablamos realmente del 3, 2 en temas de programacion

    struct nodo *it_back = NULL; 
    struct nodo *it_head = NULL; 

    //fila en nuestra lista del bucket 2
    int fila = 0;
    //definimos la mediana para colocar los valores en ella
    //Como sabemos que los valores pueden ser impares siempre trabajaremos uno hacia abajo
    int mediana = (contador_danger3/2)-1;
    //la mediana esta definida

    //mientras nuestro valor del iterador no sea null
    while(it->sig != NULL) {
        //Filtramos
        //Aqui tenemos 2 filtros.
        

        //Si el iterador fila es igual a la mediana
        //el iterador final tendra el valor de el iterador del momento
        if (fila == mediana) {
            it_back = it;
        }
        //en este caso, el cual es el comun, si la fila es igual al contador de danger
        //este sera la cabeza
        else if (fila == contador_danger3-1){
            it_head = it;
        }
        //pasamos al siguiente nodo
        it = it->sig;
        fila++;
    }

    
    it->sig = it_back->sig;
    it_back->sig = it_head->sig;
    it_head->sig = NULL;

}


void GuardarCSV(char **argv, struct nodo **Hash, int len_csv){

    FILE *archivo_salida = fopen(argv[3],"w"); //Creamos un archivo el cual tendra el nombre del tercer argumento que se le entregue al programa
    //El segundo atributo de argv es que tantos atributos de la lista quiero almacenar en mi archivo de salida
    int len_guardar = atoi(argv[2]);
    //caso borde, si el lenguardar es mayor a la cantidad de filas que tengo, simplemente por backend lo igualo y el usuario nunca se entera
    //este tipo de desicion solo tiene repercusion en que no tendre la cantidad de filas que deseo, solo la que el archivo me permita
    if(len_guardar > len_csv){
        len_guardar = len_csv;
    }
    //Mensaje para el txt
    fprintf(archivo_salida, "Los mas peligrosos son: \n\n\n");
    int len_aux=0;
    //escribimos nuestra tabla hash en el csv, en forma de cola
    for(int columna = 4; columna > -1; columna--){
        //entonces utilizando los metodos de impresion de las pilas y colas
 
        struct nodo *it = Hash[columna];
        
        while(it != NULL && len_aux < len_guardar){
            fprintf(archivo_salida, "%s\n", it->first_name);
            it = it -> sig;
            len_aux++;

        }
        if(len_aux == len_guardar){ //si el indice recorrido coincide con la cantidad de filas a guardar, simplemente rompemos el ciclo
            break;
        }
    }
    //Terminamos de leer y cerramos, lo que es equivalente a guardar.
    fclose(archivo_salida);

}

//Creamos el main
int main(int argc, char *argv[]){

    //creamos el hash
    //este tiene un tamaño definido anteriormente de 5
    struct nodo *Hash[tamano_hash];    

    //Inicializamos todas las listas en NULL para indicar que estan vacias
    for(int i=0; i<tamano_hash ; i++){
        Hash[i]=NULL;
    }

    //Leemos los datos y ordenaremos el csv en la lista hash
    printf("Entra a LEERCSV");
    int len_csv,contador_danger3 = leer_csv(argv,Hash);
    printf("Entra a Ordenamiento");
    ordenamiento(Hash,contador_danger3);
    printf("Entra a Guardar");
    GuardarCSV(argv,Hash,len_csv);
    printf("\n Se ha ordenado el csv con exito!");
    return 0;
}