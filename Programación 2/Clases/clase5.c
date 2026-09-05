/*
Vamos a cargar y a mostrar un vector con punteros.
Cargarlo y mostralo con aritmetica de punteros.
*/

#include <stdio.h>

void cargarVector(int *vector, int cantidad);
void mostrarVector(int *vector, int cantidad);

int main() {
    int vector[5];

    printf("\nCARGANDO VECTOR...\n");
    cargarVector(vector, 5);

    printf("\nMOSTRANDO VECTOR...\n");
    mostrarVector(vector, 5);

    return 0;
}

void cargarVector(int *vector, int cantidad) {
    for(int i = 0; i < cantidad; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", vector + i);
    }
}

void mostrarVector(int *vector, int cantidad) {
    for(int i = 0; i < cantidad; i++)
        printf("Elemento [%d]: %d\n", i+1, *(vector + i));
}