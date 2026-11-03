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
void mostrar(nodo nodoActual, int *contador, int ultimoElemento);

int main() {
    nodo *pila = NULL, ultimoElem;
    int numero, ultimoElemento, contador = 0;

    // Cargar la pila
    printf("--- ARMANDO LA PILA ---\n\n");

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if(numero != 0) {
        while(numero != 0) {
            apilar(&pila, crear_nodo(numero));

            ultimoElemento = numero;

            printf("Ingrese un numero: ");
            scanf("%d", &numero);
        }

        // Desapilar y realizar los calculos
        printf("\n--- DESARMANDO LA PILA ---\n\n");

        ultimoElem = desapilar(&pila);
        printf("%d\n", ultimoElem.A);

        while(pila != NULL)
            mostrar(desapilar(&pila), &contador, ultimoElemento);

        if(contador != 0)
            printf("La cantidad de multiplos del ultimo elemento de la pila es: %d.", contador);
        else
            printf("No hay multiplos del ultimo elemento de la pila.\n");

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
void mostrar(nodo nodoActual, int *contador, int ultimoElemento) {
    printf("%d\n", nodoActual.A);

    if(nodoActual.A % ultimoElemento == 0)
        *contador += 1;
}