#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void mostrarNombres(char mat[][20], int tam);

int main()
{
    char nombres[5][20] = {"Saturno", "Homeros", "Marita", "Beruska", "Carlita"};

    mostrarNombres(nombres, 5);

    ordenarNombresAlf(nombres, 5);

    mostrarNombres(nombres, 5);

    return 0;
}

void mostrarNombres(char mat[][20], int tam)
{
    printf("Los nombres son:\n");
    for(int i = 0; i < tam; i++)
    {
        printf("%s\n", mat[i]);
    }
}

void ordenarNombresAlf(char vec[][20], int tam)
{
    char aux[20];
    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(strcmp(vec[i], vec[j]) > 0)
            {
                strcpy(aux, vec[i]);
                strcpy(vec[i], vec[j]);
                strcpy(vec[j], aux);
            }
        }
    }
}
