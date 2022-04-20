//Importamos las bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BSIZE 1024 //tamaño buffer

//creamos un struct con el objetivo de almacenar las variables del txt


typedef struct columnas{
    char first_name[100];
    int danger_category;
    float attack_prob;

}dict;


//otorgamos el puntero a argv dado que es una variable otorgada por referencia
int leer_csv(int argc,char *argv[],dict values[],float *values_categoria3, int*len_categoria3){

    /* ABRIMOS EL CSV */

    char *ruta_archivo=argv[1];
    FILE *archivo =fopen(ruta_archivo,"r");

    //Utilizaremos algunas variables para leer el csv
    int contador_filas = 0;
    int contador_celda = 0;
    char buffer[BSIZE];             //el buffer  es una variable auxiliar de largo BSIZE que almacenara de forma temporal la fila del csv para mandarlo al diccionario
    int i=0,z=0;

    if (archivo ==NULL){            //condicion en cuanto no nos sea abrir el archivo.
        perror("No es posible abrir el archivo, revise el formato y/o su directorio.");
        exit(1);
    }

    /* PARA LEER EL CSV */

    while(fgets(buffer, BSIZE,archivo)){
        contador_filas++;

        if (i==0){  //No nos interesa leer la primera fila que corresponde a las columnas,  pues la saltamos.
            i++;
            continue;
        }
        contador_celda = 0;

        char *celda = strtok(buffer,",");   //leemos la fila y separamos por ","

        for(contador_celda=0; contador_celda<3;contador_celda++ ){ 

            /* 
                Para hacer un analogo, el contador celdas es lo mismo que decir contador_columnas
            Sin embargo, lo tratamos como celda por convencion dado que se estará leyendo por columna y fila

            La logica usada aqui es, estamos dentro del ciclo while, es decir que almacenamos una fila.
            la fila en sí tiene columnas, estas columnas se iran recorriendo, y como sabemos que solo tenemos
            tres columnas, de ello la condicion de ser menor o igual a 3

            Ahora clasificaremos las celdas, realizando un append a values -nuestro diccionario-
            
             */

            if(contador_celda==0){ //Agregamos el nombre
                strcpy(values[i-1].first_name,celda);
            }
            if(contador_celda==1){  //agregamos danger_category
                values[i-1].danger_category = atoi(celda);     //atoi -> convierte el string en int
            }
            if(contador_celda==2){ //agregamos a attack_prob

                /* 
                    Para nosotros attack_prob es un caso particular, dado que puede no tener valores
                    en el caso de no tener valores su clasificacion se vuelve dependiente de attack_prob
                    y se jerarquiza de la siguiente manera.

                    if danger_category == 1 || danger_category ==2
                        entonces no se conisdera peligroso y se queda al final de la lista de attack_prob
                    
                    if danger_category == 3 
                        entonces queda en la mitad de danger_category

                    if danger_category==4 || danger_category == 5
                        entonces se considera muy peligroso quedando al principio de attack_prob
                    

                    Por lo tanto para entrar en estas condiciones debemos crear la reestriccion que 
                    compruebe que no existan valores en attack_prob

                    dado que c no puede almacenar int en NULL 
                    el equivalente a null en los integrer es 0

                    C lee las cosas de esta manera

                    int *ptr =0;

                    es lo mismo que decir

                    ptr = {conjunto vacio}

                */

               if( (strlen(celda)==1) && (celda[0]!='0') && (values[i-1].danger_category == 4|| values[i-1].danger_category==5) ){
                   values[i-1].attack_prob=40;     
                   
               }
               else{
                   if(strlen(celda)==1 && celda[0]!='0' && (values[i-1].danger_category == 1 || values[i-1].danger_category == 2 || values[i-1].danger_category == 3)){
                        values[i-1].attack_prob=-1;
                    }
                   else{
                       values[i-1].attack_prob=atof(celda);
                       if(values[i-1].danger_category==3){

                           values_categoria3[z]=atof(celda);
                           *len_categoria3=*len_categoria3+1;
                           z++;
                       }
                   }
                }

            }
            celda = strtok(NULL,","); //seguimos la cadena
        }
        i++;                          //aumentamos la iteracion
    }
    fclose(archivo);
    return(contador_filas);           //devolvemos las filas que ha recorrido el while para tener una referencia para recorrerlas en otras funciones


}


void ordenar_categoria3(dict values[],int len_csv,float *values_categoria3,int len_categoria3){
    
    //Como el nombre sumamente explicito lo dice, ordenamos los valores de categoria tres que almacenamos
    

    if (len_categoria3 >= 2){   //largo minimo que necesitamos para ordenar algun valor
        int aux,i;
        int true_aux =1;
        while(true_aux){
            
            true_aux=0;
            for(i=0;i<len_categoria3-1;i--){ //recorremos el array
                if(values_categoria3[i]>values_categoria3[i+1]){  //Condicion de tamaño, si categoria i es mayor que i+1 entonces, cambiamos el valor de lugar
                        
                    //reemplazamos apoyandonos de una var auxiliar
                    aux = values_categoria3[i];
                    values_categoria3[i] = values_categoria3[i+1];
                    values_categoria3[i+1] = aux;
                    //conservamos el valor true_aux, so, no salimos del ciclo
                    true_aux=1;
                }
            }
        }

        //Además! reemplazamos los valores en la columna, so;

        //definmos la mitad
        int mitad = len_categoria3/2;
        float mediana = (values_categoria3[mitad-1] + values_categoria3[mitad])/2;
        for(int i=0; i<len_csv-1;i++){      // metemos valores :) 
            if(values[i].danger_category == 3 && values[i].attack_prob ==-1){
                values[i].attack_prob  = mediana;
            }
        }

    }
    return;     //mitico return 
}

void swap_values(dict values[], int i){

    //la logica de esta función es la misma de ordenar_categoria3, tenemos alguna variable auxiliar que nos ayudara a reemplazar
    //definimos nuevamente nuestras variables, dado que hemos intercambiarlas, para ello:
    char first_name[100];
    int danger_category;
    float attack_prob;

    //asignamos los respectivos valores de la iteración a las variables
    //por ser string debe ser strcpy

    strcpy(first_name,values[i].first_name);
    //Al ser int y float podemos asignar simplemente el valor
    danger_category=values[i].danger_category;
    attack_prob=values[i].attack_prob;



    //siguiendo la misma logica, ya almacenadas nuestras variables, como ingresamos a swap_values dado que queriamos intercambiar los valores de i e i-1, intercambiamos
    strcpy(values[i].first_name,values[i-1].first_name);
    values[i].danger_category=values[i-1].danger_category;
    values[i].attack_prob=values[i-1].attack_prob;


    strcpy(values[i-1].first_name,first_name);
    values[i-1].danger_category=danger_category;
    values[i-1].attack_prob=attack_prob;
    return;
}
void most_wanted(dict values[],char *argv[],int len_csv){
    
        // Filtramos a los más peligrosos :)
    
    int true_aux =1;

    while(true_aux){
        true_aux =0;
        for(int i=0;i<len_csv-1;i++ ){

            if(values[i].danger_category > values[i-1].danger_category 
            || (values[i].danger_category == values[i-1].danger_category && values[i].attack_prob > values[i-1].attack_prob)
            || (values[i].danger_category == values[i-1].danger_category && values[i].attack_prob == values[i-1].attack_prob && strcmp(values[i].first_name, values[i-1].first_name)<0)){

                /* En el fondo esta condicion revela las condiciones iguales dentro del array

                    ¿Es danger_category i mayor a danger_category i-1? 
                    o
                    ¿Es danger_category i mayor a danger_category i-1 y attack_prob i mayor a attack_prob i-1?
                    o
                    ¿Es danger_category i mayor a danger_category i-1 y attack_prob i mayor a attack_prob i-1 y los nombres iguales?

                    Si alguna de las tres condiciones se cumple, pasamos a intercambiar los valores para ordenarlos.
                    Cabe recalcar que la función ordernar_categoria3 solo ordena los casos de la categoria 3

                 */
                    swap_values(values,i);
                    true_aux=1;
            }

        }

    }
    return;
}







//creamos el archivo

void output(dict values[], char *argv[], int len_csv){
    
    
    // como nuestor argv[2] es el largo output de la lista, y este será tomado como un string
    // lo transformamos a int mediante atoi
    int len_lista_output = atoi(argv[2]);
    //definiremos, si len_lista output es mayor al len csv, simplemente lo acotaremos a len csv puesto que no hay más resultados

    if(len_lista_output>len_csv){
        len_lista_output=len_csv;
    }


    //creamos el archivo de output
    //creamos un archivo con el nombre que se entrega en consola, es decir el argv[3]
    FILE *archivo_out= fopen(argv[3],"w");
    //un misero for para printear lo que buscamos que salga en el txt y listeque


    for (int i=0;i<len_lista_output+1;i++){
        fprintf(archivo_out,"%s , %i , %f\n", values[i].first_name,values[i].danger_category,values[i].attack_prob);
    }
    fclose(archivo_out);



}


/*
Creamos el main, como es un programa que requiere argumentos ingresados por consola
agregamos argc y argv 
Para aclarar dudas, 
    -> argc almacena el numeor de argumentos que se ha introducido en la consola
    -> argv almacena el valor de los argumentos que se almacena en consola
*/
int main(int argc, char *argv[]){
    dict values[999];

    float values_categoria3[999];   /* 
                                    Necesitamos este array para poder almacenar los datos que no tienen attack_prob y danger_category =3
                                    El objetivo es almacenar los valores en este array y al saber su largo podremos introducirlos al array original -values-
    
                                 */
    int len_categoria3 = 0 ;    /* Necesitamos el largo de values_categoria3  */
    int len_csv=leer_csv(argc, argv,values,values_categoria3,&len_categoria3); //Los argumentos de la consola seran redireccionados a leer_csv
    ordenar_categoria3(values,len_csv,values_categoria3,len_categoria3);
    most_wanted(values, argv, len_csv);
    output(values,argv,len_csv);
    return 0;
}

