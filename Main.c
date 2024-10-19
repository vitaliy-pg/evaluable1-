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