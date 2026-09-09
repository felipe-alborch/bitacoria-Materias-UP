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
Nodo *ingresarDatos(Nodo *lista);
Nodo *insertarNodo(Nodo *lista, int valor);
float calcularPromedio(Nodo *lista);
int menorNumeroDeLaLista(Nodo *lista);

int main() {
    Nodo *lista = NULL;
    int menor = 0;
    float promedio = 0;

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    lista = ingresarDatos(lista);

    printf("\n\n--- MOSTRANDO ELEMENTOS DE LA LISTA ---\n\n");
    mostrarLista(lista);

    printf("\n\n--- CALCULANDO EL PROMEDIO DE LOS ELEMENTOS DE LA LISTA ---\n\n");
    promedio = calcularPromedio(lista);
    printf("El promedio de los elementos de la lista es: %.2f", promedio);

    printf("\n\n--- CALCULANDO EL MENOR ELEMENTO DE LA LISTA ---\n\n");
    
    if(lista != NULL) {
        menor = menorNumeroDeLaLista(lista);
        printf("El menor elemento de la lista es: %d", menor);
    }
    else
        printf("No se ingresaron elementos en la lista para calcular el menor.");

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

float calcularPromedio(Nodo *lista) {
    int contador = 0, acumulador = 0;
    Nodo *actual = lista;
    float promedio = 0;

    while(actual != NULL) {
        contador += 1;
        acumulador += actual->numero;

        actual = actual->siguiente;
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