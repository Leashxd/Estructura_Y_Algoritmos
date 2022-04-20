# Tarea 2 

## Estructura de datos y Algoritmos

### **Under Attack!**

Como nuestra tarea anterior fue un rotundo éxito! nos han contratado para estudiar a profundidad a los posibles atacantes con sus respectivas categorias, peligro y probabilidad de ataque.

Nos interesa saber rotundamente su clasificación ascendente para saber de quien tenemos que cuidarnos.

## Variables

Cree un csv que contenga tres variables:

**first_name** : Ingresa el nombre del atacante.

**danger_category** : Indica el nivel de peligrosidad. Mientras más alto el numero, el nombre es más peligroso.

**attack_prob** : responde a la probabilidad de ataque del atacante, mientras más alto el valor mayor la probabilidad. Notar que este valor es una probabilidad y que puede ir desde 0 hasta 1 -dado que es una probabilidad- además agregando una condición, este campo puede estar hasta vacío.

### Condiciones a tomar en cuenta

Para determinar quien es el más peligroso se seguira el siguiente criterio.

* Un número mayor de **danger_category** implica mayor peligrosidad.

* Un número mayor de **attack_prob** implica mayor peligrosidad.

* Si existe un nombre **sin attack_prob** entonces su peligrosidad será dependiente de su categoria.

    * Si se encuentra en las categorias 1 o 2, no se considerara peligroso, quedando al final **de su respectiva categoria**.
    * Si se encuentra en la categoria 3, se considerara medianamente peligroso, quedando en la mitad **de su respectiva categoria**. 
    * Si se encuentra en la categoria 4 o 5, se considerara muy peligroso, quedando al principio **de su respectiva categoria**.

Si existen dos nombres que empatan en peligrosidad, entonces se ordenarán por orden alfabético.

## Entrada

Se espera que el programa reciba como entrada solo tres parametros, correspondientes al nombre del archivo csv que contiene la lista de nombres, la cantidad de nombres que se quiere priorizar y por último el archivo de salida que contendra la lista generada.


        ./tarea2 lista.txt 30 lista_out.txt



### Integrantes
-Joaquin Leal\
-Camila Martinez\
-Diego Pinos




