#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarNumeros(int* vec, int tam);

int main()
{
    int numeros[] = {3,2,6,5,8};

    //Acá le pasamos la dirección de memoria del 1er elemento, y el tamaño para que sepa dónde finalizar
    mostrarNumeros(numeros, TAM);

    return 0;
}

void mostrarNumeros(int* vec, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("Numero: %d\n", vec[i]);
    }
    printf("\n\n");
}
