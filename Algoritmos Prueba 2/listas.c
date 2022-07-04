// LISTAS
struct node {   
  int x;
  struct node *next;
};
// esta es la forma de inicializar una lista vacia
// la variable lista representa a la lista enlazada y apunta al primer nodo
// cuando no hay nada a que apuntar lo asignamos al puntero vacio NULL
struct node *lista = NULL;

//AGREGAR DATOS------------------------------------------------------

// agregamos "a mano" un nodo nodo1 al final de la lista enlazada
// Recordar que nodo1->x es una abreviacion de (*nodo1).x
struct node *nodo1 = (struct node *)malloc(sizeof(struct node));
nodo1->x = 10; // seteamos el dato de nodo1
nodo1->next = NULL; // el siguiente de nodo1 es NULL ya que queda al final de la lista
lista = nodo1; // actualizamos lista a apuntar al primer nodo de la lista, es decir, nodo1


// agregamos "a mano" otro nodo nodo2 al final de la lista enlazada
struct node *nodo2 = (struct node *)malloc(sizeof(struct node));
nodo2->x = 20; // seteamos el dato de nodo2
nodo2->next = NULL; // el siguiente de nodo2 es NULL ya que queda al final de la lista
nodo1->next = nodo2; // el siguiente nodo de nodo1 pasa a ser nodo2

/* en general, para agregar un elemento al final de la lista necesitamos 
mantener un iterador que recorre los nodos (con un while) y
y deternos cuando estemos en el ultimo nodo, es decir, cuando next == NULL */

// queremos insertar nodo3 con dato 30
// Asumimos que lista no está vacia
struct node *it = lista;
while(it->next != NULL) {
it = it->next;
}
struct node *nodo3 = (struct node *)malloc(sizeof(struct node));
nodo3->x = 30;
nodo3->next = NULL;
it->next = nodo3;

// Para hacer una insercion de un nodo en el caso mas general posible, 
// debemos considerar el caso cuando la lista es vacia (ver ejemplo abajo)
// Insertemos un nodo4 asumiendo que eventualmente la lista podria ser VACIA

if(lista == NULL) { // caso que la lista es vacia
struct node *nodo4 = (struct node *)malloc(sizeof(struct node));
nodo4->x = 40; 
nodo4->next = NULL; 
lista = nodo4; 
}
else { // caso que la lista no es vacia
struct node *it2 = lista;
while(it2->next != NULL) {
    it2 = it2->next;
}
struct node *nodo4 = (struct node *)malloc(sizeof(struct node));
nodo4->x = 40;
nodo4->next = NULL;
it2->next = nodo4;
}

// IMPRIMIR LOS DATOS ---------------------------------

struct node *it3 = lista;
while(it3 != NULL) {
printf("%d ", it3->x);
it3 = it3->next;
}
printf("\n");

// INSERTAR DATO EN MEDIO-------------------------------

// Buscamos el primer nodo tal que el dato de next es >= a 25 (o NULL)
struct node *it4 = lista;
while(it4->next != NULL && it4->next->x < 25) {
it4 = it4->next;
}
// sabemos que estamos en la posicion anterior donde debe ir el dato 25
// insertamos el nodo nuevo
struct node *nodo5 = (struct node *)malloc(sizeof(struct node));
nodo5->x = 25;
struct node *tmp = it4->next; // esto es clave, sino perdemos la referencia a next
it4->next = nodo5;
nodo5->next = tmp;

// INSERTAR DATO AL PRINCIPIO-------------------------------

struct node *nodo6 = (struct node *)malloc(sizeof(struct node));
nodo6->x = 5;
tmp = lista; // esto es clave, sino perdemos la referencia al primero nodo
lista = nodo6;
nodo6->next = tmp;

// BORRAR DATO-----------------------
  // IMPORTANTE: en general hay que poner casos de bordes cuando no encontramos el elemento, 
  // es decir, al salir del while it5->next == NULL o queremos borrar el primer elemento 

struct node *it5 = lista;
while(it5->next != NULL && it5->next->x != 25) {
it5 = it5->next;
}
tmp = it5->next; // esto es clave para no perder la direccion a la que aplicamos free
it5->next = it5->next->next;
free(tmp);
//Otra opción
// borra dato valor de la lista (si es que esta) 
// (si hay repeticiones borra la primera ocurrencia de valor)
void borrar_elemento(struct node **ref_lista, int valor)
{
  if(*ref_lista == NULL) { // caso lista vacia
    return;
  }

  if((*ref_lista)->x == valor) { // caso que hay que borrar primer elemento
    struct node* tmp = *ref_lista;
    *ref_lista = (*ref_lista)->next; // aca modificamos la variable lista
    free(tmp); // importante liberar la memoria del nodo
    return;
  }

  // caso general
  struct node *lista = *ref_lista; //??
  struct node *it = lista;
  while(it->next != NULL && it->next->x != valor) { 
    it = it->next;
  }
 
  if(it->next == NULL) { // caso que valor no esta en la lista
    return;
  }

  // sabemos que valor esta en la lista y hay que borrarlo
  struct node* tmp = it->next; 
  it->next = it->next->next;
  free(tmp); // importante liberar la memoria del nodo
}

// Una forma de borrar alternativa es la siguiente
// Digamos que queremos borrar el elemento 20 (asumimos que esta)
struct node *it6 = lista;
while(it6->next != NULL && it6->next->x != 20) {
it6 = it6->next;
}

tmp = it6->next->next;
free(it6->next);
it6->next = tmp;

//SWAP---------------------------------
void swap(struct node *nodo1, struct node *nodo2)
{
    ejemplo tmp = nodo1->x;
    nodo1->x = nodo2->x;
    nodo2->x = tmp;
}

//BUBBLE SORT
void ordenar_lista(struct node *lista)
{
    if (lista == NULL) { // caso lista vacia
        return;
    }

    int swapped = 1; // indica si hubo algun swap
    struct node *it = lista;
    while(swapped == 1){
        swapped = 0;
        while (it->next != NULL){
            if(mayor_que(it->x, it->next->x) == 1) { // debemos hacer swap
                swap(it, it->next);
                swapped = 1;    
            }
            it = it->next;
        }
        it = lista; // inicializamos el iterador it
    }
}

//INSERTAR DATO DONDE VA EN ORDEN
void insertar_elemento_orden(struct node **ref_lista, ejemplo dato)
{
    if (*ref_lista == NULL) { // caso lista vacia
        struct node *nuevo_nodo = (struct node *)malloc(sizeof(struct node));
        nuevo_nodo->x = dato; 
        nuevo_nodo->next = NULL; 
        *ref_lista = nuevo_nodo; // aca modificamos la variable lista
        return;
    }

    if (mayor_que(dato, (*ref_lista)->x) == 0) { // caso hay que insertar al principio de la lista
        struct node *nuevo_nodo = (struct node *)malloc(sizeof(struct node));
        nuevo_nodo->x = dato;
        struct node *tmp = *ref_lista; 
        *ref_lista = nuevo_nodo; // aca modificamos la variable lista
        nuevo_nodo->next = tmp;
        return;
    }

    // caso general
    struct node *lista = *ref_lista;
    struct node *it = lista;
    // buscamos el primer nodo tal que el dato del siguiente nodo es >= dato de entrada
    while(it->next != NULL && mayor_que(dato, it->next->x) == 1) {
        it = it->next;
    }
   
    struct node *nuevo_nodo = (struct node *)malloc(sizeof(struct node));
    nuevo_nodo->x = dato;
    struct node *tmp = it->next; 
    it->next = nuevo_nodo;
    nuevo_nodo->next = tmp;
}

// LECTURA DE ARCHIVO CSV

  // leemos las estructuras del archivo "prueba.txt"
  // insertamos en el orden que vienen en el archivo y luego ordenamos
fp = fopen("prueba.txt", "r");
while (fgets(line, 1000, fp) != NULL) {
  strcpy(aux.nombre, strtok(line, ","));
  aux.c = atoi(strtok(NULL, ","));
  insertar_elemento(&lista, aux);
}
fclose(fp);


// BORRAR LISTAAAA
void borrar_lista(struct node **ref_lista) 
{
  struct node *tmp;
  struct node *it = *ref_lista;
  while(it != NULL) {
      tmp = it->next;
      free(it); // liberamos la memoria del nodo actual
      it = tmp; 
}

  *ref_lista = NULL; // modificamos la variable lista a ser NULL


// borra los k primeros nodos de la lista
void borrar_primeros_lista(struct node **ref_lista, int k)
{
    struct node *tmp;
    struct node *it = *ref_lista;
    for(int i = 0; i<k; i++) {
        if(it != NULL) {
            tmp = it->next;
            free(it); // liberamos la memoria del nodo actual
            it = tmp; 
        }
        else { // caso en que se acabo la lista
            break; 
        }
    }

    *ref_lista = it; // modificamos la variable lista a ser it
}
