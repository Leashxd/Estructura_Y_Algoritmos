#include <stdio.h>

/* Podemos definir variables podemos asignar la variable o
podemos dependiendo de la situacion inicializar la variable */

/*Asignando la variable  */
/* Creo la variable */
int mi_varaible;
/* le doy un valor */
mi_variable = 42;


/* Inicializando la variable */
int mi_variable1 = 42;


/* Definamos distintas variables dentro de main */

int main(){
    int a, b;
    float salary=56.1;
    char letra='t';
    a=8;
    b=34;
    int c= a+b;


    /* Imprimimos C colocando el placeholder */
    printf("%d \n",c);
    /* Imprimimos Salary colocando el placeholder */
    printf("%f \n",salary);
    /* Imprimimos "letra" colocando el placeholder */
    printf("%c \n",letra);



    return 0;
}



/* hemos de recalcar que C es muy sensible, dado que no es lo mimsmo
escribir
1)Mivar
que 
2)mivar
en este caso 1) y 2) son variables distintas */