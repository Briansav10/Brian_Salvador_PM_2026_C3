
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(void) {
    char cad[51];
    char respuesta = 'S';
    int dia, mes, anio;
    time_t ahora = time(NULL);
    struct tm *fecha = localtime(&ahora);

    if (fecha == NULL) {
        printf("No se pudo obtener la fecha.\n");
        return 1;
    }

    printf("Fecha actual: %02d/%02d/%04d\n",
           fecha->tm_mday,
           fecha->tm_mon + 1,
           fecha->tm_year + 1900);

    while (toupper((unsigned char)respuesta) == 'S') {
        printf("Ingrese fecha y texto: ");
        fgets(cad, sizeof(cad), stdin);

        if (sscanf(cad, "%d/%d/%d", &dia, &mes, &anio) == 3) {
            if (dia == fecha->tm_mday &&
                mes == fecha->tm_mon + 1 &&
                anio == fecha->tm_year + 1900) {
                printf("Coincide: %s", cad);
            }
        }

        printf("Desea continuar (S/N): ");
        scanf(" %c", &respuesta);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    return 0;
}

