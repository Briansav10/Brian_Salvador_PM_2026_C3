
#include <stdio.h>

typedef struct
{
    int matricula;
    char nombre[30];
    int carrera;
    float promedio;
} Alumno;

int main()
{
    FILE *archivo, *nuevo;
    Alumno alumnos[] = {
        {105, "Juan", 1, 8.5},
        {104, "Maria", 2, 9.2},
        {104, "Maria", 2, 9.2},
        {103, "Pedro", 1, 7.8},
        {102, "Ana", 3, 9.5},
        {102, "Ana", 3, 9.5}
    };

    Alumno actual;
    int i, anterior = -1;

    archivo = fopen("ad5.dat", "wb");
    if (archivo == NULL) return 1;

    fwrite(alumnos, sizeof(Alumno), 6, archivo);
    fclose(archivo);

    archivo = fopen("ad5.dat", "rb");
    nuevo = fopen("ad6.dat", "wb");

    if (archivo == NULL || nuevo == NULL)
    {
        printf("Error al abrir archivos.\n");
        if (archivo != NULL) fclose(archivo);
        if (nuevo != NULL) fclose(nuevo);
        return 1;
    }

    printf("Alumnos sin repetir:\n");

    while (fread(&actual, sizeof(Alumno), 1, archivo) == 1)
    {
        if (actual.matricula != anterior)
        {
            fwrite(&actual, sizeof(Alumno), 1, nuevo);

            printf("%d %s %.2f\n",
                   actual.matricula,
                   actual.nombre,
                   actual.promedio);

            anterior = actual.matricula;
        }
    }

    fclose(archivo);
    fclose(nuevo);

    return 0;
}
