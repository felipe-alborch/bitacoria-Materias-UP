/*
Ingresar números hasta que dicho número sea negativo. Calcular y mostrar:
a) Cantidad de números mayores a 4 y menores a 25.
b) Promedio de aquellos números múltiplos de 6.
c) El menor número leído.
*/

#include <stdio.h>

int main() {
    int cantNumsEntre4y25 = 0, cantMultiplosDe6 = 0, contadorNumerosIngresados = 0;
    int sumatoriaNumerosMultiplosDe6 = 0;
    int numero = 0;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    int menor = numero;
    
    while(numero >= 0) {
        contadorNumerosIngresados += 1;

        if(numero > 4 && numero < 25) {
            cantNumsEntre4y25 += 1;
        }

        if(numero % 6 == 0) {
            cantMultiplosDe6 += 1;
            sumatoriaNumerosMultiplosDe6 += numero;
        }

        if(numero < menor) {
            menor = numero;
        }

        printf("Ingrese un numero: ");
        scanf("%d", &numero);
    }

    if (contadorNumerosIngresados > 0) {
        printf("\nCantidad de numeros mayores a 4 y menores a 25: %d\n", cantNumsEntre4y25);

        if (cantMultiplosDe6 > 0) {
            float promedio = (float) sumatoriaNumerosMultiplosDe6 / cantMultiplosDe6;

            printf("Promedio de los numeros multiplos de 6: %.2f\n", promedio);
        } 
        else {
            printf("No se ingresaron numeros multiplos de 6.\n");
        }

        printf("El menor numero leido es: %d\n", menor);
    } else {
        printf("\nNo se ingresaron numeros validos.\n");
    }
    
    return 0;
}