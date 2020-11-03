#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int legajo;
    char nombre[21];
    char sexo;
    float altura;
} ePersona;

int personas_inicializar(ePersona** lista, int tam);
int personas_buscarLibre(int* pIndice, ePersona** lista, int tam);
int personas_mostrarItem(ePersona* persona);
int personas_mostrarLista(ePersona** lista, int tam);

//Contructora
ePersona* persona_new();

int main()
{
    int tam = 5;
    int indiceLibre;

    ePersona** personas = (ePersona**) malloc(tam * sizeof(ePersona*));
    ePersona* auxPersona;

    /*
    lista es un puntero a puntero, ya que apunta a la dirección
    de memoria del primer elemento de la lista, que es un puntero.
    Por eso tiene doble asterísco **
    Entonces, hay que castear el puntero como PUNTERO A PUNTERO
    con doble asterico tambien

    100PRE que declaramos un puntero hay que inicializarlo en NULL
    */

    if(personas == NULL)
    {
        printf("\nNo se pudo conseguir memoria...\n");
        exit(EXIT_FAILURE); //SOLO SE USA EXIT EN MAIN, NO EN OTRAS FUNCIONES!!!
    }

    //inicializar
    if(!personas_inicializar(personas, tam))
    {
        printf("\nInicializacion exitosa.\n");
    }
    else
    {
        printf("\nProblemas al inicializar personas.\n");
    }

    //buscar libre
    if(personas_buscarLibre(&indiceLibre, personas, tam))
    {
        printf("\nAlguno de los punteros es null\n");
    }

    if(indiceLibre == -1)
    {
        printf("\nNo hay mas lugar....\n"); //Acá habría que hacer un realloc.
    }
    else
    {
        printf("\n%d\n", indiceLibre);
        auxPersona = persona_new();
        if(auxPersona == NULL)
        {
            printf("\nNo se pudo conseguir espacio en la memoria.\n");
        }
        else
        {
            auxPersona->legajo = 1234;
            strcpy(auxPersona->nombre, "Pepe");
            auxPersona->sexo = 'm';
            auxPersona->altura = 1.88;

            *(personas + indiceLibre) = auxPersona;

            printf("\nAlta exitosa\n");
            personas_mostrarLista(personas, tam);
        }
    }

    return 0;
}

int personas_inicializar(ePersona** lista, int tam)
{
    int error = -1;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            *(lista + i) = NULL;
            //(lista+i) hace referencia al primer elemento del array.
            // con * adelanrte hacemos referencia al valor de lon que hay en esa posición
        }
        error = 0;
    }

    return error;
}

int personas_buscarLibre(int* pIndice, ePersona** lista, int tam)
{
    int error = -1;

    if(lista != NULL && pIndice != NULL && tam > 0)
    {
        *pIndice = -1; //Si no se logró cargar el dato porque el vector esta lleno
        for(int i = 0; i < tam; i++)
        {
            if(*(lista + i) == NULL)
            {
                *pIndice = i;
                break;
            }
        }
        error = 0;
    }

    return error;
}

int personas_mostrarItem(ePersona* persona)
{
    int error = -1;

    if(persona != NULL)
    {
        printf(" %d   %10s       %c       %.2f\n",
               persona->legajo,
               persona->nombre,
               persona->sexo,
               persona->altura
              );

        error = 0;
    }

    return error;
}

int personas_mostrarLista(ePersona** lista, int tam)
{
    int error = -1;
    int flag = 0;

    if(lista != NULL && tam > 0)
    {
        printf("\n ID         NOMBRE      SEXO    ALTURA\n");
        for(int i = 0; i < tam; i++)
        {
            if(*(lista + i ) != NULL)
            {
                personas_mostrarItem(*(lista + i));
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("\nNo hay personas para mostrar.\n");
        }

        error = 0;
    }
    return error;
}

ePersona* persona_new()
{
    //Nosotros al invocar esta funcion debemos asegurarnos que devuelva algo distinto de null
    return (ePersona*) malloc(sizeof(ePersona));
}
