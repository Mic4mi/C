#include <stdio.h>
#include <stdlib.h>

void mostrarEnteros(int* vec, int tam);

int main()
{
    /*
    Calloc funciona igual que malloc pero inicializa las variables en cero.
    */

    int* pNumeros = (int*) calloc(5, sizeof(int));

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", *(pNumeros + i));
    }
    printf("\n\n");

    return 0;
}

void mostrarEnteros(int* vec, int tam)
{
    printf("\nLa lista de numeros:\n");
    for(int i = 0; i < tam; i++)
    {
        printf("%d ", *(vec + i));
    }
    printf("\n\n");
}
