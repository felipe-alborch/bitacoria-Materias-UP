/*
Se ingresan la cantidad de autos vendidos en los últimos 9 años. Calcular y mostrar:
a) El año que se vendieron la mayor cantidad de autos.
b) La cantidad total de autos vendidos
*/

#include <stdio.h>

int main() {
    int autosVendidosPorAnio[9];
    int acumulador = 0;

    printf("Ingresa la cantidad de autos vendidos en el anio 1: ");
    scanf("%d", &autosVendidosPorAnio[0]);

    acumulador += autosVendidosPorAnio[0];

    int cantMaxAutosVendidos = autosVendidosPorAnio[0];
    int anioCantMaxAutosVendidos = 1;

    for(int i = 1; i < 9; i++) {
        printf("Ingrese la cantidad de autos vendidos en el anio %d: ", i+1);
        scanf("%d", &autosVendidosPorAnio[i]);

        if(autosVendidosPorAnio[i] > cantMaxAutosVendidos) {
            cantMaxAutosVendidos = autosVendidosPorAnio[i];
            anioCantMaxAutosVendidos = i+1;
        }

        acumulador += autosVendidosPorAnio[i];
    }

    printf("\nLa cantidad de autos vendidos en los ultimos 9 anios es: %d.", acumulador);
    printf("\nEl anio donde mayor cantidad de autos se vendieron fue el anio %d, con un total de %d autos vendidos.", anioCantMaxAutosVendidos, cantMaxAutosVendidos);
    
    return 0;
}