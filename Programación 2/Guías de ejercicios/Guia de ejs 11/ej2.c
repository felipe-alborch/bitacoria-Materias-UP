
#include <stdio.h>

#define MAX 10

void generarArchivo();
void generarVector(float vect[], int *cantElementos);
void mostrarMayorCantidad();

int main() {
    float vecPrecios[MAX];
    int cantElementos = 0;

    generarArchivo();
    generarVector(vecPrecios, &cantElementos);
    mostrarMayorCantidad();

    return 0;
}

void generarArchivo() {
    FILE *archivo;
    int codArticulo, cantArticulos, contador = 0;
    float precioUnitario;

    archivo = fopen("articulos.txt", "w");

    if(archivo == NULL)
        printf("No se pudo abrir el archivo.\n");
    else {
        printf("Ingrese el codigo del articulo (0 para terminar): ");
        scanf("%d", &codArticulo);

        while(codArticulo != 0 && contador < MAX) {
            printf("Ingrese la cantidad de articulos: ");
            scanf("%d", &cantArticulos);

            printf("Ingrese el precio unitario: ");
            scanf("%f", &precioUnitario);

            fprintf(archivo, "%d %d %.2f\n", codArticulo, cantArticulos, precioUnitario);

            contador++;

            if(contador < MAX) {
                printf("\nIngrese el codigo del articulo (0 para terminar): ");
                scanf("%d", &codArticulo);
            }
        }

        fclose(archivo);
    }
}

void generarVector(float vect[], int *cantElementos) {
    FILE *archivo;
    int codArticulo, cantArticulos;
    float precioUnitario;

    archivo = fopen("articulos.txt", "r");

    if(archivo == NULL)
        printf("No se pudo abrir el archivo.\n");
    else {
        fscanf(archivo, "%d %d %f", &codArticulo, &cantArticulos, &precioUnitario);

        while(!feof(archivo) && *cantElementos < MAX) {
            vect[*cantElementos] = cantArticulos * precioUnitario;
            (*cantElementos)++;

            fscanf(archivo, "%d %d %f", &codArticulo, &cantArticulos, &precioUnitario);
        }

        fclose(archivo);

        printf("\n--- PRECIOS TOTALES POR ARTICULO ---\n");

        for(int i = 0; i < *cantElementos; i++)
            printf("Articulo %d - Precio total: %.2f\n", i + 1, vect[i]);
    }
}

void mostrarMayorCantidad() {
    FILE *archivo;
    int codArticulo, cantArticulos, codMayor = 0, mayorCantidad = 0, hayArticulos = 0;
    float precioUnitario;

    archivo = fopen("articulos.txt", "r");

    if(archivo == NULL)
        printf("No se pudo abrir el archivo.\n");
    else {
        fscanf(archivo, "%d %d %f", &codArticulo, &cantArticulos, &precioUnitario);

        while(!feof(archivo)) {
            if(!hayArticulos || cantArticulos > mayorCantidad) {
                mayorCantidad = cantArticulos;
                codMayor = codArticulo;
            }

            hayArticulos = 1;

            fscanf(archivo, "%d %d %f", &codArticulo, &cantArticulos, &precioUnitario);
        }

        if(hayArticulos) {
            printf("\n--- ARTICULO CON MAYOR CANTIDAD ---\n");
            printf("Codigo: %d\n", codMayor);
            printf("Cantidad: %d\n", mayorCantidad);
        }
        else
            printf("\nEl archivo no contiene articulos.\n");

        fclose(archivo);
    }
}