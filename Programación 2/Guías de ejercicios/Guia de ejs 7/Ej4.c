/*
Buscar un elemento por su valor. Crear una función que reciba la lista y un número ingresado por el usuario. 
La función debe recorrer la lista y determinar si ese número existe. 
Si aparece, informar su posición comenzando desde 1; si no aparece, indicar que no fue encontrado. 
Como variante, contar cuántas veces aparece el valor buscado.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Nodo {
    int numero;
    struct Nodo *siguiente;
} Nodo;

void mostrarLista(Nodo *lista);
void liberarLista(Nodo *lista);
void ingresarDatos(Nodo *lista);
void buscarElemento(Nodo *lista);

int main() {
    Nodo *lista = NULL;
    lista = (Nodo *) malloc(sizeof(Nodo));

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    ingresarDatos(lista);

    if(lista != NULL) {
        printf("\n\n--- MOSTRANDO ELEMENTOS DE LA LISTA ---\n\n");
        mostrarLista(lista);

        printf("\n\n--- BUSCANDO UN ELEMENTO DE LA LISTA ---\n\n");
        buscarElemento(lista);
    }
    else
        printf("No se ingresaron elementos en la lista para realizar las operaciones.");

    printf("\n\n--- LIBERANDO LA LISTA ---\n\n");
    liberarLista(lista);
    
    return 0;
}

void ingresarDatos(Nodo *lista) {
    int numero;

    printf("Ingresa un numero: ");
    scanf("%d", &numero);

    while(numero != 0) {
        lista->numero = numero;

        printf("Ingresa un numero: ");
        scanf("%d", &numero);

        if(numero != 0) {
            lista->siguiente = (Nodo *) malloc(sizeof(Nodo));
            lista = lista->siguiente;
        }
    }

    lista->siguiente = NULL;
}

void mostrarLista(Nodo *lista) {
    int contador = 1;

    while(lista != NULL) {
        printf("Numero [%d]: %d\n", contador, lista->numero);
        lista = lista->siguiente;

        contador += 1;
    }
}

void liberarLista(Nodo *lista) {
    while (lista != NULL) {
        Nodo *siguiente = lista->siguiente;

        free(lista);

        lista = siguiente;
    }
}

void buscarElemento(Nodo *lista) {
    Nodo *actual = lista;
    int numeroBuscado, cantApariciones = 0, pos = 1;

    printf("Inserte el elemento a buscar en la lista: ");
    scanf("%d", &numeroBuscado);

    while(actual != NULL) {
        if(actual->numero == numeroBuscado) {
            cantApariciones += 1;
            printf("El elemento aparecio en la posicion [%d] \n", pos);
        }

        actual = actual->siguiente;
        pos += 1;
    }

    printf("\nEl numero [%d] aparecio un total de [%d] veces.", numeroBuscado, cantApariciones);
}