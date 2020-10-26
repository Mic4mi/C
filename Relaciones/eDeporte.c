#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "eDeporte.h"


int mostrarDeportes(eDeporte* sports, int tam)
{
    int error = -1;
    if(sports != NULL && tam > 0)
    {
        printf("******************************************\n");
        printf("               DEPORTES \n"                 );
        printf("****************************************** \n");
        printf("   ID            DESCRIPCION\n"               );
        printf("******************************************\n");
        for(int i = 0; i < tam; i++)
        {
            mostrarDeporte(sports[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}
void mostrarDeporte(eDeporte sport)
{
    printf("%d      %20s\n", sport.id, sport.descripcion);
}

//mostrar deporte por id
int findDeporteById(eDeporte* list, int len,int id)
{
    int indiceId = -1;
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id)
            {
                indiceId = list[i].id;
                break;
            }
        }
    }
    return indiceId;
}

int cargarDescripcionDeporte(eDeporte* sports, int len, int id, char descripcion[])
{
    int error = -1;
    if(sports!= NULL && id > 0 && descripcion!= NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {

            strcpy(descripcion, sports[i].descripcion);
            error = 0;
            break;
        }
    }
    return error;
}

