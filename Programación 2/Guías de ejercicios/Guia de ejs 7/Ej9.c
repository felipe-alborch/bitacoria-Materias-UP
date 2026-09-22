/*
Ejercicio 1 — Empleados

Cargar y mostrar una lista con nombre, edad y sueldo de empleados de una empresa. La carga finaliza cuando el nombre ingresado sea "FIN". Calcular y mostrar:

a) El promedio de sueldo de todos los empleados.
b) Generar una nueva lista con los empleados cuya edad esté entre 30 y 45 años, conservando nombre, edad y sueldo.
c) Generar otra lista que contenga solamente los nombres de aquellos empleados cuyo sueldo sea mayor a $1.500.000.
d) Cantidad de empleados menores de 35 años.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Empleado {
    char nombre[20];
    int edad;
    float sueldo;
    struct Empleado *siguiente;
} Empleado;

typedef struct EmpleadoNombre {
    char nombre[20];
    struct EmpleadoNombre *siguiente;
} EmpleadoNombre;

void cargarLista(Empleado *lista);
void mostrarLista(Empleado *lista);
void mostrarListaNombres(EmpleadoNombre *lista);
void promedioSueldosEmpleados(Empleado *lista);
Empleado *generarListadoEmpleadosEntre30y45(Empleado *lista, Empleado *listaEmpleadosEntre30y45);
EmpleadoNombre *generarListaSueldoPaloyMedio(Empleado *lista, EmpleadoNombre *listaNombre);

int main() {
    Empleado *lista = NULL, *listaEmpleadosEntre30y45 = NULL;
    EmpleadoNombre *listaNombre = NULL;

    lista = (Empleado *) malloc(sizeof(Empleado));
    listaEmpleadosEntre30y45 = (Empleado *) malloc(sizeof(Empleado));
    listaNombre = (EmpleadoNombre *) malloc(sizeof(EmpleadoNombre));

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n");
    cargarLista(lista);

    printf("\n\n--- MOSTRANDO ELEMENTOS DE LA LISTA ---\n");
    mostrarLista(lista);

    printf("\n\n--- CALCULANDO EL PROMEDIO DE SUELDOS DE LOS EMPLEADOS ---\n");
    promedioSueldosEmpleados(lista);

    printf("\n\n--- GENERANDO LSITA DE EMPLEADOS ENTRE 30 Y 45 ANOS ---\n");
    listaEmpleadosEntre30y45 = generarListadoEmpleadosEntre30y45(lista, listaEmpleadosEntre30y45);
    mostrarLista(listaEmpleadosEntre30y45);

    printf("\n\n--- GENERANDO LSITA DE EMPLEADOS QUE GANANA MAS DE 1.500.000$ ---\n");
    listaNombre = generarListaSueldoPaloyMedio(lista, listaNombre);
    mostrarListaNombres(listaNombre);
    
    return 0;
}

void cargarLista(Empleado *lista) {    
    printf("Ingrese el nombre del empleado: ");
    scanf("%s", lista->nombre);

    while(strcmp(lista->nombre, "FIN") != 0 && strcmp(lista->nombre, "fin") != 0) {
        do {
            printf("Ingrese la edad del empleado: ");
            scanf("%d", &lista->edad);
        } while(lista->edad < 18);

        do {
            printf("Ingrese el sueldo del empleado: ");
            scanf("%f", &lista->sueldo);
        } while(lista->sueldo < 0);

        lista->siguiente = (Empleado *) malloc(sizeof(Empleado));
        lista = lista->siguiente;
        
        printf("\nIngrese el nombre del empleado: ");
        scanf("%s", lista->nombre);
    }

    lista->siguiente = NULL;
}

void mostrarLista(Empleado *lista) {
    int contador = 1;
    
    while(strcmp(lista->nombre, "FIN") != 0 && strcmp(lista->nombre, "fin") != 0) {
        printf("\n--- Empleado [%d] ---\n", contador);
        printf("Nombre: %s\n", lista->nombre);
        printf("Edad: %d\n", lista->edad);
        printf("Sueldo: %.2f\n", lista->sueldo);

        contador += 1;
        lista = lista->siguiente;
    }
}

void mostrarListaNombres(EmpleadoNombre *lista) {
    int contador = 1;
    
    while(strcmp(lista->nombre, "FIN") != 0 && strcmp(lista->nombre, "fin") != 0) {
        printf("\n--- Empleado [%d] ---\n", contador);
        printf("Nombre: %s\n", lista->nombre);

        contador += 1;
        lista = lista->siguiente;
    }
}

void promedioSueldosEmpleados(Empleado *lista) {
    int sumatoriaSueldos = 0, cantidadSueldos = 0;
    float promedio;

    while(strcmp(lista->nombre, "FIN") != 0 && strcmp(lista->nombre, "fin") != 0) {
        cantidadSueldos += 1;
        sumatoriaSueldos += lista->sueldo;

        lista = lista->siguiente;
    }

    promedio = (float) sumatoriaSueldos / cantidadSueldos;
    printf("El promedio de los sueldos de los empleados es: %.2f", promedio);
}

Empleado *generarListadoEmpleadosEntre30y45(Empleado *lista, Empleado *listaEmpleadosEntre30y45) {
    Empleado *aux = listaEmpleadosEntre30y45;

    while(strcmp(lista->nombre, "FIN") != 0 && strcmp(lista->nombre, "fin") != 0) {
        if(lista->edad >= 30 && lista->edad <= 45) {
            strcpy(aux->nombre, lista->nombre);
            aux->edad = lista->edad;
            aux->sueldo = lista->sueldo;

            aux->siguiente = (Empleado *) malloc(sizeof(Empleado));
            aux = aux->siguiente;
        }

        lista = lista->siguiente;
    }

    strcpy(aux->nombre, "FIN");
    aux->siguiente = NULL;

    return listaEmpleadosEntre30y45;
}

EmpleadoNombre *generarListaSueldoPaloyMedio(Empleado *lista, EmpleadoNombre *listaNombre) {
    EmpleadoNombre *aux = listaNombre;

    while(strcmp(lista->nombre, "FIN") != 0 && strcmp(lista->nombre, "fin") != 0) {
        if(lista->sueldo >= 1500000) {
            strcpy(aux->nombre, lista->nombre);

            aux->siguiente = (EmpleadoNombre *) malloc(sizeof(EmpleadoNombre));
            aux = aux->siguiente;
        }

        lista = lista->siguiente;
    }

    strcpy(aux->nombre, "FIN");
    aux->siguiente = NULL;

    return listaNombre;
}