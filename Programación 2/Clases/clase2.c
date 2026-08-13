/*
Dado un vector de N posiciones (la carga finaliza cuando se ingresa un numero impar menor al cuarto elemento ingresado) calcular:

 - si la cantidad de elementos cargados en el arreglo es par, sume todos los elementos en posicion impar
 - si la cantidad de elementos es impar, realice la productoria de todos los elementos dividosres de 9 
*/

#include <stdio.h>

int cargarDemasDatos(int numeros[10]);
void mostrarDatos(int numeros[10], int cantidadElementos);
void cargaInicial(int numeros[10]);
void inicializarVector(int numeros[10]);
void realizarOperacion(int numeros[10], int cantidadElementos);

int main() {
    int numeros[10], cantidadElementos = 0;

    inicializarVector(numeros);

    cargaInicial(numeros);
    cantidadElementos = cargarDemasDatos(numeros);

    realizarOperacion(numeros, cantidadElementos);

    printf("\n\n");
    mostrarDatos(numeros, cantidadElementos);

    return 0;
}

void realizarOperacion(int numeros[10], int cantidadElementos) {
    if(cantidadElementos % 2 == 0) {
        int sumatoria = 0;
        
        for(int i = 0; i < cantidadElementos; i++) {
            if(i % 2 != 0) {
                sumatoria += numeros[i];
            }
        }

        printf("\nLa sumatoria de los numeros en posiciones impares del arreglo es: %d", sumatoria);
    }
    else {
        int productoria = 0;
        
        for(int i = 0; i < cantidadElementos; i++) {
            if(9 % numeros[i] == 0) {
                productoria *= numeros[i];
            }
        }

        printf("\nLa productoria de los numeros divisores a 9 es: %d", productoria);
    }
}

void inicializarVector(int numeros[10]) {
    for(int i = 0; i < 10; i++) {
        numeros[i] = 0;
    }
}

void cargaInicial(int numeros[10]) {
    for(int i = 0; i < 4; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }
}

int cargarDemasDatos(int numeros[10]) {
    int i = 4;
    
    printf("Ingrese un numero: ");
    scanf("%d", &numeros[i]);

    while(numeros[i] % 2 == 0 || numeros[i] >= numeros[3]) {
        i += 1;
        
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }

    return i;
}

void mostrarDatos(int numeros[10], int cantidadElementos) {
    for(int i = 0; i < cantidadElementos; i++) {
        printf("Numero en la posicion [%d]: %d\n", i, numeros[i]);
    }
}