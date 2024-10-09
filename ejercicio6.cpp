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

int main() {
    arrayLength_t arr;

    // Inicializar el array
    if (initArray(&arr) != 0) {
        printf("Error en inicialización\n");
    } else {
        printf("Array inicializado\n");
    }

    // Imprimir el array después de la inicialización
    printArr(&arr);

    // Añadir el valor 22
    if (addElement(&arr, 22) == 0) {
        printf("Elemento añadido\n");
    } else {
        printf("Error al añadir elemento\n");
    }

    // Imprimir el array después de añadir 22
    printArr(&arr);

    // Añadir el valor 44
    if (addElement(&arr, 44) == 0) {
        printf("Elemento añadido\n");
    } else {
        printf("Error al añadir elemento\n");
    }

    // Imprimir el array después de añadir 44
    printArr(&arr);

    // Obtener el número de elementos en el array con getArrSize
    int size = getArrSize(&arr);
    if (size != -1) {
        printf("El número de elementos en el array es: %d\n", size);
    } else {
        printf("Error al obtener el tamaño del array\n");
    }

    // Obtener la suma de los elementos en el array con getArrAdd
    int suma = getArrAdd(&arr);
    if (suma != -1) {
        printf("La suma de los elementos en el array es: %d\n", suma);
    } else {
        printf("Error al obtener la suma de los elementos del array\n");
    }

    // Obtener un elemento en la posición 1
    int valor = getElement(&arr, 1);
    if (valor != -1) {
        printf("El valor en la posición 1 es: %d\n", valor);
    } else {
        printf("Error al obtener el valor en la posición 1\n");
    }

    // Obtener un elemento en una posición fuera de los límites
    valor = getElement(&arr, 10);
    if (valor != -1) {
        printf("El valor en la posición 10 es: %d\n", valor);
    } else {
        printf("Error al obtener el valor en la posición 10\n");
    }

    return 0;
}