/*
Ingresar la edad y sueldo de los empleados de una empresa hasta que ambas sean cero. Calcular y mostrar:
a) El promedio de edad de los que ganan más de $10000
b) El sueldo de aquellas personas mayores a 58 años, sabiendo que cobran un plus del 5% de su sueldo.
c) El porcentaje de empleados cuyo sueldo es menor a 15000, que está entre 15000 y 20000, y mayor a 20000.
*/

#include <stdio.h>

float calcularPorcentaje(int, int);

int main() {
    // Datos de entrada
    int edad = 0, sueldo = 0;

    // Punto A
    int sumatoriaEdadEmpleadosQueGananMasDe10000 = 0, cantEmpleadosQueGananMasDe10000 = 0;

    // Punto C
    int empleadosQueGananMenosDe15000 = 0, empleadosQueGananEntre15000y20000 = 0, empleadosQueGananMasDe20000 = 0;

    // General
    int cantEmpleados = 0;

    do {
        printf("Ingrese la edad de la persona: ");
        scanf("%d", &edad);

        if(edad < 0) {
            printf("Ingrese una edad valida.\n");
        }
    } while (edad < 0);

    do {
        printf("Ingrese el sueldo de la persona: ");
        scanf("%d", &sueldo);

        if(sueldo < 0) {
            printf("Ingrese un sueldo valido.\n");
        }
    } while (sueldo < 0);
    
    while (edad != 0 || sueldo != 0) {
    
        if(sueldo > 10000) {
            sumatoriaEdadEmpleadosQueGananMasDe10000 += edad;
            cantEmpleadosQueGananMasDe10000 += 1;
        }

        if(edad > 58) {
            printf("\nEl sueldo con el plus correspondiente queda en: %.2f\n", sueldo * 1.05);
        }

        if(sueldo < 15000) {
            empleadosQueGananMenosDe15000 += 1;
        }
        else if(sueldo < 20000) {
            empleadosQueGananEntre15000y20000 += 1;
        }
        else {
            empleadosQueGananMasDe20000 += 1;
        }

        cantEmpleados += 1;

        do {
            printf("Ingrese la edad de la persona: ");
            scanf("%d", &edad);

            if(edad < 0) {
                printf("Ingrese una edad valida.\n");
            }
        } while (edad < 0);

        do {
            printf("Ingrese el sueldo de la persona: ");
            scanf("%d", &sueldo);

            if(sueldo < 0) {
                printf("Ingrese un sueldo valido.\n");
            }
        } while (sueldo < 0);
    }
    
    if(cantEmpleados > 0) {
        if (cantEmpleadosQueGananMasDe10000 > 0) {
            float promedio = (float) sumatoriaEdadEmpleadosQueGananMasDe10000 / cantEmpleadosQueGananMasDe10000;
            printf("\nEl promedio de edad de los empleados que ganan mas de 10000 es: %.2f",promedio);
        } else {
            printf("\nNo se ingresaron empleados que ganen mas de 10000.");    
        }

        printf("\n\nEl porcentaje de empleados que ganan menos de 15000$ es: %.2f%%", calcularPorcentaje(cantEmpleados, empleadosQueGananMenosDe15000));
        printf("\nEl porcentaje de empleados que ganan entre 15000$ y 20000$ es: %.2f%%", calcularPorcentaje(cantEmpleados, empleadosQueGananEntre15000y20000));
        printf("\nEl porcentaje de empleados que ganan mas de 20000$ es: %.2f%%", calcularPorcentaje(cantEmpleados, empleadosQueGananMasDe20000));
    }
    else {
        printf("\n\nNo se ingresaron empleados.");
    }
    
    return 0;
}

float calcularPorcentaje(int cantEmpleados, int cantEmpleadosConSueldoX) {
    float porcentaje = (cantEmpleadosConSueldoX * 100) / (float) cantEmpleados;

    return porcentaje;
}