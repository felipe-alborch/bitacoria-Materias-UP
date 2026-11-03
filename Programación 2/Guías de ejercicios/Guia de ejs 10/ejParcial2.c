#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol {
int dato;
struct arbol *izq;
struct arbol *der;
} arbol;

void insertar(arbol **hoja, int elem);
void mostrar (arbol *hoja);
void buscarMayorElementoDelArbolDivisorDeLaRaiz(arbol *hoja, int raiz, int *mayor);
void cantNodosHojasImpares(arbol *hoja, int *contador);

int main() {
    int numeros[] = {8, 3, 10, 1, 6, 14, 4, 7, 13}, mayor = 1, contador = 0;
    arbol *tree = NULL;
    
    printf ("--- CARGANDO ARBOL ---\n");
    for(int i = 0; i < 9; i++)
        insertar(&tree, numeros[i]);

    printf ("\n\n--- MOSTRANDO ARBOL ---\n");
    printf ("***************\n");
    mostrar (tree);

    printf ("\n\n--- MOSTRANDO EL MAYOR ELEMENTO DIVISOR DE LA RAIZ ---\n");
    buscarMayorElementoDelArbolDivisorDeLaRaiz(tree->izq, tree->dato, &mayor);
    buscarMayorElementoDelArbolDivisorDeLaRaiz(tree->der, tree->dato, &mayor);
    printf("%d", mayor);

    printf ("\n\n--- CALCULANDO CANTIDAD DE NODOS HOJAS IMPARES ---\n");
    cantNodosHojasImpares(tree, &contador);
    printf("%d\n", contador);
    
    return 0;
}

void insertar(arbol **hoja, int elem) {
    int numero = elem;

    if(elem == -1)
        return;

    if(*hoja == NULL) {
        //creo la hoja vacia
        (*hoja) = (arbol*) malloc(sizeof(arbol));
        (*hoja)->dato = elem;
        (*hoja)->der = NULL;
        (*hoja)->izq = NULL;
    }
    else {
        if(numero > (*hoja)->dato)
            insertar(&(*hoja)->der, elem);
        else
            insertar(&(*hoja)->izq, elem);
    }

    return;
}

void mostrar(arbol *hoja) {
    if(hoja != NULL) {
        mostrar(hoja->izq);
        printf("%d ", hoja->dato);
        mostrar(hoja->der);
    }

    return;
}

void buscarMayorElementoDelArbolDivisorDeLaRaiz(arbol *hoja, int raiz, int *mayor) {
    if(hoja != NULL) {
        buscarMayorElementoDelArbolDivisorDeLaRaiz(hoja->izq, raiz, mayor);

        if(raiz % hoja->dato == 0 && hoja->dato > *mayor)
            *mayor = hoja->dato;

        buscarMayorElementoDelArbolDivisorDeLaRaiz(hoja->der, raiz, mayor);
    }
}

void cantNodosHojasImpares(arbol *hoja, int *contador) {
    if(hoja != NULL) {
        cantNodosHojasImpares(hoja->izq, contador);

        if((hoja->izq == NULL && hoja->der == NULL)  && hoja->dato % 2 != 0)
            *contador += 1;

        cantNodosHojasImpares(hoja->der, contador);
    }
}