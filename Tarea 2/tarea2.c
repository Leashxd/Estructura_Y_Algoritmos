//Importamos las bibliotecas

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

char *nombre_archivo[20];
int  *listado_personas;
char *nombre_archivo_salida[20];


#define BSIZE 1024
/* Integrantes:
    Camila Martinez
    Joaquin Leal
    Diego Alfonso Pinos 

*/

typedef struct columnas{            //definimos un struct para poder almacenar las variables    de ello llamamos un diccionario para facilitar procesos más adelante
    char firstname[100];
    char danger_category[100];
    char attack_prob[100];

}dict;


leer_csv(dict values[],char *buffer,char *nombre_archivo){

    int contador_filas = 0;
    int contador_celda = 0;

    //leemos el .txt
    FILE *archivo = fopen(nombre_archivo,"r");
    //si el archivo no se encuentra
        if (archivo == NULL){                       //condición en caso de que se presente algun problema al tratar de leer el archivo 
            printf("No es posible abrir el archivo, revise el formato y/o su directorio. %s", archivo);
            exit(1);
        }
    //PROCESO PARA LEER EL CSV
        int i=0;                                    //variable que nos ayudara a recorrer filas
        while(fgets(buffer,BSIZE,archivo)){     //leemos una fila 
            contador_filas++;

            if (i==0){ //no nos interesea obtener el nombre de las columnas, dado eso las saltamos
                i++;
                continue;
            }
            char *celda = strtok(buffer, ",");                        //leemos la cadena y separamos por excelencia ","
            for (contador_celda=0; contador_celda<4 ; contador_celda++){//este for lee las columnas y las almacena

                if(contador_celda==0){                                //si la celda = first_name
                    strcpy(values[i].firstname,celda);                //almacenamos el valor de la celda en el diccionario
                }
                if(contador_celda==1){                
                strcpy(values[i].danger_category,celda);
                }
                if(contador_celda==3){                
                strcpy(values[i].attack_prob,celda);
                }
                celda = strtok(NULL,",");
            }
            i++;

        }
    return contador_filas;
}

void mostrar_valores(dict values[],int len){

    for(int i=0; i<len;i++){
        printf("Nombre: %s     danger_categor: %s    attack_prob: %s",
        values[i].firstname,
        values[i].danger_category,
        values[i].attack_prob);
    }
}




//creamos un main para darle los argumentos de entrada
int main(int argc, char *argv[]){

    /* 
        El programa debe recibir 4 argumentos 
     ./tarea2 lista.txt 30 lista_salida.txt
          1       2       3       4 


        Lo que quiere decir que abra la lista.txt generando una lista con 30 ordenada con 30 de los nombres


    */


    //Probamos si puedo crear argv falsos

  


    char buffer[BSIZE]; 
    
    char nombre_archivo[20] = {argv[1]};
    int  listado_personas = {argv[2]};
    char nombre_archivo_salida[20] = {argv[3]};



    dict values[999];                               //creamos un diccionario para leer los valores más adelante
    
    
    int contador_filas = leer_csv(values,buffer,nombre_archivo);
    mostrar_valores(values,contador_filas);


}