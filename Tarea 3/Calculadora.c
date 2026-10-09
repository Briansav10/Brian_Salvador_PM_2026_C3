#include <stdio.h>
#include <stdlib.h>

#define SALIR 0
#define SUMAR 1
#define DIVICION 2
#define RAIZ 3
#define CUADRADO 4

#define ERR_OK 0
#define ERR_DivByZero 789
#define ERR_Negativo 790

// Declaracion de funciones
int suma(double num1, double num2, double *result);
int dividir(double divisor, double denominador, double *result);
int raiz(double num, double *result);
int cuadrado(double num, double *result);

// variable global

int main()
{
    int menu = -1;
    int err = ERR_OK;
    double n1 = 0.0;
    double n2 = 0.0;
    double r = 0.0;

    do
    {
        printf("\n\n\n0-SALIR\n1-SUMAR\n2-DIVIDIR\n3-RAIZ CUADRADA\n4-ELEVAR AL CUADRADO\n");
        scanf("%i", &menu);

        if(menu == SUMAR)
        {
            printf("\nIngresa el primer sumando:");
            scanf("%lf", &n1);

            printf("\nIngresa el segundo sumando:");
            scanf("%lf", &n2);

            err = suma(n1,n2,&r);

            if(err == ERR_OK)
            {
                printf("\nSuma de %lf mas %lf es %lf",n1,n2,r);
            }
            else
            {
                printf("\nError de operacion suma");
            }
        }

        if(menu == DIVICION)
        {
            printf("\nIngresa el dividendo:");
            scanf("%lf", &n1);

            printf("\nIngresa el denominador:");
            scanf("%lf", &n2);

            err = dividir(n1,n2,&r);

            if(err == ERR_OK)
            {
                printf("\nDivision de %lf entre %lf es %lf",n1,n2,r);
            }
            else
            {
                if(err == ERR_DivByZero)
                {
                    printf("\nError no se puede dividir entre cero");
                }
                else
                {
                    printf("\nError inesperado");
                }
            }
        }

        if(menu == RAIZ)
        {
            printf("\nIngresa el numero para sacar raiz:");
            scanf("%lf", &n1);

            err = raiz(n1,&r);

            if(err == ERR_OK)
            {
                printf("\nLa raiz cuadrada de %lf es %lf",n1,r);
            }
            else
            {
                printf("\nNo se puede sacar raiz de un numero negativo");
            }
        }

        if(menu == CUADRADO)
        {
            printf("\nIngresa el numero para elevar al cuadrado:");
            scanf("%lf", &n1);

            err = cuadrado(n1,&r);

            if(err == ERR_OK)
            {
                printf("\nEl cuadrado de %lf es %lf",n1,r);
            }
            else
            {
                printf("\nError en la operacion");
            }
        }

    }
    while(menu != SALIR);

    return 0;
}

// Funcion para sumar
int suma(double num1, double num2, double *result)
{
    *result = num1 + num2;
    return ERR_OK;
}

// Funcion para dividir
int dividir(double divisor, double denominador, double *result)
{
    if(denominador == 0.0)
    {
        return ERR_DivByZero;
    }
    else
    {
        *result = divisor / denominador;
        return ERR_OK;
    }
}

// Funcion para calcular raiz cuadrada
int raiz(double num, double *result)
{
    double x;
    int i;

    if(num < 0)
    {
        return ERR_Negativo;
    }
    else
    {
        if(num == 0)
        {
            *result = 0;
        }
        else
        {
            x = num;

            for(i = 0; i < 20; i++)
            {
                x = (x + num / x) / 2;
            }

            *result = x;
        }

        return ERR_OK;
    }
}

// Funcion para elevar al cuadrado
int cuadrado(double num, double *result)
{
    *result = num * num;
    return ERR_OK;
}
