#include <stdio.h>
#include <math.h>

#define MAX 100

void Lectura(int *, int);
float Media(int *, int);
float Varianza(int *, int, float);
float Desviacion(float);
void Frecuencia(int *, int, int *);
int Moda(int *, int);

int main(void)
{
    int TAM, MOD, ALU[MAX], FRE[11] = {0};
    float MED, VAR, DES;

    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);

    Lectura(ALU, TAM);

    MED = Media(ALU, TAM);
    VAR = Varianza(ALU, TAM, MED);
    DES = Desviacion(VAR);

    Frecuencia(ALU, TAM, FRE);
    MOD = Moda(FRE, 11);

    printf("\nMedia: %.2f", MED);
    printf("\nVarianza: %.2f", VAR);
    printf("\nDesviacion estandar: %.2f", DES);
    printf("\nModa: %d", MOD);

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

float Media(int A[], int T)
{
    int I;
    float SUM = 0;

    for (I=0; I<T; I++)
        SUM += A[I];

    return SUM/T;
}

float Varianza(int A[], int T, float M)
{
    int I;
    float SUM = 0;

    for (I=0; I<T; I++)
        SUM += pow(A[I]-M, 2);

    return SUM/T;
}

float Desviacion(float V)
{
    return sqrt(V);
}

void Frecuencia(int A[], int T, int F[])
{
    int I;

    for (I=0; I<T; I++)
        if (A[I]>=0 && A[I]<=10)
            F[A[I]]++;
}

int Moda(int F[], int T)
{
    int I, MAY = F[0], MOD = 0;

    for (I=1; I<T; I++)
        if (F[I] > MAY)
        {
            MAY = F[I];
            MOD = I;
        }

    return MOD;
}
