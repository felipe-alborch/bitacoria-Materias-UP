/*
Ejercicio 2 — Modificar mediante un puntero

Pedir al usuario un número entero. Crear un puntero que apunte a esa variable y, utilizando únicamente el puntero, duplicar el valor.
*/

#include <stdio.h>

void duplicarValor(int *);

int main() {
    int numero;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    duplicarValor(&numero);
    
    printf("El nuevo valor del numero es: %d", numero);
    
    return 0;
}

void duplicarValor(int *numero) {
    *numero = *numero * 2;
}

/*
Primero se solicita un número y se almacena normalmente en la variable numero mediante scanf. 
Luego llamamos a duplicarValor(&numero). Utilizamos &numero porque no queremos enviar solamente el valor, 
sino la dirección de memoria donde está almacenado, permitiendo que la función pueda modificar la variable original.

La función recibe esa dirección mediante el parámetro int *numero. Esto significa que, dentro de la función, numero es un puntero a un entero. 
Para acceder al valor que se encuentra en la dirección recibida utilizamos *numero. 
Por eso hacemos *numero = *numero * 2: obtenemos el valor original, 
lo multiplicamos por dos y guardamos el resultado nuevamente en la misma dirección.

De esta manera, si en el main teníamos numero = 5, la función recibe su dirección y modifica directamente su contenido a 10. 
Cuando volvemos al main, numero ya vale 10. 
La idea principal del ejercicio es que pasar una dirección a una función mediante un puntero permite modificar la variable original, 
en lugar de trabajar solamente con una copia de su valor.
*/