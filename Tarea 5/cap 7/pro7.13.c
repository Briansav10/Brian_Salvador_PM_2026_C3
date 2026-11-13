
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char ARC[10][51];
    int i, j, palabras, dentro;

    for (i = 0; i < 10; i++) {
        printf("Ingrese cadena %d: ", i + 1);
        fgets(ARC[i], sizeof(ARC[i]), stdin);
        ARC[i][strcspn(ARC[i], "\n")] = '\0';
    }

    for (i = 0; i < 10; i++) {
        palabras = 0;
        dentro = 0;

        for (j = 0; ARC[i][j] != '\0'; j++) {
            if (isspace((unsigned char)ARC[i][j])) {
                dentro = 0;
            } else if (!dentro) {
                palabras++;
                dentro = 1;
            }
        }

        printf("Cadena %d: %d palabras\n",
               i + 1, palabras);
    }

    return 0;
}
