
#include <stdio.h>
#include <stdlib.h>

#define CANT 5

typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo;

nodo *crearNodo(int numero);
void acolar(nodo **primero, nodo **ultimo, nodo *nuevoNodo);
nodo desacolar(nodo **primero);
void mostrar(nodo nodoAMostrar);
void calcularProductoria(nodo **primero, nodo **ultimo);
void promedioDivisoresDelUltimoDeLaCola(nodo** primero, nodo **ultimo, int ultimoNumero);

int main() {
    int numero, ultimoNumero, primerElemento;
    nodo *primero = NULL;
    nodo *ultimo = NULL;

    printf("--- CARGANDO COLA ---\n\n");
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    primerElemento = numero;

    while(numero != 0) {
        ultimoNumero = numero;

        acolar(&primero, &ultimo, crearNodo(numero));

        printf("Ingrese un numero: ");
        scanf("%d", &numero);
    }

    printf("\n--- DESACOLANDO ---\n\n");
    while(primero != NULL)
        mostrar(desacolar(&primero));

    return 0;
}

nodo *crearNodo(int numero) {
    nodo *nuevoNodo;

    nuevoNodo = (nodo *)malloc(sizeof(nodo));

    nuevoNodo->dato = numero;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

void acolar(nodo **primero, nodo **ultimo, nodo *nuevoNodo) {
    if(*primero == NULL)
        *primero = *ultimo = nuevoNodo;
    else {
        (*ultimo)->siguiente = nuevoNodo;
        *ultimo = nuevoNodo;
    }
}

nodo desacolar(nodo **primero) {
    nodo *auxiliar;
    nodo datos;

    datos = **primero;
    auxiliar = *primero;

    *primero = (*primero)->siguiente;

    free(auxiliar);

    return datos;
}

void mostrar(nodo nodoAMostrar) {
    printf("%d\n", nodoAMostrar.dato);
}

void calcularProductoria(nodo **primero, nodo **ultimo) {
    nodo *primeroAuxiliar = NULL, *ultimoAuxiliar = NULL;
    nodo nodoDesacolado;
    int productoria = 1, contador = 0;

    while(*primero != NULL) {
        nodoDesacolado = desacolar(primero);

        if(nodoDesacolado.dato % 7 == 0) {
            productoria *= nodoDesacolado.dato;
            contador++;
        }

        acolar(&primeroAuxiliar, &ultimoAuxiliar, crearNodo(nodoDesacolado.dato));
    }

    // Restauramos la cola original
    *ultimo = NULL;

    while(primeroAuxiliar != NULL) {
        nodoDesacolado = desacolar(&primeroAuxiliar);

        acolar(primero, ultimo, crearNodo(nodoDesacolado.dato));
    }

    if(contador > 0)
        printf("La productoria es: %d\n", productoria);
    else
        printf("No hay multiplos de 7.\n");
}

void promedioDivisoresDelUltimoDeLaCola(nodo** primero, nodo **ultimo, int ultimoNumero) {
    nodo *primeroAuxiliar = NULL, *ultimoAuxiliar = NULL;
    nodo nodoDesacolado;
    int cantDivisores = 0, acumDivisores = 0;

    while(*primero != NULL) {
        nodoDesacolado = desacolar(primero);

        if(ultimoNumero % nodoDesacolado.dato == 0) {
            acumDivisores += nodoDesacolado.dato;
            cantDivisores += 1;
        }

        acolar(&primeroAuxiliar, &ultimoAuxiliar, crearNodo(nodoDesacolado.dato));
    }

    *ultimo = NULL;

    while(primeroAuxiliar != NULL) {
        nodoDesacolado = desacolar(&primeroAuxiliar);

        acolar(primero, ultimo, crearNodo(nodoDesacolado.dato));
    }

    if(cantDivisores > 0) 
        printf("El promedio de los divisores del ultimo elemento de la cola es: %.2f", acumDivisores / cantDivisores);
    else
        printf("No se encontraron divisores para el numero: %d", ultimoNumero);
}