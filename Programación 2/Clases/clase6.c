/*
Ingresar nombres de alumnos junto a su legajo y nota.
Todo en formato de listas.
Calcular el promedio de las notas de los alumnos ingresados.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Nodo {
    char nombre[20];
    float nota;
    int legajo;
    struct Nodo *siguiente;
} Nodo;

Nodo *ingresarDatos(Nodo *lista);
float calcularPromedio(Nodo *lista);
void mostrarLista(Nodo *lista);
void liberarLista(Nodo *lista);

int main() {
    Nodo *lista = NULL;

    printf("\n--- REALIZANDO CARGA DE DATOS ---\n");
    lista = ingresarDatos(lista);

    printf("\n--- MOSTRANDO ALUMNOS INGRESADOS ---\n");
    mostrarLista(lista);

    if (lista != NULL) {
        float promedio = calcularPromedio(lista);
        printf("\nPromedio de notas: %.2f\n", promedio);
    } else {
        printf("\nNo se ingresaron alumnos.\n");
    }

    liberarLista(lista);

    return 0;
}

Nodo *ingresarDatos(Nodo *lista) {
    int legajo;

    printf("\nIngrese legajo (0 para finalizar): ");
    scanf("%d", &legajo);

    while (legajo != 0) {

        if (legajo < 0) {
            printf("El legajo debe ser positivo.\n");
        } else {
            // Se reserva memoria para un nuevo nodo
            Nodo *nuevo = malloc(sizeof(Nodo));

            if (nuevo == NULL) {
                printf("No se pudo reservar memoria.\n");
                return lista;
            }

            // Se cargan los datos del alumno
            nuevo->legajo = legajo;

            printf("Ingrese nombre: ");
            scanf("%19s", nuevo->nombre);

            do {
                printf("Ingrese nota (0 a 10): ");
                scanf("%f", &nuevo->nota);

                if (nuevo->nota < 0 || nuevo->nota > 10) {
                    printf("La nota debe estar entre 0 y 10.\n");
                }
            } while (nuevo->nota < 0 || nuevo->nota > 10);

            nuevo->siguiente = NULL;

            // Si la lista está vacía, el nuevo es el primero
            if (lista == NULL) {
                lista = nuevo;
            } else {
                // Se recorre hasta encontrar el último nodo
                Nodo *actual = lista;

                while (actual->siguiente != NULL)
                    actual = actual->siguiente;

                // Se enlaza el último nodo con el nuevo
                actual->siguiente = nuevo;
            }
        }

        // Vuelvo a consultar el legajo para ver si salgo del ciclo
        printf("\nIngrese legajo (0 para finalizar): ");
        scanf("%d", &legajo);
    }

    return lista;
}

float calcularPromedio(Nodo *lista) {
    float suma = 0;
    int cantidad = 0;
    Nodo *actual = lista;

    while (actual != NULL) {
        suma += actual->nota;
        cantidad++;

        actual = actual->siguiente;
    }

    if (cantidad == 0) {
        return 0;
    }

    return suma / cantidad;
}

void mostrarLista(Nodo *lista) {
    Nodo *actual = lista;

    while (actual != NULL) {
        printf("\nLegajo: %d", actual->legajo);
        printf("\nNombre: %s", actual->nombre);
        printf("\nNota: %.2f\n", actual->nota);

        actual = actual->siguiente;
    }
}

void liberarLista(Nodo *lista) {
    Nodo *actual = lista;

    while (actual != NULL) {
        Nodo *siguiente = actual->siguiente;

        free(actual);

        actual = siguiente;
    }
}