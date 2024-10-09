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
int addElement(arrayLength_t *arr, int valor) {
    // Verificar si el valor es positivo
    if (valor <= 0) {
        return -1; // Error, el valor no es positivo
    }

    // Verificar si hay espacio en el array
    if (arr->arrSize >= 10) {
        return -1; // Error, el array está lleno
    }

    // Añadir el nuevo valor a la primera posición libre
    arr->arrInt[arr->arrSize] = valor;

    // Actualizar arrSize y arrAdd
    arr->arrSize++;
    arr->arrAdd += valor;

    return 0; // Éxito
}

void printArr(const arrayLength_t *arr) {
    printf("{[");

    for (int i = 0; i < 10; i++) {
        printf("%d", arr->arrInt[i]);
        if (i < 9) {
            printf(", ");
        }
    }

    printf("], %d, %d}\n", arr->arrSize, arr->arrAdd);
}
int getArrSize(const arrayLength_t *arr) {
    if (arr == NULL) {
        return -1;  // Error si el puntero es nulo
    }
    return arr->arrSize;  // Devuelve el número de elementos en el array
}

int getArrAdd(const arrayLength_t *arr) {
    if (arr == NULL) {
        return -1;  // Error si el puntero es nulo
    }
    return arr->arrAdd;  // Devuelve la suma de los elementos en el array
}