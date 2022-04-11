#include <stdio.h>


/* 
scanf() es una funcion hecha para asignar a las entradas variables, de la forma en que sila variable no le corresponde un input esta no sera rellenada 
cabe decir que el formato de la variable, se le otorga durante el codigo tal que podemos decidir si esta sera int float o string


%d -> Decimal
%c -> character
%s -> string
%f -> float
%x -> hexadecimal


[*] saltara el input
*/

int main(){
    int x,y;
    char text[20];

    scanf("%2d %d %*f %5s", &x ,&y ,text);
    /* input 1234 5.7 elephant */
    printf("%d %d %s",x,y,text);
    /* output 12 34 eleph */
    return 0;

    /* %*f se saltara y no se mostrara ni se almacenara */
}