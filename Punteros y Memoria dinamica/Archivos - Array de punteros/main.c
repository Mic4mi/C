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
ePersona* persona_newParams(int id, char* nombre, char sexo, float altura);

//destructora
int personas_destruir(ePersona* persona);

//buscar
int personas_buscar(int* pIndice, int id, ePersona** lista, int tam);

int main()
{
    int tam = 5;
    int indiceLibre;
    int indiceBaja;

    ePersona** personas = (ePersona**) malloc(tam * sizeof(ePersona*));
    ePersona* auxPersona;

    /*
    lista es un puntero a puntero, ya que apunta a la direcci�n
    de memoria del primer elemento de la lista, que es un puntero.
    Por eso tiene doble aster�sco **
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
        printf("\nNo hay mas lugar....\n"); //Ac� habr�a que hacer un realloc.
    }
    else
    {
        printf("\n%d\n", indiceLibre);
        auxPersona = persona_newParams(1450, "Agustin", 'm', 1.82);
        if(auxPersona == NULL)
        {
            printf("\nNo se pudo conseguir espacio en la memoria.\n");
        }
        else
        {

            *(personas + indiceLibre) = auxPersona;
            printf("\nAlta exitosa\n");
        }
    }
    personas_mostrarLista(personas, tam);
    printf("\n----------------------------------------------------\n");

    personas_buscar(&indiceBaja, 1450, personas,tam);

    if(indiceBaja == -1)
    {
        printf("\nNo hay personas con ese id\n");
    }
    else
    {
        personas_destruir(*(personas + indiceBaja));
        *(personas + indiceBaja) = NULL;
    }

    personas_mostrarLista(personas, tam);

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
            // con * adelanrte hacemos referencia al valor de lon que hay en esa posici�n
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
        *pIndice = -1; //Si no se logr� cargar el dato porque el vector esta lleno
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
    ePersona* nuevaPersona;
    nuevaPersona = (ePersona*) malloc(sizeof(ePersona));

    if(nuevaPersona != NULL)
    {
        nuevaPersona->legajo = 0;
        strcpy(nuevaPersona->nombre, "");
        nuevaPersona->sexo = ' ';
        nuevaPersona->altura = 0;
    }

    return nuevaPersona;
}

ePersona* persona_newParams(int id, char* nombre, char sexo, float altura)
{
    ePersona* nuevaPersona;

    nuevaPersona = persona_new();

    if(nuevaPersona != NULL)
    {
        //Cada campo se debe validar con un SETTER
        nuevaPersona->legajo = id;
        strcpy(nuevaPersona->nombre, nombre);
        nuevaPersona->sexo = sexo;
        nuevaPersona->altura = altura;
    }
    /*
    UNA VEZ QUE SE VALIDA CADA CAMPO CON LOS SETTER,
    SI LAS COSAS NO SON VALIDAS, SE ENTRA POR ESTE ELSE
    QUE BASICAMENTE LIBERA LA MEMORIA OCUPADA Y CONVIERTE
    EL PUNTERO A NULL

    else
    {
       free(nuevaPersona);
       nuevaPersona = NULL;
    }
    */

    return nuevaPersona;
}

int personas_destruir(ePersona* persona)
{
    int error = -1;

    if(persona != NULL)
    {
        free(persona);
        error = 0;
    }

    return error;
}

int personas_buscar(int* pIndice, int id, ePersona** lista, int tam)
{
    int error = -1;

    if(lista != NULL && pIndice != NULL && tam > 0)
    {
        *pIndice = -1; //Si no se logr� cargar el dato porque no lo econtr�
        for(int i = 0; i < tam; i++)
        {
            if(*(lista + i) != NULL && (*(lista + i ))->legajo == id)
            {
                *pIndice = i;
                break;
            }
        }
        error = 0;
    }

    return error;
}

