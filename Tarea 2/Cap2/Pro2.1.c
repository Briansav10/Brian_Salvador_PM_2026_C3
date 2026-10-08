#include <stdio.h>

/* Promedio curso.
El programa recibe el promedio de un alumno
y muestra aprobado si es mayor o igual a 6.
PRO: variable de tipo real.
*/

int main()
{
    float PRO;

    // Pedir el promedio del alumno
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &PRO);

    // Verificar si el alumno aprobo
    if (PRO >= 6)
    {
        printf("\nAprobado");
    }

    return 0;
}
