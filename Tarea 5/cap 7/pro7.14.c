
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char ARC[20][81];
    int frecuencia[81] = {0};
    int i, j, longitud, maximo = 0;

    for (i = 0; i < 20; i++) {
        printf("Ingrese cadena %d: ", i + 1);
        fgets(ARC[i], sizeof(ARC[i]), stdin);
        ARC[i][strcspn(ARC[i], "\n")] = '\0';
    }

    for (i = 0; i < 20; i++) {
        longitud = 0;

        for (j = 0; ; j++) {
            unsigned char c = (unsigned char)ARC[i][j];

            if (isalnum(c) || c >= 128) {
                longitud++;
            } else if (longitud > 0) {
                frecuencia[longitud]++;

                if (longitud > maximo)
                    maximo = longitud;

                longitud = 0;
            }

            if (c == '\0')
                break;
        }
    }

    printf("\nLongitud\tFrecuencia\n");

    for (i = 1; i <= maximo; i++) {
        printf("%d\t\t%d\n", i, frecuencia[i]);
    }

    return 0;
}
