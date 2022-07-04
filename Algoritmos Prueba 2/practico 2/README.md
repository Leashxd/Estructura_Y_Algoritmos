# Práctico 2

## Introducción

Una tienda de componentes electrónicas (de esas donde venden capacitores, microchips, compuertas lógicas, etc.) ha innovado en el área de administración de su inventario, creando un nuevo método de guardado de domponentes.

El nuevo método consiste en un tubo recto, donde se pueden insertar componentes electrónicas por ambos lados. La regla es que por un lado (por ejemplo el izquierdo) se inserta un tipo de componente (por ejemplo resistencias), mientras que por el otro lado (por ejemplo el derecho) se inserta un tipo diferente de componente (por ejemplo capacitores).

De esta manera, el sistema funciona como una especie de Pila compartida **sólo para inserción, y no para eliminación**.

---

## Requerimiento

Como experto en Estructura de Datos, se le pide que implemente el sistema de tubo para esta empresa, el cual insertará **Resistencias** por izquierda y **Capacitancias** por derecha. Para llevar a cabo su trabajo, se le entregan las siguientes estructuras:

```C
typedef struct n {
  float valor;
  char tipo;
  struct n *sgte;
} nodo;

typedef struct l {
  nodo *cabecera;
  nodo *centinela;
} lista;
```

La estructura tipo nodo contiene tres valores: valor (float) que corresponde al valor de la componente electrónica, tipo (char) que corresponde al tipo de componente ('R' o 'C'), y sgte (nodo*) que es un puntero al siguiente elemento. 

La estructura tipo lista contiene dos punteros a nodo que corresponden a la parte izquierda (cabecera) y a la parte derecha (centinela). Ambos punteros **SIEMPRE** apuntan al primer elemento por izquierda (cabecera) y al primer elemento por derecha (centinela).

Además puede utilizar las siguientes dos macros definidas si así lo desea:

```C
#define RESISTENCIA 'R'
#define CAPACITANCIA 'C'
```

---

## Funciones

Las funciones son las siguientes

| función                                                           | descripción                                                                                                                                                                                                                                                                                                                                                                 |
| ----------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| ```lista* crear_tubo()```                                         | No recibe argumentos. Crea un puntero a lista con todos los elementos inicializados a NULL. Retorna la lista creada.                                                                                                                                                                                                                                                        |
| ```void insertar_resistencia(float valor, lista* l)```            | Función que recibe como argumento un flotante $valor$, y un puntero a lista $l$. La función inserta una resistencia con un valor de $valor$ en la lista $l$. Recordar que las resistencias son insertadas por izquierda siempre. La función no retorna nada.                                                                                                                |
| ```void insertar_capacitancia(float valor, lista *l)```           | Función que recibe como argumento un flotante $valor$, y un puntero a lista $l$. La función inserta una capacitancia con un valor de $valor$ en la lista $l$. Recordar que las capacitancias son insertadas por derecha siempre. La función no retorna nada.                                                                                                                |
| ```int contar_componentes(char tipo, lista* l)```                 | Función que recibe como argumento el tipo de componente $tipo$ que serán contados ('R' o 'C'), y un puntero a lista $l$. La función contará la cantidad de componentes de tipo $tipo$ que seencuentran en el tubo. La función retorna el número de componentes del tipo $tipo$ contadas en el tubo.                                                                         |
| ```nodo* eliminar_componente(float valor, char tipo, lista* l)``` | Función que recibe como argumento un flotante $valor$, un tipo de componente $tipo$, y un puntero a lista $l$. La función elimina de la lista $l$ **uno de los componentes de tipo $tipo$ y valor $valor$**. Si hay más de uno, **sólo elimina uno**. La función retorna la componente eliminada de la lista en caso que esta haya existido, y NULL en cualquier otro caso. |

## Consideraciones especiales

1. Sólo puede modificar los archivos **pregunta_X.c**. No puede modificar NADA MÁS.
2. Para facilitar su codificación se le entrega un Makefile que automatiza la compilación y ejecución de su código. Para ocuparlo debe hacer dos cosas:
   1. Modificar la línea 8 del archivo *utilities.h*, cambiando el número que aparece ahí por el número de la pregunta que desea compilar
   2. Escribir en la shell(consola-terminal) lo siguiente:

       ```bash
        make p1
       ```

       Este ejemplo es para compilar la pregunta 1. Si desea compilar la pregunta dos, en utilities.h edita el número mencionado anteriormente por un 2 y el make lo hace con p2
3. Sólo debe subir los archivos pregunta_X.c. SIN COMPRIMIR. No suba un zip, ni suba el main.c. Todo archivo extra subido a Webcursos será ignorado.
4. Nunca está demás decir que todos los códigos serán analizados con un detector de plagio. Esta evaluación se rige por la normas de conducta propias de un alumno UAI.
