
#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *archivo;
    int letra, palabras = 0, dentro = 0;

    archivo = fopen("arc.txt", "w");
    if (archivo == NULL) return 1;

    fprintf(archivo, "Soy liceista\n");
    fprintf(archivo, "A por la 25\n");
    fclose(archivo);

    archivo = fopen("arc.txt", "r");
    if (archivo == NULL) return 1;

    while ((letra = fgetc(archivo)) != EOF)
    {
        if (isspace((unsigned char)letra))
        {
            dentro = 0;
        }
        else if (dentro == 0)
        {
            palabras++;
            dentro = 1;
        }
    }

    printf("Cantidad de palabras: %d\n", palabras);

    fclose(archivo);
    return 0;
}
