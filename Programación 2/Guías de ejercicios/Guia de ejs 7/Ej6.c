/*
Cargar una lista ordenada de menor a mayor. Ingresar números enteros hasta escribir 0, 
validando que cada nuevo número sea mayor o igual al anterior. 
Si el usuario ingresa un número menor, solicitarlo nuevamente hasta que respete el orden. Los valores repetidos deben permitirse. 
Insertar cada número al final y mostrar la lista resultante. 
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

int main() {
    Nodo *lista = NULL;

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    lista = ingresarDatos(lista);

    printf("\n\n--- MOSTRANDO ELEMENTOS DE LA LISTA ---\n\n");
    mostrarLista(lista);

    printf("\n\n--- LIBERANDO LA LISTA ---\n\n");
    liberarLista(lista);
    
    return 0;
}

Nodo *ingresarDatos(Nodo *lista) {
    int numero, aux = 0;
    
    printf("Ingresa un numero: ");
    scanf("%d", &numero);

    while(numero != 0) {
        if(numero >= aux) {
            lista = insertarNodo(lista, numero);
            aux = numero;
        }    
        else
            printf("Tenes que ingresar un numero que sea mayor o igual al anterior [%d]\n", aux);
        
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