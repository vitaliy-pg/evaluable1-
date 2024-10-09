#include <stdio.h>

// Estructura arrayLength_t
typedef struct {
    int arrInt[10];   // Array de enteros positivos o -1 si no hay valores
    int arrSize;      // Número de elementos almacenados
    int arrAdd;       // Suma de los elementos del array
} arrayLength_t;

// Funciones

int initArray(arrayLength_t *arr) {
    if (!arr) return -1; // Error si el puntero es NULL
    for (int i = 0; i < 10; i++) {
        arr->arrInt[i] = -1; // Inicializar todas las posiciones a -1
    }
    arr->arrSize = 0;      // Inicializar arrSize a 0
    arr->arrAdd = 0;       // Inicializar arrAdd a 0
    return 0;              // Retornar 0 si no hay error
}

int addElement(arrayLength_t *arr, int valor) {
    if (!arr || valor < 0 || arr->arrSize >= 10) return -1; // Error si el puntero es NULL o si el valor es negativo o no hay espacio
    arr->arrInt[arr->arrSize] = valor; // Añadir valor al array
    arr->arrSize++;                     // Incrementar arrSize
    arr->arrAdd += valor;               // Sumar el valor a arrAdd
    return 0;                            // Retornar 0 si no hay error
}

void printArr(const arrayLength_t *arr) {
    if (!arr) return; // No imprimir si el puntero es NULL
    printf("{[");
    for (int i = 0; i < 10; i++) {
        printf("%d", arr->arrInt[i]);
        if (i < 9) printf(", ");
    }
    printf("], %d, %d}\n", arr->arrSize, arr->arrAdd);
}

int getArrSize(const arrayLength_t *arr) {
    if (!arr) return -1; // Error si el puntero es NULL
    return arr->arrSize; // Retornar arrSize
}

int getArrAdd(const arrayLength_t *arr) {
    if (!arr) return -1; // Error si el puntero es NULL
    return arr->arrAdd;  // Retornar arrAdd
}

int getElement(const arrayLength_t *arr, int posicion) {
    if (!arr || posicion < 0 || posicion >= 10 || arr->arrInt[posicion] == -1) return -1; // Error en caso de posición inválida
    return arr->arrInt[posicion]; // Retornar el valor en la posición especificada
}

int setElement(arrayLength_t *arr, int posicion, int nuevoValor) {
    if (!arr || posicion < 0 || posicion >= 10 || arr->arrInt[posicion] == -1 || nuevoValor < 0) return -1; // Error en caso de posición inválida
    arr->arrAdd -= arr->arrInt[posicion]; // Restar el valor anterior de arrAdd
    arr->arrInt[posicion] = nuevoValor;    // Asignar nuevo valor
    arr->arrAdd += nuevoValor;              // Sumar el nuevo valor a arrAdd
    return 0;                               // Retornar 0 si no hay error
}

void resetArr(arrayLength_t *arr) {
    if (!arr) return; // No hacer nada si el puntero es NULL
    initArray(arr); // Reiniciar el array usando initArray
}

// Función principal
int main() {
    // a) Declarar dos estructuras de tipo arrayLength_t
    arrayLength_t al1, al2;

    // b) Inicializar al1 y almacenar los valores 0, 10, 20, …, 90
    initArray(&al1);
    for (int i = 0; i < 10; i++) {
        addElement(&al1, i * 10);  // Añadir 0, 10, 20, ..., 90
    }

    // c) Mostrar la estructura almacenada en al1
    printf("Contenido de al1:\n");
    printArr(&al1);

    // d) Actualizar las posiciones impares de al1 para que almacenen 1, 3, 5, 7 y 9
    for (int i = 1; i < 10; i += 2) {
        setElement(&al1, i, i * 2 - 1);  // Asignar 1, 3, 5, 7, 9 en las posiciones impares
    }

    // e) Mostrar de nuevo la estructura
    printf("Contenido de al1 después de actualizar posiciones impares:\n");
    printArr(&al1);

    // f) Añadir las posiciones pares del array al1 al array al2
    initArray(&al2);  // Inicializar al2
    for (int i = 0; i < 10; i += 2) {
        addElement(&al2, getElement(&al1, i));  // Añadir elementos de posiciones pares de al1 a al2
    }

    // g) Actualizar las posiciones finales del array de al2 para que almacenen 0 a 4
    for (int i = al2.arrSize; i < 10; i++) {
        setElement(&al2, i, i);  // Asignar 0, 1, 2, 3, 4 en las posiciones finales
    }

    // h) Mostrar la estructura al2 después de hacer todos los ejercicios
    printf("Contenido de al2:\n");
    printArr(&al2);

    return 0;
}
