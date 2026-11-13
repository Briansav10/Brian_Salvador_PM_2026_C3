
#include <stdio.h>

typedef struct
{
    char calle[40];
    int numero;
    char colonia[40];
    char codigoPostal[15];
    char ciudad[40];
    char telefono[20];
} Domicilio;

typedef struct
{
    int clave;
    char nombre[50];
    int edad;
    char sexo;
    int condicion;
    Domicilio domicilio;
} Paciente;

int main()
{
    FILE *archivo;
    Paciente pacientes[5] = {
        {1, "Juan Perez", 25, 'M', 2,
         {"Central", 10, "Norte", "10001", "Quito", "111111"}},

        {2, "Maria Lopez", 35, 'F', 3,
         {"Sur", 20, "Centro", "10002", "Quito", "222222"}},

        {3, "Pedro Ruiz", 65, 'M', 4,
         {"Este", 30, "Norte", "10003", "Quito", "333333"}},

        {4, "Ana Gomez", 18, 'F', 1,
         {"Oeste", 40, "Sur", "10004", "Quito", "444444"}},

        {5, "Luis Diaz", 82, 'M', 5,
         {"Principal", 50, "Centro", "10005", "Quito", "555555"}}
    };

    Paciente p;
    int hombres = 0, mujeres = 0, total = 0;
    int condiciones[5] = {0};
    int edades[11] = {0};
    int i, grupo;

    archivo = fopen("pacientes.dat", "wb");
    if (archivo == NULL) return 1;

    fwrite(pacientes, sizeof(Paciente), 5, archivo);
    fclose(archivo);

    archivo = fopen("pacientes.dat", "rb");
    if (archivo == NULL) return 1;

    while (fread(&p, sizeof(Paciente), 1, archivo) == 1)
    {
        total++;

        if (p.sexo == 'M')
            hombres++;

        if (p.sexo == 'F')
            mujeres++;

        if (p.condicion >= 1 && p.condicion <= 5)
            condiciones[p.condicion - 1]++;

        if (p.edad >= 0)
        {
            grupo = p.edad / 10;

            if (grupo >= 10)
                grupo = 10;

            edades[grupo]++;
        }
    }

    fclose(archivo);

    printf("ESTADISTICAS DEL HOSPITAL\n");

    if (total > 0)
    {
        printf("\nPorcentaje hombres: %.2f%%\n",
               hombres * 100.0 / total);

        printf("Porcentaje mujeres: %.2f%%\n",
               mujeres * 100.0 / total);
    }

    printf("\nPACIENTES POR CONDICION\n");

    for (i = 0; i < 5; i++)
    {
        printf("Condicion %d: %d pacientes\n",
               i + 1, condiciones[i]);
    }

    printf("\nPACIENTES POR EDAD\n");

    for (i = 0; i < 10; i++)
    {
        printf("%d-%d anios: %d pacientes\n",
               i * 10, i * 10 + 9, edades[i]);
    }

    printf("100 o mas anios: %d pacientes\n", edades[10]);

    return 0;
}
