#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cliente {
    char nombre[20];
    int cantPersonasReserva;
    int fechaReserva;
    int horaReserva;
    char tipoDeMesa[10];
    struct cliente *siguiente;
} cliente;

int cargarLista(cliente *lista);
void mostrarLista(cliente *lista);
void mostrarReservasParaDeterminadoDia(cliente *lista);
void porcentajeMesasExterior(cliente *lista);
cliente *generarListaAdicional(cliente *lista, cliente *listaAdicional);
cliente *insertarNodoEspecial(cliente *lista);
cliente *insertarCabezal(cliente *lista);
void insertarEnResto(cliente *actual, cliente *anterior);
cliente *eliminarReserva(cliente *lista);
cliente *eliminarCabezal(cliente *lista);
void eliminarResto(cliente *actual, cliente *anterior);

int main() {
    int cantElementos = 0, opcion;
    cliente *lista = NULL, *listaAdicional = NULL;

    lista = (cliente *) malloc(sizeof(cliente));
    listaAdicional = (cliente *) malloc(sizeof(cliente));

    printf("\n--- CARGANDO ELEMENTOS DE LA LISTA---\n");
    cantElementos = cargarLista(lista);

    if(cantElementos > 0) {
        printf("\n\nSeleccione una opcion... \n");
        printf("\t- 1: MOSTRAR LISTA.\n");
        printf("\t- 2: MOSTRAR RESERVAS PARA DETERMINADO DIA.\n");
        printf("\t- 3: PORCENTAJES DE LAS RESERVAS EN LAS MESAS EXTERIORES.\n");
        printf("\t- 4: GENERAR LISTA ADICIONAL.\n");
        printf("\t- 5: INSERTAR NODOS ESPECIALES.\n");
        printf("\t- 6: CANCELAR RESERVA.\n");
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
                    printf("\n\n--- MOSTRANDO LA LISTA DE RESERVAS PARA DETERMINADO DIA ---\n");
                    mostrarReservasParaDeterminadoDia(lista);
                    break;    

                case 3:
                    printf("\n\n--- MOSTRANDO EL PORCENTAJE DE RESERVAS EN EL EXTERIOR ---\n");
                    porcentajeMesasExterior(lista);
                    break;
                
                case 4:
                    printf("\n\n--- GENERANDO NUEVA LISTA DE RESERVAS EN LA PRIMERA QUINCENA Y MESAS EN EL EXTERIOR ---\n");
                    listaAdicional = generarListaAdicional(lista, listaAdicional);
                    mostrarLista(listaAdicional);
                    break;
                
                case 5:
                    printf("\n\n--- INSERTANDO NODOS ESPECIALES ---\n");
                    lista = insertarNodoEspecial(lista);
                    mostrarLista(lista);
                    break;
                
                case 6:
                    printf("\n\n--- ELIMINANDO LA RESERVA CANCELADA DE LA LISTA ---\n");
                    lista = eliminarReserva(lista);
                    mostrarLista(lista);
                    break;

                default:
                    printf("Opcion no reconocida.\n");
                    break;
            }

            printf("\n\nSeleccione una opcion... \n");
            printf("\t- 1: MOSTRAR LISTA.\n");
            printf("\t- 2: MOSTRAR RESERVAS PARA DETERMINADO DIA.\n");
            printf("\t- 3: PORCENTAJES DE LAS RESERVAS EN LAS MESAS EXTERIORES.\n");
            printf("\t- 4: GENERAR LISTA ADICIONAL.\n");
            printf("\t- 5: INSERTAR NODOS ESPECIALES.\n");
            printf("\t- 6: CANCELAR RESERVA.\n");
            printf("\t- 0: SALIR DEL MENU.\n");
            printf("Opcion: ");
            scanf("%d", &opcion);
        } 
    }
    else
        printf("\nNo se ingresaron elementos.\n\n");
    
    return 0;
}

int cargarLista(cliente *lista) {
    int cantElementos = 0;
    
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", lista->nombre);

    while(strcmp(lista->nombre, "FIN") != 0 && strcmp(lista->nombre, "fin") != 0) {
        do {
            printf("Ingrese el numero de personas que integraran la reserva: ");
            scanf("%d", &lista->cantPersonasReserva);
        } while(lista->cantPersonasReserva < 1);

        do {
            printf("Ingrese la fecha de la reserva: ");
            scanf("%d", &lista->fechaReserva);
        } while(lista->fechaReserva < 1 || lista->fechaReserva > 30);

        do {
            printf("Ingrese el horario de la reserva: ");
            scanf("%d", &lista->horaReserva);
        } while(lista->horaReserva < 9 || lista->horaReserva > 22);

        do {
            printf("Ingrese el tipo de mesa de la reserva: ");
            scanf("%s", &lista->tipoDeMesa);
        } while(strcmp(lista->tipoDeMesa, "interior") != 0 && strcmp(lista->tipoDeMesa, "exterior"));

        lista->siguiente = (cliente *) malloc(sizeof(cliente));
        lista = lista->siguiente;
        cantElementos += 1;
        
        printf("\nIngrese el nombre del cliente: ");
        scanf("%s", lista->nombre);
    }

    lista->siguiente = NULL;
    return cantElementos;
}

void mostrarLista(cliente *lista) {
    int contador = 1;

    while(lista->siguiente != NULL) {
        printf("\n--- CLIENTE [%d] ---\n", contador);
        printf("Nombre: %s\n", lista->nombre);
        printf("Cantidad de las personas de la reserva: %d\n", lista->cantPersonasReserva);
        printf("Fecha de la reserva: %d\n", lista->fechaReserva);
        printf("Hora de la reserva: %d\n", lista->horaReserva);
        printf("Tipo de mesa: %s\n", lista->tipoDeMesa);

        lista = lista->siguiente;
        contador += 1;
    }
}

void mostrarReservasParaDeterminadoDia(cliente *lista) {
    int dia;
    
    do {
        printf("Ingrese la fecha para consultar las reservas: ");
        scanf("%d", &dia);
    } while(dia < 1 && dia);

    while(lista->siguiente != NULL) {
        if(lista->fechaReserva == dia) {
            printf("\nNombre: %s\n", lista->nombre);
            printf("Cantidad de las personas de la reserva: %d\n", lista->cantPersonasReserva);
            printf("Fecha de la reserva: %d\n", lista->fechaReserva);
            printf("Hora de la reserva: %d\n", lista->horaReserva);
            printf("Tipo de mesa: %s\n", lista->tipoDeMesa);
        }

        lista = lista->siguiente;
    }
}

void porcentajeMesasExterior(cliente *lista) {
    int contMesasExt = 0, contMesasTotales = 0;
    float porcentaje;

    while(lista->siguiente != NULL) {
        if(strcmp(lista->tipoDeMesa, "exterior") == 0)
            contMesasExt += 1;

        contMesasTotales += 1;
        lista = lista->siguiente;
    }

    porcentaje = ((float) contMesasExt * 100) / contMesasTotales;
    printf("El porcentajes de mesas reservadas en el exterior es: %.2f%%", porcentaje);
}

cliente *generarListaAdicional(cliente *lista, cliente *listaAdicional) {
    cliente *aux = listaAdicional;

    while(lista->siguiente != NULL) {
        if(lista->fechaReserva <= 15 && strcmp(lista->tipoDeMesa, "exterior") == 0) {
            strcpy(aux->nombre, lista->nombre);
            aux->cantPersonasReserva = lista->cantPersonasReserva;
            aux->fechaReserva = lista->fechaReserva;
            aux->horaReserva = lista->horaReserva;
            strcpy(aux->tipoDeMesa, lista->tipoDeMesa);

            aux->siguiente = (cliente *) malloc(sizeof(cliente));
            aux = aux->siguiente;
        }
        
        lista = lista->siguiente;
    }

    aux->siguiente = NULL;

    return listaAdicional;
}

cliente *insertarNodoEspecial(cliente *lista) {
    cliente *actual = NULL, *anterior = NULL;

    // CASO 1: insertar antes del cabezal
    if(lista->siguiente != NULL && lista->cantPersonasReserva > 10)
        lista = insertarCabezal(lista);

    // CASO 2: insertar en el resto
    anterior = lista;
    actual = lista->siguiente;

    while(actual->siguiente != NULL) {
        if(actual->cantPersonasReserva > 10)
            insertarEnResto(actual, anterior);
        
        anterior = actual;
        actual = actual->siguiente;
    }

    return lista;
}

cliente *insertarCabezal(cliente *lista) {
    cliente *nuevo = NULL;

    nuevo = (cliente *) malloc(sizeof(cliente));

    strcpy(nuevo->nombre, "PRIORIDAD");
    nuevo->cantPersonasReserva = 0;
    nuevo->fechaReserva = 0;
    nuevo->horaReserva = 0;
    strcpy(nuevo->tipoDeMesa, "interior");

    nuevo->siguiente = lista;

    return nuevo;
}

void insertarEnResto(cliente *actual, cliente *anterior) {
    cliente *nuevo = NULL;

    nuevo = (cliente *) malloc(sizeof(cliente));

    strcpy(nuevo->nombre, "PRIORIDAD");
    nuevo->cantPersonasReserva = 0;
    nuevo->fechaReserva = 0;
    nuevo->horaReserva = 0;
    strcpy(nuevo->tipoDeMesa, "interior");

    nuevo->siguiente = actual;
    anterior->siguiente = nuevo;
}

cliente *eliminarReserva(cliente *lista) {
    char reservaAEliminar[20];
    cliente *anterior = NULL, *actual = NULL;
    
    printf("\nIngrese el nombre de la reserva a cancelar: ");
    scanf("%s", reservaAEliminar);

    //Corroboro si la reserva a eliminar está en el cabezal de la lista
    if(strcmp(lista->nombre, reservaAEliminar) == 0) {
        lista = eliminarCabezal(lista);

        return lista;
    }

    //Como ya verifique el primer elemento, itero una vez
    anterior = lista;
    actual = lista->siguiente;

    //Busco el elemento que tiene la reserva que quiero eliminar
    while(actual->siguiente != NULL && strcmp(actual->nombre, reservaAEliminar) != 0) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if(actual->siguiente != NULL)
        eliminarResto(actual, anterior);
    else
        printf("Esa reserva no se encontro en la lista, por lo que no fue posible eliminarla.\n");

    return lista;
}

cliente *eliminarCabezal(cliente *lista) {
    cliente *aux = lista;

    lista = lista->siguiente;
    free(aux);

    return lista;
}

void eliminarResto(cliente *actual, cliente *anterior) {
    anterior->siguiente = actual->siguiente;

    free(actual);
}