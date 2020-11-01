#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarEnteros(int* vec, int tam);

int main()
{
    /*
    Cuando se declara un puntero es buena práctica inicializarlos en NULL.
    De lo contrario, puede mostrar basura o apuntar a direcciones aleatorias.
    */

    int* pNumeros = NULL;

    pNumeros = (int*) malloc(TAM * sizeof(int)); //conseguir espacio para un vector de 5

    if(pNumeros == NULL)
    {
        printf("\nNo se pudo obtener memoria.\n");
        exit(EXIT_FAILURE);
    }

    //Cargar el vector? Para colocar un solo elemento en x posición hay que correrse x cantidad de sizeofss
    //Ejemplo: Cargar en la posición 3 un numero

    *(pNumeros + 2) = 5;
    printf("\nEl elemento en el indice 2 vale: %d\n", *(pNumeros + 2));

    //Cargar secuencialmente
    for(int i = 0; i < TAM; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", pNumeros + i);
    }

    printf("\n\n");

    mostrarEnteros(pNumeros, TAM);

    free(pNumeros);
    return 0;
}

void mostrarEnteros(int* vec, int tam)
{
    //Mostrar numeros
    system("cls");
    printf("\nLa lista de numeros:\n");
    for(int i = 0; i < tam; i++)
    {
        printf("%d ", *(vec + i));
    }
    printf("\n\n");
}
