/*
Leer números enteros hasta cargar un arreglo de 10 elementos donde los primeros 5 son positivos y los restantes negativos.

a) Mostrar los primeros 4 elementos mayores del arreglo.
b) Generar otro arreglo intercalando el número positivo con los números negativos. Mostrarlo.
*/

#include <stdio.h>

void cargarNumeros(int []);
void ordenarArreglo(int []);
void mostrarPrimerosCuatroNumerosMayores(int []);
void intercalarArreglos(int [], int []);
void mostrarElementos(int [], int);

int main() {
    int numeros[10], numerosIntercalados[10];

    printf("\n\nCARGANDO ARREGLO...\n");
    cargarNumeros(numeros);

    printf("\n\nORDENANDO ARREGLO...");
    ordenarArreglo(numeros);

    printf("\n\nMOSTRANDO LOS PRIMEROS CUATRO ELEMENTOS DEL ARREGLO...\n");
    mostrarPrimerosCuatroNumerosMayores(numeros);

    printf("\n\nINTERCALANDO ELEMENTOS...");
    intercalarArreglos(numeros, numerosIntercalados);

    printf("\n\nMOSTRANDO LOS ELEMENTOS DEL NUEVO ARREGLO...\n");
    mostrarElementos(numerosIntercalados, 10);
    
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

void mostrarElementos(int arreglo[], int longitud) {
    for(int i = 0; i < longitud; i++)
        printf("Mostrando elemento [%d]: %d\n", i, arreglo[i]);
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

void intercalarArreglos(int numeros[], int numerosIntercalados[]) {
    int contadorPrimerArreglo = 0, contadorSegundoArreglo = 0;

    while(contadorPrimerArreglo < 10) {
        if(numeros[contadorPrimerArreglo] < 0) {
            numerosIntercalados[contadorSegundoArreglo] = numeros[contadorPrimerArreglo];
            contadorSegundoArreglo += 1;
        }

        contadorPrimerArreglo += 1;
    }

    contadorPrimerArreglo = 0;

    while(contadorPrimerArreglo < 5) {
        if(numeros[contadorPrimerArreglo] > 0) {
            numerosIntercalados[contadorSegundoArreglo] = numeros[contadorPrimerArreglo];
            contadorSegundoArreglo += 1;
        }

        contadorPrimerArreglo += 1;
    }
}