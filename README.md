# evaluable1-
Para entrar al repositiro pincha aqui: https://github.com/vitaliy-pg/evaluable1-.git

#TRABAJO 1 DE SISTEMAS OPERATIVOS RESUMEN:

Estructura Común: arrayLength_t

Esta estructura se utiliza en todos los ejercicios y contiene tres miembros:

arrInt[10]: Un array de enteros de tamaño 10 que almacena números positivos o -1 si no hay valores.
arrSize: Un entero que guarda el número de elementos almacenados en arrInt.
arrAdd: Un entero que almacena la suma de todos los elementos en arrInt.
Funciones Comunes
int initArray(arrayLength_t *arr)

Inicializa el array estableciendo todos sus elementos a -1, arrSize a 0 y arrAdd a 0. Retorna 0 si la inicialización fue exitosa, o -1 si el puntero es nulo.
int addElement(arrayLength_t *arr, int valor)

Añade un valor positivo al array en la primera posición libre, actualizando arrSize y arrAdd. Retorna 0 si se añade el elemento correctamente, o -1 si el valor es negativo o el array está lleno.
void printArr(const arrayLength_t *arr)

Imprime el contenido del array en un formato específico, incluyendo los valores almacenados, el tamaño del array y la suma de sus elementos. No hace nada si el puntero es nulo.
int getArrSize(const arrayLength_t *arr)

Devuelve el número de elementos almacenados en el array (arrSize). Retorna -1 si el puntero es nulo.
int getArrAdd(const arrayLength_t *arr)

Devuelve la suma de los elementos del array (arrAdd). Retorna -1 si el puntero es nulo.
int getElement(const arrayLength_t *arr, int posicion)

Devuelve el valor en la posición especificada si es válida y contiene un valor positivo; de lo contrario, retorna -1. Verifica que la posición esté dentro de los límites y que el puntero no sea nulo.
int setElement(arrayLength_t *arr, int posicion, int nuevoValor)

Permite actualizar el valor en una posición específica del array, ajustando también arrAdd. Verifica que el nuevo valor sea positivo y que la posición esté dentro de límites. Retorna 0 si se modifica el elemento, o -1 en caso de error.
void resetArr(arrayLength_t *arr)

Reinicializa el array utilizando initArray. No realiza ninguna acción si el puntero es nulo.
Funciones Específicas en main
Para cada ejercicio, el main lleva a cabo operaciones específicas usando las funciones anteriores:

Ejercicio 1
Inicializa el array al1 y almacena los valores 0, 10, 20, ..., 90.
Imprime el contenido de al1.
Ejercicio 2
Actualiza las posiciones impares de al1 para almacenar 1, 3, 5, 7 y 9.
Imprime el contenido actualizado de al1.
Ejercicio 3
Inicializa el array al2.
Añade los elementos en posiciones pares del array al1 a al2.
Ejercicio 4
Actualiza las posiciones finales del array al2 para que almacenen 0 a 4.
Imprime el contenido de al2.
