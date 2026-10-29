#include <stdio.h>
#include <stdlib.h>

#define I 2
#define Z 4

typedef struct nodo {
    int A;
    struct nodo *siguiente;
} nodo;

nodo *crearNodo(int numero);
void apilar(nodo **pila, nodo *nuevoNodo);
nodo desapilar(nodo **pila);
void mostrar(nodo nodoActual);
void asignarValorI(nodo **pila, int n);
void eliminarValorZ(nodo **pila);
void invertirElementosPila(nodo **pila);

int main() {
    nodo *pila = NULL;
    int numero, n;

    printf("--- ARMANDO LA PILA ---\n\n");
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    while(numero != 0) {
        apilar(&pila, crearNodo(numero));

        printf("Ingrese un numero: ");
        scanf("%d", &numero);
    }

    printf("\n\nIngrese un valor N: ");
    scanf("%d", &n);
    asignarValorI(&pila, n);

    printf("\n\n--- ELIMINANDO VALOR Z ---\n\n");
    eliminarValorZ(&pila);

    printf("\n\n--- INVIRTIENDO LOS ELEMENTOS DE LA PILA ---\n\n");
    invertirElementosPila(&pila);

    printf("--- DESARMANDO LA PILA ---\n\n");
    while(pila != NULL) {
        mostrar(desapilar(&pila));
    }
    
    return 0;
}

nodo *crearNodo(int numero) {
    nodo *nuevoNodo;

    nuevoNodo = (nodo *) malloc(sizeof(nodo));
    nuevoNodo->A = numero;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

void apilar(nodo **pila, nodo *nuevoNodo) {
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
}

nodo desapilar(nodo **pila) {
    nodo *nodoAuxiliar, datos;

    datos = **pila;
    nodoAuxiliar = *pila;
    *pila = (*pila)->siguiente;

    free(nodoAuxiliar);

    return datos;
}

void mostrar(nodo nodoActual) {
    printf("%d\n", nodoActual.A);
}


void asignarValorI(nodo **pila, int n) {
    nodo *pilaAuxiliar = NULL;
    nodo nodoActual;
    int contador = 1;

    // Desapilar hasta llegar a la posicion N
    while(*pila != NULL && contador < n) {
        nodoActual = desapilar(pila);
        apilar(&pilaAuxiliar, crearNodo(nodoActual.A));

        contador++;
    }

    // Modificar el elemento en la posicion N
    if(*pila != NULL) {
        nodoActual = desapilar(pila);
        nodoActual.A = I;

        apilar(pila, crearNodo(nodoActual.A));
    } 
    else
        printf("La posicion ingresada no existe.\n");

    // Recuperar los elementos originales
    while(pilaAuxiliar != NULL) {
        nodoActual = desapilar(&pilaAuxiliar);
        apilar(pila, crearNodo(nodoActual.A));
    }
}

void eliminarValorZ(nodo **pila) {
    nodo *pilaAux = NULL, nodoActual;

    while(*pila != NULL && (*pila)->A != Z) {
        nodoActual = desapilar(pila);
        apilar(&pilaAux, crearNodo(nodoActual.A));
    }

    if(*pila != NULL)
        nodoActual = desapilar(pila);
    else
        printf("No existe ese valor en la pila.\n");

    while(pilaAux != NULL) {
        nodoActual = desapilar(&pilaAux);
        apilar(pila, crearNodo(nodoActual.A));
    }
}

void invertirElementosPila(nodo **pila) {
    nodo *pilaAux = NULL;
    nodo nodoActual;

    while(*pila != NULL) {
        nodoActual = desapilar(pila);
        apilar(&pilaAux, crearNodo(nodoActual.A));
    }

    *pila = pilaAux;
}