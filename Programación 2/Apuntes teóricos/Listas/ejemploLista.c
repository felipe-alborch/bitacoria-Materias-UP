#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

// Prototipos
Nodo *insertarInicio(Nodo *lista, int valor);
void mostrarLista(Nodo *lista);
void liberarLista(Nodo *lista);

int main() {
    Nodo *lista = NULL;

    lista = insertarInicio(lista, 30);
    lista = insertarInicio(lista, 20);
    lista = insertarInicio(lista, 10);

    printf("Elementos de la lista:\n");
    mostrarLista(lista);

    liberarLista(lista);

    return 0;
}

Nodo *insertarInicio(Nodo *lista, int valor) {
    Nodo *nuevo = malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        printf("No se pudo reservar memoria.\n");
        return lista;
    }

    nuevo->dato = valor;
    nuevo->siguiente = lista;

    return nuevo;
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