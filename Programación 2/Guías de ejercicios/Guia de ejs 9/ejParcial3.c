/*
Crear una pila con la siguiente información:
    - num: numero entero.
    - siguiente: puntero al próximo elemento de la pila.

Escribir la función necesaria para calcular la cantidad de elementos múltiplos del último número ingresado a la pila. Si no hubiera ningún número mostrar una leyenda.
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
void mostrar(nodo nodoActual, int ultimoElemento, int *contador);

int main() {
    nodo *pila = NULL;
    int numero, ultimoElemento, contador = 0;

    printf("--- ARMANDO LA PILA ---\n\n");

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    while(numero != 0) {
        apilar(&pila, crearNodo(numero));

        ultimoElemento = numero;

        printf("Ingrese un numero: ");
        scanf("%d", &numero);
    }

    if(pila != NULL) {
        printf("\n--- DESARMANDO LA PILA ---\n\n");

        // Desapilamos el ultimo elemento ingresado
        desapilar(&pila);

        // Procesamos los elementos restantes
        while(pila != NULL)
            mostrar(desapilar(&pila), ultimoElemento, &contador);

        if(contador > 0)
            printf("\nLa cantidad de multiplos de %d es: %d\n",
                   ultimoElemento, contador);
        else
            printf("\nNo hay numeros multiplos del ultimo elemento.\n");
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
    nodo *nodoAuxiliar;
    nodo datos;

    datos = **pila;
    nodoAuxiliar = *pila;
    *pila = (*pila)->siguiente;

    free(nodoAuxiliar);

    return datos;
}

// Mostrar y contar multiplos
void mostrar(nodo nodoActual, int ultimoElemento, int *contador) {
    printf("%d\n", nodoActual.num);

    if(nodoActual.num % ultimoElemento == 0)
        *contador += 1;
}
