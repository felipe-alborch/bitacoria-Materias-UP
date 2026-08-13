/*
Ingresar los datos de las cuentas de distintos clientes de un banco. Ellos son:

 - Nro. de cuenta
 - Nombre y Apellido
 - Tipo de cuenta (1. caja de ahorro, 2. cuenta corriente)
 - Saldo.

La carga de datos finaliza cuando el número de cuenta es 0. Calcular y mostrar:

a) Los datos ordenados de menor a mayor por número de cuenta
b) El nombre y apellido y el tipo de cuenta con menor saldo.
c) Generar un vector con todos los datos de aquellos clientes que tienen saldo negativo. Mostrarlo.
d) El porcentaje de clientes que tiene un saldo en la cuenta mayor a$100.000.
e) Se ingresan los datos de una cuenta nueva a insertarla en el vector
   de tal manera que la información siga ordenada por número de cuenta. (desplazando los elementos a derecha).
*/

#include <stdio.h>
#include <string.h>

int cargarDatos(int [], int [], float [], char [][20], char [][20]);
void mostrarDatos(int [], int [], float [], char [][20], char [][20], int);
void ordenarDatos(int [], int [], float [], char [][20], char [][20], int);
void cuentaConMenorSaldo(int [], int [], float [], char [][20], char [][20], int);

int main() {
    int numerosDeCuenta[5], tiposDeCuenta[5], datosCargados;
    float saldosDisponibles[5];
    char nombres[5][20], apellidos[5][20];

    printf("\n\nCARGANDO DATOS...\n");
    datosCargados = cargarDatos(numerosDeCuenta, tiposDeCuenta, saldosDisponibles, nombres, apellidos);

    printf("\n\nORDENANDO LOS DATOS...");
    ordenarDatos(numerosDeCuenta, tiposDeCuenta, saldosDisponibles, nombres, apellidos, datosCargados);

    printf("\n\nMOSTRANDO LOS DATOS...\n");
    mostrarDatos(numerosDeCuenta, tiposDeCuenta, saldosDisponibles, nombres, apellidos, datosCargados);

    printf("\n\nBUSCANDO AL USUARIO CON MENOR SALDO...\n");
    cuentaConMenorSaldo(numerosDeCuenta, tiposDeCuenta, saldosDisponibles, nombres, apellidos, datosCargados);
    
    return 0;
}

int cargarDatos(int numerosDeCuenta[], int tiposDeCuenta[], float saldosDisponibles[], char nombres[][20], char apellidos[][20]) {
    int numeroDeCuenta, tipoDeCuenta, i = 0;
    float saldoDisponible;
    char nombre[20], apellido[20];
    
    do {
        printf("Introduzca el valor del numero de cuenta: ");
        scanf("%d", &numeroDeCuenta);

        if(numeroDeCuenta < 0)
            printf("\nEl numero de cuenta es invalido.\n");
    } while (numeroDeCuenta < 0);

    while (numeroDeCuenta != 0) {
        printf("Introduzca el nombre de la persona: ");
        scanf("%19s", &nombre);

        printf("Introduzca el apellido de la persona: ");
        scanf("%19s", &apellido);
    
        do {
            printf("Introduzca el tipo de cuenta: ");
            scanf("%d", &tipoDeCuenta);

            if(tipoDeCuenta != 1 && tipoDeCuenta != 2)
                printf("\nEl tipo de cuenta es invalido.\n");
        } while (tipoDeCuenta != 1 && tipoDeCuenta != 2);

        printf("Introduzca el saldo disponible de la cuenta: ");
        scanf("%f", &saldoDisponible);
        
        numerosDeCuenta[i] = numeroDeCuenta;
        tiposDeCuenta[i] = tipoDeCuenta;
        saldosDisponibles[i] = saldoDisponible;
        strcpy(nombres[i], nombre);
        strcpy(apellidos[i], apellido);

        i += 1;

        do {
            printf("Introduzca el valor del numero de cuenta: ");
            scanf("%d", &numeroDeCuenta);

            if(numeroDeCuenta < 0)
                printf("\nEl numero de cuenta es invalido.\n");
        } while (numeroDeCuenta < 0);
    }

    return i;
}

void mostrarDatos(int numerosDeCuenta[], int tiposDeCuenta[], float saldosDisponibles[], char nombres[][20], char apellidos[][20], int datosCargados) {
    for(int i = 0; i < datosCargados; i++) {
        printf("Numero de cuenta: %d\n", numerosDeCuenta[i]);
        printf("Tipo de cuenta: %d\n", tiposDeCuenta[i]);
        printf("Nombre y apellido: %s %s\n", nombres[i], apellidos[i]);
        printf("Saldo: %.2f\n\n", saldosDisponibles[i]);
    }
}

void ordenarDatos(int numerosDeCuenta[], int tiposDeCuenta[], float saldosDisponibles[], char nombres[][20], char apellidos[][20], int datosCargados) {
    int aux;
    char auxChar[20];

    for(int i = 0; i < datosCargados; i++) {
        for(int j = 0; j < datosCargados - 1; j++) {
            if(numerosDeCuenta[j] > numerosDeCuenta[j+1]) {
                aux = numerosDeCuenta[j];
                numerosDeCuenta[j] = numerosDeCuenta[j+1];
                numerosDeCuenta[j+1] = aux;

                aux = tiposDeCuenta[j];
                tiposDeCuenta[j] = tiposDeCuenta[j+1];
                tiposDeCuenta[j+1] = aux;

                aux = saldosDisponibles[j];
                saldosDisponibles[j] = saldosDisponibles[j+1];
                saldosDisponibles[j+1] = aux;

                strcpy(auxChar, nombres[j]);
                strcpy(nombres[j], nombres[j+1]);
                strcpy(nombres[j+1], auxChar);

                strcpy(auxChar, apellidos[j]);
                strcpy(apellidos[j], apellidos[j+1]);
                strcpy(apellidos[j+1], auxChar);
            }
        }
    }
}

void cuentaConMenorSaldo(int numerosDeCuenta[], int tiposDeCuenta[], float saldosDisponibles[], char nombres[][20], char apellidos[][20], int datosCargados) {
    int posMenor = 0;
    
    for(int i = 1; i < datosCargados; i++) {
        if(saldosDisponibles[i] < saldosDisponibles[posMenor]) 
            posMenor = i;
    }

    printf("La persona con menor saldo en su cuenta es: %s %s\n", nombres[posMenor], apellidos[posMenor]);
    printf("El tipo de la cuenta [%d] es: %d\n", numerosDeCuenta[posMenor], tiposDeCuenta[posMenor]);
    printf("El saldo disponible es: %.2f", saldosDisponibles[posMenor]);
}

void vectorConUsuariosConSaldoNegativo(int numerosDeCuenta[], int tiposDeCuenta[], float saldosDisponibles[], char nombres[][20], char apellidos[][20], int datosCargados, float saldosNegativos[], int cuentasNegativas[], int tiposCuentasNegativas[], char nombresNegativos[][20], char apellidosNegativos[][20]) {
    int contadorVectoresNegativos = 0;
    
    for(int i = 0; i < datosCargados; i++) {
        if(saldosDisponibles[i] < 0) {
            cuentasNegativas[contadorVectoresNegativos] = numerosDeCuenta[i];
            tiposCuentasNegativas[contadorVectoresNegativos] = tiposDeCuenta[i];
            saldosNegativos[contadorVectoresNegativos] = saldosDisponibles[i];
            strcpy(nombresNegativos[contadorVectoresNegativos], nombres[i]);
            strcpy(apellidosNegativos[contadorVectoresNegativos], apellidos[i]);
        }
    }
}