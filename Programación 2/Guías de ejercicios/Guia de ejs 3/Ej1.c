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
void promedioMultiplosDe5(int n, int matriz[][n]);
void minimoElementoDeCadaFila(int n, int matriz[][n]);
void mostrarDiagonalSecundaria(int n, int matriz[][n]);
void verificarMatrizSimetrica(int n, int matriz[][n]);
void sumatoriaDiagonalPrincipal(int n, int matriz[][n]);
void mostrarElementosDebajoDiagonalPrincipal(int n, int matriz[][n]);

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

    printf("\n\nCALCULANDO LA SUMATORIA DE LA DIAGONAL PRINCIPAL...\n");
    sumatoriaDiagonalPrincipal(n, matriz);

    printf("\n\nCALCULANDO EL MAYOR ELEMENTO DE LA SEGUNDA COLUMNA DE LA MATRIZ...\n");
    mayorElementoSegundaColumna(n, matriz);
    
    printf("\n\nCALCULANDO EL PROMEDIO DE LOS MULTIPLOS DE 5 DE LA MATRIZ...\n");
    promedioMultiplosDe5(n, matriz);

    printf("\n\nCALCULANDO EL MENOR ELEMENTO DE CADA FILA DE LA MATRIZ...\n");
    minimoElementoDeCadaFila(n, matriz);

    printf("\n\nMOSTRANDO DIAGONAL SECUNDARIA...\n");
    mostrarDiagonalSecundaria(n, matriz);

    printf("\n\nMOSTRANDO ELEMENTOS DEBAJO DE LA DIAGONAL PRINCIPAL...\n");
    mostrarElementosDebajoDiagonalPrincipal(n, matriz);

    printf("\n\nVERIFICANDO SI LA MATRIZ ES SIMETRICA...\n");
    verificarMatrizSimetrica(n, matriz);

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
        if(matriz[i][1] > mayor) {
            mayor = matriz[i][1];
            posMayor = i;
        }
    }

    printf("El mayor elemento de la segunda columna es [%d], en la fila [%d]", mayor, posMayor);
}

void promedioMultiplosDe5(int n, int matriz[][n]) {
    int sumatoriaMultiplosDe5 = 0, cantMultiplosDe5 = 0;
    float promedio = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matriz[i][j] % 5 == 0) {
                printf("El elemento [%d][%d], %d, es multiplo de 5.\n", i, j, matriz[i][j]);
                
                sumatoriaMultiplosDe5 += matriz[i][j];
                cantMultiplosDe5 += 1;
            }
        }
    }
    
    if(cantMultiplosDe5 != 0) {
        promedio = (float) sumatoriaMultiplosDe5 / cantMultiplosDe5;
        printf("\nEl promedio de los multiplos de 5 de la matriz es: %.2f", promedio);
    }
    else {
        printf("\nNo se ingresaron multiplos de 5.");
    }
}

void sumatoriaDiagonalPrincipal(int n, int matriz[][n]) {
    int sumatoriaElementosDiagonalPrincipal = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                sumatoriaElementosDiagonalPrincipal += matriz[i][j];
            }
        }
    }

    printf("La sumatoria de los elementos de la diagonal principal es: %d", sumatoriaElementosDiagonalPrincipal);
}

void minimoElementoDeCadaFila(int n, int matriz[][n]) {

    for(int i = 0; i < n; i++) {
        int elementoMinimo = matriz[i][0];

        for(int j = 1; j < n; j++) {
            if(matriz[i][j] < elementoMinimo)
                elementoMinimo = matriz[i][j];
        }

        printf("\nEl menor elemento de la fila [%d] es: %d", i, elementoMinimo);
    }
}

void mostrarDiagonalSecundaria(int n, int matriz[][n]) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(i + j == n - 1) {
                printf("Elemento [%d][%d]: %d\n", i, j, matriz[i][j]);
            }
        }
    }
}

void verificarMatrizSimetrica(int n, int matriz[][n]) {
    int diferencias = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(matriz[i][j] != matriz[j][i]) {
                diferencias++;
            }
        }
    }

    if(diferencias == 0)
        printf("La matriz es simetrica.");
    else
        printf("La matriz no es simetrica.");
}

void mostrarElementosDebajoDiagonalPrincipal(int n, int matriz[][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i > j) 
                printf("Elemento [%d][%d]: %d\n", i, j, matriz[i][j]);
        }
    }
}