#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

// Prototipos
Nodo *insertarFinal(Nodo *lista, int valor);
void mostrarLista(Nodo *lista);
void liberarLista(Nodo *lista);

int main() {
    Nodo *lista = NULL;

    lista = insertarFinal(lista, 10);
    lista = insertarFinal(lista, 20);
    lista = insertarFinal(lista, 30);
    lista = insertarFinal(lista, 40);

    printf("Elementos de la lista:\n");
    mostrarLista(lista);

    liberarLista(lista);

    return 0;
}

Nodo *insertarFinal(Nodo *lista, int valor) {
    Nodo *nuevo = malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        printf("No se pudo reservar memoria.\n");
        return lista;
    }

    nuevo->dato = valor;
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

    while (actual != NULL) {
        printf("%d\n", actual->dato);
        actual = actual->siguiente;
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