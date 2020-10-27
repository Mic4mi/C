#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarNumerosV(int vec[], int tam);
void mostrarNumerosP(int* vec, int tam);

int main()
{
    int numeros[] = {3,2,6,5,8};



    printf("Funcion con nomenclatura vectorial:\n");
    mostrarNumerosV(numeros, TAM);

    printf("\n\n");
    //Acá le pasamos la dirección de memoria del 1er elemento, y el tamaño para que sepa dónde finalizar
    printf("Funcion con nomenclatura de punteros:\n");
    mostrarNumerosP(numeros, TAM);

    return 0;
}

//Nomenclatura vectorial
void mostrarNumerosV(int vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("Numero: %d\n", vec[i]);
    }
    printf("\n\n");
}

//Nomenclatura punteros
void mostrarNumerosP(int* vec, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("Numero: %d\n", *(vec + i));
    }
    printf("\n\n");
}
