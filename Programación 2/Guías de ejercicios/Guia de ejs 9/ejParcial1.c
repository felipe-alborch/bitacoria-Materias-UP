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

nodo *crearNodo(int numero);
void apilar(nodo **pila, nodo *nuevoNodo);
nodo desapilar(nodo **pila);
void mostrar(nodo nodoAMostrar);
void calcularSumatoria(nodo **pila, int primerElemento);  

int main() {
    int numero, primerElemento;
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

    printf("\n\n--- CALCULANDO LA SUMATORIA DE LOS ELEMENTOS MAYORES AL PRIMER ELEMENTO INGRESADO DE LA PILA ---\n\n");
    calcularSumatoria(&pila, primerElemento);

    printf("\n\n--- DESARMANDO LA PILA ---\n\n");
    while(pila != NULL)
        mostrar(desapilar(&pila));
    
    return 0;
}

nodo *crearNodo(int numero) {
    nodo *nuevoNodo;

    nuevoNodo = (nodo *) malloc(sizeof(nodo));
    nuevoNodo->num = numero;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

void apilar(nodo **pila, nodo *nuevoNodo) {
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
}

nodo desapilar(nodo **pila) {
    nodo *nodoAux;
    nodo datos;

    nodoAux = *pila;
    datos = **pila;

    *pila = (*pila)->siguiente;

    free(nodoAux);

    return datos;
}

void mostrar(nodo nodoAMostrar) {
    printf("%d\n", nodoAMostrar.num);
}


void calcularSumatoria(nodo **pila, int primerElemento) {
    nodo *pilaAux = NULL;
    nodo nodoActual;
    int sumatoria = 0, contador = 0;

    while(*pila != NULL) {
        nodoActual = desapilar(pila);

        if(nodoActual.num > primerElemento) {
            sumatoria += nodoActual.num;
            contador++;
        }

        apilar(&pilaAux, crearNodo(nodoActual.num));
    }

    // Recuperar los elementos de la pila original
    while(pilaAux != NULL) {
        nodoActual = desapilar(&pilaAux);
        apilar(pila, crearNodo(nodoActual.num));
    }

    if(contador > 0)
        printf("La sumatoria es: %d\n", sumatoria);
    else
        printf("No hay numeros mayores al primer elemento.\n");
}