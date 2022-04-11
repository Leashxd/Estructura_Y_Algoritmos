#include <stdio.h>

/* Las constates son valores que no pueden cambiarse desde su valor inicial
IDealmente se identifican las variables de las constantes dado que las constantes 
son almacenadas con mayusculas */

/* %f placeholder para float numbers */

int main(){
    const double PI =3.14;
    printf("%f \n", PI);

    return 0;
}


/* Otra forma de definir constantes es con 

#define PI 3.14, la unica diferencia es como se almacenan 
la primera utiliza memoria y la otra no. */