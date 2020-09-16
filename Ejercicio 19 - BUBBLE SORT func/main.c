#include <stdio.h>
#include <stdlib.h>

/*
*
TAREA:
modificar la función para que sea una función que ordene numeros enteros
PERO el criteorio de ordenamieto se lo tengo que pasar yo

trucazo: si le paso un 1 que sea ascendente, 0 descendente
*
*/

int bubleSort(int vec[], int tam, int condicion);

int main()
{
    int coso[] = {6, 4, 5, 2, 3, 1};
    bubleSort(coso, 6, 1);
    bubleSort(coso, 6, 0);
    bubleSort(coso, 6, 4);

    return 0;
}


int bubleSort(int vec[], int tam, int condicion)
{
    int error = 0;
    int aux;
    if(condicion == 1)
    {
        for(int i = 0; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(vec[i] > vec[j])
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }

        printf("\nEl vector ordenado en forma creciente queda:\n");
        for(int i = 0; i < tam; i++)
        {
            printf("%d ", vec[i]);
        }
    }
    else if(condicion == 0)
    {
        for(int i = 0; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(vec[i] < vec[j])
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
        printf("\nEl vector ordenado en forma decreciente queda:\n");
        for(int i = 0; i < tam; i++)
        {
            printf("%d ", vec[i]);
        }
    } else {
    error = 1;
    printf("\nAlgo salio mal...\n");
    }

    return error;
}
