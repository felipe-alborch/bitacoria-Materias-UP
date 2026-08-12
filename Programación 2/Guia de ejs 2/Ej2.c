/*
Leer números enteros hasta cargar un arreglo de 10 elementos donde los primeros 5 son positivos y los restantes negativos.

a) Mostrar los primeros 4 elementos mayores del arreglo.
b) Generar otro arreglo intercalando el número positivo con los números negativos. Mostrarlo.
*/

#include <stdio.h>

void cargarNumeros(int []);
void ordenarArreglo(int []);
void mostrarPrimerosCuatroNumerosMayores(int []);

int main() {
    int numeros[10];

    printf("\n\nCARGANDO ARREGLO...\n");
    cargarNumeros(numeros);

    printf("\n\nORDENANDO ARREGLO...");
    ordenarArreglo(numeros);

    printf("\n\nMOSTRANDO LOS ELEMENTOS DEL ARREGLO...\n");
    mostrarPrimerosCuatroNumerosMayores(numeros);
    
    return 0;
}

void cargarNumeros(int numeros[]) {
    int numero, contador = 0;

    while (contador < 5) {
        printf("Ingresa un numero: ");
        scanf("%d", &numero);
        
        if(numero > 0) {
            numeros[contador] = numero;
            contador += 1;
        }
    }

    while (contador < 10) {
        printf("Ingresa un numero: ");
        scanf("%d", &numero);
        
        if(numero < 0) {
            numeros[contador] = numero;
            contador += 1;
        }
    }
}

void ordenarArreglo(int numeros[]) {
    int aux;
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 9; j++) {
            if(numeros[j] < numeros[j+1]) {
                aux = numeros[j+1];
                numeros[j+1] = numeros[j];
                numeros[j] = aux;
            }
        }
    }
}

void mostrarPrimerosCuatroNumerosMayores(int numeros[]) {
    for(int i = 0; i < 4; i++) {
        printf("Mostrando elemento [%d]: %d\n", i, numeros[i]);
    }
}