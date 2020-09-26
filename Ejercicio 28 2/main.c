#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void mostrarNombres(char mat[][20], int tam);

int main()
{
    //MOSTRAR INICIALES
    /* ¿Cómo muestro un solo char? Acá estaría agarrando el segundo elemento de la cadena
    en el indice cero, es decir, una letra.
    */
    char nombres[5][20] = {"saturno", "homeros", "marita", "berus", "carlita"};
    char aux[20];

    //mostrar nombres del array de arrays
    /*
        printf("\nLos nombres son:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%s\n", nombres[i]);
    }
    */
    mostrarNombres(nombres, 5);

    //mostrar iniciales
    printf("\nLas inciales son:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%c\n", nombres[i][0]);
    }

    // muestro una cadena dentro de una matriz
    printf("\nMuestro la primer cadena dentro de la matriz:\n");
    printf("%s\n", nombres[0]);

    return 0;
}

void mostrarNombres(char mat[][20], int tam)
{
    printf("\nLos nombres son:\n");
    for(int i = 0; i < tam; i++)
    {
        printf("%s\n", mat[i]);
    }
}
