#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct equipo {
    char nombreEquipo[20];
    struct equipo *siguiente;
    struct jugador *cabezal;
} equipo;

typedef struct jugador {
    char nombreJugador[20];
    char posicion[20];
    int numeroCamiseta;
    struct jugador *siguiente;
} jugador;

void cargarEquipos(equipo *lista);
void cargarJugadores(jugador *lista);

int main() {
    equipo *lista = NULL;

    lista = (equipo *) malloc(sizeof(equipo));
    
    
    return 0;
}

void cargarEquipos(equipo *lista) {
    printf("Ingrese el nombre del equipo - FIN para terminar: ");
    scanf("%s", lista->nombreEquipo);

    while(strcmp(lista->nombreEquipo, "FIN") != 0) {
        lista->cabezal = NULL;
        lista->cabezal = (jugador *) malloc(sizeof(jugador));

        cargarEquipos(lista->cabezal);
        
        lista->siguiente = (equipo *) malloc(sizeof(equipo));
        lista = lista->siguiente;

        printf("Ingrese el nombre del equipo - FIN para terminar: ");
        scanf("%s", lista->nombreEquipo);
    }
}

void cargarJugadores(jugador *lista) {
    printf("Ingrese el nombre del jugador - FIN para terminar: ");
    scanf("%s", lista->nombreJugador);

    while(strcmp(lista->nombreJugador, "FIN") != 0) {
        printf("Ingrese su posicion: ");
        scanf("%s", lista->posicion);

        printf("Ingrese su dorsal: ");
        scanf("%d", &lista->numeroCamiseta);
        
        lista->siguiente = (jugador *) malloc(sizeof(jugador));
        lista = lista->siguiente;
        
        printf("Ingrese el nombre del jugador - FIN para terminar: ");
        scanf("%s", lista->nombreJugador);
    }
}