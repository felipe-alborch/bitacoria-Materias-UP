/*
1) Se ingresan los datos de vuelos a distintas ciudades para obtener estadísticas. Para ello se pide: 
 
 - Día de vuelo
 - Nombre de la ciudad 
 - Capacidad del avión 
 - Cantidad de pasajes vendidos. 

Estos datos se ingresan hasta que el día de vuelo sea cero. Mostrar los datos ingresados. Calcular y mostrar:

a) La ciudad y el día con la mayor cantidad de pasajes vendidos
b) El porcentaje de pasajes vendidos de cada ciudad.
c) Mostar las ciudades en forma ordenada de menor a mayor según la cantidad de pasajes vendidos
*/

#include <stdio.h>
#include <string.h>

int cargarDatos(int [5], int [5], int [5], char [5][50]);
void mostrarDatos(int [5], int [5], int [5], char [5][50], int);
void calcularMayorVenta(int [], int [], char [][50], int);
void porcentajePasajesVendidosPorCiudad(int [], char [][50], int);
void ordenarArreglo(int [], int [], int [], char [][50], int);

int main() {
    int diasDeVuelo[5], capacidadesDeLosAviones[5], cantidadesDePasajesVendidos[5];
    char ciudades[5][50];

    int cantidadDatosCargados = cargarDatos(diasDeVuelo, capacidadesDeLosAviones, cantidadesDePasajesVendidos, ciudades);
    
    printf("\n\nMOSTRANDO LOS DATOS...\n");
    mostrarDatos(diasDeVuelo, capacidadesDeLosAviones, cantidadesDePasajesVendidos, ciudades, cantidadDatosCargados);
    
    printf("\n\nCALCULANDO LA MAYOR VENTA...\n");
    calcularMayorVenta(diasDeVuelo, cantidadesDePasajesVendidos, ciudades, cantidadDatosCargados);
    
    printf("\n\nCALCULANDO EL PORCENTAJE DE PASAJES VENDIDOS POR CIUDAD...\n");
    porcentajePasajesVendidosPorCiudad(cantidadesDePasajesVendidos, ciudades, cantidadDatosCargados);
    
    printf("\n\nORDENANDO LOS DATOS...");
    ordenarArreglo(cantidadesDePasajesVendidos, diasDeVuelo, capacidadesDeLosAviones, ciudades, cantidadDatosCargados);

    printf("\n\nMOSTRANDO LOS NUEVOS DATOS...\n");
    mostrarDatos(diasDeVuelo, capacidadesDeLosAviones, cantidadesDePasajesVendidos, ciudades, cantidadDatosCargados);

    return 0;
}

void ordenarArreglo(int cantidadesDePasajesVendidos[], int diasDeVuelo[], int capacidadesDeLosAviones[], char ciudades[][50], int cantidadDatosCargados) {
    int aux;
    char auxCiudad[50];
    
    for(int i = 0; i < cantidadDatosCargados; i++) {
        for(int j = 0; j < cantidadDatosCargados - 1; j++) {
            if(cantidadesDePasajesVendidos[j] > cantidadesDePasajesVendidos[j+1]) {
                aux = cantidadesDePasajesVendidos[j];
                cantidadesDePasajesVendidos[j] = cantidadesDePasajesVendidos[j+1];
                cantidadesDePasajesVendidos[j+1] = aux;

                aux = diasDeVuelo[j];
                diasDeVuelo[j] = diasDeVuelo[j+1];
                diasDeVuelo[j+1] = aux;

                aux = capacidadesDeLosAviones[j];
                capacidadesDeLosAviones[j] = capacidadesDeLosAviones[j+1];
                capacidadesDeLosAviones[j+1] = aux;

                strcpy(auxCiudad, ciudades[j]);
                strcpy(ciudades[j], ciudades[j+1]);
                strcpy(ciudades[j+1], auxCiudad);
            }
        }
    }
}

int cargarDatos(int diasDeVuelo[5], int capacidadesDeLosAviones[5], int cantidadesDePasajesVendidos[5], char ciudades[5][50]) {
    int diaVuelo, capacidadAvion, cantidadPasajesVendidos, i = 0;
    char ciudad[50];

    printf("Ingresa el dia del vuelo: ");
    scanf("%d", &diaVuelo);

    while (diaVuelo != 0 && i < 5) {
        printf("Ingresa la capacidad del avion: ");
        scanf("%d", &capacidadAvion);

        printf("Ingresa la cantidad de pasajes vendidos: ");
        scanf("%d", &cantidadPasajesVendidos);

        printf("Ingresa la ciudad de destino: ");
        scanf("%s", ciudad);

        diasDeVuelo[i] = diaVuelo;
        capacidadesDeLosAviones[i] = capacidadAvion;
        cantidadesDePasajesVendidos[i] = cantidadPasajesVendidos;
        strcpy(ciudades[i], ciudad);

        i += 1;

        printf("Ingresa el dia del vuelo: ");
        scanf("%d", &diaVuelo);
    }

    return i;
}

void mostrarDatos(int diasDeVuelo[5], int capacidadesDeLosAviones[5], int cantidadesDePasajesVendidos[5], char ciudades[5][50], int cantidadDatosCargados) {
    for(int i = 0; i < cantidadDatosCargados; i++) {
        printf("Dia del vuelo [%d]: %d\n", i, diasDeVuelo[i]);
        printf("Capacidad del avion [%d]: %d\n", i, capacidadesDeLosAviones[i]);
        printf("Cantidad de pasajes vendidos [%d]: %d\n", i, cantidadesDePasajesVendidos[i]);
        printf("Nombre de la ciudad destino [%d]: %s\n\n", i, ciudades[i]);
    }
}

void calcularMayorVenta(int diasDeVuelo[], int cantidadesDePasajesVendidos[], char ciudades[][50], int cantidadDatosCargados) {
    int mayorCantidad = 0;
    int diaMayor;
    char ciudadMayor[50];

    for (int i = 0; i < cantidadDatosCargados; i++) {

        int acumulador = 0;

        for (int j = 0; j < cantidadDatosCargados; j++) {

            if (diasDeVuelo[i] == diasDeVuelo[j] && strcmp(ciudades[i], ciudades[j]) == 0)
                acumulador += cantidadesDePasajesVendidos[j];
        }

        if (acumulador > mayorCantidad) {
            mayorCantidad = acumulador;
            diaMayor = diasDeVuelo[i];
            strcpy(ciudadMayor, ciudades[i]);
        }
    }

    printf("Dia con mayor cantidad de pasajes vendidos: %d\n", diaMayor);
    printf("Ciudad: %s\n", ciudadMayor);
    printf("Cantidad de pasajes vendidos: %d\n", mayorCantidad);
}

void porcentajePasajesVendidosPorCiudad(int cantidadesDePasajesVendidos[], char ciudades[][50], int cantidadDatosCargados) {
    int cantidadPasajesTotalesVendidos = 0;

    char ciudadesProcesadas[5][50];
    int cantidadCiudadesProcesadas = 0;

    for (int i = 0; i < cantidadDatosCargados; i++)
        cantidadPasajesTotalesVendidos += cantidadesDePasajesVendidos[i];

    for (int i = 0; i < cantidadDatosCargados; i++) {
        int coincidencias = 0;

        // Busco si la ciudad ya fue procesada
        for (int j = 0; j < cantidadCiudadesProcesadas; j++) {

            if (strcmp(ciudades[i], ciudadesProcesadas[j]) == 0)
                coincidencias++;
        }

        // Si no apareció, la proceso
        if (coincidencias == 0) {
            int acumuladorPorCiudad = 0;

            for (int j = 0; j < cantidadDatosCargados; j++) {

                if (strcmp(ciudades[i], ciudades[j]) == 0)
                    acumuladorPorCiudad += cantidadesDePasajesVendidos[j];
            }

            float porcentaje = acumuladorPorCiudad * 100 / (float) cantidadPasajesTotalesVendidos;

            printf("El porcentaje de pasajes vendidos de la ciudad [%s] es del: %.2f%%", ciudades[i], porcentaje);

            // Una vez procesada, se guarda
            strcpy(ciudadesProcesadas[cantidadCiudadesProcesadas], ciudades[i]);

            cantidadCiudadesProcesadas++;
        }
    }
}