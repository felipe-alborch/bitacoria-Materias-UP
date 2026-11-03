/*
Para los siguientes ejercicios crear una pila con la siguiente información:
  - A: entero.
  - SIG: puntero al próximo elemento de la pila.
y calcular:
1) La cantidad de números múltiplos de 3.
2) El promedio de aquellos números divisores de 4.
3) La sumatoria de aquellos números múltiplos del primer elemento ingresado a la pila.
4) El número máximo y su posición en la pila.
5) El número mínimo y su posición en la pila.
6) Ingresar un numero por teclado y calcular la cantidad de veces que está en la pila. Si no está, mostrar una leyenda
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tiponodo {
    int A;
    struct tiponodo *SIG;
} nodo;

// Prototipos
nodo* crear_nodo(int numero);
void apilar(nodo **pila, nodo *nuevoNodo);
nodo desapilar(nodo **pila);
void mostrar(nodo nodoActual, int primerElemento, int *sumatoria, int *contador);

int main() {
    nodo *pila = NULL;
    int numero, primerElemento;
    int sumatoria = 0, contador = 0;

    // Cargar la pila
    printf("--- ARMANDO LA PILA ---\n\n");

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if(numero != 0) {
        primerElemento = numero;

        while(numero != 0) {
            apilar(&pila, crear_nodo(numero));

            printf("Ingrese un numero: ");
            scanf("%d", &numero);
        }

        // Desapilar y realizar los calculos
        printf("\n--- DESARMANDO LA PILA ---\n\n");

        while(pila != NULL)
            mostrar(desapilar(&pila), primerElemento, &sumatoria, &contador);

        // Mostrar resultado
        if(contador > 0)
            printf("\nLa sumatoria es: %d\n", sumatoria);
        else
            printf("\nNo hay numeros mayores al primer elemento.\n");

    } 
    else
        printf("No se ingresaron numeros en la pila.\n");

    return 0;
}

// Crear nodo
nodo* crear_nodo(int numero) {
    nodo *nuevoNodo;

    nuevoNodo = (nodo*) malloc(sizeof(nodo));
    nuevoNodo->A = numero;
    nuevoNodo->SIG = NULL;

    return nuevoNodo;
}

// Apilar
void apilar(nodo **pila, nodo *nuevoNodo) {
    nuevoNodo->SIG = *pila;
    *pila = nuevoNodo;
}

// Desapilar
nodo desapilar(nodo **pila) {
    nodo *nodoAuxiliar;
    nodo datos;

    datos = **pila;
    nodoAuxiliar = *pila;
    *pila = (*pila)->SIG;

    free(nodoAuxiliar);

    return datos;
}

// Mostrar y calcular sumatoria
void mostrar(nodo nodoActual, int primerElemento, int *sumatoria, int *contador) {
    printf("%d\n", nodoActual.A);

    if(nodoActual.A > primerElemento) {
        *sumatoria += nodoActual.A;
        (*contador)++;
    }
}