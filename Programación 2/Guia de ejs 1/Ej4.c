/*
Ingresar números hasta que dicho número sea negativo. Calcular y mostrar:
a) Cantidad de números mayores a 4 y menores a 25.
b) Promedio de aquellos números múltiplos de 6.
c) El menor número leído.
*/

#include <stdio.h>

int main() {
    int cantNumsEntre4y25 = 0;
    int cantMultiplosDe6 = 0;
    int numero = 0;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    
    while(numero >= 0) {
        if(numero > 4 && numero < 25) {
            cantNumsEntre4y25 += 1;
        }

        if(numero % 6 == 0) {
            cantMultiplosDe6 += 1;
        }

        printf("Ingrese un numero: ");
        scanf("%d", &numero);
    }
    
    return 0;
}