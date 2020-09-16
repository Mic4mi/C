#include <stdio.h>
#include <stdlib.h>

/*
Función swap. Que reciba dos variables e intercambie su valor
*/
void swapEnteros (int* pA, int* pB);

int main()
{
    int x = 5;
    int y = 10;

    printf("x: %d y: %d\n", x, y);

    swapEnteros(&x, &y);

    printf("x: %d y: %d\n", x, y);

    return 0;
}

void swapEnteros (int* pA, int* pB)
{
    int aux;

    aux = *pA;
    *pA = *pB;
    *pB = aux;
}
