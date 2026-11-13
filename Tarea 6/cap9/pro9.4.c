
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *archivo;
    char cad[51], linea[300];
    int contador = 0, i;

    archivo = fopen("arc2.txt", "w");
    if (archivo == NULL) return 1;

    fprintf(archivo, "sasassassas\n");
    fprintf(archivo, "sassassas\n");
    fprintf(archivo, "sasaasassas\n");
    fclose(archivo);

    printf("Ingrese la cadena a buscar: ");
    scanf("%50s", cad);

    archivo = fopen("arc2.txt", "r");
    if (archivo == NULL) return 1;

    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        for (i = 0; linea[i] != '\0'; i++)
        {
            if (strncmp(&linea[i], cad, strlen(cad)) == 0)
                contador++;
        }
    }

    printf("La cadena aparece %d veces.\n", contador);

    fclose(archivo);
    return 0;
}
