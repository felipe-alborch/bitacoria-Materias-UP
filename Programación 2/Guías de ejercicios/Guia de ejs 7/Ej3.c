/*
3) Ingresar una lista de enteros y calcular el promedio de sus valores, el número mayor y el número menor. 
Resolver cada operación mediante una función independiente. 
Considerar qué debe ocurrir si la lista está vacía y evitar utilizar un valor arbitrario, como 0, para inicializar el mayor 
o el menor cuando podría producir un resultado incorrecto.
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
float calcularPromedio(Nodo *lista);
int menorNumeroDeLaLista(Nodo *lista);
int mayorNumeroDeLaLista(Nodo *lista);

int main() {
    Nodo *lista = NULL;
    int menor = 0, mayor = 0;
    float promedio = 0;

    lista = (Nodo *) malloc(sizeof(Nodo));

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    ingresarDatos(lista);
    
    if(lista != NULL) {
        printf("\n\n--- MOSTRANDO ELEMENTOS DE LA LISTA ---\n\n");
        mostrarLista(lista);

        printf("\n\n--- CALCULANDO EL PROMEDIO DE LOS ELEMENTOS DE LA LISTA ---\n\n");
        promedio = calcularPromedio(lista);
        printf("El promedio de los elementos de la lista es: %.2f", promedio);

        printf("\n\n--- CALCULANDO EL MENOR ELEMENTO DE LA LISTA ---\n\n");
        menor = menorNumeroDeLaLista(lista);
        printf("El menor elemento de la lista es: %d", menor);

        printf("\n\n--- CALCULANDO EL MAYOR ELEMENTO DE LA LISTA ---\n\n");
        mayor = mayorNumeroDeLaLista(lista);
        printf("El mayor elemento de la lista es: %d", mayor);
    }
    else
        printf("No se ingresaron elementos en la lista para realizar las operaciones.");

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

float calcularPromedio(Nodo *lista) {
    int contador = 0, acumulador = 0;
    float promedio = 0;

    while(lista != NULL) {
        contador += 1;
        acumulador += lista->numero;

        lista = lista->siguiente;
    }

    promedio = (float) acumulador / contador;

    return promedio;
}

int menorNumeroDeLaLista(Nodo *lista) {
    Nodo *actual = lista, *menor = lista;

    while(actual != NULL) {
        if(actual->numero < menor->numero)
            menor = actual;

        actual = actual->siguiente;
    }

    return menor->numero;
}

int mayorNumeroDeLaLista(Nodo *lista) {
    Nodo *actual = lista, *mayor = lista;

    while(actual != NULL) {
        if(actual->numero > mayor->numero)
            mayor = actual;

        actual = actual->siguiente;
    }

    return mayor->numero;
}