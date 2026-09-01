/*
Ejercicio 1 — Primer contacto con un puntero

Declarar una variable entera y un puntero que apunte a ella. Mostrar:

 A) El valor de la variable.
 B) La dirección de la variable.
 C) El contenido de p.
 D) El valor apuntado por p.
 E) La dirección del propio puntero.

Por ejemplo:

int numero = 15;
int *p = &numero;
*/

#include <stdio.h>

int main()
{
    int numero = 10;
    int *puntero = &numero;

    // A
    printf("El valor de la variable 'numero' es: %d\n", numero);

    // B
    printf("La direccion de la variable 'numero' es: %p\n", (void *)&numero);

    // C
    printf("El contenido de la variable 'puntero' es: %p\n", (void *)puntero);

    // D
    printf("El valor apuntado por 'puntero' es: %d\n", *puntero);

    // E
    printf("La direccion del propio puntero es: %p\n", (void *)&puntero);

    return 0;
}


/*
Partimos de int numero = 10; y int *puntero = &numero;. Con esto declaramos un puntero a int y guardamos en él la dirección de memoria de numero. 
Por eso, puntero y &numero representan la misma dirección, mientras que *puntero accede al valor almacenado en esa dirección, es decir, 10. 
En cambio, &puntero representa la dirección de memoria donde está almacenado el propio puntero.

Al mostrar estos datos con printf, usamos %d cuando queremos mostrar un valor entero, como numero o *puntero, 
y %p cuando queremos mostrar una dirección, como puntero, &numero o &puntero.

Cuando usamos %p, escribimos por ejemplo printf("%p", (void *)puntero);. 
El (void *) es un casteo: le indicamos a C que trate esa dirección como un puntero genérico de tipo void *, 
que es el tipo que %p espera recibir. Esto no modifica el puntero ni su contenido; permite imprimir la dirección de la forma correcta.
*/