/*
Crear una pila con la siguiente información:

 - num: numero entero.
 - siguiente: puntero al próximo elemento de la pila.

Desarrollar una función que permita mostrar la sumatoria de números
mayores al primer elemento ingresado en la pila. Si no hubiera ningún
número mostrar una leyenda.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int num;
    struct nodo *siguiente;
} nodo;

// Prototipos
nodo *crearNodo(int numero);
void apilar(nodo **pila, nodo *nuevoNodo);
nodo desapilar(nodo **pila);
void mostrar(nodo nodoAMostrar, int primerElemento, int *sumatoria, int *contador);

int main() {
    int numero, primerElemento;
    int sumatoria = 0, contador = 0;
    nodo *pila = NULL;

    printf("--- ARMANDO LA PILA ---\n\n");

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    primerElemento = numero;

    while(numero != 0) {
        apilar(&pila, crearNodo(numero));

        printf("Ingrese un numero: ");
        scanf("%d", &numero);
    }

    if(pila != NULL) {
        printf("\n--- DESARMANDO LA PILA ---\n\n");

        while(pila != NULL)
            mostrar(desapilar(&pila), primerElemento, &sumatoria, &contador);

        if(contador > 0)
            printf("\nLa sumatoria es: %d\n", sumatoria);
        else
            printf("\nNo hay numeros mayores al primer elemento.\n");
    }
    else
        printf("\nNo se ingresaron elementos en la pila.\n");

    return 0;
}

// Crear nodo
nodo *crearNodo(int numero) {
    nodo *nuevoNodo;

    nuevoNodo = (nodo *) malloc(sizeof(nodo));
    nuevoNodo->num = numero;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

// Apilar
void apilar(nodo **pila, nodo *nuevoNodo) {
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
}

// Desapilar
nodo desapilar(nodo **pila) {
    nodo *nodoAux;
    nodo datos;

    nodoAux = *pila;
    datos = **pila;

    *pila = (*pila)->siguiente;

    free(nodoAux);

    return datos;
}

// Mostrar y calcular la sumatoria
void mostrar(nodo nodoAMostrar, int primerElemento, int *sumatoria, int *contador) {

    printf("%d\n", nodoAMostrar.num);

    if(nodoAMostrar.num > primerElemento) {
        *sumatoria += nodoAMostrar.num;
        *contador += 1;
    }
}