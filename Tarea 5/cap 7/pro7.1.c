
#include <stdio.h>
#include <string.h>

int main(void) {
    char cad[51];
    int i;

    printf("Ingrese una cadena: ");
    fgets(cad, sizeof(cad), stdin);
    cad[strcspn(cad, "\n")] = '\0';

    printf("Caracteres en posiciones impares: ");
    for (i = 0; cad[i] != '\0'; i += 2) {
        printf("%c", cad[i]);
    }

    printf("\n");
    return 0;
}
