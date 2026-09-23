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
Partido *eliminar_InsertarElementos(Partido *lista, Partido *listaCandidatosConMenosDe30Votos);

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
        

        printf("\n\n--- HACIENDO PUNT C ---\n");
        lista = eliminar_InsertarElementos(lista, listaCandidatosConMenosDe30Votos);
        mostrarLista(lista);
        printf("\n\n");
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

Partido *eliminar_InsertarElementos(Partido *lista, Partido *listaCandidatosConMenosDe30Votos) {
    Partido *actual = lista, *anterior = NULL, *aux = NULL, *actualNuevaLista = listaCandidatosConMenosDe30Votos;

    while(actual->numeroLista != 0) {
        if(actual->votosObtenidos < 30) {
            // Copiar a la nueva lista
            actualNuevaLista->numeroLista = actual->numeroLista;
            strcpy(actualNuevaLista->nombrePartido, actual->nombrePartido);
            strcpy(actualNuevaLista->candidatoPrincipal, actual->candidatoPrincipal);
            actualNuevaLista->votosObtenidos = actual->votosObtenidos;

            actualNuevaLista->siguiente = (Partido *) malloc(sizeof(Partido));
            actualNuevaLista = actualNuevaLista->siguiente;

            // Eliminar de la lista original
            aux = actual;

            // Caso 1: estoy eliminando el primer nodo
            if(anterior == NULL) {
                lista = actual->siguiente;
                actual = actual->siguiente;
            }
            // Caso 2: estoy eliminando cualquier otro nodo
            else {
                anterior->siguiente = actual->siguiente;
                actual = actual->siguiente;
            }

            free(aux);
        }
        else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    // Nodo final de la nueva lista
    actualNuevaLista->numeroLista = 0;
    actualNuevaLista->siguiente = NULL;

    return lista;
}