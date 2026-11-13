
#include <stdio.h>
#include <string.h>

int main(void) {
    char cad1[51], cad2[51];
    char *palabras1[30], *palabras2[30];
    int n1 = 0, n2 = 0, i;

    printf("Ingrese la primera cadena: ");
    fgets(cad1, sizeof(cad1), stdin);

    printf("Ingrese la segunda cadena: ");
    fgets(cad2, sizeof(cad2), stdin);

    char *p = strtok(cad1, " \t\n");
    while (p != NULL && n1 < 30) {
        palabras1[n1++] = p;
        p = strtok(NULL, " \t\n");
    }

    p = strtok(cad2, " \t\n");
    while (p != NULL && n2 < 30) {
        palabras2[n2++] = p;
        p = strtok(NULL, " \t\n");
    }

    printf("Resultado: ");

    for (i = 0; i < n1 || i < n2; i++) {
        if (i < n1)
            printf("%s ", palabras1[i]);

        if (i < n2)
            printf("%s ", palabras2[i]);
    }

    printf("\n");
    return 0;
}
