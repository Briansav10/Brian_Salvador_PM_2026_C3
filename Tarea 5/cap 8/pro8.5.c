
#include <stdio.h>

#define MAX 100

typedef struct {
    int clave;
    char nombre[60];
    int existencia;
} Producto;

int buscar(Producto tienda[], int n, int clave) {
    int i;

    for (i = 0; i < n; i++) {
        if (tienda[i].clave == clave)
            return i;
    }

    return -1;
}

int main(void) {
    Producto TIENDA[MAX];
    int n, i, clave, cantidad, pos;
    char operacion;

    printf("Cantidad de productos: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
        return 1;

    for (i = 0; i < n; i++) {
        printf("\nProducto %d\n", i + 1);

        printf("Clave: ");
        scanf("%d", &TIENDA[i].clave);

        printf("Nombre: ");
        scanf(" %59[^\n]", TIENDA[i].nombre);

        printf("Existencia inicial: ");
        scanf("%d", &TIENDA[i].existencia);
    }

    do {
        printf("\nOperacion (C=Compra, V=Venta, 0=Salir): ");
        scanf(" %c", &operacion);

        if (operacion == '0')
            break;

        if (operacion != 'C' && operacion != 'V' &&
            operacion != 'c' && operacion != 'v') {
            printf("Operacion invalida.\n");
            continue;
        }

        printf("Clave del producto: ");
        scanf("%d", &clave);

        printf("Cantidad: ");
        scanf("%d", &cantidad);

        pos = buscar(TIENDA, n, clave);

        if (pos == -1 || cantidad <= 0) {
            printf("Producto o cantidad invalida.\n");
            continue;
        }

        if (operacion == 'C' || operacion == 'c') {
            TIENDA[pos].existencia += cantidad;
            printf("Compra registrada.\n");
        } else {
            if (cantidad > TIENDA[pos].existencia) {
                printf("Existencia insuficiente.\n");
            } else {
                TIENDA[pos].existencia -= cantidad;
                printf("Venta registrada.\n");
            }
        }

    } while (operacion != '0');

    printf("\nINVENTARIO FINAL\n");
    printf("%-10s %-30s %s\n",
           "CLAVE", "PRODUCTO", "EXISTENCIA");

    for (i = 0; i < n; i++) {
        printf("%-10d %-30s %d\n",
               TIENDA[i].clave,
               TIENDA[i].nombre,
               TIENDA[i].existencia);
    }

    return 0;
}
