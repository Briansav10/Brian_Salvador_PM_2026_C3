
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char cad[51];
    int i, inicio = 1;

    printf("Ingrese una cadena: ");
    fgets(cad, sizeof(cad), stdin);
    cad[strcspn(cad, "\n")] = '\0';

    for (i = 0; cad[i] != '\0'; i++) {
        if (isspace((unsigned char)cad[i])) {
            inicio = 1;
        } else {
            if (inicio) {
                cad[i] = toupper((unsigned char)cad[i]);
            }
            inicio = 0;
        }
    }

    printf("Resultado: %s\n", cad);
    return 0;
}
