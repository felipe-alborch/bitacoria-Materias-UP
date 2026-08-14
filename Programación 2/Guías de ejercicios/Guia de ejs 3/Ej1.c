/*
1. Cargar una matriz de n*n de números enteros. Mostrar:

a) la sumatoria de los elementos de la 2º fila.
b) el mayor elemento de la segunda columna.
c) el promedio de todos los múltiplos de 5 en la matriz.
d) la sumatoria de la diagonal principal de la matriz.
e) el elemento mínimo de cada fila.
f) los elementos de la diagonal secundaria.
g) los elementos que se encuentran debajo de la diagonal principal.
h) si la matriz es simétrica.
*/

#include <stdio.h>

void cargarMatriz(int n, int matriz[][n]);
void mostrarMatriz(int n, int matriz[][n]);
void sumatoriaElementosSegundaFila(int n, int matriz[][n]);
void mayorElementoSegundaColumna(int n, int matriz[][n]);

int main() {
    int n;
    
    do {
        printf("Seleccione la cantidad de filas y columnas que tendra la matriz: ");
        scanf("%d", &n);
    } while(n < 2); 

    int matriz[n][n];

    printf("\n\nCARGANDO LA MATRIZ...\n");
    cargarMatriz(n, matriz);

    printf("\n\nMOSTRANDO LA MATRIZ...\n");
    mostrarMatriz(n, matriz);

    printf("\n\nCALCULANDO SUMATORIA DE LA SEGUNDA FILA DE LA MATRIZ...\n");
    sumatoriaElementosSegundaFila(n, matriz);

    printf("\n\nCALCULANDO EL MAYOR ELEMENTO DE LA SEGUNDA COLUMNA DE LA MATRIZ...\n");
    mayorElementoSegundaColumna(n, matriz);
    
    return 0;
}

void cargarMatriz(int n, int matriz[][n]) {    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("Ingrese el valor del elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int n, int matriz[][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d", matriz[i][j]);
            printf(" ");
        }
        
        printf("\n");
    }
}

void sumatoriaElementosSegundaFila(int n, int matriz[][n]) {
    int sumatoria = 0;
    
    for(int j = 0; j < n; j++)
        sumatoria += matriz[1][j];

    printf("La sumatoria de los elementos de la segunda fila de la matriz es: %d", sumatoria);
}

void mayorElementoSegundaColumna(int n, int matriz[][n]) {
    int mayor = matriz[0][1], posMayor = 0;

    for(int i = 1; i < n; i++) {
        if(matriz[i][2] > mayor) {
            mayor = matriz[i][1];
            posMayor = i;
        }
    }

    printf("El mayor elemento de la segunda columna es [%d], en la fila [%d]", mayor, posMayor);
}