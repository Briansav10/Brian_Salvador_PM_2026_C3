
#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *archivo;
    int letra;
    int a = 0, e = 0, i = 0, o = 0, u = 0;

    archivo = fopen("arc.txt", "w");
    if (archivo == NULL) return 1;

    fprintf(archivo, "Soy liceista de corazon.\n");
    fprintf(archivo, "A por la 25.\n");
    fclose(archivo);

    archivo = fopen("arc.txt", "r");
    if (archivo == NULL) return 1;

    while ((letra = fgetc(archivo)) != EOF)
    {
        letra = tolower((unsigned char)letra);

        if (letra == 'a') a++;
        if (letra == 'e') e++;
        if (letra == 'i') i++;
        if (letra == 'o') o++;
        if (letra == 'u') u++;
    }

    printf("a: %d\n", a);
    printf("e: %d\n", e);
    printf("i: %d\n", i);
    printf("o: %d\n", o);
    printf("u: %d\n", u);

    fclose(archivo);
    return 0;
}
