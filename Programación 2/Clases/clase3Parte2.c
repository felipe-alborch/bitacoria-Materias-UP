/*
Ingresar un texto caracter a caracater, terminando en punto y mostrarlo intercalando entre mayusculas y minusculas,
con solo un espacio de separación.
*/

#include <stdio.h>

int main() {
    int cantLetras = 1;

    printf("Ingresa un texto: ");

    char letra = getchar();

    while (letra != '.') {
        if (letra != ' ') {
            if (cantLetras % 2 != 0) {
                // Queremos minúscula
                if (letra >= 'A' && letra <= 'Z')
                    letra += 32;
            }
            else {
                // Queremos mayúscula
                if (letra >= 'a' && letra <= 'z')
                    letra -= 32;
            }

            cantLetras++;
        }

        putchar(letra);

        letra = getchar();
    }

    return 0;
}