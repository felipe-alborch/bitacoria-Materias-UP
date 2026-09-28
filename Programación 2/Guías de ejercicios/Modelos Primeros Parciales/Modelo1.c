#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct alumno {
    int NumeroLegajo;
    char nombre[20];
    int edad;
    char carrera[30];
    int anioQueEstaCursando;
    struct alumno *siguiente;
} alumno;

int cargarLista(alumno *lista);
void mostrarLista(alumno *lista);
alumno *generarListaEstudiantesIA(alumno *lista, alumno *listaAlumnosIA);
void porcentajeAlumnosEnSeguridad(alumno *lista);

int main() {
    int cantElementos;
    alumno *lista = NULL, *listaAlumnosIA = NULL;

    lista = (alumno *) malloc(sizeof(alumno));  
    listaAlumnosIA = (alumno *) malloc(sizeof(alumno));

    printf("\n--- CARGANDO ELEMENTOS DE LA LISTA---\n");
    cantElementos = cargarLista(lista);

    if(cantElementos > 0) {
        printf("\n\n--- MOSTRANDO LA LISTA ---\n");
        mostrarLista(lista);

        printf("\n\n--- GENERANDO NUEVA LISTA DE ALUMNOS QUE ESTUDIAN INTELIGENCIA ARTIFICIAL ---\n");
        listaAlumnosIA = generarListaEstudiantesIA(lista, listaAlumnosIA);
        mostrarLista(listaAlumnosIA);
    }
    else
        printf("\nNo se ingresaron elementos.\n\n");

    return 0;
}

int cargarLista(alumno *lista) {
    int cantElementos = 0;
    
    do {
        printf("Ingrese el numero de legajo: ");
        scanf("%d", &lista->NumeroLegajo);
    } while(lista->NumeroLegajo < 0);

    while(lista->NumeroLegajo != 0) {
        printf("Ingrese el nombre del alumno: ");
        scanf("%s", lista->nombre);

        do {
            printf("Ingrese la edad del alumno: ");
            scanf("%d", &lista->edad);
        } while(lista->edad < 17);

        printf("Ingrese el nombre de la carrera del alumno: ");
        scanf(" %[^\n]", lista->carrera);

        do {
            printf("Ingrese el anio que se encuentra cursando: ");
            scanf("%d", &lista->anioQueEstaCursando);
        } while(lista->anioQueEstaCursando < 1 || lista->anioQueEstaCursando > 5);

        lista->siguiente = (alumno *) malloc(sizeof(alumno));
        lista = lista->siguiente;
        cantElementos += 1;

        do {
            printf("\nIngrese el numero de legajo: ");
            scanf("%d", &lista->NumeroLegajo);
        } while(lista->NumeroLegajo < 0);;
    }

    lista->siguiente = NULL;

    return cantElementos;
}

void mostrarLista(alumno *lista) {
    int contador = 0;

    while(lista->siguiente != NULL) {
        printf("\n--- ALUMNO [%d] ---\n", contador);
        printf("Numero de legajo: %d\n", lista->NumeroLegajo);
        printf("Nombre: %s\n", lista->nombre);
        printf("Edad: %d\n", lista->edad);
        printf("Carrera que estudia: %s\n", lista->carrera);
        printf("Anio en curso: %d\n", lista->anioQueEstaCursando);

        contador += 1;
        lista = lista->siguiente;
    }
}

alumno *generarListaEstudiantesIA(alumno *lista, alumno *listaAlumnosIA) {
    alumno *aux = listaAlumnosIA;

    while(lista->siguiente != NULL) {
        if(strcmp(lista->carrera, "Inteligencia Artificial") == 0 && lista->anioQueEstaCursando > 2) {
            aux->NumeroLegajo = lista->NumeroLegajo;
            strcpy(aux->nombre, lista->nombre);
            aux->edad = lista->edad;
            strcpy(aux->carrera, lista->carrera);
            aux->anioQueEstaCursando = lista->anioQueEstaCursando;

            aux->siguiente = (alumno *) malloc(sizeof(alumno));
            aux = aux->siguiente;
        }
        
        lista = lista->siguiente;
    }

    aux->siguiente = NULL;

    return listaAlumnosIA;
}

void porcentajeAlumnosEnSeguridad(alumno *lista) {
    int totalAlumnos = 0, totalAlumnosSeguridad = 0;
    float promedio;

    while(lista->siguiente != NULL) {
        if(strcmp(lista->carrera, "Seguridad") == 0)
            totalAlumnosSeguridad += 1;
        
        totalAlumnos += 1;
        lista = lista->siguiente;
    }

    promedio = (float) totalAlumnos / totalAlumnosSeguridad;
    printf("El promedio de alumnos que elijen estudiar Seguridad es: %.2f.", promedio);
}