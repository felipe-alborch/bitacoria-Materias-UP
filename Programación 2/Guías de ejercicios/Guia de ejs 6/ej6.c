/*
Escribir un programa efectúe las siguientes operaciones:
a) Declarar una matriz de 3x4 de tipo int. Cargar sus elementos y mostrarla.
b) Declarar un puntero a entero.
c) Asignar al puntero la dirección de la matriz.
d) Recorrer con el puntero la matriz, mostrando la dirección y el contenido de cada
posición.
*/

#include <stdio.h>

void cargarMatriz(int matriz[3][4]);
void mostrarMatriz(int matriz[3][4]);
void cargarMatrizConPunteros(int *puntero);
void mostrarMatrizConPuntero(int *puntero);

int main() {
    int matriz[3][4], *puntero;

    puntero = &matriz[0][0]; // Esto va a apuntar la variable puntero al primer elemento de la matriz

    printf("CARGANDO LA MATRIZ...\n\n");
    cargarMatrizConPunteros(puntero);
    //cargarMatriz(matriz);

    printf("\n\nMOSTRANDO LA MATRIZ...\n\n");
    mostrarMatriz(matriz);

    //printf("\nMOSTRANDO CON PUNTEROS...\n\n");
    //mostrarMatrizConPuntero(puntero);
    
    return 0;
}

void cargarMatriz(int matriz[3][4]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            printf("Ingrese el elemento [%d][%d] de la matriz: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }
}

void mostrarMatriz(int matriz[3][4]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            printf("Elemento [%d][%d]: %d\n", i, j, matriz[i][j]);    
        }
        printf("\n");
    }
}

void cargarMatrizConPunteros(int *puntero) {
    for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 4; j++) {
                printf("Ingrese el elemento [%d][%d]: ", i, j);
                scanf("%d", puntero + i * 4 + j);
            }
            printf("\n");
        }
}

void mostrarMatrizConPuntero(int *puntero) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            // COMENTARIO 1: para mostrar DIRECCIONES de memoria, tenemos que usar el %p. Además, debemos castear a void *
            // COMENTARIO 2: para acceder a un elemento de la matriz, podemos usar la siguiente "fórmula": puntero + (fila * cantColumnas) + columna
            printf("Elemento [%d][%d] - DIRECCION: %p\n", i, j, (void *)(puntero + i * 4 + j));
            printf("Elemento [%d][%d] - CONTENIDO: %d\n", i, j, *(puntero + i * 4 + j));
        }
        printf("\n");
    }
}