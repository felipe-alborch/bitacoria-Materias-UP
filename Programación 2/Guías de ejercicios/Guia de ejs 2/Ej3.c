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
int vectorConUsuariosConSaldoNegativo(int [], int [], float [], char [][20], char [][20], int, float [], int [], int [], char [][20], char [][20]);
void porcentajeClientesConSaldoMayorA100K(float [], int);
void insertarElemento(int [], int [], float [], char [][20], char [][20], int);

int main() {
    int numerosDeCuenta[10], tiposDeCuenta[10], datosCargados, cuentasNegativas[10], tiposCuentasNegativas[10], cuentasNegativasCargadas;
    float saldosDisponibles[10], saldosNegativos[10];
    char nombres[10][20], apellidos[10][20], apellidosNegativos[10][20], nombresNegativos[10][20];

    printf("\n\nCARGANDO DATOS...\n");
    datosCargados = cargarDatos(numerosDeCuenta, tiposDeCuenta, saldosDisponibles, nombres, apellidos);

    if(datosCargados > 0) {
        printf("\n\nORDENANDO LOS DATOS...");
        ordenarDatos(numerosDeCuenta, tiposDeCuenta, saldosDisponibles, nombres, apellidos, datosCargados);

        printf("\n\nMOSTRANDO LOS DATOS...\n");
        mostrarDatos(numerosDeCuenta, tiposDeCuenta, saldosDisponibles, nombres, apellidos, datosCargados);

        printf("\n\nBUSCANDO AL USUARIO CON MENOR SALDO...\n");
        cuentaConMenorSaldo(numerosDeCuenta, tiposDeCuenta, saldosDisponibles, nombres, apellidos, datosCargados);

        printf("\n\nARMANDO ARREGLOS DE LOS USUARIOS CON SALDO NEGATIVO...\n");
        cuentasNegativasCargadas = vectorConUsuariosConSaldoNegativo(numerosDeCuenta, tiposDeCuenta, saldosDisponibles, nombres, apellidos, datosCargados, saldosNegativos, cuentasNegativas, tiposCuentasNegativas, nombresNegativos, apellidosNegativos);
        mostrarDatos(cuentasNegativas, tiposCuentasNegativas, saldosNegativos, nombresNegativos, apellidosNegativos, cuentasNegativasCargadas);

        printf("\n\nCALCULANDO EL PORCENTAJE DE LOS CLIENTES CON SALDO DISPONIBLE MAYOR A 100.000$...\n");
        porcentajeClientesConSaldoMayorA100K(saldosDisponibles, datosCargados);

        if(datosCargados < 10) {
            printf("\n\nCARGANDO NUEVO ELEMENTO...\n");
            insertarElemento(numerosDeCuenta, tiposDeCuenta, saldosDisponibles, nombres, apellidos, datosCargados);
            printf("\n\nMOSTRANDO LOS NUEVOS DATOS...\n");
            mostrarDatos(numerosDeCuenta, tiposDeCuenta, saldosDisponibles, nombres, apellidos, datosCargados+1);
        }
        else {
            printf("NO HAY SUFICIENTE ESPACIO PARA AGREGAR UN NUEVO ELEMENTO.");
        }
    }
    else {
        printf("\n\nNO SE CARGARON DATOS.");
    }

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
        scanf("%s", nombre);

        printf("Introduzca el apellido de la persona: ");
        scanf("%s", apellido);
    
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
            printf("\nIntroduzca el valor del numero de cuenta: ");
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

int vectorConUsuariosConSaldoNegativo(int numerosDeCuenta[], int tiposDeCuenta[], float saldosDisponibles[], char nombres[][20], char apellidos[][20], int datosCargados, float saldosNegativos[], int cuentasNegativas[], int tiposCuentasNegativas[], char nombresNegativos[][20], char apellidosNegativos[][20]) {
    int contadorVectoresNegativos = 0;
    
    for(int i = 0; i < datosCargados; i++) {
        if(saldosDisponibles[i] < 0) {
            cuentasNegativas[contadorVectoresNegativos] = numerosDeCuenta[i];
            tiposCuentasNegativas[contadorVectoresNegativos] = tiposDeCuenta[i];
            saldosNegativos[contadorVectoresNegativos] = saldosDisponibles[i];
            strcpy(nombresNegativos[contadorVectoresNegativos], nombres[i]);
            strcpy(apellidosNegativos[contadorVectoresNegativos], apellidos[i]);

            contadorVectoresNegativos += 1;
        }
    }

    return contadorVectoresNegativos;
}

void porcentajeClientesConSaldoMayorA100K(float saldosDisponibles[], int datosCargados) {
    int clientesConSaldoMayorA100K = 0;

    for(int i = 0; i < datosCargados; i++) {
        if(saldosDisponibles[i] > 100000)
            clientesConSaldoMayorA100K += 1;
    }

    printf("El porcentaje de clientes con un saldo disponible mayor a 100.000$ es: %.2f%%", (clientesConSaldoMayorA100K * 100) / (float) datosCargados);
}

void insertarElemento(int numerosDeCuenta[], int tiposDeCuenta[], float saldosDisponibles[], char nombres[][20], char apellidos[][20], int datosCargados) {
    int numeroDeCuenta, tipoDeCuenta, contador = 0;
    float saldoDisponible;
    char nombre[20], apellido[20];
    
    do {
        printf("Introduzca el valor del numero de cuenta: ");
        scanf("%d", &numeroDeCuenta);

        if(numeroDeCuenta < 0)
            printf("\nEl numero de cuenta es invalido.\n");
    } while (numeroDeCuenta < 0);

    printf("Introduzca el nombre de la persona: ");
    scanf("%s", nombre);

    printf("Introduzca el apellido de la persona: ");
    scanf("%s", apellido);

    do {
        printf("Introduzca el tipo de cuenta: ");
        scanf("%d", &tipoDeCuenta);

        if(tipoDeCuenta != 1 && tipoDeCuenta != 2)
            printf("\nEl tipo de cuenta es invalido.\n");
    } while (tipoDeCuenta != 1 && tipoDeCuenta != 2);

    printf("Introduzca el saldo disponible de la cuenta: ");
    scanf("%f", &saldoDisponible);

    while(numerosDeCuenta[contador] < numeroDeCuenta && contador < datosCargados)
        contador += 1;

    if(contador < datosCargados) {
        for(int i = datosCargados; i > contador; i--) {
            numerosDeCuenta[i] = numerosDeCuenta[i-1];
            tiposDeCuenta[i] = tiposDeCuenta[i-1];
            saldosDisponibles[i] = saldosDisponibles[i-1];
            strcpy(nombres[i], nombres[i-1]);
            strcpy(apellidos[i], apellidos[i-1]);
        }

        numerosDeCuenta[contador] = numeroDeCuenta;
        tiposDeCuenta[contador] = tipoDeCuenta;
        saldosDisponibles[contador] = saldoDisponible;
        strcpy(nombres[contador], nombre);
        strcpy(apellidos[contador], apellido);
    }
    else {
        numerosDeCuenta[datosCargados] = numeroDeCuenta;
        tiposDeCuenta[datosCargados] = tipoDeCuenta;
        saldosDisponibles[datosCargados] = saldoDisponible;
        strcpy(nombres[datosCargados], nombre);
        strcpy(apellidos[datosCargados], apellido);
    }
}