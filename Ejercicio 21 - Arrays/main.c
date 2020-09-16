#include <stdio.h>
#include <stdlib.h>

#define TAM 5

/** \brief Imprime un vector de numeros enteros
 *
 * \param vector
 * \param tamaño del vector
 *
 */
void mostrarVectoresEnteros(int vec[], int tam);

/** \brief Suma dos vectores y carga los resultados en un nuevo vector
 *
 * \param vector 1
 * \param vector 2
 * \param vector total
 * \param tamaño de los vectores
 *
 */
void sumarVectores(int a[], int b[], int totales[], int tam);

int main()
{
    int vec1[] = {2,1,5,4,6};
    int vec2[] = {5,7,3,9,5};
    int totales[TAM] = {};

    sumarVectores(vec1, vec2, totales, TAM);

    mostrarVectoresEnteros(vec1, TAM);
    mostrarVectoresEnteros(vec2, TAM);
    mostrarVectoresEnteros(totales, TAM);

    return 0;
}

void mostrarVectoresEnteros(int vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

void sumarVectores(int a[], int b[], int totales[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        totales[i] = a[i] + b[i];
    }
}
