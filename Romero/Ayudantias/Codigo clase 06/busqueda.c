#include "busqueda.h"

// Busqueda Lineal
int linear_search(int *arreglo, int N, int x)
{
    for (int i=0; i<N; i++) {
        if(arreglo[i] == x) {
            return i;
        }
    }
    return -1;
}

// Busqueda Binaria
int binary_search(int *arreglo, int N, int x)
{
    // ipos y fpos mantienen las posiciones inicial y final del subarreglo donde estamos buscando
    int ipos = 0;
    int fpos = N-1;
    // mpos mantiene la posicion en la mitad entre ipos y fpos
    int mpos;
    while (ipos <= fpos) {
        mpos = ipos + (fpos-ipos)/2; // ojo que (fpos-ipos)/2 es division entera ya que fpos e ipos son ints
        if (arreglo[mpos] == x) {
            return mpos;
        }
        else if (x < arreglo[mpos]) {
            fpos = mpos - 1;
        }
        else {
            ipos = mpos + 1;
        }
    }
    // si salimos de este while es porque no encontramos el elemento
    return -1;
}
