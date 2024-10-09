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
