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


int getElement(const arrayLength_t *arr, int posicion) {
    // Verificar que la posición está dentro de los límites (0 a 9)
    if (arr == NULL || posicion < 0 || posicion >= 10) {
        return -1;  // Error si el puntero es nulo o la posición está fuera de los límites
    }

    // Verificar que la posición contiene un valor positivo
    if (arr->arrInt[posicion] > 0) {
        return arr->arrInt[posicion];  // Devuelve el valor almacenado si es positivo
    } else {
        return -1;  // Devuelve -1 si la posición no tiene un valor positivo
    }
}

int setElement(arrayLength_t *arr, int posicion, int nuevoValor) {
    // Verificar que el nuevo valor es positivo
    if (nuevoValor <= 0) {
        return -1; // Error, el nuevo valor no es positivo
    }

    // Verificar que la posición está dentro de los límites (0 a 9)
    if (arr == NULL || posicion < 0 || posicion >= 10) {
        return -1;  // Error si el puntero es nulo o la posición está fuera de los límites
    }

    // Verificar que la posición contiene un valor positivo
    if (arr->arrInt[posicion] > 0) {
        // Actualizar la suma de los elementos (restar el valor anterior y sumar el nuevo valor)
        arr->arrAdd = arr->arrAdd - arr->arrInt[posicion] + nuevoValor;

        // Asignar el nuevo valor a la posición
        arr->arrInt[posicion] = nuevoValor;

        return 0; // Éxito
    } else {
        return -1; // Error, la posición no tiene un valor positivo
    }
}

void resetArr(arrayLength_t *arr) {
    // Verificar que el puntero no es nulo
    if (arr == NULL) {
        return; // No se realiza ninguna acción si el puntero es nulo
    }

    // Utilizar la función initArray para resetear el array
    initArray(arr);
}
