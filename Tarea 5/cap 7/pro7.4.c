
#include <stdio.h>

int main(void) {
    int dia, mes, anio;
    char cad[30];

    const char *meses[] = {
        "", "Enero", "Febrero", "Marzo",
        "Abril", "Mayo", "Junio", "Julio",
        "Agosto", "Septiembre", "Octubre",
        "Noviembre", "Diciembre"
    };

    printf("Ingrese la fecha (dd/mm/aa): ");
    scanf("%29s", cad);

    if (sscanf(cad, "%d/%d/%d", &dia, &mes, &anio) != 3 ||
        dia < 1 || dia > 31 || mes < 1 || mes > 12 ||
        anio < 0 || anio > 99) {
        printf("Fecha invalida.\n");
        return 1;
    }

    if (anio <= 49)
        anio += 2000;
    else
        anio += 1900;

    printf("%02d de %s de %d\n",
           dia, meses[mes], anio);

    return 0;
}
