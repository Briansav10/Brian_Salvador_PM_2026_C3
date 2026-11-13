
#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *archivo;
    int anterior = 0, actual;
    int errores = 0;

    archivo = fopen("doc.dat", "w");
    if (archivo == NULL) return 1;

    fprintf(archivo, "El campo es amplio.\n");
    fprintf(archivo, "Un enbase tiene un error.\n");
    fprintf(archivo, "El invierno es bonito.\n");
    fclose(archivo);

    archivo = fopen("doc.dat", "r");
    if (archivo == NULL) return 1;

    while ((actual = fgetc(archivo)) != EOF)
    {
        actual = tolower((unsigned char)actual);

        if ((anterior == 'n' && actual == 'b') ||
            (anterior == 'n' && actual == 'p') ||
            (anterior == 'm' && actual == 'v'))
        {
            printf("Error ortografico: %c%c\n",
                   anterior, actual);
            errores++;
        }

        anterior = actual;
    }

    printf("Total de errores: %d\n", errores);

    fclose(archivo);
    return 0;
}
