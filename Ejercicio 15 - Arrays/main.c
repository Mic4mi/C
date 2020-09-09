#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define TAM 6


/*
Funcion con array.

el nombre de un vector es una dirección de memoria.
*/

void mostrarVectoresEnteros(int vec[], int tam);

int main()
{
    int numeros[TAM] = {0};
    int suma;

    // Cargo los primeros 5 elementos
    for(int i = 0; i < TAM-1; i++)
    {
        printf("Ingrese un numero\n");
        scanf("%d", &numeros[i]);
    }

    // Sumo elementos
    for(int i = 0; i < TAM-1; i++)
    {
        suma += numeros[i];
    }
    numeros[5] = suma;

    // Muestro
    mostrarVectoresEnteros(numeros, TAM);

    return 0;
}

void mostrarVectoresEnteros(int vec[], int tam)
{
    printf("\nEl vector queda:\n");
    for(int i = 0; i < tam; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n\n");
}
