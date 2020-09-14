#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void printArrayNum(int vec[], int tam);

int main()
{
    int aux;

    int coso[] = {6, 4, 5, 2, 3, 1};

    printArrayNum(coso, TAM);

    //bubble sort creciente
    for(int i = 0; i < TAM - 1; i++)
    {
        for(int j = i + 1; j < TAM; j++)
        {
            if(coso[i] > coso[j])
            {
                aux = coso[i];
                coso[i] = coso[j];
                coso[j] = aux;
            }
        }
    }

    printf("\nVector ordenado crecientemente: \n");
    printArrayNum(coso, TAM);

    //bubble sort decreciente
    for(int i = 0; i < TAM - 1; i++)
    {
        for(int j = i + 1; j < TAM; j++)
        {
            if(coso[i] < coso[j])
            {
                aux = coso[i];
                coso[i] = coso[j];
                coso[j] = aux;
            }
        }
    }
    printf("\nVector ordenado decrecientemente: \n");
    printArrayNum(coso, TAM);


    return 0;
}

void printArrayNum(int vec[], int tam)
{
    for(int i = 0; i < TAM; i++)
    {
        printf("%d ", vec[i]);
    }
}






/*
Cuando pasamos un vector por una función, estamos pasando su dirección en memoria.
Los valores serán reemplazados segun el tratamiento que reciban.

*/

/*
TAREA:
modificar la función para que sea una función que ordene numeros enteros
PERO el criteorio de ordenamieto se lo tengo que pasar yo

trucazo: si le paso un 1 que sea ascendente, 0 descendente
*/
