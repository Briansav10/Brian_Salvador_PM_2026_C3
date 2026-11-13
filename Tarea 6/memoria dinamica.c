
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *archivo;
    char *texto;
    char *temp;
    char mensaje[] = "Soy liceista.\nA por la 25!";
    int i = 0;
    int letra;

    archivo = fopen("texto.txt", "w");

    if (archivo == NULL)
    {
        printf("Error al crear el archivo.\n");
        return 1;
    }

    fprintf(archivo, "%s", mensaje);
    fclose(archivo);

    archivo = fopen("texto.txt", "r");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    texto = (char *)malloc(1);

    if (texto == NULL)
    {
        fclose(archivo);
        return 1;
    }

    while ((letra = fgetc(archivo)) != EOF)
    {
        temp = (char *)realloc(texto, i + 2);

        if (temp == NULL)
        {
            free(texto);
            fclose(archivo);
            return 1;
        }

        texto = temp;
        texto[i] = letra;
        i++;
    }

    texto[i] = '\0';

    printf("%s\n", texto);

    free(texto);
    fclose(archivo);

    return 0;
}
