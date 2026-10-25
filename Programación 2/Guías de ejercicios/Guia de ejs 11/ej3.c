
#include <stdio.h>

#define FILAS 4
#define COLUMNAS 4

void cargarMatriz(int mat[FILAS][COLUMNAS]);
int esPrimo(int numero);
int contarPrimos(int mat[FILAS][COLUMNAS], int posicion, FILE *archivo);
void mostrarArchivo();
int cantDivisores(int numero);

int main() {
    int matriz[FILAS][COLUMNAS];
    int cantidadPrimos;
    FILE *archivo;

    cargarMatriz(matriz);

    archivo = fopen("primos.txt", "w");

    if(archivo == NULL)
        printf("Error al abrir el archivo.\n");
    else {
        cantidadPrimos = contarPrimos(matriz, 0, archivo);

        fclose(archivo);

        printf("\nCantidad de numeros primos: %d\n", cantidadPrimos);

        mostrarArchivo();
    }

    return 0;
}

void cargarMatriz(int mat[FILAS][COLUMNAS]) {
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            printf("Ingrese un numero [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

int cantDivisores(int numero) {
    int contadorDivisores = 0, acumulador = 0;

    while(acumulador < numero && contadorDivisores < 2) {
        if(numero % acumulador == 0)
            contadorDivisores += 1;
        
        acumulador += 1;
    }

    return contadorDivisores;
}

int esPrimo(int numero) {
    if(numero < 2)
        return 0;

    for(int i = 2; i <= numero / i; i++) {
        if(numero % i == 0)
            return 0;
    }

    return 1;
}

int contarPrimos(int mat[FILAS][COLUMNAS], int posicion, FILE *archivo) {
    int fila, columna;
    int cantidad = 0;

    if(posicion == FILAS * COLUMNAS)
        return 0;

    fila = posicion / COLUMNAS;
    columna = posicion % COLUMNAS;

    if(cantDivisores(mat[fila][columna]) == 2) {
        fprintf(archivo, "%d\n", mat[fila][columna]);
        cantidad = 1;
    }

    return cantidad + contarPrimos(mat, posicion + 1, archivo);
}

void mostrarArchivo() {
    FILE *archivo;
    int numero;

    archivo = fopen("primos.txt", "r");

    if(archivo == NULL)
        printf("Error al abrir el archivo.\n");
    else {
        printf("\n--- NUMEROS PRIMOS DEL ARCHIVO ---\n");

        fscanf(archivo, "%d", &numero);

        while(!feof(archivo)) {
            printf("%d\n", numero);
            fscanf(archivo, "%d", &numero);
        }

        fclose(archivo);
    }
}