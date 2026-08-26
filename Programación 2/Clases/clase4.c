//FUNCIONES RECURSIVAS

#include <stdio.h>

int factorial(int);
void calcularBinario(int);
int sumaNumeroDeTresCifras(int);
void cargarMatriz(int n, int matriz[][n], int fila, int columna);

int main() {
    int numero, resultadoFactorial, resultadoSuma, n;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if(numero < 0)
        printf("No se puede calcular las operaciones de un numero negativo.\n");
    else {
        if(numero < 10) {
            resultadoFactorial = factorial(numero);
            printf("El factorial de %d es %d\n", numero, resultadoFactorial);
        }

        printf("\nEl numero en binario es: ");
        calcularBinario(numero);

        if(numero >= 100) {
            resultadoSuma = sumaNumeroDeTresCifras(numero);
            printf("\nLa suma de las cifras del numero es: %d", resultadoSuma);
        }
    }

    printf("Ingrese la cantidad de filas y columnas de la matriz: ");
    scanf("%d", &n);

    int matriz[n][n];

    cargarMatriz(n, matriz, 0, 0);

    return 0;
}

// Funcion recursiva
int factorial(int numero) {
    // Caso base
    if(numero == 0)
        return 1;

    // Caso recursivo
    return numero * factorial(numero - 1);
}

void calcularBinario(int numero) {    
    if(numero < 2)
        printf("%d", 1);
    else { 
        calcularBinario((numero/2));
        printf("%d", numero % 2);
    }
}

int sumaNumeroDeTresCifras(int numero) {
    if(numero < 10)
        return numero;
    else
        return (numero % 10) + sumaNumeroDeTresCifras(numero/10);
}

void cargarMatriz(int n, int matriz[][n], int fila, int columna) {
    if(fila == n)
        return;

    printf("Ingrese matriz[%d][%d]: ", fila, columna);
    scanf("%d", &matriz[fila][columna]);

    if(columna == n - 1)
        cargarMatriz(n, matriz, fila + 1, 0);
    else
        cargarMatriz(n, matriz, fila, columna + 1);
}

int sumatoriaDiagonalPrincipal(int n, int matriz[][n]) {

}