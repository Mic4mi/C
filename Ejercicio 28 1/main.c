#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char nombres[5][20];

    // Cargar nombres en el array de arrays
    for(int i = 0; i < 5; i++)
    {
        printf("Ingrese nombre\n");
        fflush(stdin);
        gets(nombres[i]);
    }

    //mostrar nombres del array de arrays
    printf("\nLos nombres son:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%s\n", nombres[i]);
    }

    return 0;
}
