/* 
Dado 5 nombres de alumnos y sus notas. Calcular
 - Quien es el abanderado (el de mayor nota)
 - El abanderado es Lucas?
*/

#include <stdio.h>
#include <string.h>

void cargarArreglos(int [], char [][20]);
void calcularAbanderado(int [], char [][20]);

int main() {
    int notas[5];
    char nombres[5][20];

    printf("\nCARGANDO ARREGLOS...\n");
    cargarArreglos(notas, nombres);

    printf("\n\nCALCULANDO ABANDERADO...\n");
    calcularAbanderado(notas, nombres);
    
    return 0;
}

void cargarArreglos(int notas[], char nombres[][20]) {
    char nombre2[80];
    
    for(int i = 0; i < 5; i++) {
        do {
            printf("Ingresa una nota: ");
            scanf("%d", &notas[i]);
        } while(notas[i] < 0 || notas[i] > 10);

        do {
            printf("Ingresa el nombre del alumno: ");
            scanf("%s", nombre2);

            if(strlen(nombre2) > 20)
                printf("Ingresa un nombre de, como mucho, 19 caracteres.\n");
        } while(strlen(nombre2) < 20);
        

        strcpy(nombres[i], nombre2);
    }
}

void calcularAbanderado(int notas[], char nombres[][20]) {
    char abanderado[20];
    int notaMaxima = notas[0];

    strcpy(abanderado, nombres[0]);
    
    for(int i = 0; i < 5; i++) {
        if(notas[i] > notaMaxima) {
            notaMaxima = notas[i];
            strcpy(abanderado, nombres[i]);
        }
    }

    printf("\nEl abanderado es %s, con nota: %d", abanderado, notaMaxima);

    if((strcmp(abanderado, "Lucas") == 0) || (strcmp(abanderado, "lucas")))
        printf("\nEL ABANDERADO ES LUCAS!!\n");
    else
        printf("\nEL ABANDERADO NO ES LUCAS.\n");
}