#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int cargarVector(int* vec, int tam);
void mostrarVector(int* vec, int tam);

int main()
{
    int numeros[TAM];

    cargarVector(numeros, TAM);
    mostrarVector(numeros, TAM);

    return 0;
}

int cargarVector(int* vec, int tam)
{
    int error = -1;

    if(vec != NULL)
    {
        printf("Bienevenido\n\nCargue 5 numeros enteros\n");
        for(int i = 0; i < tam; i++)
        {
            printf("\nIngrese numero: ");
            fflush(stdin);
            scanf("%d", vec + i);
        }
        error = 0;
    }
    return error;
}



void mostrarVector(int* vec, int tam)
{
    if(vec != NULL)
    {
        printf("\nEl vector quedó: \n");
        for(int i = 0; i < tam; i++)
        {
            printf("%d\n", *(vec + i));
        }
    }
}
