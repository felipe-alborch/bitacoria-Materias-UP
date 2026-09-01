#include <stdio.h>

int main()
{
    int numero = 10;
    int *p = &numero;

    printf("numero: %d\n", numero);
    printf("&numero: %p\n", (void *)&numero);
    printf("p: %p\n", (void *)p);
    printf("*p: %d\n", *p);
    printf("&p: %p\n", (void *)&p);

    return 0;
}