#include <stdio.h>

// Definir la estructura
typedef struct {
    int arrInt[10];   // Array de enteros positivos
    int arrSize;      // Número de elementos almacenados
    int arrAdd;       // Suma de los elementos del array
} arrayLength_t;

void inicializar(arrayLength_t *arr) {
    arr->arrSize = 0;
    arr->arrAdd = 0;
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

void imprimirArray(const arrayLength_t *arr) {
    printf("Elementos en el array: ");
    for (int i = 0; i < arr->arrSize; i++) {
        printf("%d ", arr->arrInt[i]);
    }
    printf("\nSuma de los elementos: %d\n", arr->arrAdd);
}
