
#include <stdio.h>

#define MAX 100

typedef struct {
    char calle[60];
    char codigoPostal[15];
    char colonia[40];
    char ciudad[40];
    char telefono[20];
} Domicilio;

typedef struct {
    long numeroCuenta;
    char nombre[60];
    Domicilio domicilio;
    double saldo;
} Cliente;

int buscar(Cliente clientes[], int n, long cuenta) {
    int i;
    for (i = 0; i < n; i++) {
        if (clientes[i].numeroCuenta == cuenta)
            return i;
    }
    return -1;
}

int main(void) {
    Cliente CLI[MAX];
    int n, i, opcion, pos;
    long cuenta;
    double cantidad;

    printf("Cantidad de clientes (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
        return 1;

    for (i = 0; i < n; i++) {
        printf("\nCliente %d\n", i + 1);

        printf("Numero de cuenta: ");
        scanf("%ld", &CLI[i].numeroCuenta);

        printf("Nombre: ");
        scanf(" %59[^\n]", CLI[i].nombre);

        printf("Calle y numero: ");
        scanf(" %59[^\n]", CLI[i].domicilio.calle);

        printf("Codigo postal: ");
        scanf(" %14s", CLI[i].domicilio.codigoPostal);

        printf("Colonia: ");
        scanf(" %39[^\n]", CLI[i].domicilio.colonia);

        printf("Ciudad: ");
        scanf(" %39[^\n]", CLI[i].domicilio.ciudad);

        printf("Telefono: ");
        scanf(" %19s", CLI[i].domicilio.telefono);

        printf("Saldo inicial: ");
        scanf("%lf", &CLI[i].saldo);
    }

    do {
        printf("\n1. Deposito\n");
        printf("2. Retiro\n");
        printf("3. Consultar saldo\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if (opcion == 0)
            break;

        if (opcion < 1 || opcion > 3) {
            printf("Opcion invalida.\n");
            continue;
        }

        printf("Numero de cuenta: ");
        scanf("%ld", &cuenta);

        pos = buscar(CLI, n, cuenta);

        if (pos == -1) {
            printf("Cuenta no encontrada.\n");
            continue;
        }

        if (opcion == 3) {
            printf("Cliente: %s\n", CLI[pos].nombre);
            printf("Saldo: %.2f\n", CLI[pos].saldo);
            continue;
        }

        printf("Cantidad: ");
        scanf("%lf", &cantidad);

        if (cantidad <= 0) {
            printf("Cantidad invalida.\n");
            continue;
        }

        if (opcion == 1) {
            CLI[pos].saldo += cantidad;
            printf("Deposito realizado.\n");
        } else {
            if (cantidad > CLI[pos].saldo) {
                printf("Fondos insuficientes.\n");
            } else {
                CLI[pos].saldo -= cantidad;
                printf("Retiro realizado.\n");
            }
        }

        printf("Saldo actual: %.2f\n", CLI[pos].saldo);

    } while (opcion != 0);

    return 0;
}
