#include<stdio.h>

typedef struct {
    int arrInt[10];   // Array de enteros positivos o -1 si no hay valores
    int arrSize;      // Número de elementos almacenados
    int arrAdd;       // Suma de los elementos del array
} arrayLength_t;


int initArray(arrayLength_t *arr);
int addElement(arrayLength_t *arr, int valor);
void printArr(const arrayLength_t *arr);
int getArrSize(const arrayLength_t *arr);
int getArrAdd(const arrayLength_t *arr);
int getElement(const arrayLength_t *arr, int posicion);
int setElement(arrayLength_t *arr, int posicion, int nuevoValor);
void resetArr(arrayLength_t *arr);


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