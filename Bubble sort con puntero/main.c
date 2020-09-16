#include <stdio.h>
#include <stdlib.h>

void bubleSort(int vec[], int tam, int ascendente);
void swapEnteros (int* pA, int* pB);

int main()
{
    int coso[] = {6, 4, 5, 2, 3, 1};

    return 0;
}

void bubleSort(int vec[], int tam, int ascendente)
{
    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(vec[i] > vec[j] && ascendente)
            {
                swapEnteros(&vec[i], &vec[j]);
            }
            else if (vec[i] < vec[j] && !ascendente)
            {
                swapEnteros(&vec[i], &vec[j]);
            }
        }

    }
}


void swapEnteros (int* pA, int* pB)
{
    int aux;

    aux = *pA;
    *pA = *pB;
    *pB = aux;
}


// terminar
