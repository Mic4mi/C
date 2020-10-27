#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void cargarVector(int* vec, int tam);
void mostrarNumerosP(int* vec, int tam);

int main()
{
    int numeros[TAM];

    cargarVector(numeros, TAM);
    printf("\n\n");
    mostrarNumerosP(numeros, TAM);

    return 0;
}

//Nomenclatura punteros
void cargarVector(int* vec, int tam)
{
    printf("Bienvenido!!!!\n\nCargue 5 numeros enteros en el vector\n");
    for(int i = 0; i < tam; i++)
    {
        printf("\nIngrese un numero: ");
        fflush(stdin);
        scanf("%d", vec + i);
    }
}

void mostrarNumerosP(int* vec, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("Numero: %d\n", *(vec + i));
    }
    printf("\n\n");
}
