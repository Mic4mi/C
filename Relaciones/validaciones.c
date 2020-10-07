#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"


int getOption(int* pResult, char* errorMsj, int min, int max)
{
    int error = -1;
    int opcion;
    int validate;
    if(pResult != NULL && errorMsj != NULL && min <= max)
    {
        do
        {
            printf("\nIngrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            validate = isdigit(opcion);
            if((opcion >= min && opcion <= max) && !validate)
            {
                *pResult = opcion;
                error = 0;
            }
            else
            {
                printf("%s\n", errorMsj);
                system("pause");
            }
        }
        while(error != 0);
    }
    return error;
}

int charOnly(char str[])
{

    int i = 0;
    while (str[i])
    {
        if (
            !isalpha(str[i])
            && str[i] != ' '
        )
            return -1;
        i++;
    }

    return 0;
}
