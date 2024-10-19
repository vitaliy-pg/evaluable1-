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
    // Verificar si el valor es positivo o igual a 0
    if (valor < 0) {   // Modificado para permitir el 0
        return -1; // Error, el valor no es válido
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

int getElement(const arrayLength_t *arr, int posicion) {
    // Verificar que la posición está dentro de los límites (0 a 9)
    if (arr == NULL || posicion < 0 || posicion >= 10) {
        return -1;  // Error si el puntero es nulo o la posición está fuera de los límites
    }

    // Verificar que la posición contiene un valor válido (no -1)
    if (arr->arrInt[posicion] != -1) {
        return arr->arrInt[posicion];  // Devuelve el valor almacenado si es válido
    } else {
        return -1;  // Devuelve -1 si la posición no tiene un valor válido
    }
}

int setElement(arrayLength_t *arr, int posicion, int nuevoValor) {
    // Verificar que el nuevo valor es positivo o igual a 0
    if (nuevoValor < 0) {
        return -1; // Error, el nuevo valor no es válido
    }

    // Verificar que la posición está dentro de los límites (0 a 9)
    if (arr == NULL || posicion < 0 || posicion >= 10) {
        return -1;  // Error si el puntero es nulo o la posición está fuera de los límites
    }

    // Verificar que la posición contiene un valor válido
    if (arr->arrInt[posicion] != -1) {
        // Actualizar la suma de los elementos (restar el valor anterior y sumar el nuevo valor)
        arr->arrAdd = arr->arrAdd - arr->arrInt[posicion] + nuevoValor;

        // Asignar el nuevo valor a la posición
        arr->arrInt[posicion] = nuevoValor;

        return 0; // Éxito
    } else {
        return -1; // Error, la posición no tiene un valor válido
    }
}

int main() {
    arrayLength_t al1, al2;

    // a) Declarar dos estructuras de tipo arrayLength_t
    if (initArray(&al1) != 0 || initArray(&al2) != 0) {
        printf("Error en inicialización\n");
        return -1;
    }

    // b) Hacer que al1 almacene los valores 0, 10, 20, ..., 90
    for (int i = 0; i < 10; i++) {
        if (addElement(&al1, i * 10) != 0) {
            printf("Error al añadir elemento %d en al1\n", i * 10);
        }
    }

    // c) Mostrar la estructura de al1
    printf("Estructura al1 después de añadir 0, 10, 20, ..., 90:\n");
    printArr(&al1);

    // d) Actualizar las posiciones impares con los valores 1, 3, 5, 7, 9
    for (int i = 1; i < 10; i += 2) {
        if (setElement(&al1, i, i) != 0) {
            printf("Error al modificar la posición %d en al1\n", i);
        }
    }

    // e) Mostrar de nuevo la estructura de al1
    printf("Estructura al1 después de modificar las posiciones impares con 1, 3, 5, 7, 9:\n");
    printArr(&al1);

    // f) Añadir las posiciones pares de al1 a al2
    for (int i = 0; i < 10; i += 2) {
        if (addElement(&al2, getElement(&al1, i)) != 0) {
            printf("Error al añadir el elemento de la posición %d de al1 a al2\n", i);
        }
    }

    // g) Actualizar las posiciones finales de al2 para que almacenen los valores de 0 a 4
    for (int i = al2.arrSize; i < 10 && i - al2.arrSize < 5; i++) {
        if (addElement(&al2, i - al2.arrSize) != 0) {
            printf("Error al añadir el valor %d a al2\n", i - al2.arrSize);
        }
    }

    // h) Mostrar la estructura de al2
    printf("Estructura al2 después de añadir las posiciones pares de al1 y los valores 0 a 4:\n");
    printArr(&al2);

    return 0;
}