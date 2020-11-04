#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    La idea es declarar en memoria dinamica un puntero a puntero entero.
    */

    int* pNum = (int*) malloc(sizeof(int));

    *pNum = 5;

    int** pNum2 = (int**) malloc(sizeof(int*));

    *pNum2 = pNum; //pNum y pNum2 apuntan a la misma direccion de memoria

    **pNum2 = 7;

    printf("pNum: %d\n", *pNum);
    printf("pNum2: %d\n", **pNum2);

    return 0;
}
