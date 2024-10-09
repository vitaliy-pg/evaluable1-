#include <stdio.h>


typedef struct {
    int arrInt[10];   // Array de enteros positivos o -1 si no hay valores
    int arrSize;      // Número de elementos almacenados
    int arrAdd;       // Suma de los elementos del array
} arrayLength_t;

int initArray(arrayLength_t *arr) {
    if (arr == NULL) {
        return -1; // Error si el puntero es nulo
    }

    for (int i = 0; i < 10; i++) {
        arr->arrInt[i] = -1;
    }

    arr->arrSize = 0;
    arr->arrAdd = 0;

    return 0; // Todo salió bien
}
void agregarElemento(arrayLength_t *arr, int valor) {
    if (valor <= 0) {
        printf("El valor debe ser un entero positivo.\n");
        return;
    }

    if (arr->arrSize < 10) {
        arr->arrInt[arr->arrSize] = valor;
        arr->arrSize++;
        arr->arrAdd += valor;
    } else {
        printf("El array está lleno.\n");
    }
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
int main() {
    arrayLength_t miArray;

    // Inicializar el array con la función initArray
    if (initArray(&miArray) == 0) {
        printf("Array inicializado correctamente.\n");
    } else {
        printf("Error al inicializar el array.\n");
        return -1;  // Finaliza si ocurre algún error
    }

    // Imprimir el array inicializado
    printArr(&miArray);  // Debería mostrar {[-1, -1, -1, -1, -1, -1, -1, -1, -1, -1], 0, 0}

    // Agregar algunos elementos al array
    agregarElemento(&miArray, 5);
    agregarElemento(&miArray, 10);
    agregarElemento(&miArray, 15);

    // Imprimir el array después de agregar elementos
    printArr(&miArray);  // Debería mostrar {[5, 10, 15, -1, -1, -1, -1, -1, -1, -1], 3, 30}

    return 0;
}
