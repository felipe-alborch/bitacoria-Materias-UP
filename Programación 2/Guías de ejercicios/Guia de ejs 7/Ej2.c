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
Nodo *ingresarDatos(Nodo *lista);
Nodo *insertarNodo(Nodo *lista, int valor);
int calcularCantidadDeNodos(Nodo *lista);
int sumatoriaValores(Nodo *lista);

int main() {
    Nodo *lista = NULL;
    int cantNodos = 0, sumatoriaNumeros = 0;

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    lista = ingresarDatos(lista);

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

int calcularCantidadDeNodos(Nodo *lista) {
    int contador = 0;
    Nodo *actual = lista;

    while(actual != NULL) {
        contador += 1;
        actual = actual->siguiente;
    }

    return contador;
}

int sumatoriaValores(Nodo *lista) {
    Nodo *actual = lista;
    int acumulador = 0;

    while(actual != NULL) {
        acumulador += actual->numero;
        actual = actual->siguiente;
    }

    return acumulador;
}