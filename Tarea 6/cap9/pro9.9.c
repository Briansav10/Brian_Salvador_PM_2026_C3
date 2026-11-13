
#include <stdio.h>

#define MAX 100

typedef struct
{
    int clave;
    char nombre[40];
    int existencia;
    float precio;
} Producto;

Producto productos[MAX];
int n = 0;

void guardar()
{
    FILE *archivo = fopen("com.dat", "wb");

    if (archivo == NULL)
    {
        printf("Error al guardar.\n");
        return;
    }

    fwrite(productos, sizeof(Producto), n, archivo);
    fclose(archivo);
}

void cargar()
{
    FILE *archivo = fopen("com.dat", "rb");

    if (archivo == NULL)
    {
        n = 3;

        productos[0] = (Producto){101, "Pintura blanca", 20, 850};
        productos[1] = (Producto){102, "Pintura azul", 15, 900};
        productos[2] = (Producto){103, "Impermeabilizante", 10, 1500};

        guardar();
        return;
    }

    n = fread(productos, sizeof(Producto), MAX, archivo);
    fclose(archivo);
}

int buscar(int clave)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (productos[i].clave == clave)
            return i;
    }

    return -1;
}

void inventario()
{
    int i;

    printf("\nINVENTARIO\n");

    for (i = 0; i < n; i++)
    {
        printf("%d - %s - Cantidad: %d - Precio: %.2f\n",
               productos[i].clave,
               productos[i].nombre,
               productos[i].existencia,
               productos[i].precio);
    }
}

void ventas()
{
    int clave, cantidad, pos;
    float total = 0;

    while (1)
    {
        printf("Clave del producto (0 para terminar): ");
        scanf("%d", &clave);

        if (clave == 0) break;

        pos = buscar(clave);

        if (pos == -1)
        {
            printf("Producto no encontrado.\n");
            continue;
        }

        printf("Cantidad: ");
        scanf("%d", &cantidad);

        if (cantidad <= 0 ||
            cantidad > productos[pos].existencia)
        {
            printf("Cantidad no disponible.\n");
        }
        else
        {
            productos[pos].existencia -= cantidad;
            total += cantidad * productos[pos].precio;
            printf("Venta realizada.\n");
        }
    }

    printf("Total de la venta: %.2f\n", total);
    guardar();
}

void reabastecer()
{
    int clave, cantidad, pos;

    while (1)
    {
        printf("Clave del producto (0 para terminar): ");
        scanf("%d", &clave);

        if (clave == 0) break;

        pos = buscar(clave);

        if (pos == -1)
        {
            printf("Producto no encontrado.\n");
            continue;
        }

        printf("Cantidad a agregar: ");
        scanf("%d", &cantidad);

        if (cantidad > 0)
        {
            productos[pos].existencia += cantidad;
            printf("Inventario actualizado.\n");
        }
    }

    guardar();
}

void agregar()
{
    Producto nuevo, aux;
    int i, j;

    while (n < MAX)
    {
        printf("Clave nueva (0 para terminar): ");
        scanf("%d", &nuevo.clave);

        if (nuevo.clave == 0) break;

        if (buscar(nuevo.clave) != -1)
        {
            printf("La clave ya existe.\n");
            continue;
        }

        printf("Nombre: ");
        scanf(" %39[^\n]", nuevo.nombre);

        printf("Existencia: ");
        scanf("%d", &nuevo.existencia);

        printf("Precio: ");
        scanf("%f", &nuevo.precio);

        if (nuevo.existencia < 0 || nuevo.precio < 0)
        {
            printf("Datos invalidos.\n");
            continue;
        }

        productos[n] = nuevo;
        n++;

        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (productos[i].clave > productos[j].clave)
                {
                    aux = productos[i];
                    productos[i] = productos[j];
                    productos[j] = aux;
                }
            }
        }

        printf("Producto agregado.\n");
    }

    guardar();
}

int main()
{
    int opcion;

    cargar();

    do
    {
        printf("\nMENU\n");
        printf("1. Ventas\n");
        printf("2. Reabastecimiento\n");
        printf("3. Nuevos productos\n");
        printf("4. Inventario\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1: ventas(); break;
            case 2: reabastecer(); break;
            case 3: agregar(); break;
            case 4: inventario(); break;
            case 0: printf("Fin del programa.\n"); break;
            default: printf("Opcion incorrecta.\n");
        }

    } while (opcion != 0);

    return 0;
}
