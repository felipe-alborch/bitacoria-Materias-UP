/*
2) Contar elementos y sumar sus valores. Utilizando una lista cargada como en el ejercicio anterior, crear dos funciones: 
una que devuelva la cantidad de nodos y otra que devuelva la suma de sus valores. Mostrar ambos resultados desde main. 
No se debe utilizar un vector auxiliar ni conocer de antemano cuántos elementos tendrá la lista.
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
int calcularCantidadDeNodos(Nodo *lista);
int sumatoriaValores(Nodo *lista);

int main() {
    Nodo *lista = NULL;
    int cantNodos = 0, sumatoriaNumeros = 0;

    lista = (Nodo *) malloc(sizeof(Nodo));

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    ingresarDatos(lista);

    printf("\n\n--- MOSTRANDO ELEMENTOS DE LA LISTA ---\n\n");
    mostrarLista(lista);

    printf("\n\n--- CONTANDO LA CANTIDAD DE ELEMENTOS DE LA LISTA ---\n\n");
    cantNodos = calcularCantidadDeNodos(lista);
    printf("La cantidad de nodos que contiene la lista es: %d", cantNodos);

    printf("\n\n--- HACIENDO LA SUMATORIA DE LOS ELEMENTOS DE LA LISTA ---\n\n");
    sumatoriaNumeros = sumatoriaValores(lista);
    printf("La sumatoria de los numeros de la lista es: %d", sumatoriaNumeros);

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

int calcularCantidadDeNodos(Nodo *lista) {
    int contador = 0;

    while(lista != NULL) {
        contador += 1;
        lista = lista->siguiente;
    }

    return contador;
}

int sumatoriaValores(Nodo *lista) {
    int acumulador = 0;

    while(lista != NULL) {
        acumulador += lista->numero;
        lista = lista->siguiente;
    }

    return acumulador;
}