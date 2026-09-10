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
Nodo *ingresarDatos(Nodo *lista);
Nodo *insertarNodo(Nodo *lista, int valor);
void buscarElemento(Nodo *lista);

int main() {
    Nodo *lista = NULL;

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    lista = ingresarDatos(lista);

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

Nodo *ingresarDatos(Nodo *lista) {
    int numero;
    
    printf("Ingresa un numero: ");
    scanf("%d", &numero);

    while(numero != 0) {
        lista = insertarNodo(lista, numero);
        
        printf("Ingresa un numero: ");
        scanf("%d", &numero);
    }

    return lista;
}

Nodo *insertarNodo(Nodo *lista, int valor) {
    Nodo *nuevo = malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        printf("No se pudo reservar memoria.\n");
        return lista;
    }

    nuevo->numero = valor;
    nuevo->siguiente = NULL;

    if (lista == NULL) {
        return nuevo;
    }

    Nodo *actual = lista;

    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo;

    return lista;
}

void mostrarLista(Nodo *lista) {
    Nodo *actual = lista;
    int contador = 1;

    while (actual != NULL) {
        printf("Numero [%d]: %d\n", contador, actual->numero);
        actual = actual->siguiente;

        contador += 1;
    }
}

void liberarLista(Nodo *lista) {
    Nodo *actual = lista;

    while (actual != NULL) {
        Nodo *siguiente = actual->siguiente;

        free(actual);

        actual = siguiente;
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