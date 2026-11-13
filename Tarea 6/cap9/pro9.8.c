
#include <stdio.h>

typedef struct
{
    int matricula;
    float notas[3];
} Alumno;

int main()
{
    FILE *archivo, *nuevo;
    Alumno alumnos[100], aux;
    int n = 0, i, j;

    archivo = fopen("arc.dat", "w");
    if (archivo == NULL) return 1;

    fprintf(archivo, "51 8.7 6.7 8.9\n");
    fprintf(archivo, "15 7.8 7.6 5.8\n");
    fprintf(archivo, "11 7.8 9.0 9.9\n");
    fprintf(archivo, "32 8.8 9.9 9.7\n");
    fprintf(archivo, "96 8.9 9.1 9.9\n");
    fprintf(archivo, "29 9.3 9.6 9.8\n");

    fclose(archivo);

    archivo = fopen("arc.dat", "r");
    if (archivo == NULL) return 1;

    while (n < 100 &&
           fscanf(archivo, "%d %f %f %f",
                  &alumnos[n].matricula,
                  &alumnos[n].notas[0],
                  &alumnos[n].notas[1],
                  &alumnos[n].notas[2]) == 4)
    {
        n++;
    }

    fclose(archivo);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (alumnos[i].matricula > alumnos[j].matricula)
            {
                aux = alumnos[i];
                alumnos[i] = alumnos[j];
                alumnos[j] = aux;
            }
        }
    }

    nuevo = fopen("arc1.dat", "w");
    if (nuevo == NULL) return 1;

    printf("Alumnos ordenados:\n");

    for (i = 0; i < n; i++)
    {
        fprintf(nuevo, "%d %.1f %.1f %.1f\n",
                alumnos[i].matricula,
                alumnos[i].notas[0],
                alumnos[i].notas[1],
                alumnos[i].notas[2]);

        printf("%d %.1f %.1f %.1f\n",
               alumnos[i].matricula,
               alumnos[i].notas[0],
               alumnos[i].notas[1],
               alumnos[i].notas[2]);
    }

    fclose(nuevo);
    return 0;
}
