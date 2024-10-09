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
