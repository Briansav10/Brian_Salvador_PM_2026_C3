
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char ARC[10][51];
    int i, j, vocales, mayor = -1, posicion = 0;

    for (i = 0; i < 10; i++) {
        printf("Ingrese cadena %d: ", i + 1);
        fgets(ARC[i], sizeof(ARC[i]), stdin);
        ARC[i][strcspn(ARC[i], "\n")] = '\0';
    }

    for (i = 0; i < 10; i++) {
        vocales = 0;

        for (j = 0; ARC[i][j] != '\0'; j++) {
            char c = tolower((unsigned char)ARC[i][j]);

            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u') {
                vocales++;
            }
        }

        if (vocales > mayor) {
            mayor = vocales;
            posicion = i;
        }
    }

    printf("Cadena con mas vocales: %s\n", ARC[posicion]);
    printf("Cantidad de vocales: %d\n", mayor);

    return 0;
}
