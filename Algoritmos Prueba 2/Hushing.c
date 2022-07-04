//HASHING
// Lista cuyas posiciones se obtienen para otorgarle posiciones a lo que se quiera guardar
// Las colisiones se solucionan de dos formas:
// Sondeo lineal: Se ponen en la siguiente posición libre
// Encadenamiento separado: Se agregan posiciones a listas en cada posición de la tabla
// factor de carga = Q de claves/ Q casillas totales
// Se busca que sea bajo, mas que anda estar bajo cierto umbral

// TABLA DE HUSHING PARA SONDEO(se llena de -1)
int tabla[TABLE_SIZE];
for (int i=0; i < TABLE_SIZE; i++) {
    tabla[i] = -1;
}

//Estructura para guardar datos
struct node {
  int x;
  struct node *next;
};

// SONDEO LINEAL
//tabla = tabla de hushing
// N = largo tabla n
// Key = valor a agregar
void insertar_sondeolineal(int *tabla, int N, int key)
{
  int i = key % N; // calculamos el valor de la funcion de hash
  /* buscamos la primera casilla vacia (con -1) 
  desde i hacia abajo (circularmente) en la tabla */
  while(tabla[i] != -1) {
    if (tabla[i] == key) { // caso en que key ya estaba en la tabla (no hay que insertar)
      return;
    }
    i = (i+1) % N; // incremento circular. Despues de N-1 (ultima casilla) pasamos a 0
  }
  // aca sabemos que key no esta en la tabla y va en la casilla i
  tabla[i] = key;
}

int buscar_sondeolineal(int *tabla, int N, int key)
{
  int i = key % N; // calculamos el valor de la funcion de hash
  /* buscamos desde i hacia abajo (circularmente) hasta encontrar key o
  hasta encontrar una casilla vacia (-1) en cuyo caso sabemos que key no esta en la tabla */
  while(tabla[i] != -1) {
    if (tabla[i] == key) { // caso en que encontramos key. Retornamos la casilla i
      return i;
    }
    i = (i+1) % N; // incremento circular. Despues de N-1 (ultima casilla) pasamos a 0
  }
  // aca sabemos que key no esta en la tabla
  return -1;
}

void imprimir_tabla_sondeolineal(int *tabla, int N)
{
  // recorrido simple de la tabla
  for (int i=0; i<N; i++){
    printf("%d\n", tabla[i]);
  }
}
//  ENCADENAMIENTO

//Tabla de hushing para encadenamiento
struct node *tabla[TABLE_SIZE];

for (int i=0; i < TABLE_SIZE; i++) {
    tabla[i] = NULL;
}

void insertar_encadenamiento(struct node **tabla, int N, int key)
{
  int i = key % N; // calculamos el valor de la funcion de hash
  if (tabla[i] == NULL) { // caso que la lista tabla[i] es vacia
    struct node *nuevo_nodo = (struct node *)malloc(sizeof(struct node));
    nuevo_nodo->x = key;
    nuevo_nodo->next = NULL;
    tabla[i] = nuevo_nodo; // nuevo nodo pasa a ser el primer nodo
  }
  else { // caso que la lista tabla[i] no es vacia
    struct node *it = tabla[i];

    /* si el dato del primer nodo es key, no hay que insertar
    Es importante hacer el caso del primero nodo aparte, ya que el while de abajo, 
    siempre pregunta por el dato del siguiente nodo, 
    luego chequea todos los nodos menos el primero */
    if(it->x == key) {
        return;
      }

    /* recorremos la lista 
    OJO: esta parte es distinta a la del video de la ayudantia, 
    ahora preguntamos por it->next->x == key en vez de it->x == key, 
    al preguntar por it->x == key nos saltamos el ultimo dato de la lista
    */
    while(it->next != NULL) {
      if(it->next->x == key) { // caso en que key esta en la tabla (no hay que insertar)
        return;
      }
      it = it->next;
    }
    // insertamos nuevo nodo al final de la lista
    struct node *nuevo_nodo = (struct node *)malloc(sizeof(struct node));
    nuevo_nodo->x = key;
    nuevo_nodo->next = NULL;
    it->next = nuevo_nodo;
  }
}

int buscar_encadenamiento(struct node **tabla, int N, int key)
{
  int i = key % N; // calculamos el valor de la funcion de hash
  struct node *it = tabla[i];
  // recorremos la lista
  while(it != NULL) {
    if(it->x == key) { // caso en que encontramos key. Retornamos la casilla i
      return i;
    }
    it = it->next;
  }
  // aca sabemos que key no esta
  return -1;
}

void imprimir_tabla_encadenamiento(struct node **tabla, int N)
{
  // para cada casilla i de la tabla, recorremos la lista tabla[i]
  for(int i=0; i<N; i++) {
    struct node *it = tabla[i];
    while(it != NULL) {
      printf("%d ", it->x);
      it = it->next;
    }
    printf("\n");

  }
}