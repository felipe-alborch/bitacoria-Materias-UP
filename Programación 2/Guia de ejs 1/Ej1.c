/*
Calcular el indice de masa corporal ingresando el peso de una persona en kilos y su
estatura en metros. Este indice se obtiene realizando el cociente entre el peso y el
cuadrado de la estatura
*/

#include <stdio.h>

int main() {
    float imc = 0, altura = 0, peso = 0;

    printf("Ingrese su peso: ");
    scanf("%f", &peso);

    printf("\nIngrese su altura: ");
    scanf("%f", &altura);
    
    imc = peso / (altura * altura);
    printf("\nSu IMC es: %f", imc);
    
    return 0;
}