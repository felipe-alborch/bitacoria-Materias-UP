
#include <stdio.h>

void cargarVector(int vect[], int cantElementos);
void cargarArchivo(int vect[], int cantElementos);
void mostrarArchivo();
void mostrarTercerRegistro();

int main() {
    int vec[30];

    cargarVector(vec, 30);
    cargarArchivo(vec, 30);
    mostrarArchivo();
    mostrarTercerRegistro();

    return 0;
}

void cargarVector(int vect[], int cantElementos) {
    for(int i = 0; i < cantElementos; i++) {
        printf("Ingrese un valor: ");
        scanf("%d", &vect[i]);
    }
}

void cargarArchivo(int vect[], int cantElementos) {
    FILE *archivo;

    archivo = fopen("pares.txt", "w");

    if(archivo == NULL)
        printf("Error al abrir el archivo.\n");
    else {
        for(int i = 0; i < cantElementos; i++) {
            if(vect[i] % 2 == 0)
                fprintf(archivo, "%d\n", vect[i]);
        }

        fclose(archivo);
    }
}

void mostrarArchivo() {
    FILE *archivo;
    int numero;

    archivo = fopen("pares.txt", "r");

    if(archivo == NULL)
        printf("Error al abrir el archivo.\n");
    else {
        printf("\n--- NUMEROS PARES DEL ARCHIVO ---\n");

        fscanf(archivo, "%d", &numero);

        while(!feof(archivo)) {
            printf("%d\n", numero);
            fscanf(archivo, "%d", &numero);
        }

        fclose(archivo);
    }
}

void mostrarTercerRegistro() {
    FILE *archivo;
    int numero, contador = 0;

    archivo = fopen("pares.txt", "r");

    if(archivo == NULL)
        printf("Error al abrir el archivo.\n");
    else {
        fscanf(archivo, "%d", &numero);

        while(!feof(archivo)) {
            contador++;

            if(contador == 3) {
                printf("\nEl tercer registro es: %d\n", numero);
                break;
            }

            fscanf(archivo, "%d", &numero);
        }

        if(contador < 3)
            printf("\nEl archivo tiene menos de 3 registros.\n");

        fclose(archivo);
    }
}