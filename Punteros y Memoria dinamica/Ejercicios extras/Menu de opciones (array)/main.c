#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 5


int obtenerOpcion(int* pResultado, char* errorMsj, int min, int max);
void menuPrincipal();
int cargarVector(int* vec, int tam);
int mostrarVector(int* vec, int tam);
int ordenarVector(int* vec, int tam);

int main()
{
    int numeros[TAM];
    int menu;
    int opcion;
    int bandera = 0;

    do
    {
        menuPrincipal();
        menu = obtenerOpcion(
                   &opcion,
                   "\nLo sentimos, algio salio mal...\n",
                   1,
                   4
               );

        if(!menu)
        {
            switch(opcion)
            {
            case 1:
                if(cargarVector(numeros, TAM) < 0)
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                else
                {
                    printf("\nOperacion exitosa\n");
                    bandera = 1;
                }
                break;
            case 2:
                if(!bandera)
                {
                    printf("\nPrimero debe cargar el vector...\n");
                    break;
                }

                if(ordenarVector(numeros, TAM) < 0)
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                else
                {
                    printf("\nOperacion exitosa\n");
                }
                break;
            case 3:
                if(!bandera)
                {
                    printf("\nPrimero debe cargar el vector...\n");
                    break;
                }

                if(mostrarVector(numeros, TAM) < 0)
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                else
                {
                    printf("\nOperacion exitosa\n");
                }
                break;
            case 4:
                printf("\nSaliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while(opcion != 4);


    return 0;
}

int obtenerOpcion(int* pResultado, char* errorMsj, int min, int max)
{
    int error = -1;
    int opcion;
    int validar;
    if(pResultado != NULL && errorMsj != NULL && min <= max && min > 0 && max > 0)
    {

        do
        {
            printf("\nIngrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            validar = isdigit(opcion);
            if((opcion >= min && opcion <= max) && !validar)
            {
                *pResultado = opcion;
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

void menuPrincipal()
{
    system("cls");
    printf("______________________________________________________\n");
    printf("            Manipular numeros enteros\n");
    printf("______________________________________________________\n");
    printf("                  MENU PRINCIPAL\n");
    printf("______________________________________________________\n");
    printf("1. CARGAR VECTOR\n");
    printf("2. ORDENAR VECTOR\n");
    printf("3. MOSTRAR VECTOR\n");
    printf("4. SALIR\n");
}

int cargarVector(int* vec, int tam)
{
    int error = -1;

    if(vec != NULL)
    {
        system("cls");
        printf("______________________________________________________\n");
        printf("                  CARGAR VECTOR\n");
        printf("______________________________________________________\n");
        for(int i = 0; i < tam; i++)
        {
            printf("\nIngrese numero: ");
            fflush(stdin);
            scanf("%d", vec + i);
        }
        error = 0;
    }
    return error;
}

int mostrarVector(int* vec, int tam)
{
    int error = -1;
    if(vec != NULL)
    {
        system("cls");
        printf("______________________________________________________\n");
        printf("                   MOSTRAR VECTOR\n");
        printf("______________________________________________________\n");
        for(int i = 0; i < tam; i++)
        {
            printf("%d\n", *(vec + i));
        }
        error = 0;
    }
    return error;
}

int ordenarVector(int* vec, int tam)
{
    int error = -1;
    int aux;
    if(vec != NULL)
    {
        system("cls");
        printf("Ordenando vector...\n");
        for(int i = 0; i < tam-1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(*(vec + i) > *(vec + j))
                {
                    aux = *(vec + i);
                    *(vec + i) = *(vec + j);
                    *(vec + j) = aux;
                }
            }
        }
        error = 0;
    }
    return error;
}
