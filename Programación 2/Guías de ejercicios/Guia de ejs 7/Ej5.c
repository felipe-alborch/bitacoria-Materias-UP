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
void ingresarDatos(Nodo *lista);
Nodo *insertarNodoAlInicio(Nodo *lista, int valor);
Nodo *agregarElementoExtra(Nodo *lista);

int main() {
    Nodo *lista = NULL;
    lista = (Nodo *) malloc(sizeof(Nodo));

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    ingresarDatos(lista);

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