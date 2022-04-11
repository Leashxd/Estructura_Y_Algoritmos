#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <stdlib.h>

/* Integrantes:
    Camila Martinez
    Joaquin Leal
    Diego Alfonso Pinos 

*/

#define BSIZE 1024  //tamaño del buffer para leer la cadena

int main(int argc, char *argv[]);
void encode_decode(char a[BSIZE],char b[50],char c[50], char nombre_archivo_salida[20]);

void encode_decode(char a[BSIZE],char b[50],char c[50], char nombre_archivo_salida[20]){
    //a texto ingresado
    //b palabra1
    //c palabra2 


    //palabra2 buscara algun match de letras con texto in
    //el objetivo es sacar su posicion , una vez obtenida la posicion de las letras de palabra2 en palabra_ingreada
    //hemos de reemplazar en palabra_ingresada y exportarlo en un archivo.txt
    int i=0,z=0;



    char *bUP = malloc(strlen(a));
    char *bLW = malloc(strlen(a));
    char *cUP = malloc(strlen(a));
    char *cLW = malloc(strlen(a));


    for(i=0; i<strlen(b);i++){  //transformamos nuestra palabra1 y palabra 2 en un string más largo que contenga una versión upper y otra lower para poder comparar a gusto
    bUP[i]=toupper((unsigned char)b[i]);
    cUP[i]=toupper(c[i]);
    bLW[i]=tolower(b[i]);
    cLW[i]=tolower(c[i]);
    }
    b= strcat(bUP,bLW);     //juntamos los UPPER y LOWER en el string b de forma que el string del ejemplo no es puro si no  PUROpuro para comparar el upper y lower
    c= strcat(cUP,cLW);


    for (i=0;  a[i] != '\0' ;i++){                            //for para encontrar las letras coincidentes entre palabra2 y palabra_ingresada
            for (z=0;  b[z] != '\0' ;z++){       
                if (a[i] == b[z]){  //Buscamos coincidencias entre palabra1 y palabra_ingresada
                    a[i]=c[z];
                    break; 
                }
                if (a[i]==c[z]){    //Buscamos coincidencias entre palabra2 y palabra_ingresada                
                    a[i]=b[z];      //reemplazamos por la palabra 1
                    break;          //Si encontramos coincidencias saltamos a la siguiente interación de i, para no reemplazar dos veces el mismo caracter!
                }
            }
    char* filename= nombre_archivo_salida; //se crea el nuevo arcivo txt para guardar el texto codificado/decodificado
    FILE* archivo_out =fopen(filename,"w+");
    fwrite(a,1,(strlen(a)),archivo_out);
    fclose(archivo_out);
    }
}



int main(int argc, char *argv[]){

    char buffer[BSIZE];

    char opcion1[]={"encode"};
    char opcion2[]={"decode"};

    char *palabra1={argv[3]};
    char *palabra2={argv[4]};

    char *nombre_archivo[20] = {argv[1]};
    char *nombre_archivo_salida[20] ={argv[5]};
    

    //condiciones 
    if (argc > 6){  //en el caso de que ingrese más o menos argumentos de los necesarios
        printf("ERROR: Debes ingresar 5 argumentos\n");
        return -1;
    }
    palabra1= strupr(palabra1);                     //transformamos a upper para comparar los caracteres iguales.
    palabra2= strupr(palabra2);
    for(int i=0; palabra1[i] !='\0';i++){           //Para evitar que las palabras ingresadas tengan los mismos caracteres.
        for(int z=0; palabra2[z] !='\0';z++){
            if (palabra1[i]==palabra2[z]){
                printf("Las palabras no pueden contener caracteres iguales. %s %s", palabra1,palabra2);
                return -1;
            }
        }
    }
    if(strlen(palabra1)!= strlen(palabra2)){        //Para que el largo de las palabras sea igual
        printf("ERROR: El largo de las palabras debe ser el mismo.");
        return -1;
    }
    if (strcmp(*nombre_archivo,*nombre_archivo_salida)== 0){ //Para que el archivo de entrada y salida tengan nombres distintos
        printf("ERROR: El archivo de entrada y salida deben tener nombres distintos ");
        return -1;
    }
    FILE *archivo=fopen(argv[1],"r"); // damos el directorio del archivo
    //si el archivo no se encuentra
    if (archivo == NULL){                       //condición en caso de que se presente algun problema al tratar de leer el archivo 
        perror("No es posible abrir el archivo, revise el formato y/o su directorio.");
        exit(1);
    }
    else{
        (fgets(buffer,BSIZE,archivo));          //almacenamos en buffer
    }
    fclose(archivo);


    //Filtramos la eleccion del usuario

    if(strcmp(argv[2],opcion1) == 0){ //Codificar
        encode_decode(buffer,palabra1,palabra2,*nombre_archivo_salida);
    }
    else if(strcmp(argv[2],opcion2) == 0){ //decodificar
        encode_decode(buffer,palabra1,palabra2,*nombre_archivo_salida);
    }
    else {
       printf("Por favor, ingrese una funcion valida. encode o decode");
    }
    return 0;
}