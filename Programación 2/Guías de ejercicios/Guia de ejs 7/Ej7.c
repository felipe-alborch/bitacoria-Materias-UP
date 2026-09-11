/*
Eliminar la primera aparición de un valor. Cargar una lista y solicitar un número a eliminar. 
Si existe, eliminar solamente su primera aparición, enlazando correctamente los nodos y liberando la memoria del nodo eliminado. 
Considerar los casos en que el valor se encuentra en el primer nodo, en el medio, al final o no existe. 
La función debe devolver el inicio actualizado de la lista.
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
Nodo *eliminarElemento(Nodo *lista);

int main() {
    Nodo *lista = NULL;

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    lista = ingresarDatos(lista);

    printf("\n\n--- MOSTRANDO ELEMENTOS DE LA LISTA ---\n\n");
    mostrarLista(lista);

    printf("\n\n--- ELIMINANDO UN ELEMENTO DE LA LISTA ---\n\n");
    eliminarElemento(lista);

    printf("\n\n--- MOSTRANDO ELEMENTOS DE LA LISTA ---\n\n");
    mostrarLista(lista);

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

Nodo *eliminarElemento(Nodo *lista) {
    int numAEliminar;
    Nodo *actual = lista, *anterior = NULL;

    printf("Ingrese el elemento a eliminar: ");
    scanf("%d", &numAEliminar);

    while (actual != NULL) {
        if (actual->numero == numAEliminar) {
            // Caso 1: el nodo a eliminar es el primero
            if (anterior == NULL) {
                lista = actual->siguiente;
            }
            else {
                // Caso 2 y 3: está en el medio o al final
                anterior->siguiente = actual->siguiente;
            }

            free(actual);

            return lista;
        }

        anterior = actual;
        actual = actual->siguiente;
    }

    printf("El elemento no existe en la lista.\n");

    return lista;
}