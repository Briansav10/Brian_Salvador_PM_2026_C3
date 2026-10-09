#include <stdio.h>

#define TAM 50

void Lectura(int *, int);
void Frecuencia(int *, int, int *, int);
void Imprime(int *, int);
void Mayor(int *, int);

int main(void)
{
    int CAL[TAM], FRE[6] = {0};

    Lectura(CAL, TAM);
    Frecuencia(CAL, TAM, FRE, 6);
    Imprime(FRE, 6);
    Mayor(FRE, 6);

    return 0;
}

void Lectura(int A[], int T)
{
    int I;

    for (I=0; I<T; I++)
    {
        printf("Ingrese la calificacion %d: ", I+1);
        scanf("%d", &A[I]);
    }
}

void Frecuencia(int A[], int T, int B[], int N)
{
    int I;

    for (I=0; I<T; I++)
        if (A[I]>=0 && A[I]<N)
            B[A[I]]++;
}

void Imprime(int A[], int T)
{
    int I;

    for (I=0; I<T; I++)
        printf("\nCalificacion %d: %d", I, A[I]);
}

void Mayor(int A[], int T)
{
    int I, MAY = A[0], POS = 0;

    for (I=1; I<T; I++)
        if (A[I] > MAY)
        {
            MAY = A[I];
            POS = I;
        }

    printf("\nMayor frecuencia: %d", MAY);
    printf("\nCalificacion: %d", POS);
}
