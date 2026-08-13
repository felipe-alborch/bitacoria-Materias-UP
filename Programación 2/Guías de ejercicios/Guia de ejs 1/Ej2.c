/*
Ingresar el día y la cotización del dólar durante un mes. Calcular y mostrar el día
donde hubo la mayor cotización.
*/

#include <stdio.h>

int main() {
    int diasDelMes = 0;

    do {
        printf("Ingrese cuantos dias tiene el mes en curso: ");
        scanf("%d", &diasDelMes);
    } while (diasDelMes < 28 || diasDelMes > 30);
    
    
    float cotizaciones[diasDelMes];

    printf("Ingrese la cotizacion del dia 1: ");
    scanf("%d", &cotizaciones[0]);

    float cotizacionMaxima = cotizaciones[0];
    int diaCotizacionMaxima = 1;

    for(int i = 1; i < diasDelMes; i++) {
        printf("Ingrese la cotizacion del dolar del dia %d: ", i+1);
        scanf("%f", &cotizaciones[i]);

        if(cotizaciones[i] > cotizacionMaxima) {
            cotizacionMaxima = cotizaciones[i];
            diaCotizacionMaxima = i+1;
        }
    }
    
    for(int i = 0; i < diasDelMes; i++) {
        printf("\nCotizacion del dia %d: %f", i+1, cotizaciones[i]);
    }

    printf("\nLa cotizacion maxima encontrada fue de %f, el dia %d", cotizacionMaxima, diaCotizacionMaxima);

    return 0;
}