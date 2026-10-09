#include <stdio.h>

#define MAX 100

void Lectura(int *, int);
void Imprime(int *, int);
void Ordena(int *, int);

int main(void)
{
    int TAM, VEC[MAX];

    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);
    Ordena(VEC, TAM);
    Imprime(VEC, TAM);

    return 0;
}

void Lectura(int A[], int T)
{
    int I;

    for (I=0; I<T; I++)
    {
        printf("Ingrese el elemento %d: ", I+1);
        scanf("%d", &A[I]);
    }
}

void Imprime(int A[], int T)
{
    int I;

    for (I=0; I<T; I++)
        printf("\nA[%d]: %d", I, A[I]);
}

void Ordena(int A[], int T)
{
    int I, J, AUX;

    for (I=1; I<T; I++)
    {
        AUX = A[I];
        J = I-1;

        while (J >= 0 && A[J] > AUX)
        {
            A[J+1] = A[J];
            J--;
        }

        A[J+1] = AUX;
    }
}
