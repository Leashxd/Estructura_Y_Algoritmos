#include <stdio.h>


/* \n -> Un salto de linea para que no se queden las cosas juntas en la consola */
/*  %ld placeholder para float 
    %d placeholder para int
    %s placeholder para string 
    sizeof muestra el requerimiento de memoria necesaria para cada variable
    printf puede tener varios formatos */
int main() {
    printf("int: %ld \n", sizeof(int));
    printf("float: %ld \n", sizeof(float));
    printf("double: %ld \n",sizeof(double));
    printf("char: %ld \n", sizeof(char));
    return 0;
}