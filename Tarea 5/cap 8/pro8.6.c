
#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MATERIAS 7

typedef struct {
    char calle[60];
    char codigoPostal[15];
    char colonia[40];
    char ciudad[40];
    char telefono[20];
} Domicilio;

typedef struct {
    char nivel[30];
    int grado;
    char salon[20];
} Estudios;

typedef struct {
    char materia[50];
    float promedio;
} Calificacion;

typedef struct {
    int matricula;
    char nombre[60];
    Domicilio domicilio;
    Estudios estudios;
    Calificacion calificaciones[MATERIAS];
} Alumno;

float calcularPromedio(Alumno a) {
    float suma = 0;
    int i;

    for (i = 0; i < MATERIAS; i++) {
        suma += a.calificaciones[i].promedio;
    }

    return suma / MATERIAS;
}

int buscarAlumno(Alumno escuela[], int n, int matricula) {
    int i;

    for (i = 0; i < n; i++) {
        if (escuela[i].matricula == matricula)
            return i;
    }

    return -1;
}

int pertenece(Alumno a, char nivel[],
              int grado, char salon[]) {
    return strcmp(a.estudios.nivel, nivel) == 0 &&
           a.estudios.grado == grado &&
           strcmp(a.estudios.salon, salon) == 0;
}

int main(void) {
    static Alumno ESCUELA[MAX];
    int n, i, j, opcion, matricula, pos;
    int grado, mejor;
    char nivel[30], salon[20];
    float promedio, mayor;

    printf("Cantidad de alumnos: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
        return 1;

    for (i = 0; i < n; i++) {
        printf("\nALUMNO %d\n", i + 1);

        printf("Matricula: ");
        scanf("%d", &ESCUELA[i].matricula);

        printf("Nombre: ");
        scanf(" %59[^\n]", ESCUELA[i].nombre);

        printf("Calle y numero: ");
        scanf(" %59[^\n]",
              ESCUELA[i].domicilio.calle);

        printf("Codigo postal: ");
        scanf(" %14s",
              ESCUELA[i].domicilio.codigoPostal);

        printf("Colonia: ");
        scanf(" %39[^\n]",
              ESCUELA[i].domicilio.colonia);

        printf("Ciudad: ");
        scanf(" %39[^\n]",
              ESCUELA[i].domicilio.ciudad);

        printf("Telefono: ");
        scanf(" %19s",
              ESCUELA[i].domicilio.telefono);

        printf("Nivel educativo: ");
        scanf(" %29[^\n]",
              ESCUELA[i].estudios.nivel);

        printf("Grado: ");
        scanf("%d", &ESCUELA[i].estudios.grado);

        printf("Salon: ");
        scanf(" %19s", ESCUELA[i].estudios.salon);

        for (j = 0; j < MATERIAS; j++) {
            printf("Nombre materia %d: ", j + 1);
            scanf(" %49[^\n]",
                  ESCUELA[i].calificaciones[j].materia);

            printf("Promedio de la materia: ");
            scanf("%f",
                  &ESCUELA[i].calificaciones[j].promedio);
        }
    }

    do {
        printf("\nMENU ACADEMICO\n");
        printf("1. Promedio de un alumno\n");
        printf("2. Listado por nivel, grado y salon\n");
        printf("3. Alumno con mejor promedio\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf("Matricula: ");
            scanf("%d", &matricula);

            pos = buscarAlumno(ESCUELA, n, matricula);

            if (pos == -1) {
                printf("Alumno no encontrado.\n");
            } else {
                promedio = calcularPromedio(ESCUELA[pos]);

                printf("Nombre: %s\n", ESCUELA[pos].nombre);
                printf("Promedio general: %.2f\n", promedio);
            }
        }

        if (opcion == 2 || opcion == 3) {
            printf("Nivel educativo: ");
            scanf(" %29[^\n]", nivel);

            printf("Grado: ");
            scanf("%d", &grado);

            printf("Salon: ");
            scanf(" %19s", salon);

            if (opcion == 2) {
                printf("\nLISTADO DE ALUMNOS\n");

                for (i = 0; i < n; i++) {
                    if (pertenece(ESCUELA[i],
                                 nivel, grado, salon)) {
                        printf("Matricula: %d\n",
                               ESCUELA[i].matricula);
                        printf("Nombre: %s\n",
                               ESCUELA[i].nombre);
                        printf("Promedio: %.2f\n\n",
                               calcularPromedio(ESCUELA[i]));
                    }
                }
            } else {
                mejor = -1;
                mayor = -1;

                for (i = 0; i < n; i++) {
                    if (pertenece(ESCUELA[i],
                                 nivel, grado, salon)) {
                        promedio = calcularPromedio(ESCUELA[i]);

                        if (promedio > mayor) {
                            mayor = promedio;
                            mejor = i;
                        }
                    }
                }

                if (mejor == -1) {
                    printf("No hay alumnos en ese grupo.\n");
                } else {
                    printf("\nMEJOR ALUMNO\n");
                    printf("Matricula: %d\n",
                           ESCUELA[mejor].matricula);
                    printf("Nombre: %s\n",
                           ESCUELA[mejor].nombre);
                    printf("Promedio: %.2f\n", mayor);
                }
            }
        }

    } while (opcion != 0);

    return 0;
}
