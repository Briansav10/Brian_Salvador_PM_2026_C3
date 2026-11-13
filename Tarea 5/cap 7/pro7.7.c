
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char cad[30];
    int i;

    printf("Ingrese el telefono de 10 digitos: ");
    scanf("%29s", cad);

    if (strlen(cad) != 10) {
        printf("El telefono debe tener 10 digitos.\n");
        return 1;
    }

    for (i = 0; i < 10; i++) {
        if (!isdigit((unsigned char)cad[i])) {
            printf("El telefono solo debe contener numeros.\n");
            return 1;
        }
    }

    printf("Telefono: (%.2s)-%c-%s\n",
           cad, cad[2], cad + 3);

    return 0;
}
