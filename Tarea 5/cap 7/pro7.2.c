
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char cad[51];
    int i;

    printf("Ingrese una cadena: ");
    fgets(cad, sizeof(cad), stdin);
    cad[strcspn(cad, "\n")] = '\0';

    printf("Digitos en posiciones pares: ");

    for (i = 1; cad[i] != '\0'; i += 2) {
        if (isdigit((unsigned char)cad[i])) {
            printf("%c", cad[i]);
        }
    }

    printf("\n");
    return 0;
}
