
#include <stdio.h>

void hanoi(int n, char origen, char destino, char auxiliar)
{
    if (n == 1)
    {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
    }
    else
    {
        hanoi(n - 1, origen, auxiliar, destino);

        printf("Mover disco %d de %c a %c\n", n, origen, destino);

        hanoi(n - 1, auxiliar, destino, origen);
    }
}

int main()
{
    int discos;

    printf("TORRES DE HANOI\n");

    printf("Ingrese la cantidad de discos: ");
    scanf("%d", &discos);

    if (discos > 0)
    {
        hanoi(discos, 'A', 'C', 'B');
    }
    else
    {
        printf("Cantidad de discos incorrecta");
    }

    return 0;
}
