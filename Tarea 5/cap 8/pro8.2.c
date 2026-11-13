
#include <stdio.h>
#include <string.h>

#define MAX 20

typedef struct {
    char nombre[40];
    int jugados;
    int ganados;
    int empatados;
    int perdidos;
    int favor;
    int contra;
    int diferencia;
    int puntos;
} Equipo;

int buscar(Equipo equipos[], int n, char nombre[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(equipos[i].nombre, nombre) == 0)
            return i;
    }
    return -1;
}

void actualizar(Equipo *a, Equipo *b, int ga, int gb) {
    a->jugados++;
    b->jugados++;

    a->favor += ga;
    a->contra += gb;
    b->favor += gb;
    b->contra += ga;

    if (ga > gb) {
        a->ganados++;
        b->perdidos++;
        a->puntos += 3;
    } else if (ga < gb) {
        b->ganados++;
        a->perdidos++;
        b->puntos += 3;
    } else {
        a->empatados++;
        b->empatados++;
        a->puntos++;
        b->puntos++;
    }

    a->diferencia = a->favor - a->contra;
    b->diferencia = b->favor - b->contra;
}

int main(void) {
    Equipo FUTBOL[MAX] = {0};
    Equipo aux;
    int n, partidos, i, j;
    int ga, gb, a, b;
    char nombre1[40], nombre2[40];

    printf("Cantidad de equipos: ");
    scanf("%d", &n);

    if (n < 2 || n > MAX)
        return 1;

    for (i = 0; i < n; i++) {
        printf("Nombre del equipo %d: ", i + 1);
        scanf(" %39[^\n]", FUTBOL[i].nombre);
    }

    printf("Cantidad de partidos: ");
    scanf("%d", &partidos);

    for (i = 0; i < partidos; i++) {
        printf("\nPartido %d\n", i + 1);

        printf("Equipo local: ");
        scanf(" %39[^\n]", nombre1);

        printf("Goles local: ");
        scanf("%d", &ga);

        printf("Equipo visitante: ");
        scanf(" %39[^\n]", nombre2);

        printf("Goles visitante: ");
        scanf("%d", &gb);

        a = buscar(FUTBOL, n, nombre1);
        b = buscar(FUTBOL, n, nombre2);

        if (a == -1 || b == -1 || a == b ||
            ga < 0 || gb < 0) {
            printf("Datos invalidos.\n");
            continue;
        }

        actualizar(&FUTBOL[a], &FUTBOL[b], ga, gb);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (FUTBOL[j].puntos > FUTBOL[i].puntos ||
                (FUTBOL[j].puntos == FUTBOL[i].puntos &&
                 FUTBOL[j].diferencia > FUTBOL[i].diferencia)) {
                aux = FUTBOL[i];
                FUTBOL[i] = FUTBOL[j];
                FUTBOL[j] = aux;
            }
        }
    }

    printf("\n%-20s PJ PG PE PP GF GC DG PTS\n", "EQUIPO");

    for (i = 0; i < n; i++) {
        printf("%-20s %2d %2d %2d %2d %2d %2d %3d %3d\n",
               FUTBOL[i].nombre,
               FUTBOL[i].jugados,
               FUTBOL[i].ganados,
               FUTBOL[i].empatados,
               FUTBOL[i].perdidos,
               FUTBOL[i].favor,
               FUTBOL[i].contra,
               FUTBOL[i].diferencia,
               FUTBOL[i].puntos);
    }

    return 0;
}
