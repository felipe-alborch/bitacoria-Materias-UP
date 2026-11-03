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
alumno *quitarAlumnosQueDejanCarrera(alumno *lista);
alumno *eliminarCabezalLista(alumno *lista);
void eliminarCuerpoLista(alumno *actual, alumno *anterior);
alumno *insertarNodoEspecial(alumno *lista);
alumno *insertarCabezal(alumno *lista);
void insertarCuerpo(alumno *actual, alumno *anterior);

int main() {
    int cantElementos, opcion;
    alumno *lista = NULL, *listaAlumnosIA = NULL;

    lista = (alumno *) malloc(sizeof(alumno));  
    listaAlumnosIA = (alumno *) malloc(sizeof(alumno));

    printf("\n--- CARGANDO ELEMENTOS DE LA LISTA---\n");
    cantElementos = cargarLista(lista);

    if(cantElementos > 0) {
        printf("\n\nSeleccione una opcion... \n");
        printf("\t- 1: MOSTRAR LISTA.\n");
        printf("\t- 2: GENERAR LISTA CON ALUMNOS QUE ESTUDIAN INTELIGENCIA ARTIFICIAL.\n");
        printf("\t- 3: ELIMINAR ALUMNO QUE DEJA CARRERA.\n");
        printf("\t- 4: INSERTAR NODO ESPECIAL.\n");
        printf("\t- 0: SALIR DEL MENU.\n");
        printf("Opcion: ");
        scanf("%d", &opcion); 

        while(opcion != 0) {
            switch(opcion) {
                case 1:
                    printf("\n\n--- MOSTRANDO LA LISTA ---\n");
                    mostrarLista(lista);
                    break;
                
                case 2:
                    printf("\n\n--- GENERANDO NUEVA LISTA DE ALUMNOS QUE ESTUDIAN INTELIGENCIA ARTIFICIAL ---\n");
                    listaAlumnosIA = generarListaEstudiantesIA(lista, listaAlumnosIA);
                    mostrarLista(listaAlumnosIA);
                    break;

                case 3:
                    printf("\n\n--- ELIMINANDO ALUMNO QUE DEJA LA CARRERA ---\n");
                    lista = quitarAlumnosQueDejanCarrera(lista);
                    mostrarLista(lista);
                    break;

                case 4:
                    printf("\n\n--- INSERTANDO NODO ESPECIAL ---\n");
                    lista = insertarNodoEspecial(lista);
                    mostrarLista(lista);
                    break;
                
                default:
                    printf("Opcion no reconocida.\n");
                    break;
            }

            printf("\n\nSeleccione una opcion... \n");
            printf("\t- 1: MOSTRAR LISTA.\n");
            printf("\t- 2: GENERAR LISTA CON ALUMNOS QUE ESTUDIAN INTELIGENCIA ARTIFICIAL.\n");
            printf("\t- 3: ELIMINAR ALUMNO QUE DEJA CARRERA.\n");
            printf("\t- 4: INSERTAR NODO ESPECIAL.\n");
            printf("\t- 0: SALIR DEL MENU.\n");
            printf("Opcion: ");
            scanf("%d", &opcion); 
        }
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

alumno *quitarAlumnosQueDejanCarrera(alumno *lista) {
    int legajoAEliminar;
    alumno *actual = NULL, *anterior = NULL;

    printf("Ingrese el legajo del alumno que abandono la carera: ");
    scanf("%d", &legajoAEliminar);

    if(lista->siguiente != NULL && lista->NumeroLegajo == legajoAEliminar) {
        lista = eliminarCabezalLista(lista);

        return lista;
    }

    anterior = lista;
    actual = lista->siguiente;

    while(actual->siguiente != NULL && actual->NumeroLegajo != legajoAEliminar) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if(actual->NumeroLegajo == legajoAEliminar)
        eliminarCuerpoLista(actual, anterior);
    else
        printf("No se encontro el alumno que desea eliminar.");

    return lista;
}

alumno *eliminarCabezalLista(alumno *lista) {
    alumno *aux = lista;

    lista = lista->siguiente;
    free(aux);

    return lista;
}

void eliminarCuerpoLista(alumno *actual, alumno *anterior) {
    anterior->siguiente = actual->siguiente;

    free(actual);
}

alumno *insertarNodoEspecial(alumno *lista) {
    int legajoABuscar;
    alumno *actual = NULL, *anterior = NULL;

    printf("Inserte el numero de legajo donde se requiera poner el nodo especial: ");
    scanf("%d", &legajoABuscar);

    if(lista->siguiente != NULL && lista->NumeroLegajo == legajoABuscar) {
        lista = insertarCabezal(lista);

        return lista;
    }

    anterior = lista;
    actual = lista->siguiente;

    while(actual->siguiente != NULL && actual->NumeroLegajo != legajoABuscar) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if(actual->NumeroLegajo == legajoABuscar)
        insertarCuerpo(actual, anterior);
    else
        printf("No se encontro el alumno.");

    return lista;
}

alumno *insertarCabezal(alumno *lista) {
    alumno *nuevo = NULL;

    nuevo = (alumno *) malloc(sizeof(alumno));
    
    nuevo->NumeroLegajo = 9999;
    strcpy(nuevo->nombre, "PEPE");
    nuevo->edad = 99;
    strcpy(nuevo->carrera, "Inteligencia");
    nuevo->anioQueEstaCursando = 0;
    nuevo->siguiente = lista;

    return nuevo;
}

void insertarCuerpo(alumno *actual, alumno *anterior) {
    alumno *nuevo = NULL;

    nuevo = (alumno *) malloc(sizeof(alumno));
    
    nuevo->NumeroLegajo = 9999;
    strcpy(nuevo->nombre, "PEPE");
    nuevo->edad = 99;
    strcpy(nuevo->carrera, "Inteligencia");
    nuevo->anioQueEstaCursando = 0;
    
    nuevo->siguiente = actual;
    anterior->siguiente = nuevo;
}