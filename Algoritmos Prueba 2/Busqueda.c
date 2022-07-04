// Apuntes propios

//BUSQUEDA LINEAL 
//(Recorre la lista con un for, si el valor es =, guarda el index)

//BUSQUEDA BINARIA
//Divide el espacio en mitades
//Debe estar ordenado

//ipos= posición incial, inicia en 0
//fpos= largo del arreglo
// x valor a buscar
int binary_search(int *arreglo, int ipos, int fpos, int x)
{
  int mpos;

  while (ipos <= fpos) {
    mpos = ipos + (fpos - ipos)/2;
    if (arreglo[mpos] == x) {
      return mpos;
    }
    else if (arreglo[mpos] > x) {
      fpos = mpos-1;
    }
    else {
      ipos = mpos + 1;
    }
  }

  return -1;
}

// Busqueda exponencíal
// Crea subespacios cada vez maś grandes en orden 2 para hacer binary search
// Debe estar ordenado

int exponential_search(int *arreglo, int N, int x)
{
  // caso de borde, vemos si x es el primer elemento o no
  if (arreglo[0] == x) {
    return 0;
  }

  // buscamos la primera posicion i tal que arreglo[i] > x
  // en cada paso doblamos i
  int i = 1;
  while (i < N && arreglo[i] <= x) {
    i = i * 2;
  }


  if (i < N) {
    return binary_search(arreglo, i/2, i, x);
  }
  else { // este es el caso en que el indice i paso los limites del arreglo 
    return binary_search(arreglo, i/2, N-1, x);
  }

}