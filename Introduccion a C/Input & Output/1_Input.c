#include <stdio.h>

/* C tiene mil maneras de tomar un input
Por ejemplo tenemos getchar() */


/*  %d place holder que leera la variable como un numero 
    %c placeholder que scaneara la variable e imprimira un string*/

/* int main(){
    char a = getchar();
    printf("Tu input es: %c", a);

    return 0;
}
 */
/* Como podemos ver, solo obtenemos el primer valor del string que ingresemos */

/* Otro ejemplo, ahora para leer todo el string 
    Contempla, el string entero hasta con saltos de linea*/

/* int main() {
    char a[100];
    gets(a);
    printf("Tu input es: %s", a);
    return 0;
} */

/*1- Genero un int 
  2- scaneamos el input, si colocamos &a presumo que sirve variable almacenada para el placeholder 
  3- mostramos el input bajo el placeholder y la variable 
  4- Si el input en un int es un string el input sera automaticamente 0 */
/* int main(){
    int a;
    scanf("%d",&a);
    printf("Tu input es: %d",a);
    return 0;
} */



int main(){
    int a, b;
    printf("Ingresa dos numeros de la forma 1 3");
    scanf("%d %d", &a, &b);
    printf("\nLa suma es: %d", a+b);
    return 0;
}