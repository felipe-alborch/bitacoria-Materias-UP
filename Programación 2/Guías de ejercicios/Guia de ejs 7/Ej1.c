/*
1) Crear y mostrar una lista de enteros. Ingresar números enteros hasta que el usuario escriba 0. 
Cada número debe almacenarse en un nodo nuevo, insertándolo al final de la lista. 
Luego, recorrerla y mostrar todos los valores en el mismo orden en que fueron ingresados. 
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
//Nodo *insertarNodo(Nodo *lista, int valor);

int main() {
    Nodo *lista = NULL;
    lista = (Nodo *) malloc(sizeof(Nodo));

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    ingresarDatos(lista);

    printf("\n\n--- MOSTRANDO ELEMENTOS DE LA LISTA ---\n\n");
    mostrarLista(lista);

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

void ingresarDatos2(Nodo *lista) {
    Nodo *aux = NULL;
    
    printf("Ingresa un numero: ");
    scanf("%d", &lista->numero);

    if(lista->numero == 0) {
        lista->siguiente = NULL;
        return;
    }

    lista->siguiente = (Nodo *) malloc(sizeof(Nodo));
    ingresarDatos2(lista->siguiente);
}

/*Nodo *insertarNodo(Nodo *lista, int valor) {
    Nodo *nuevo = malloc(sizeof(Nodo));

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
}*/

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