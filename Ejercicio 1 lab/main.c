#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n1;
   int n2;
   int suma;


    printf("Ingrese un número: ");
    scanf("%d", &n1);

    printf("Ingrese otro número: ");
    scanf("%d", &n2);

    suma = n1 + n2;

    printf("La suma es: %d", suma);

    return 0;
}
