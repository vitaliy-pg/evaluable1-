
//1. Estructura arrayLength_t
//Esta estructura sirve para encapsular un array de enteros con capacidad para almacenar hasta 10 valores, junto con dos campos adicionales:

//arrInt[10]: El array que almacenará hasta 10 enteros. Si una posición no tiene un valor válido, se almacena -1.
//arrSize: Indica cuántos elementos válidos (positivos o 0) se han añadido al array.
//arrAdd: Mantiene la suma de todos los valores almacenados en el array.


//2. Función initArray(arrayLength_t *arr)
//Esta función inicializa el array y otros campos de la estructura. Su objetivo es asegurarse de que el array comience en un estado válido:

//Establece todas las posiciones del array a -1 para indicar que están vacías.
//Inicializa arrSize y arrAdd a 0, indicando que no hay elementos añadidos y la suma es 0.
//Esta función es crucial porque asegura que el array siempre tenga valores controlados antes de su uso. Se utiliza en la inicialización de las variables al1 y al2.


//3. Función addElement(arrayLength_t *arr, int valor)
//Esta función añade un nuevo valor al array, siempre que:

//El valor sea mayor o igual a 0.
//Haya espacio disponible en el array (es decir, arrSize es menor que 10).
//Si todo es válido, añade el nuevo valor en la primera posición vacía, actualiza el tamaño (arrSize) y la suma de los elementos (arrAdd).

// importante porque permite que se agreguen nuevos valores al array y actualiza las estadísticas de la estructura (cantidad de elementos y suma). Esta función se usa en varias partes del programa, como al agregar valores en el paso b).

//4. Función printArr(const arrayLength_t *arr)
//Su función es mostrar el estado actual de la estructura en distintos momentos del programa.

//5. Función getElement(const arrayLength_t *arr, int posicion)
//Recibe una posición del array y devuelve el valor almacenado en esa posición, si es válido (es decir, si la posición está dentro del rango de 0 a 9 y contiene un valor distinto de -1). Si no, devuelve -1.

//Se usa para obtener valores específicos del array, como en el paso f), donde se añaden las posiciones pares del array al1 al array al2.

//6. Función setElement(arrayLength_t *arr, int posicion, int nuevoValor)
//Modifica un valor ya existente en una posición específica del array, siempre que:

//La posición sea válida (0 a 9).
//La posición ya contenga un valor válido.
//El nuevo valor a insertar sea mayor o igual a 0.
//Si se cumplen las condiciones, la función actualiza el valor en esa posición y modifica la suma arrAdd correctamente, restando el valor anterior y sumando el nuevo.

//Esta función es importante para modificar los elementos del array. Por ejemplo, en el paso d) se actualizan las posiciones impares del array al1:

//7. Función main()
//La función main() es el programa principal que coordina todas las funciones anteriores para realizar varias operaciones sobre las estructuras al1 y al2.

//a) Declarar dos estructuras de tipo arrayLength_t
//al1 y al2 son dos instancias de la estructura. Se inicializan usando la función initArray.
//b) Añadir valores al array al1
  //      Se utiliza la función addElement para almacenar los valores 0, 10, 20, ..., 90 en el array al1.

//c) Mostrar la estructura de al1
  //      Se llama a printArr para mostrar el contenido de al1 tras haber añadido los valores.

//d) Actualizar las posiciones impares con valores 1, 3, 5, 7, 9
//Usa setElement para modificar las posiciones impares del array al1.

//e) Mostrar de nuevo la estructura de al1
  //      Se imprime la estructura modificada para verificar los cambios.

//f) Añadir las posiciones pares de al1 a al2
//Utiliza getElement y addElement para copiar los valores en las posiciones pares del array al1 a al2.

//g) Añadir los valores 0, 1, 2, 3, 4 a las posiciones finales de al2
//Se usa addElement para completar el array al2 con los valores 0 a 4 en sus posiciones restantes.

//h) Mostrar la estructura de al2
  //      Finalmente, se muestra el contenido de al2.


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