#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pNumero; //declaracion dinamica
    pNumero = (int*) malloc(sizeof(int)); //le tengo que pasar la cantidad de bytes q necesito y castearlo

    if(pNumero == NULL) //Si malloc no consigue espacio retorna null. Hay que validar.
    {
        printf("\nNo hay espacio en memoria.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nIngrese un numero: ");
    scanf("%d", pNumero); //Scanf siempre recibe direcciones de memoria, como pNumero ya es una, no requiere &

    printf("\nNumero ingresado: %d", *pNumero);

    free(pNumero);

    return 0;
}
