/*
Cargar y mostrar una lista con nombre y edad de los alumnos de UP hasta que el nombre sea FIN.
Calcular y mostrar:

a) El promedio de edad.
b) Generar una nueva lista con aquellos alumnos cuya edad esta entre 40 y 50 años.
c) Generar otra lista con los nombres solamente de aquellos alumnos cuya edad es menor a 30.
d) Cantidad de alumnos cuya edad esta entre 20 y 35 años (sobre la lista original).
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Alumno {
    char nombre[30];
    int edad;
    struct Alumno *siguiente;
} Alumno;

typedef struct AlumnoNombre {
    char nombre[30];
    struct AlumnoNombre *siguiente;
} AlumnoNombre;

void cargarAlumno(Alumno *lista);
void mostrarLista(Alumno *lista);
void promedioEdadLista(Alumno *lista);
Alumno *generarListaDeAlumnosDeterminadaEdad(Alumno *listaAlumnosEntre40y50, Alumno *lista, int limiteInferior, int limiteSuperior);
int cantAlumnosEntre20y35(Alumno *lista);
AlumnoNombre *generarListaMenoresDe30(AlumnoNombre *listaMenoresDe30, Alumno *lista);
void mostrarListaNombres(AlumnoNombre *lista);

int main() {
    Alumno *lista = NULL, *listaAlumnosEntre40y50 = NULL;
    int contEdadesEntre20y35;
    AlumnoNombre *listaMenoresDe30 = NULL;

    lista = (Alumno *) malloc(sizeof(Alumno));
    listaAlumnosEntre40y50 = (Alumno *) malloc(sizeof(Alumno));
    listaMenoresDe30 = (AlumnoNombre *) malloc(sizeof(AlumnoNombre));

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    cargarAlumno(lista);

    if(lista != NULL) {
        printf("\n\n--- MOSTRANDO ELEMENTOS DE LA LISTA ---\n");
        mostrarLista(lista);
        promedioEdadLista(lista);

        printf("\n\n--- GENERANDO LISTA DE ALUMNOS ENTRE 40 Y 50 ANIOS ---\n");
        listaAlumnosEntre40y50 = generarListaDeAlumnosDeterminadaEdad(listaAlumnosEntre40y50, lista, 40, 50);
        mostrarLista(listaAlumnosEntre40y50);

        printf("\n\n--- GENERANDO LISTA DE ALUMNOS MENORES DE 30 ANIOS ---\n");
        listaMenoresDe30 = generarListaMenoresDe30(listaMenoresDe30, lista);
        mostrarListaNombres(listaMenoresDe30);

        printf("\n\n--- CALCULANDO LA CANTIDAD DE ALUMNOS DE EDAD ENTRE 20 Y 35 ---\n");
        contEdadesEntre20y35 = cantAlumnosEntre20y35(lista);
        printf("La cantidad de alumnos entre 20 y 35 anios es: %d\n\n", contEdadesEntre20y35);
    }
    else
        printf("No hay datos sobre los cuales operar.");
    
    return 0;
}

void cargarAlumno(Alumno *lista) {
    char nombre[30];

    printf("Ingrese el nombre del alumno: ");
    scanf("%s", nombre);

    while(strcmp(nombre, "FIN") != 0 && strcmp(nombre, "fin") != 0) {
        strcpy(lista->nombre, nombre);

        printf("Ingrese la edad del alumno: ");
        scanf("%d", &lista->edad);

        printf("Ingrese el nombre del alumno: ");
        scanf("%s", nombre);

        if(strcmp(nombre, "FIN") != 0 && strcmp(nombre, "fin") != 0) {
            lista->siguiente = (Alumno *) malloc(sizeof(Alumno));
            lista = lista->siguiente;
        }
    }

    lista->siguiente = NULL;
}

void mostrarLista(Alumno *lista) {
    int contador = 1;

    while(lista != NULL) {
        printf("\n-- Alumno [%d] --\n", contador);
        printf("Nombre: %s\n", lista->nombre);
        printf("Edad: %d\n", lista->edad);

        lista = lista->siguiente;
        contador += 1;
    }
}

void promedioEdadLista(Alumno *lista) {
    int contador = 0, acumulador = 0;
    float promedio = 0;

    while(lista != NULL) {
        contador += 1;
        acumulador += lista->edad;
        lista = lista->siguiente;
    }

    promedio = (float) acumulador / contador;
    printf("\nEl promedio de edad de los alumnos de la lista es: %.2f", promedio);    
}

Alumno *generarListaDeAlumnosDeterminadaEdad(Alumno *listaAlumnosEntre40y50, Alumno *lista, int limiteInferior, int limiteSuperior) {
    Alumno *aux = listaAlumnosEntre40y50;

    // Busco el primer alumno que cumpla la condición
    while(lista != NULL && (lista->edad < limiteInferior || lista->edad > limiteSuperior))
        lista = lista->siguiente;

    // Si llegué al final, no había ningún alumno que cumpliera
    if(lista == NULL) {
        free(listaAlumnosEntre40y50);
        return NULL;
    }

    // Cargo el primer nodo de la nueva lista
    strcpy(aux->nombre, lista->nombre);
    aux->edad = lista->edad;
    aux->siguiente = NULL;

    lista = lista->siguiente;

    // Busco los siguientes alumnos que cumplan
    while(lista != NULL) {
        if(lista->edad >= limiteInferior && lista->edad <= limiteSuperior) {
            aux->siguiente = (Alumno *) malloc(sizeof(Alumno));
           
            aux = aux->siguiente;

            strcpy(aux->nombre, lista->nombre);
            aux->edad = lista->edad;
            aux->siguiente = NULL;
        }

        lista = lista->siguiente;
    }

    return listaAlumnosEntre40y50;
}

int cantAlumnosEntre20y35(Alumno *lista) {
    Alumno *actual = lista;
    int contador = 0;

    while(actual != NULL) {
        if(actual->edad >= 20 && actual->edad <= 35)
            contador += 1;
        
        actual = actual->siguiente;
    }

    return contador;
}

AlumnoNombre *generarListaMenoresDe30(AlumnoNombre *listaMenoresDe30, Alumno *lista) {
    AlumnoNombre *aux = listaMenoresDe30;

    // Busco el primer alumno menor de 30
    while(lista != NULL && lista->edad >= 30)
        lista = lista->siguiente;

    // Si no encontré ninguno
    if(lista == NULL) {
        free(listaMenoresDe30);
        return NULL;
    }

    // Cargo el primer nombre
    strcpy(aux->nombre, lista->nombre);

    lista = lista->siguiente;

    // Busco los demás
    while(lista != NULL) {
        if(lista->edad < 30) {
            aux->siguiente = (AlumnoNombre *) malloc(sizeof(AlumnoNombre));
            aux = aux->siguiente;

            strcpy(aux->nombre, lista->nombre);
        }

        lista = lista->siguiente;
    }

    aux->siguiente = NULL;

    return listaMenoresDe30;
}

void mostrarListaNombres(AlumnoNombre *lista) {
    int contador = 1;

    while(lista != NULL) {
            printf("\n-- Alumno [%d] --\n", contador);
            printf("Nombre: %s\n", lista->nombre);

            lista = lista->siguiente;
            contador += 1;
        }
}