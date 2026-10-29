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
void mostrar(nodo nodoActual);

int main() {
    nodo *pila = NULL;
    int numero, contadorMultiplosDe3 = 0;

    // Cargar la pila
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    while(numero != 0) {
        if(numero % 3 == 0)
            contadorMultiplosDe3 += 1;
        
        apilar(&pila, crear_nodo(numero));
        
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
    }

    // Desapilar y mostrar los elementos
    printf("\nElementos de la pila:\n");

    while(pila != NULL)
        mostrar(desapilar(&pila));

    printf("La cantidad de multiplos de 3 es: %d", contadorMultiplosDe3);

    return 0;
}

// Crear un nodo
nodo* crear_nodo(int numero) {
    nodo *nuevoNodo;

    nuevoNodo = (nodo*) malloc(sizeof(nodo));
    nuevoNodo->A = numero;
    nuevoNodo->SIG = NULL;

    return nuevoNodo;
}

// Apilar un nodo
void apilar(nodo **pila, nodo *nuevoNodo) {
    nuevoNodo->SIG = *pila;
    *pila = nuevoNodo;
}

// Desapilar un nodo
nodo desapilar(nodo **pila) {
    nodo *nodoAuxiliar;
    nodo datos;

    datos = **pila;
    nodoAuxiliar = *pila;
    *pila = (*pila)->SIG;

    free(nodoAuxiliar);

    return datos;
}

// Mostrar un nodo
void mostrar(nodo nodoActual) {
    printf("%d\n", nodoActual.A);
}