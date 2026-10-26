/*
Ejercicio: Multilistas – Equipos de fútbol y jugadores

Desarrollar un programa en lenguaje C que permita administrar equipos de fútbol y sus respectivos jugadores mediante la utilización de **multilistas**.

De cada equipo se deberá almacenar:
- Nombre del equipo.

De cada jugador se deberá almacenar:
- Nombre del jugador.
- Posición.
- Número de camiseta.

Se pide:

1. Crear una multilista que permita cargar equipos de fútbol y sus respectivos jugadores. La carga de equipos y jugadores finalizará al ingresar "FIN".
2. Mostrar todos los equipos cargados junto con los datos de sus respectivos jugadores.
3. Mostrar la cantidad total de equipos registrados.
4. Mostrar la cantidad total de jugadores registrados entre todos los equipos.

Consideraciones:
- Utilizar estructuras dinámicas y punteros.
- Implementar funciones para cargar y mostrar los datos.
- Utilizar recursividad para la carga y el recorrido de las listas, siguiendo la metodología vista en clase.
*/

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

// Declaracion de funciones
void cargarEquipos(equipo *lista);
void cargarJugadores(jugador *lista);
void mostrarEquipos(equipo *lista);
void mostrarJugadores(jugador *lista);
int contarEquipos(equipo *lista);
int contarJugadores(equipo *lista);
int contarJugadoresEquipo(jugador *lista);

int main() {
    equipo *lista = NULL;

    lista = (equipo *) malloc(sizeof(equipo));

    cargarEquipos(lista);

    printf("\n--- EQUIPOS Y JUGADORES ---\n");
    mostrarEquipos(lista);

    printf("\nCantidad de equipos: %d\n", contarEquipos(lista));

    printf("Cantidad total de jugadores: %d\n", contarJugadores(lista));

    return 0;
}

// Cargar equipos
void cargarEquipos(equipo *lista) {
    printf("\nIngrese nombre del equipo - FIN para terminar: ");
    scanf("%s", lista->nombreEquipo);

    if (strcmp(lista->nombreEquipo, "FIN") == 0) {
        lista->siguiente = NULL;
        return;
    }
    else {
        lista->cabezal = (jugador *) malloc(sizeof(jugador));

        cargarJugadores(lista->cabezal);

        lista->siguiente = (equipo *) malloc(sizeof(equipo));

        cargarEquipos(lista->siguiente);
    }
}

// Cargar jugadores
void cargarJugadores(jugador *lista) {
    printf("\nIngrese nombre del jugador - FIN para terminar: ");
    scanf("%s", lista->nombreJugador);

    if (strcmp(lista->nombreJugador, "FIN") == 0) {
        lista->siguiente = NULL;
        return;
    }
    else {
        printf("Ingrese su posicion: ");
        scanf("%s", lista->posicion);

        printf("Ingrese su dorsal: ");
        scanf("%d", &lista->numeroCamiseta);

        lista->siguiente = (jugador *) malloc(sizeof(jugador));

        cargarJugadores(lista->siguiente);
    }
}

// Mostrar equipos
void mostrarEquipos(equipo *lista) {
    if (lista->siguiente != NULL) {
        printf("\nEquipo: %s\n", lista->nombreEquipo);

        mostrarJugadores(lista->cabezal);

        mostrarEquipos(lista->siguiente);
    }
}

// Mostrar jugadores
void mostrarJugadores(jugador *lista) {
    if (lista->siguiente != NULL) {
        printf("\nJugador: %s\n", lista->nombreJugador);
        printf("Posicion: %s\n", lista->posicion);
        printf("Dorsal: %d\n", lista->numeroCamiseta);

        mostrarJugadores(lista->siguiente);
    }
}

// Contar equipos
int contarEquipos(equipo *lista) {
    if (lista->siguiente == NULL)
        return 0;
    else
        return 1 + contarEquipos(lista->siguiente);
}

// Contar jugadores de un equipo
int contarJugadoresEquipo(jugador *lista) {
    if (lista->siguiente == NULL)
        return 0;
    else
        return 1 + contarJugadoresEquipo(lista->siguiente);
}

// Contar jugadores de todos los equipos
int contarJugadores(equipo *lista) {
    if (lista->siguiente == NULL)
        return 0;
    else
        return contarJugadoresEquipo(lista->cabezal) + contarJugadores(lista->siguiente);
}