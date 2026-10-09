#include <stdio.h>

/* Cubo-3.
El programa calcula el cubo de los 10 primeros numeros naturales con la
ayuda de una funcion y utilizando parametros por valor. */

int cubo(int);

int main(void)
{
    int I;

    for (I = 1; I <= 10; I++)
        printf("\nEl cubo de I es: %d", cubo(I));

    return 0;
}

int cubo(int K)
{
    /* La funcion calcula el cubo del parametro K. */
    return (K*K*K);
}
