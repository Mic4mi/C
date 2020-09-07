#include <stdio.h>
#include <stdlib.h>
#include "acunia.h"

int main()
{
    int a;
    int b;

    printf("Ingrese un numero\n");
    scanf("%d", &a);

    printf("Ingrese otro numero\n");
    scanf("%d", &b);

    printf("El promedio es: %.2f\n", calcularPromedio(a, b));

    return 0;
}

