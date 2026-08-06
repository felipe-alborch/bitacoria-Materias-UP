/*
Ingresar números hasta que dicho número sea negativo. Por cada número leído, ingresar esa cantidad de números y obtener:
a) El promedio de cada lote leído.
b) Contar la cantidad de números pares de todos los números leídos.
*/

#include <stdio.h>

float calcularPromedio(int, int);

int main() {
    int lote = 0, cantNumerosPares = 0, numerosIngresados = 0;

    printf("Detalle el lote de numeros a ingresar: ");
    scanf("%d", &lote);

    while(lote > 0) {
        int sumatoriaNumerosLeidos = 0, cantNumerosLeidos = 0;
        
        for(int i = 0; i < lote; i++) {
            int numero = 0;

            printf("Ingrese un numero: ");
            scanf("%d", &numero);

            if(numero % 2 == 0) {
                cantNumerosPares += 1;
            }

            numerosIngresados += 1;
            sumatoriaNumerosLeidos += numero;
            cantNumerosLeidos += 1;
        }    

        float promedio = calcularPromedio(sumatoriaNumerosLeidos, cantNumerosLeidos);
        printf("\nEl promedio de los numeros del lote ingresado es: %.2f", promedio);

        printf("\n\nDetalle el lote de numeros a ingresar: ");
        scanf("%d", &lote);
    }
    
    if(numerosIngresados > 0) {
        printf("\n\nLa cantidad total de numeros pares leidos es: %d.", cantNumerosPares);
    }
    else {
        printf("\n\nNo se ingresaron numeros.");
    }

    return 0;
}

float calcularPromedio(int sumatoriaNumerosLeidos, int cantNumerosLidos) {
    float promedio = (float) sumatoriaNumerosLeidos / cantNumerosLidos;

    return promedio;
}