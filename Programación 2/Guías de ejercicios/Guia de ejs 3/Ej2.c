/*
2. Cargar una matriz de n*n de números enteros y mostrar:
a) la matriz transpuesta
b) El promedio de los elementos de las dos diagonales (principal y secundaria)
c) Multiplicar la matriz por su transpuesta.
d) Determinar cuántos números primos hay en la matriz.
*/

#include <stdio.h>

void cargarMatriz(int n, int matriz[][n]);
void mostrarMatriz(int n, int matriz[][n]);
void matrizTraspuesta(int n, int matriz[][n], int traspuesta[][n]);
int extraerElementosDiagonalPrincipal(int n, int matriz[][n], int []);
void extraerElementosDiagonalSecundaria(int n, int matriz[][n], int []);
void promedioElementosDiagonalesDeLaMatriz(int, int [], int []);
void multiplicarMatrices(int n, int matriz[][n], int traspuesta[][n], int resultado[][n]);
int cantidadDivisores(int);
void cantidadNumerosPrimosEnMatriz(int n, int matriz[][n]);

int main() {
    int n, elementosDiagonalPrincipal[20], elementosDiagonalSecundaria[20];
    
    do {
        printf("Seleccione la cantidad de filas y columnas que tendra la matriz: ");
        scanf("%d", &n);
    } while(n < 2); 

    int matriz[n][n], traspuesta[n][n], resultado[n][n];

    printf("\n\nCARGANDO LA MATRIZ...\n");
    cargarMatriz(n, matriz);

    printf("\n\nMOSTRANDO LA MATRIZ...\n");
    mostrarMatriz(n, matriz);

    printf("\n\nREALIZANDO LA TRASPUESTA DE LA MATRIZ...\n");
    matrizTraspuesta(n, matriz, traspuesta);
    mostrarMatriz(n, traspuesta);

    printf("\n\nCALCULANDO EL PROMEDIO DE AMBAS DIAGONALES DE LA MATRIZ...\n");
    int contador = extraerElementosDiagonalPrincipal(n, matriz, elementosDiagonalPrincipal);
    extraerElementosDiagonalSecundaria(n, matriz, elementosDiagonalSecundaria);
    promedioElementosDiagonalesDeLaMatriz(contador, elementosDiagonalPrincipal, elementosDiagonalSecundaria);

    printf("\n\nMULTIPLICANDO MATRICES...\n");
    multiplicarMatrices(n, matriz, traspuesta, resultado);
    mostrarMatriz(n, resultado);

    printf("\n\nCALCULANDO LA TOTALIDAD DE NUMEROS PRIMOS DE LA MATRIZ...\n");
    cantidadNumerosPrimosEnMatriz(n, matriz);
    
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

void matrizTraspuesta(int n, int matriz[][n], int traspuesta[][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            traspuesta[j][i] = matriz[i][j];
    }
}

// FORMA ALTERNATIVA: CARGAR LA TRASPUESTA EN LA MISMA MATRIZ.
/*void matrizTraspuesta(int n, int matriz[][n]) {
    int aux;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j > i) {
                aux = matriz[i][j];
                matriz[i][j] = matriz[j][i];
                matriz[j][i] = aux;
            }
        }
    }
}*/

int extraerElementosDiagonalPrincipal(int n, int matriz[][n], int elementosDiagonalPrincipal[]) {
    int contador = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                elementosDiagonalPrincipal[contador] = matriz[i][j];
                contador += 1;
            }
        }
    }

    return contador;
}

void extraerElementosDiagonalSecundaria(int n, int matriz[][n], int elementosDiagonalSecundaria[]) {
    int contador = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i + j == n - 1) {
                elementosDiagonalSecundaria[contador] = matriz[i][j];
                contador += 1;
            }
        }
    }
}

void promedioElementosDiagonalesDeLaMatriz(int contador, int elementosDiagonalPrincipal[], int elementosDiagonalSecundaria[]) {
    int acumulador = 0;
    
    for(int i = 0; i < contador; i++) 
        acumulador += elementosDiagonalPrincipal[i] + elementosDiagonalSecundaria[i];

    float promedio = (float) acumulador / (contador * 2);
    printf("\nEl promedio de los elementos de ambas diagonales es: %.2f.", promedio);
}

void multiplicarMatrices(int n, int matriz[][n], int traspuesta[][n], int resultado[][n]) {

    for(int i = 0; i < n; i++) { // filas del resultado
        for(int j = 0; j < n; j++) { // columnas del resultado
            resultado[i][j] = 0;

            for(int k = 0; k < n; k++) // multiplicar y acumular
                resultado[i][j] += matriz[i][k] * traspuesta[k][j];
        }
    }
}

int cantidadDivisores(int numero) {
    int cant = 0;
    
    for(int i = 1; i <= numero; i++) {
        if(numero % i == 0)
            cant += 1;
    }

    return cant;
}

void cantidadNumerosPrimosEnMatriz(int n, int matriz[][n]) {
    int cantTotalDeNumerosPrimos = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int cantidadDeDivisores = cantidadDivisores(matriz[i][j]);

            if(cantidadDeDivisores == 2) {
                printf("\nNumero primo en [%d][%d]: %d", i, j, matriz[i][j]);
                cantTotalDeNumerosPrimos += 1;
            }
        }
    }

    printf("\nLa cantidad total de numeros primos en la matriz es: %d", cantTotalDeNumerosPrimos);
}