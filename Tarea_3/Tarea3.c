//Importamos las bibliotecas


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 1024
#define tamano_hash 5

//definimos los atributos de la lista
struct nodo{
    char first_name[50];
    float attack_prob;
    //no agregamos danger_category dado que es el tamaño del hash
    //autoreferenciamos la lista para que sea 'lista'
    struct nodo *sig;

};

int leer_csv(char *argv[],struct nodo *Lista_hash[]){
    
    //almacenamos el nombre dek archivo csv
    char *ruta_archivo = argv[1];
    FILE *archivo = fopen(ruta_archivo,"r");

    //utilizamos variables para leer el csv
    int contador_celda=0;
    int contador_danger3 =0;
    char buffer[BSIZE]; //variable auxiliar apra leer el largo de una fila
    int i=0;//variables auxiliares para leer el csv

    if(archivo == NULL){
        perror("No es posible abrir el archivo, revise su formato y/o directiorio");
        exit(1);
    }
    //Para leer el csv
    while(fgets(buffer, BSIZE, archivo)){
        
        if(i==0){//saltamos la primera fila dado que son los nombres de las columnas
            i++;
            continue;
        }

        contador_celda=0;
        int danger_category=0; //para almacenar dangercategory al leer el csv
        char *celda = strtok(buffer,",");
        //creamos un nuevo nodo cada vez que se itera

        struct nodo *nuevonodo = (struct nodo *)malloc(sizeof(struct nodo));


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

                //todos los que tienen numero, seran asignados al nodo
                nuevonodo -> attack_prob = atof(celda);

                if(strlen(celda)== 1 && celda[0] != '0' && (danger_category==4 || danger_category==5)){
                    //Si el valor existe, y este es distitnot de 0 y este pertenece a danger 4 o 5, lo colocamos como uno de los mas peligrosos
                    nuevonodo -> attack_prob = 100;
                }                
                else{
                    if(strlen(celda)== 1 && celda[0] != '0' && (danger_category==1 || danger_category==2)){
                        
                        nuevonodo -> attack_prob = -1;

                    }
                }
                celda = strtok(NULL, ",");               
            }
            if(danger_category == 3 && nuevonodo -> attack_prob != -1 || nuevonodo -> attack_prob != 100){
                //en el caso que danger category sea 3 y que el nuevo nodo sea distinto de alguna de los filtros anteriores
                //aumentamos el contador
                contador_danger3++;
            }
            //ahora que hemos creado nodos para clasificar segun attack_prob dado danger category
            //nos toca meterlo a una funcion de hashing
            //la cual estara se ejecutara durante cada ciclo
            //es decirm que para el ciclo 1, se decide para el nodo que toque en la iteracion donde debe ir
            

            //Antes de generar el hash, debemos crear los casos bordes
            //En el caso que la lista este vacia
            if(Lista_hash[danger_category] == NULL){
                //si esta vacia quiere decir que el header es null
                //queremos que el valor siguiente a header sea null para meter
                //algun valor a 1 que su direccion este en header
                nuevonodo->sig = NULL;
                //Ya que el nuevo nodo paso al siguiente valor 
                // el nuevo nodo necesariamente tiene que ser null

            }

        }
    }
    
}

int main(int argc, char *argv[]){

    //creamos el hash
    struct nodo *Lista_hash[tamano_hash];    

    //todas las listas hash tienen que partir en null
    for(int i=0; i<tamano_hash ; i++){
        Lista_hash[i]=NULL;
    }

    //Leemos los datos y ordenaremos el csv en la lista hash
    int len_csv = leer_csv(argv,Lista_hash);

}