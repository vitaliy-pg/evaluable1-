#include<stdio.h>

typedef struct {
    int arrInt[10];   // Array de enteros positivos o -1 si no hay valores
    int arrSize;      // Número de elementos almacenados
    int arrAdd;       // Suma de los elementos del array
} arrayLength_t;

int initArray(arrayLength_t *arr) {
    if (arr == NULL) {
        return -1; // Error si el puntero es nulo
    }

    // Inicializar los valores del array a -1
    for (int i = 0; i < 10; i++) {
        arr->arrInt[i] = -1;
    }

    arr->arrSize = 0;
    arr->arrAdd = 0;

    return 0; // Éxito
}