
#include <stdio.h>

int main()
{
    FILE *archivo;
    char cadena[200];
    int i, longitud, mayor = 0;

    archivo = fopen("arc1.txt", "w");
    if (archivo == NULL) return 1;

    fprintf(archivo, "Soy liceista\n");
    fprintf(archivo, "A por la 25\n");
    fprintf(archivo, "Los Tigres del Licey\n");
    fclose(archivo);

    archivo = fopen("arc1.txt", "r");
    if (archivo == NULL) return 1;

    while (fgets(cadena, sizeof(cadena), archivo) != NULL)
    {
        longitud = 0;

        for (i = 0; cadena[i] != '\0'; i++)
        {
            if (cadena[i] != '\n')
                longitud++;
        }

        if (longitud > mayor)
            mayor = longitud;
    }

    printf("Longitud de la cadena mas larga: %d\n", mayor);

    fclose(archivo);
    return 0;
}
