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

Alumno *insertarNodo(Alumno *lista, char nombre[30], int edad);
Alumno *cargarAlumno(Alumno *lista);
void mostrarLista(Alumno *lista);
Alumno *generarListaDeAlumnosDeterminadaEdad(Alumno *listaAlumnosEntre40y50, Alumno *lista, int limiteInferior, int limiteSuperior);
void promedioEdadLista(Alumno *lista);
int cantAlumnosEntre20y35(Alumno *lista);
AlumnoNombre *insertarNombre(AlumnoNombre *lista, char nombre[30]);
AlumnoNombre *generarListaMenoresDe30(AlumnoNombre *listaMenoresDe30, Alumno *lista);
void mostrarListaNombres(AlumnoNombre *lista);

int main() {
    Alumno *lista = NULL, *listaAlumnosEntre40y50 = NULL;
    int contEdadesEntre20y35;
    AlumnoNombre *listaMenoresDe30 = NULL;

    lista = (Alumno *) sizeof(Alumno);
    listaAlumnosEntre40y50 = (Alumno *) sizeof(Alumno);
    listaMenoresDe30 = (AlumnoNombre *) sizeof(AlumnoNombre);

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    lista = cargarAlumno(lista);

    if(lista != NULL) {
        printf("\n\n--- MOSTRANDO ELEMENTOS DE LA LISTA ---\n\n");
        mostrarLista(lista);

        printf("\n\n--- GENERANDO LISTA DE ALUMNOS ENTRE 40 Y 50 ANIOS ---\n\n");
        listaAlumnosEntre40y50 = generarListaDeAlumnosDeterminadaEdad(listaAlumnosEntre40y50, lista, 40, 50);
        mostrarLista(listaAlumnosEntre40y50);

        printf("\n\n--- GENERANDO LISTA DE ALUMNOS MENORES DE 30 ANIOS ---\n\n");
        listaMenoresDe30 = generarListaMenoresDe30(listaMenoresDe30, lista);
        mostrarListaNombres(listaMenoresDe30);

        printf("\n\n--- CALCULANDO LA CANTIDAD DE ALUMNOS DE EDAD ENTRE 20 Y 35 ---\n\n");
        contEdadesEntre20y35 = cantAlumnosEntre20y35(lista);
        printf("La cantidad de alumnos entre 20 y 35 anios es: %d\n", contEdadesEntre20y35);
    }
    else
        printf("No hay datos sobre los cuales operar.");
    
    return 0;
}

Alumno *cargarAlumno(Alumno *lista) {
    char nombre[30];
    int edad;

    printf("Ingrese el nombre del alumno: ");
    scanf("%s", nombre);

    while(strcmp(nombre, "FIN") != 0 && strcmp(nombre, "fin") != 0) {
        printf("Ingrese la edad del alumno: ");
        scanf("%d", &edad);

        lista = insertarNodo(lista, nombre, edad);

        printf("Ingrese el nombre del alumno: ");
        scanf("%s", nombre);
    }

    return lista;
}

Alumno *insertarNodo(Alumno *lista, char nombre[30], int edad) {
    Alumno *nuevo = (Alumno *) malloc(sizeof(Alumno));

    if (nuevo == NULL) {
        printf("No se pudo reservar memoria.\n");
        return lista;
    }

    nuevo->edad = edad;
    strcpy(nuevo->nombre, nombre);
    nuevo->siguiente = NULL;

    if (lista == NULL)
        return nuevo;

    Alumno *actual = lista;

    while (actual->siguiente != NULL)
        actual = actual->siguiente;

    actual->siguiente = nuevo;

    return lista;
}

void mostrarLista(Alumno *lista) {
    Alumno *actual = lista;
    int contador = 0;

    while(actual != NULL) {
        printf("Nombre del alumno [%d]: %s\n", contador, actual->nombre);
        printf("Edad del alumno [%d]: %d\n\n", contador, actual->edad);

        contador += 1;
        actual = actual->siguiente;
    }
}

void promedioEdadLista(Alumno *lista) {
    Alumno *actual = lista;
    int contador = 0, acumulador = 0;
    float promedio = 0;

    while(actual != NULL) {
        contador += 1;
        acumulador += actual->edad;
        actual = actual->siguiente;
    }

    promedio = (float) acumulador / contador;
    printf("El promedio de edad de los alumnos de la lista es: %.2f", promedio);    
}

Alumno *generarListaDeAlumnosDeterminadaEdad(Alumno *listaAlumnosEntre40y50, Alumno *lista, int limiteInferior, int limiteSuperior) {
    Alumno *actual = lista;

    while(actual != NULL) {
        if(actual->edad <= limiteSuperior && actual->edad >= limiteInferior)
            listaAlumnosEntre40y50 = insertarNodo(listaAlumnosEntre40y50, actual->nombre, actual->edad);

        actual = actual->siguiente;
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
    Alumno *actual = lista;

    while (actual != NULL) {
        if (actual->edad < 30)
            listaMenoresDe30 = insertarNombre(listaMenoresDe30, actual->nombre);

        actual = actual->siguiente;
    }

    return listaMenoresDe30;
}

AlumnoNombre *insertarNombre(AlumnoNombre *lista, char nombre[30]) {
    AlumnoNombre *nuevo = malloc(sizeof(AlumnoNombre));

    if (nuevo == NULL) {
        printf("No se pudo reservar memoria.\n");
        return lista;
    }

    strcpy(nuevo->nombre, nombre);
    nuevo->siguiente = NULL;

    if (lista == NULL)
        return nuevo;

    AlumnoNombre *actual = lista;

    while (actual->siguiente != NULL)
        actual = actual->siguiente;

    actual->siguiente = nuevo;

    return lista;
}

void mostrarListaNombres(AlumnoNombre *lista) {
    AlumnoNombre *actual = lista;

    while (actual != NULL) {
        printf("Nombre: %s\n", actual->nombre);
        actual = actual->siguiente;
    }
}