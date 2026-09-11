/*
Partiendo de una lista ya cargada, permitir que el usuario elija si desea agregar un número al comienzo o al final. 
Implementar ambas operaciones en funciones separadas y mostrar la lista después de cada inserción.
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
Nodo *insertarNodoAlInicio(Nodo *lista, int valor);
Nodo *agregarElementoExtra(Nodo *lista);

int main() {
    Nodo *lista = NULL;

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    lista = ingresarDatos(lista);

    printf("\n\n--- MOSTRANDO ELEMENTOS DE LA LISTA ---\n\n");
    mostrarLista(lista);

    printf("\n\n--- INSERTANDO UN NUEVO ELEMENTO EN LA LISTA ---\n\n");
    lista = agregarElementoExtra(lista);

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

Nodo *insertarNodoAlInicio(Nodo *lista, int valor) {
    Nodo *nuevo = malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        printf("No se pudo reservar memoria.\n");
        return lista;
    }

    nuevo->numero = valor;
    nuevo->siguiente = lista;

    return nuevo;
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

Nodo *agregarElementoExtra(Nodo *lista) {
    char seguirCargandoDatos, inicioFinal;
    int numero;

    do {
        printf("Desea agregar un elemento a la lista? (S/N): ");
        scanf("%c", &seguirCargandoDatos);

        if(seguirCargandoDatos != 'N' && seguirCargandoDatos != 'n' && seguirCargandoDatos != 'S' && seguirCargandoDatos != 's')
            printf("Las unicas respuestas validas son: S/s/N/n\n");
    } while(seguirCargandoDatos != 'N' && seguirCargandoDatos != 'n' && seguirCargandoDatos != 'S' && seguirCargandoDatos != 's');

    while(seguirCargandoDatos != 'N' && seguirCargandoDatos != 'n') {
        do {
            printf("Donde desea agregar el elemento? (I/F): ");
            scanf("%c", &inicioFinal);

            if(inicioFinal != 'I' && inicioFinal != 'i' && inicioFinal != 'F' && inicioFinal != 'f')
                printf("Las unicas respuestas validas son: I/i/F/f\n");
        } while(inicioFinal != 'I' && inicioFinal != 'i' && inicioFinal != 'F' && inicioFinal != 'f');

        printf("Ingrese el numero a agregar: ");
        scanf("%d", &numero);

        if(inicioFinal == 'F' || inicioFinal == 'f')
            lista = insertarNodo(lista, numero);
        else
            lista = insertarNodoAlInicio(lista, numero);
        
        do {
            printf("Desea agregar un elemento a la lista? (S/N): ");
            scanf("%c", &seguirCargandoDatos);

            if(seguirCargandoDatos != 'N' && seguirCargandoDatos != 'n' && seguirCargandoDatos != 'S' && seguirCargandoDatos != 's')
                printf("Las unicas respuestas validas son: S/s/N/n\n");
        } while(seguirCargandoDatos != 'N' && seguirCargandoDatos != 'n' && seguirCargandoDatos != 'S' && seguirCargandoDatos != 's');
    }

    return lista;
}