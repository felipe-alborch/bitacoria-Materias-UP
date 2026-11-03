/*
Dibujar un árbol binario de búsqueda desde los siguientes números: 12-7-4-28-36-9-48-18-27-1
Crear y mostrar un árbol binario de búsqueda. Escribir las funciones necesarias para calcular y luego mostrar:

a) Sumatoria de aquellos nodos múltiplos de 9 con un solo hijo. (Rta: 36)
b) Buscar el máximo elemento del árbol que no sea múltiplo de la raíz. (Rta: 28)
c) Mostrar el árbol en pre-orden.
d) Indicar en qué nivel del árbol se encuentra un determinado número (el mismo debe ser solicitado al usuario). Si el número no se encuentra en el árbol informarlo.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct arbol {
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

void insertar(treenode **hoja, int elem);
void mostrar(treenode *hoja);
void sumarMultiplos9(treenode *hoja, int *suma);
void buscarMaximo(treenode *hoja, int raiz, int *maximo);
int buscarNivel(treenode *hoja, int numeroBuscado, int nivel);

int main() {
    treenode *arbol = NULL;
    int numeros[] = {12, 7, 4, 28, 36, 9, 48, 18, 27, 1}, suma = 0, maximo = 7, numeroBuscado, nivelEncontrado;

    // Cargamos los números en el árbol
    for(int i = 0; i < 10; i++)
        insertar(&arbol, numeros[i]);

    printf("--- ARBOL BINARIO DE BUSQUEDA ---\n\n");
    mostrar(arbol);

    printf("\n\n--- MULTIPLOS DE 9 ---\n");
    sumarMultiplos9(arbol, &suma);
    printf("Sumatoria multiplos de 9 con un solo hijo: %d", suma);

    printf("\n\n--- BUSCANDO MAXIMO ---\n");
    buscarMaximo(arbol, arbol->dato, &maximo);
    printf("Maximo: %d", maximo);

    printf("\n\n--- BUSCAR NIVEL DE UN NUMERO ---\n");
    printf("Ingrese un numero: ");
    scanf("%d", &numeroBuscado);

    nivelEncontrado = buscarNivel(arbol, numeroBuscado, 0);

    if(nivelEncontrado == -1)
        printf("El numero no se encuentra en el arbol.\n");
    else
        printf("El numero %d se encuentra en el nivel %d.\n", numeroBuscado, nivelEncontrado);

    return 0;
}

void insertar(treenode **hoja, int elem) {
    if(*hoja == NULL) {
        (*hoja) = (treenode*) malloc(sizeof(treenode));
        (*hoja)->dato = elem;
        (*hoja)->izq = NULL;
        (*hoja)->der = NULL;
    }
    else {
        if(elem > (*hoja)->dato)
            insertar(&(*hoja)->der, elem);
        else
            insertar(&(*hoja)->izq, elem);
    }
}

void mostrar(treenode *hoja) {
    if(hoja != NULL) {
        mostrar(hoja->izq);
        printf("%d ", hoja->dato);
        mostrar(hoja->der);
    }
}

void sumarMultiplos9(treenode *hoja, int *suma) {
    if(hoja != NULL) {
        sumarMultiplos9(hoja->izq, suma);

        if(hoja->dato % 9 == 0 && ((hoja->izq != NULL && hoja->der == NULL) || (hoja->izq == NULL && hoja->der != NULL)))
            *suma += hoja->dato;

        sumarMultiplos9(hoja->der, suma);
    }
}

void buscarMaximo(treenode *hoja, int raiz, int *maximo) {
    if(hoja != NULL) {
        buscarMaximo(hoja->izq, raiz, maximo);

        if(hoja->dato % raiz != 0 && hoja->dato > *maximo)
            *maximo = hoja->dato;

        buscarMaximo(hoja->der, raiz, maximo);
    }
}


int buscarNivel(treenode *hoja, int numeroBuscado, int nivel) {
    int resultado = -1;

    if(hoja != NULL) {
        if(hoja->dato == numeroBuscado)
            resultado = nivel;
        else {
            if(numeroBuscado < hoja->dato)
                resultado = buscarNivel(hoja->izq, numeroBuscado, nivel + 1);
            else
                resultado = buscarNivel(hoja->der, numeroBuscado, nivel + 1);
        }
    }

    return resultado;
}