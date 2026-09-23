#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Partido {
    int numeroLista;
    char nombrePartido[20];
    char candidatoPrincipal[20];
    int votosObtenidos;
    struct Partido *siguiente;
} Partido;

int cargarLista(Partido *lista);
void mostrarLista(Partido *lista);
void insertarNodoEspecial(Partido *lista);
Partido *conversionCandidatosConMenosDe30Votos(Partido *lista, Partido *listaCandidatosConMenosDe30Votos);
Partido *eliminarCabezal(Partido *lista);
void eliminarNodo(Partido *anterior);
Partido *insertarElemento(Partido *destino, Partido *origen);

int main() {
    Partido *lista = NULL, *listaCandidatosConMenosDe30Votos = NULL;
    int cantElementos = 0;

    lista = (Partido *) malloc(sizeof(Partido));
    listaCandidatosConMenosDe30Votos = (Partido *) malloc(sizeof(Partido));

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    cantElementos = cargarLista(lista);

    if(cantElementos > 0) {
        printf("\n\n--- MOSTRANDO ELEMENTOS DE LA LISTA ---\n");
        mostrarLista(lista);

        printf("\n\n--- INSERTANDO NODOS ESPECIALES EN LA LISTA ---\n");
        insertarNodoEspecial(lista);
        mostrarLista(lista);

        printf("\n--- HACIENDO PUNTO C ---\n");
        lista = conversionCandidatosConMenosDe30Votos(lista, listaCandidatosConMenosDe30Votos);
        
        printf("\n\n--- MOSTRANDO COMO QUEDO LA LISTA ORIGINAL ---\n");
        mostrarLista(lista);

        printf("\n\n--- MOSTRANDO COMO QUEDO LA NUEVA LISTA ---\n");
        mostrarLista(listaCandidatosConMenosDe30Votos);
    }
    else
        printf("\nNo se ingresaron elementos.\n\n");

    return 0;
}

int cargarLista(Partido *lista) {
    int cantElementos = 0;

    printf("Ingrese el numero de lista: ");
    scanf("%d", &lista->numeroLista);

    while(lista->numeroLista != 0) {
        printf("Ingrese el nombre del partido: ");
        scanf("%s", lista->nombrePartido);

        printf("Ingrese el nombre del candidato principal: ");
        scanf("%s", lista->candidatoPrincipal);

        printf("Ingrese la cantidad de votos obtenidos: ");
        scanf("%d", &lista->votosObtenidos);

        lista->siguiente = (Partido *) malloc(sizeof(Partido));
        lista = lista->siguiente;
        cantElementos += 1;
        
        printf("\nIngrese el numero de lista: ");
        scanf("%d", &lista->numeroLista);
    }

    lista->siguiente = NULL;
    return cantElementos;
}

void mostrarLista(Partido *lista) {
    int contador = 0;

    while(lista->numeroLista != 0) {
        printf("\n--- Partido [%d] ---\n", contador);
        printf("Numero de lista: %d\n", lista->numeroLista);
        printf("Nombre del partido: %s\n", lista->nombrePartido);
        printf("Candidato principal: %s\n", lista->candidatoPrincipal);
        printf("Votos obtenidos: %d\n", lista->votosObtenidos);

        contador += 1;
        lista = lista->siguiente;
    }
}

void insertarNodoEspecial(Partido *lista) {
    Partido *anterior = NULL, *nodoEspecial = NULL;
    int sumatoriaVotos = 0;

    while(lista->numeroLista != 0) {
        if(anterior != NULL && strcmp(lista->nombrePartido, anterior->nombrePartido) != 0) {
            nodoEspecial = (Partido *) malloc(sizeof(Partido));

            nodoEspecial->numeroLista = 9999;
            strcpy(nodoEspecial->nombrePartido, "Nuevo_Partido");
            strcpy(nodoEspecial->candidatoPrincipal, "XXXX");
            nodoEspecial->votosObtenidos = sumatoriaVotos;


            nodoEspecial->siguiente = lista;
            anterior->siguiente = nodoEspecial;
            sumatoriaVotos = lista->votosObtenidos;
        }
        else
            sumatoriaVotos += lista->votosObtenidos;
        
        anterior = lista;
        lista = lista->siguiente;
    }

    nodoEspecial = (Partido *) malloc(sizeof(Partido));
    nodoEspecial->numeroLista = 9999;
    strcpy(nodoEspecial->nombrePartido, "Nuevo_Partido");
    strcpy(nodoEspecial->candidatoPrincipal, "XXXX");
    nodoEspecial->votosObtenidos = sumatoriaVotos;
    nodoEspecial->siguiente = lista;
    anterior->siguiente = nodoEspecial;
}

Partido *conversionCandidatosConMenosDe30Votos(Partido *lista, Partido *listaCandidatosConMenosDe30Votos) {
    Partido *actual = NULL, *actualNuevaLista = listaCandidatosConMenosDe30Votos;

    /*
        PRIMER CASO:
        Eliminar elementos desde el cabezal.
    */

    while(lista->siguiente != NULL && lista->votosObtenidos < 30) {
        // Copiamos a la nueva lista
        actualNuevaLista = insertarElemento(actualNuevaLista, lista);

        // Eliminamos el cabezal
        lista = eliminarCabezal(lista);
    }

    /*
        SEGUNDO CASO:
        Eliminar elementos del resto de la lista.
    */

    actual = lista;

    while(actual->siguiente != NULL && actual->siguiente->numeroLista != 0) {
        if(actual->siguiente->votosObtenidos < 30) {
            // Copiamos a la nueva lista
            actualNuevaLista = insertarElemento(actualNuevaLista, actual->siguiente);

            // Eliminamos actual->siguiente
            eliminarNodo(actual);
        }
        else
            actual = actual->siguiente;
    }

    // Cerramos la nueva lista
    actualNuevaLista->numeroLista = 0;
    actualNuevaLista->siguiente = NULL;

    return lista;
}

Partido *eliminarCabezal(Partido *lista) {
    Partido *aux = lista;

    lista = lista->siguiente;
    free(aux);

    return lista;
}

void eliminarNodo(Partido *anterior) {
    Partido *aux = anterior->siguiente;

    anterior->siguiente = aux->siguiente;

    free(aux);
}

Partido *insertarElemento(Partido *destino, Partido *origen) {
    destino->numeroLista = origen->numeroLista;
    strcpy(destino->nombrePartido, origen->nombrePartido);
    strcpy(destino->candidatoPrincipal, origen->candidatoPrincipal);
    destino->votosObtenidos = origen->votosObtenidos;

    destino->siguiente = (Partido *) malloc(sizeof(Partido));

    return destino->siguiente;
}