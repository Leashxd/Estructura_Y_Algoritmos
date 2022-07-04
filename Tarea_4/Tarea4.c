#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BSIZE 1024
#define HashSize 5

/* 
Integrantes
Diego Alfonos
Joaquin Leal
Camila Martinez
 */

//creamos la estructura del arbol AVL

struct nodo{
    char firstname[100];
    int danger_category;
    float attack_prob;
    int height;
    struct nodo *left;
    struct nodo *right;
};


//ufuncion auxiliar maximo
int max(int a, int b){
    return(a>b)? a:b;
}

//encontramos la altura del nodo
int altura(struct nodo *nodo){
    //Si el nodo es NULL, la atura es 0 
    if (nodo == NULL){
        return 0;
    }
    //cuando no es nulo, es un nodo hoja, lo que quiere decir que su altura se le suma 1
    return 1 + max(altura(nodo->left),altura(nodo->right));
}

//balance
int balance(struct nodo *nodo){
    //mismo caso que altura, si el nodo es NULL la altura es 0
    if (nodo == NULL){
        return 0;
    }
    //si no es null devolvemos la altura del hijo izq - hijo der
    return altura(nodo-> left)- altura(nodo->right);
}


//Rotamos hacia la derecha el arbol con raiz
// asumimos que la raiz y junto al pivote y->left no son NULL
//retornamos la nueva raiz del arbol rotado

struct nodo *rightRotate(struct nodo *y){
    //x , nueva raiz
    struct nodo *x = y->left;
    //somos conscientes que z puede ser null pero no nos supone un problema
    struct nodo *z = x->right;

    //rotamos
    //asignamos y al nodo derecho
    x->right=y;
    // asignamos z al nodo izq
    y->left = z;


    //Al rotar debemos actualizar la altura de x e y
    y->height = altura(y);
    x->height= altura(x);
    //retornamos la nueva raiz
    return x;
}

//Rotamos a la izq, es la misma base del right rotate.
struct nodo *leftRotate(struct nodo *x){
    // nueva raiz
    struct nodo *y = x->right;
    struct nodo *z = y->left;

    //rotamos a la izq
    y->left = x;
    x->right = z;
    //actualizamos la altura
    y->height = altura(y);
    x->height = altura(x);
    //retornamos la nueva raiz
    return y;
}


//insertamos datos al arbol AVL

struct nodo *insert(struct nodo *nodo, char firstname[100], int danger_category, float attack_prob){

    
    if (nodo == NULL){//en el caso de que el arbol este vacio
        struct nodo *tmp = (struct nodo *)malloc(sizeof(struct nodo));
        //asignamos los parametros a tmp
        strcpy(tmp->firstname, firstname); //firstname
        tmp->danger_category = danger_category; //danger category
        tmp->attack_prob = attack_prob; // attack prob
        // los nodos de la izq y derecha estan vacios

        tmp->left = NULL;
        tmp->right = NULL;
        tmp->height = 1;

        //retornamos tmp 
        return tmp;
    }

    //Si el arbol no esta vacio.
    //en el caso de que la raiz sea la misma se llama recursivamente a la funcion -return node-
    //actualizamos el hijo de la raiz de la iteracion correspondiente

    if(attack_prob < nodo -> attack_prob){ //insertamos a la izq
        nodo->left = insert(nodo->left, firstname,danger_category,attack_prob);
    }
    else{//insertamos a la derehca
        nodo->right = insert(nodo->right, firstname,danger_category,attack_prob);
    }
    
    //actualizamos la altura
    nodo->height= altura(nodo);
    // comprobamos balance
    //1> v <-1 esta desbalanceado
    int balanceado_nodo = balance(nodo);

    //rotamos
    //LL
    if(balanceado_nodo > 1 && danger_category < nodo->left->danger_category ){
        return rightRotate(nodo);
        //rotamos a la derecha
    }
    //RR
    if(balanceado_nodo < -1 && danger_category < nodo->right->danger_category ){
        //rotamos a la derecha
        return leftRotate(nodo);
    }
    //LR
    if(balanceado_nodo > 1 && danger_category < nodo->left->danger_category ){
        //rotamos a la izq
        nodo->left= leftRotate(nodo->left);
        //rotamos a la derecha
        return rightRotate(nodo);
    }
    //RL
    if(balanceado_nodo < -1 && danger_category < nodo->right->danger_category ){
        //rotamos a la derecha
        nodo->right= rightRotate(nodo->right);
        //luego rotamos a la izq 
        return leftRotate(nodo);
    }
    return nodo;
}

int mostrar_INORDER(struct nodo *raiz,int lenlista, int altura){
    //jugamos con la altura, sabemos que tenemos un maximo que es lenlista,
    //entonces nuestra altura definira si podemos iterar entre los niveles
    //para poder imprimir los nodos
    if (raiz == NULL) {//si es nulo retornamos
        return altura;
    }
    altura=mostrar_INORDER(raiz->left, lenlista, altura);
    if(altura < lenlista){
        printf("%s\n", raiz->firstname);
        altura = altura +1;
    }else{
        return altura;
    }
    altura=mostrar_INORDER(raiz->right, lenlista, altura);
    return altura;
}

void leer_csv(char *argv[], struct nodo *raiz){//
    char *ruta_archivo = argv[1];
    FILE *archivo = fopen(ruta_archivo,"r");
    
    int i=0;
    int contador_celda=0;
    char buffer[BSIZE];

    if(archivo==NULL){
        perror("No es posible abrir el archivo, compuebe el directorio o el tipo de archibo");
        exit(1);
    
    }
    //para leer el csv
    //generamos auxiliares de variables
    char firstname[80];
    int danger_category;
    float attack_prob;

    while(fgets(buffer,BSIZE,archivo)){
        if(i==0){
            i++;
            continue;
        }
        contador_celda=0;
        char *celda =strtok(buffer,",");
        //creamos el primer nodo como vacio para dps sobreescribirlo
        strcpy(firstname,"");
        danger_category=0;
        attack_prob=0;


        for(contador_celda=0;contador_celda<3;contador_celda++){
            if(contador_celda==0){//agregamos a firstname
                strcpy(firstname,celda);
            }
            if(contador_celda==1){//agregamos a danger
                danger_category=atoi(celda);
            }
            if(contador_celda==2){//agregamos a attackprob
                attack_prob=atof(celda);
            }
            celda=strtok(NULL,",");

        }
        //insertamos en el arbol con los valores que obtuvimos
        raiz = insert(raiz,firstname,danger_category,attack_prob);
        //pasamos a la siguiente iteracion
        i++;
    }
    //cerramos el archivo
    fclose(archivo);

    //Un arreglo simple para que ne el caso que nuestra lista tenga menor largo que el que pedimos
    //se conserve el largo mas pequeño y no tengamos problemas al imprimir valores.
    int lenlista = i-1;
    int leninput = atoi(argv[2]);
    //Es mayor nuestra lista que nuestro input?
    //conservamos el mayor
    if(lenlista<leninput){
        leninput = lenlista;
    }
    //ahora mostramos la lista en orden
    mostrar_INORDER(raiz, leninput,0);

    }//cierra leer csv

int main(int argc, char *argv[]){
    struct nodo *raiz = NULL;
    leer_csv(argv,raiz);
    return 0;

}

