#include <stdio.h>
#include <stdlib.h>


void mostrarEnteros(int* vec, int tam);

int main()
{
    int tam = 5;
    int* pNumeros = NULL;
    int* pNumerosAux = NULL;

    pNumeros = (int*) malloc(tam * sizeof(int)); //conseguir espacio para un vector de 5

    if(pNumeros == NULL)
    {
        printf("\nNo se pudo obtener memoria.\n");
        exit(EXIT_FAILURE);
    }

    //Cargo
    for(int i = 0; i < tam; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", pNumeros + i);
    }

    mostrarEnteros(pNumeros, tam);

    /*
    Si quiero cambiar el tamaño del vector? Uso realloc();

    x void* <--- malloc(sizeof(int) * 5);
    x void* <--- realloc(x, sizeof(int) * (5*2)); ---> Ahora quiero 10 espacios

    Realloc puede devolver  cosas
    - misma direccion
    - direccion nueva si tuvo que buscar otro lugar
    - NULL si no consiguió

    */

    //pedir lugar para 5 lugares mas. Lo guardo primero en un aux, por si devuelve null
    pNumerosAux = (int*) realloc(pNumeros, sizeof(int) * (tam * 2));
    if(pNumerosAux != NULL)
    {
        pNumeros = pNumerosAux;
        tam *= 2;
        printf("\nVector redimensionado con exito\n");
        pNumerosAux = NULL;
    }
    else
    {
        printf("No fue posible conseguir mas espacio.");
    }

    //reanudar carga
    for(int i = 5; i < tam; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", pNumeros + i);
    }

    mostrarEnteros(pNumeros, tam);

    //Achicar vector
    pNumeros = (int*) realloc(pNumeros, sizeof(int) * (tam - 4));
    tam -= 4;

    mostrarEnteros(pNumeros, tam);


    free(pNumeros);
    return 0;
}

void mostrarEnteros(int* vec, int tam)
{
    //Mostrar numeros
    printf("\nLa lista de numeros:\n");
    for(int i = 0; i < tam; i++)
    {
        printf("%d ", *(vec + i));
    }
    printf("\n\n");
}
