#include <stdio.h>
#include <stdlib.h>

void duplicarValor(int* pEntero);

int main()
{
    /*
        El objetivo es lograr una funci�n que escriba sobre una variable,
        por lo tanto debe recibir una direcci�n de memoria y no un valor.
    */

    int ejemplo = 5;

    printf("Numero actual: %d\n", ejemplo);

    duplicarValor(&ejemplo);

    printf("Numero duplicado: %d\n", ejemplo);

    /*
    Tambi�n es lo mismo hacer:

    a)     *(&ejemplo) = *(&ejemplo) * 2;
    b)     ejemplo = ejemplo * 2;

    */

    return 0;
}

void duplicarValor(int* pEntero)
{
    *pEntero = *pEntero * 2;
}
