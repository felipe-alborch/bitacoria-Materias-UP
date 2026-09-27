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

typedef struct PartidoEncimaPromedioVotos {
    int numeroLista;
    struct PartidoEncimaPromedioVotos *siguiente;
} PartidoEncimaPromedioVotos;

typedef struct Partido_NuevaLista {
    char nombrePartido[20];
    float porcentajeVotosRespectoAlTotal;
    struct Partido_NuevaLista *siguiente;
} Partido_NuevaLista;

int cargarLista(Partido *lista);
void mostrarLista(Partido *lista);
void mostrarLista2(PartidoEncimaPromedioVotos *lista);
void mostrarLista3(Partido_NuevaLista *lista);
void insertarNodosEspeciales(Partido *lista);
Partido *conversionCandidatosConMenosDe30Votos(Partido *lista, Partido *listaCandidatosConMenosDe30Votos);
Partido *eliminarCabezal(Partido *lista);
void eliminarNodo(Partido *anterior);
Partido *insertarElemento(Partido *destino, Partido *origen);
float promedioGeneralVotos(Partido *lista);
PartidoEncimaPromedioVotos *generarListaPartidosConMasVotosQueElPromedio(Partido *lista, PartidoEncimaPromedioVotos *listaPartidosConMasVotosQueElPromedio, float promedioGeneralDeVotos);
Partido_NuevaLista *generarNuevaLista(Partido *lista, Partido_NuevaLista *listaNueva, int totalDeVotos);
int calcularTotalDeVotos(Partido *lista);
void candidatoGanadorDeCadaPartido(Partido *lista);

int main() {
    Partido *lista = NULL, *listaCandidatosConMenosDe30Votos = NULL;
    PartidoEncimaPromedioVotos *listaPartidosConMasVotosQueElPromedio = NULL;
    Partido_NuevaLista *listaNueva = NULL;
    int cantElementos = 0, totalDeVotos = 0;
    float promedioGeneralDeVotos;

    lista = (Partido *) malloc(sizeof(Partido));
    listaCandidatosConMenosDe30Votos = (Partido *) malloc(sizeof(Partido));
    listaPartidosConMasVotosQueElPromedio = (PartidoEncimaPromedioVotos *) malloc(sizeof(PartidoEncimaPromedioVotos));
    listaNueva = (Partido_NuevaLista *) malloc(sizeof(Partido_NuevaLista));

    printf("\n\n--- INGRESANDO ELEMENTOS A LA LISTA ---\n\n");
    cantElementos = cargarLista(lista);

    if(cantElementos > 0) {
        // PRIMER PUNTO
        printf("\n\n--- MOSTRANDO ELEMENTOS DE LA LISTA ---\n");
        mostrarLista(lista);
        
        //SEGUNDO PUNTO
        printf("\n\n--- INSERTANDO NODOS ESPECIALES EN LA LISTA ---\n");
        insertarNodosEspeciales(lista);
        mostrarLista(lista);

        //TERCER PUNTO
        printf("\n--- ELIMINANDO CANDIDATOS CON MENOS DE 30 VOTOS ---\n");
        lista = conversionCandidatosConMenosDe30Votos(lista, listaCandidatosConMenosDe30Votos);
        
        printf("\n--- MOSTRANDO COMO QUEDO LA LISTA ORIGINAL ---\n");
        mostrarLista(lista);

        printf("\n--- MOSTRANDO COMO QUEDO LA LISTA DE CANDIDATOS ELIMINADOS ---\n");
        mostrarLista(listaCandidatosConMenosDe30Votos);

        //CUARTO PUNTO
        printf("\n--- GENERANDO NUEVA LISTA CON PARTIDOS POR ENCIMA DEL PROMEDIO GENERAL DE VOTOS ---\n");
        promedioGeneralDeVotos = promedioGeneralVotos(lista);
        listaPartidosConMasVotosQueElPromedio = generarListaPartidosConMasVotosQueElPromedio(lista, listaPartidosConMasVotosQueElPromedio, promedioGeneralDeVotos);

        if(listaPartidosConMasVotosQueElPromedio->numeroLista != 0)
            mostrarLista2(listaPartidosConMasVotosQueElPromedio);
        else
            printf("No se encontraron listas con mas votos que el promedio.\n");

        //QUINTO PUNTO
        printf("\n--- GENERANDO NUEVA LISTA CON PORCENTAJE DE VOTOS DE CADA PARTIDO RESPECTO AL TOTAL ---\n");
        totalDeVotos = calcularTotalDeVotos(lista);
        listaNueva = generarNuevaLista(lista, listaNueva, totalDeVotos);
        mostrarLista3(listaNueva);
        
        //SEXTO PUNTO
        printf("\n--- CALCULANDO EL CANDIDATO GANADOR DE CADA PARTIDO ---\n");
        candidatoGanadorDeCadaPartido(lista);
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

    while(lista->siguiente != NULL) {
        printf("\n--- Partido [%d] ---\n", contador);
        printf("Numero de lista: %d\n", lista->numeroLista);
        printf("Nombre del partido: %s\n", lista->nombrePartido);
        printf("Candidato principal: %s\n", lista->candidatoPrincipal);
        printf("Votos obtenidos: %d\n", lista->votosObtenidos);

        contador += 1;
        lista = lista->siguiente;
    }
}

void mostrarLista2(PartidoEncimaPromedioVotos *lista) {
    int contador = 0;

    while(lista->siguiente != NULL) {
        printf("\n--- Partido [%d] ---\n", contador);
        printf("Numero de lista: %d\n", lista->numeroLista);

        contador += 1;
        lista = lista->siguiente;
    }
}

void mostrarLista3(Partido_NuevaLista *lista) {
    int contador = 0;

    while(lista->siguiente != NULL) {
        printf("\n--- Partido [%d] ---\n", contador);
        printf("Nombre del partido: %s\n", lista->nombrePartido);
        printf("Promedio de votos respecto al total: %.2f", lista->porcentajeVotosRespectoAlTotal);

        contador += 1;
        lista = lista->siguiente;
    }
}

void insertarNodosEspeciales(Partido *lista) {
    Partido *ultimoDelPartido = NULL, *nodoEspecial = NULL;
    int sumatoriaVotos;
    char partidoActual[20];

    while(lista->siguiente != NULL) {
        // guardo qué partido estoy procesando
        strcpy(partidoActual, lista->nombrePartido);

        sumatoriaVotos = 0;
        ultimoDelPartido = NULL;

        // se recorren todas las listas electorales de ese partido
        while(lista->siguiente != NULL && strcmp(lista->nombrePartido, partidoActual) == 0) {
            sumatoriaVotos += lista->votosObtenidos;

            ultimoDelPartido = lista;
            lista = lista->siguiente;
        }

        // creo el nodo especial
        nodoEspecial = (Partido *) malloc(sizeof(Partido));

        nodoEspecial->numeroLista = 9999;
        strcpy(nodoEspecial->nombrePartido, "Nuevo_Partido");
        strcpy(nodoEspecial->candidatoPrincipal, "XXXX");
        nodoEspecial->votosObtenidos = sumatoriaVotos;

        // se inserta entre el último nodo del partido y el comienzo del siguiente partido
        nodoEspecial->siguiente = lista;
        ultimoDelPartido->siguiente = nodoEspecial;
    }
}

Partido *conversionCandidatosConMenosDe30Votos(Partido *lista, Partido *listaCandidatosConMenosDe30Votos) {
    Partido *actual = NULL, *actualNuevaLista = listaCandidatosConMenosDe30Votos;

    //PRIMER CASO: Eliminar elementos desde el cabezal
    while(lista->siguiente != NULL && lista->votosObtenidos < 30) {
        // copio a la nueva lista
        actualNuevaLista = insertarElemento(actualNuevaLista, lista);

        // elimino el cabezal
        lista = eliminarCabezal(lista);
    }

    //SEGUNDO CASO: Eliminar elementos del resto de la lista
    actual = lista;

    while(actual->siguiente != NULL && actual->siguiente->numeroLista != 0) {
        if(actual->siguiente->votosObtenidos < 30) {
            // copio a la nueva lista
            actualNuevaLista = insertarElemento(actualNuevaLista, actual->siguiente);

            // elimino actual->siguiente
            eliminarNodo(actual);
        }
        else
            actual = actual->siguiente;
    }

    // acá "cierro" la nueva lista
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

float promedioGeneralVotos(Partido *lista) {
    int contador = 0, acumulador = 0;
    float promedio;

    while(lista->siguiente != NULL) {
        contador += 1;
        acumulador += lista->votosObtenidos;

        lista = lista->siguiente;
    }

    promedio = (float) acumulador / contador;
    
    return promedio;
}

int calcularTotalDeVotos(Partido *lista) {
    int sumatoriaVotos = 0;

    while(lista->siguiente != NULL) {
        sumatoriaVotos += lista->votosObtenidos;
        lista = lista->siguiente;
    }

    return sumatoriaVotos;
}

PartidoEncimaPromedioVotos *generarListaPartidosConMasVotosQueElPromedio(Partido *lista, PartidoEncimaPromedioVotos *listaPartidosConMasVotosQueElPromedio, float promedioGeneralDeVotos) {
    PartidoEncimaPromedioVotos *aux = listaPartidosConMasVotosQueElPromedio;
    
    while(lista->siguiente != NULL) {
        if(lista->votosObtenidos > promedioGeneralDeVotos) {
            aux->numeroLista = lista->numeroLista;
            aux->siguiente = (PartidoEncimaPromedioVotos *) malloc(sizeof(PartidoEncimaPromedioVotos));

            aux = aux->siguiente;
        }

        lista = lista->siguiente;
    }

    aux->numeroLista = 0;
    aux->siguiente = NULL;

    return listaPartidosConMasVotosQueElPromedio;
}

Partido_NuevaLista *generarNuevaLista(Partido *lista, Partido_NuevaLista *listaNueva, int totalVotos) {
    Partido_NuevaLista *aux = listaNueva;
    int sumatoriaVotos = 0;
    char partidoActual[20];

    while(lista->siguiente != NULL) {
        // guardo qué partido estamos procesando
        strcpy(partidoActual, lista->nombrePartido);

        // guardo el nombre en la nueva lista
        strcpy(aux->nombrePartido, partidoActual);

        sumatoriaVotos = 0;

        // sumo todas las listas electorales del mismo partido
        while(lista->siguiente != NULL && strcmp(lista->nombrePartido, partidoActual) == 0) {
            sumatoriaVotos += lista->votosObtenidos;
            lista = lista->siguiente;
        }

        aux->porcentajeVotosRespectoAlTotal = ((float) sumatoriaVotos * 100) / totalVotos;

        // cierro el siguiente nodo
        aux->siguiente = (Partido_NuevaLista *) malloc(sizeof(Partido_NuevaLista));
        aux = aux->siguiente;
    }

    aux->siguiente = NULL;

    return listaNueva;
}

void candidatoGanadorDeCadaPartido(Partido *lista) {
    char partidoActual[20];
    Partido *ganador = NULL;

    while(lista->siguiente != NULL) {
        strcpy(partidoActual, lista->nombrePartido);

        //asumo que el primer candidato del partido es el ganador
        ganador = lista;

        while(lista->siguiente != NULL && strcmp(lista->nombrePartido, partidoActual) == 0) {
            if(lista->votosObtenidos > ganador->votosObtenidos)
                ganador = lista;

            lista = lista->siguiente;
        }

        printf("\n--- GANADOR DEL PARTIDO [%s] ---\n", partidoActual);
        printf("Numero de lista: %d\n", ganador->numeroLista);
        printf("Nombre del partido: %s\n", ganador->nombrePartido);
        printf("Candidato principal: %s\n", ganador->candidatoPrincipal);
        printf("Votos obtenidos: %d\n", ganador->votosObtenidos);
    }
}