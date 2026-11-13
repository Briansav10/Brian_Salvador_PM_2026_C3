
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char calle[60];
    char colonia[40];
    char codigoPostal[15];
    char ciudad[40];
    char telefono[20];
} Domicilio;

typedef struct {
    int numero;
    char nombre[60];
    char departamento[40];
    Domicilio domicilio;
    double salario;
    int activo;
} Empleado;

int buscar(Empleado empleados[], int n, int numero) {
    int i;

    for (i = 0; i < n; i++) {
        if (empleados[i].numero == numero &&
            empleados[i].activo)
            return i;
    }

    return -1;
}

int main(void) {
    Empleado EMPLE[MAX];
    Empleado nuevo;
    int n = 0, opcion, numero, pos, i, j;
    char departamento[40];

    do {
        printf("\nMENU DE EMPLEADOS\n");
        printf("1. Alta\n");
        printf("2. Baja\n");
        printf("3. Listado por departamento\n");
        printf("0. Salir\n");
        printf("Seleccione: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (n >= MAX) {
                    printf("Capacidad completa.\n");
                    break;
                }

                printf("Numero: ");
                scanf("%d", &nuevo.numero);

                if (buscar(EMPLE, n, nuevo.numero) != -1) {
                    printf("Empleado existente.\n");
                    break;
                }

                printf("Nombre: ");
                scanf(" %59[^\n]", nuevo.nombre);

                printf("Departamento: ");
                scanf(" %39[^\n]", nuevo.departamento);

                printf("Calle y numero: ");
                scanf(" %59[^\n]", nuevo.domicilio.calle);

                printf("Colonia: ");
                scanf(" %39[^\n]", nuevo.domicilio.colonia);

                printf("Codigo postal: ");
                scanf(" %14s", nuevo.domicilio.codigoPostal);

                printf("Ciudad: ");
                scanf(" %39[^\n]", nuevo.domicilio.ciudad);

                printf("Telefono: ");
                scanf(" %19s", nuevo.domicilio.telefono);

                printf("Salario mensual: ");
                scanf("%lf", &nuevo.salario);

                nuevo.activo = 1;

                pos = n;

                for (i = 0; i < n; i++) {
                    if (nuevo.numero < EMPLE[i].numero) {
                        pos = i;
                        break;
                    }
                }

                for (j = n; j > pos; j--) {
                    EMPLE[j] = EMPLE[j - 1];
                }

                EMPLE[pos] = nuevo;
                n++;

                printf("Empleado registrado.\n");
                break;

            case 2:
                printf("Numero del empleado: ");
                scanf("%d", &numero);

                pos = buscar(EMPLE, n, numero);

                if (pos == -1) {
                    printf("Empleado no encontrado.\n");
                } else {
                    EMPLE[pos].activo = 0;
                    printf("Baja realizada.\n");
                }
                break;

            case 3:
                printf("Departamento: ");
                scanf(" %39[^\n]", departamento);

                printf("\nNUMERO  NOMBRE  SALARIO\n");

                for (i = 0; i < n; i++) {
                    if (EMPLE[i].activo &&
                        strcmp(EMPLE[i].departamento,
                               departamento) == 0) {
                        printf("%d  %s  %.2f\n",
                               EMPLE[i].numero,
                               EMPLE[i].nombre,
                               EMPLE[i].salario);
                    }
                }
                break;

            case 0:
                printf("Programa finalizado.\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 0);

    return 0;
}
