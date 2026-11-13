
#include <stdio.h>
#include <string.h>

int main(void) {
    char cad[51];
    char *palabras[30];
    int n = 0, i;

    printf("Ingrese una cadena: ");
    fgets(cad, sizeof(cad), stdin);

    char *p = strtok(cad, " \t\n");

    while (p != NULL && n < 30) {
        palabras[n++] = p;
        p = strtok(NULL, " \t\n");
    }

    printf("Cadena invertida: ");

    for (i = n - 1; i >= 0; i--) {
        printf("%s", palabras[i]);

        if (i > 0)
            printf(" ");
    }

    printf("\n");
    return 0;
}
