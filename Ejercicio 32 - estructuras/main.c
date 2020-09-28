#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 4


struct
{
    int legajo;
    char name[51];
    char sexo;
    float altura;
    int isEmpty;
} typedef ePersona;

int inicializarPersonas(ePersona list[], int len);
int printPersonas(ePersona list[], int len);
void printPersona(ePersona emp);
int altaPersona(ePersona list[], int len, char name[], char sexo, float altura);
int buscarLibre(ePersona list[], int len);

int main()
{
    ePersona lista[TAM];
    inicializarPersonas(lista, TAM);

    printPersonas(lista, TAM);

    return 0;
}

int inicializarPersonas(ePersona list[], int len)
{
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        return 0;
    }

    return -1;
}

int printPersonas(ePersona list[], int len)
{
    int flag = 0;
    if(list != NULL && len > 0 && len <= 1000)
    {
        //system("cls");
        printf("Legajo         Nombre    Sexo     Altura \n");
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty != 1)
            {
                printPersona(list[i]);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay personas\n");
        }

        printf("\n\n");
        return 0;
    }
    return -1;
}

void printPersona(ePersona emp)
{
    printf(" %4d    %10s    %c    %.2f \n",
           emp.legajo,
           emp.name,
           emp.sexo,
           emp.altura);
}

int altaPersona(ePersona list[], int len, char name[], char sexo, float altura)
{
    int error = -1
    ePersona nuevaPersona;
    int indice;

    if(list != NULL && len > 0)
    {
        indice = buscarLibre(list, len);
        if(indice == -1){
            printf("Sistema Completo.\n");
        }

        for(int i = 0; i < len; i++)
        {

        }
    }

}

int buscarLibre(ePersona list[], int len)
{
    int indiceLibre = -1;
    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            indiceLibre = i;
        }
    }
    return indiceLibre;
}
