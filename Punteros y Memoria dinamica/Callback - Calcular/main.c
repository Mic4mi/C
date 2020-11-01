#include <stdio.h>
#include <stdlib.h>

int sumar(int a, int b);
int restar(int a, int b);
int multiplicar(int a, int b);
int calcular(int a, int b, int (*callback)(int, int));

int main()
{
    printf("Calculando con callbacks:\n");

    printf("\nSuma: %d\n", calcular(5,3,sumar));

    printf("\nResta: %d\n", calcular(5,3,restar));

    printf("\nMultiplicacion: %d\n", calcular(5,3,multiplicar));

    return 0;
}

int sumar(int a, int b)
{
    return a+b;
}

int restar(int a, int b)
{
    return a-b;
}

int multiplicar(int a, int b)
{
    return a*b;
}

int calcular(int a, int b, int (*callback)(int, int))
{
    return callback(a,b);
}
