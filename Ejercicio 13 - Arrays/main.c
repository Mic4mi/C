#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#define TAM 10

/*
1) pedir posicion y valor mientrase el quiera
2) mostrar el array
*/

int main()
{
    int numeros[TAM] = {0};
    int posicion;
    char seguir = 's';

    do
    {
        printf("Ingrese posicion para guardar el dato\n");
        scanf("%d", &posicion);
        while(posicion < 1 || posicion > 10)
        {
            printf("Posicion invalida.\nIngrese posicion para guardar el dato\n");
            scanf("%d", &posicion);
        }

        printf("Ingrese un numero\n");
        scanf("%d", &numeros[posicion-1]);

        printf("Quiere continuar?\n");
        fflush(stdin);
        seguir = tolower(getchar());
    }
    while(seguir == 's');

    printf("El array quedo: \n");
    for(int i = 0; i < TAM; i++)
    {
        printf("%d\n", numeros[i]);
    }



    return 0;
}


