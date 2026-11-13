
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *archivo, *nuevo;
    char cadenas[100][200];
    int n = 0, i;

    archivo = fopen("arc.txt", "w");
    if (archivo == NULL) return 1;

    fprintf(archivo, "Primera cadena\n");
    fprintf(archivo, "Segunda cadena\n");
    fprintf(archivo, "Tercera cadena\n");
    fprintf(archivo, "Cuarta cadena\n");
    fclose(archivo);

    archivo = fopen("arc.txt", "r");
    if (archivo == NULL) return 1;

    while (n < 100 &&
           fgets(cadenas[n], sizeof(cadenas[n]), archivo) != NULL)
    {
        n++;
    }

    fclose(archivo);

    nuevo = fopen("arc_invertido.txt", "w");
    if (nuevo == NULL) return 1;

    for (i = n - 1; i >= 0; i--)
    {
        fputs(cadenas[i], nuevo);
    }

    fclose(nuevo);

    printf("Archivo invertido:\n");

    for (i = n - 1; i >= 0; i--)
    {
        printf("%s", cadenas[i]);
    }

    return 0;
}
