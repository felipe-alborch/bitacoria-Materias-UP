/*
Dado un array de números enteros ordenado de menor a mayor,
escribe una función en C que elimine todos los elementos duplicados de modo que cada elemento aparezca solo una vez.
La función debe modificar el array directamente mediante punteros y devolver la nueva longitud del array sin duplicados. 
Los elementos que queden más allá de la nueva longitud no importan.
*/

#include <stdio.h>

void cargarVectorOrdenado(int *vector, int cantidad);
int eliminarDuplicados(int *vector, int cantidad);
void mostrarVector(int *vector, int cantidad);

int main() {
    int vector[8];
    int cantidad = 8;

    cargarVectorOrdenado(vector, cantidad);

    cantidad = eliminarDuplicados(vector, cantidad);

    printf("\nVector sin duplicados:\n");
    mostrarVector(vector, cantidad);

    return 0;
}

void cargarVectorOrdenado(int *vector, int cantidad) {
    for(int i = 0; i < cantidad; i++) {
        do {
            printf("Ingrese el elemento %d: ", i + 1);
            scanf("%d", vector + i);

            if(i > 0 && *(vector + i) < *(vector + i - 1))
                printf("Error. Debe ingresar un numero mayor o igual al anterior.\n");

        } while(i > 0 && *(vector + i) < *(vector + i - 1));
    }
}

int eliminarDuplicados(int *vector, int cantidad) {
    if(cantidad == 0)
        return 0;

    int posicion = 1;

    for(int i = 1; i < cantidad; i++) {
        if(*(vector + i) != *(vector + posicion - 1)) {
            *(vector + posicion) = *(vector + i);
            posicion++;
        }
    }

    return posicion;
}

void mostrarVector(int *vector, int cantidad)
{
    for(int i = 0; i < cantidad; i++)
        printf("%d ", *(vector + i));
}