
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char ARC[10][51];
    int i, j, cantidad, mayor = -1, posicion = 0;

    for (i = 0; i < 10; i++) {
        printf("Ingrese cadena %d: ", i + 1);
        fgets(ARC[i], sizeof(ARC[i]), stdin);
        ARC[i][strcspn(ARC[i], "\n")] = '\0';
    }

    for (i = 0; i < 10; i++) {
        cantidad = 0;

        for (j = 0; ARC[i][j] != '\0'; j++) {
            if (isupper((unsigned char)ARC[i][j])) {
                cantidad++;
            }
        }

        if (cantidad > mayor) {
            mayor = cantidad;
            posicion = i;
        }
    }

    printf("Cadena con mas mayusculas: %s\n", ARC[posicion]);
    printf("Cantidad: %d\n", mayor);

    return 0;
}
