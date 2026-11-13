
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char cad[21], mayor[21] = "";
    char respuesta = 'S';
    size_t longitudMayor = 0;

    while (toupper((unsigned char)respuesta) == 'S') {
        printf("Ingrese una cadena: ");
        fgets(cad, sizeof(cad), stdin);
        cad[strcspn(cad, "\n")] = '\0';

        if (strlen(cad) > longitudMayor) {
            longitudMayor = strlen(cad);
            strcpy(mayor, cad);
        }

        printf("Desea continuar (S/N): ");
        scanf(" %c", &respuesta);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    printf("Cadena mas larga: %s\n", mayor);
    printf("Longitud: %zu\n", longitudMayor);

    return 0;
}
