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
void ingresarDatos(Nodo *lista);

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