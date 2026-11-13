
#include <stdio.h>
#include <string.h>

#define MAX 200

typedef struct {
    int numero;
    char nombre[60];
    char departamento[40];
    char puesto[40];
    char grado[40];
    char nacionalidad[40];
    double salarios[12];
} Profesor;

int main(void) {
    Profesor EMPLE[MAX];
    char departamentos[4][40] = {
        "Economia", "Derecho",
        "Computacion", "Administracion"
    };

    double gastos[4] = {0};
    double total = 0, extranjeros = 0;
    double mayorIngreso = -1, ingreso;
    int n, i, j, k, mayorProfesor = 0;
    int mayorDepartamento = 0;

    printf("Cantidad de profesores: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
        return 1;

    for (i = 0; i < n; i++) {
        printf("\nProfesor %d\n", i + 1);

        printf("Numero de empleado: ");
        scanf("%d", &EMPLE[i].numero);

        printf("Nombre y apellido: ");
        scanf(" %59[^\n]", EMPLE[i].nombre);

        printf("Departamento: ");
        scanf(" %39[^\n]", EMPLE[i].departamento);

        printf("Puesto: ");
        scanf(" %39[^\n]", EMPLE[i].puesto);

        printf("Grado academico: ");
        scanf(" %39[^\n]", EMPLE[i].grado);

        printf("Nacionalidad: ");
        scanf(" %39[^\n]", EMPLE[i].nacionalidad);

        ingreso = 0;

        for (j = 0; j < 12; j++) {
            printf("Salario mes %d: ", j + 1);
            scanf("%lf", &EMPLE[i].salarios[j]);

            ingreso += EMPLE[i].salarios[j];
        }

        total += ingreso;

        if (ingreso > mayorIngreso) {
            mayorIngreso = ingreso;
            mayorProfesor = i;
        }

        if (strcmp(EMPLE[i].nacionalidad, "Colombiana") != 0 &&
            strcmp(EMPLE[i].nacionalidad, "Colombiano") != 0 &&
            strcmp(EMPLE[i].nacionalidad, "Colombia") != 0) {
            extranjeros += ingreso;
        }

        for (k = 0; k < 4; k++) {
            if (strcmp(EMPLE[i].departamento,
                       departamentos[k]) == 0) {
                gastos[k] += ingreso;
                break;
            }
        }
    }

    for (i = 1; i < 4; i++) {
        if (gastos[i] > gastos[mayorDepartamento])
            mayorDepartamento = i;
    }

    printf("\nPROFESOR CON MAYORES INGRESOS\n");
    printf("Nombre: %s\n", EMPLE[mayorProfesor].nombre);
    printf("Departamento: %s\n",
           EMPLE[mayorProfesor].departamento);
    printf("Nacionalidad: %s\n",
           EMPLE[mayorProfesor].nacionalidad);
    printf("Ingreso anual: %.2f\n", mayorIngreso);

    printf("\nGASTOS EN PROFESORES EXTRANJEROS\n");
    printf("Total: %.2f\n", extranjeros);

    if (total > 0) {
        printf("Porcentaje: %.2f%%\n",
               extranjeros * 100.0 / total);
    }

    printf("\nDEPARTAMENTO CON MAYOR GASTO\n");
    printf("Departamento: %s\n",
           departamentos[mayorDepartamento]);
    printf("Gasto: %.2f\n", gastos[mayorDepartamento]);

    return 0;
}
