#include <stdio.h>

/* Conflicto de variables con el mismo nombre. */

void f1(void);
int K = 5;  /* Variable global. */

int main(void)
{
    int I;

    for (I = 1; I <= 3; I++)
        f1();

    return 0;
}

void f1(void)
{
    /* La funcion utiliza una variable local
       y una variable global. */

    int K = 2;

    K += K;
    printf("\n\nEl valor de la variable local es: %d", K);

    printf("\nEl valor de la variable global es: %d", 5 + K);
}
