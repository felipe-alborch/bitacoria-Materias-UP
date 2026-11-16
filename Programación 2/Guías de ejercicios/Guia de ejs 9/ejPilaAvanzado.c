
#include <stdio.h>
#include <stdlib.h>

#define I 2
#define Z 4

typedef struct nodo {
    int A;
    struct nodo *siguiente;
} nodo;

// Prototipos
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

    if(pila != NULL) {
        printf("\nIngrese un valor N: ");
        scanf("%d", &n);

        asignarValorI(&pila, n);

        printf("\n--- ELIMINANDO VALOR Z ---\n");
        eliminarValorZ(&pila);

        printf("\n--- INVIRTIENDO LA PILA ---\n");
        invertirElementosPila(&pila);

        printf("\n--- DESARMANDO LA PILA ---\n");

        while(pila != NULL)
            mostrar(desapilar(&pila));
    }
    else
        printf("No se ingresaron elementos.\n");

    return 0;
}

// Crear nodo
nodo *crearNodo(int numero) {
    nodo *nuevoNodo;

    nuevoNodo = (nodo *) malloc(sizeof(nodo));
    nuevoNodo->A = numero;
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
    nodo *nodoAuxiliar;
    nodo datos;

    datos = **pila;
    nodoAuxiliar = *pila;
    *pila = (*pila)->siguiente;

    free(nodoAuxiliar);

    return datos;
}

// Mostrar
void mostrar(nodo nodoActual) {
    printf("%d\n", nodoActual.A);
}

// Ejercicio 1: Asignar valor I a la posicion N
void asignarValorI(nodo **pila, int n) {
    nodo *pilaAuxiliar = NULL;
    nodo nodoActual;
    int contador = 1;

    if(n < 1) {
        printf("La posicion ingresada no es valida.\n");
    }
    else {
        while(*pila != NULL && contador < n) {
            nodoActual = desapilar(pila);
            apilar(&pilaAuxiliar, crearNodo(nodoActual.A));

            contador++;
        }

        if(*pila != NULL) {
            nodoActual = desapilar(pila);
            nodoActual.A = I;

            apilar(pila, crearNodo(nodoActual.A));
        }
        else
            printf("La posicion ingresada no existe.\n");

        while(pilaAuxiliar != NULL) {
            nodoActual = desapilar(&pilaAuxiliar);
            apilar(pila, crearNodo(nodoActual.A));
        }
    }
}

// Ejercicio 2: Eliminar el primer nodo con valor Z
void eliminarValorZ(nodo **pila) {
    nodo *pilaAuxiliar = NULL;
    nodo nodoActual;

    while(*pila != NULL && (*pila)->A != Z) {
        nodoActual = desapilar(pila);
        apilar(&pilaAuxiliar, crearNodo(nodoActual.A));
    }

    if(*pila != NULL)
        nodoActual = desapilar(pila);
    else
        printf("No existe el valor Z en la pila.\n");

    while(pilaAuxiliar != NULL) {
        nodoActual = desapilar(&pilaAuxiliar);
        apilar(pila, crearNodo(nodoActual.A));
    }
}

// Ejercicio 3: Invertir la pila
void invertirElementosPila(nodo **pila) {
    nodo *pilaAuxiliar = NULL;
    nodo nodoActual;

    while(*pila != NULL) {
        nodoActual = desapilar(pila);
        apilar(&pilaAuxiliar, crearNodo(nodoActual.A));
    }

    *pila = pilaAuxiliar;
}