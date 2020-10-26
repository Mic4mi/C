#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "eDeporte.h"
#include "validaciones.h"
#include "ePersonas.h"
#define TAM 25
#define TAM_D 6
#define INIT_ID 20000

/*
Informe:
La idea es mostrar a las personas por x parametro
Ej: Mostrar por sexo:
1_ Solo debe mostrar las personas por sexo f o m según corresponda
*/

int main()
{
    ePersona list[TAM];
    int opMenu;
    int opcion;
    int resultadoHarcodeo;
    // case 1
    int addPer;
    int actualID = INIT_ID;
    // case 2
    int borrar;
    // case 3
    int modificarPer;
    // case 4
    int imprimirPersonas;
    //DEPORTES!!! NUEVO
    eDeporte deportes[TAM_D] =
    {
        {1000, "No practica"},
        {1001, "Bicicleta"},
        {1002, "Patin"},
        {1003, "Esqui"},
        {1004, "Surf"},
        {1005, "Parapente"}
    };

    initPersonas(list, TAM);
    resultadoHarcodeo = hardcodearPersonas(list, TAM, 10);
    actualID += resultadoHarcodeo + 1;
    do
    {
        menu();
        opMenu = getOption(&opcion, "\nOpcion invalida, intente nuevamente\n", 1, 8);
        if(!opMenu)
        {
            switch(opcion)
            {
            case 1:
                addPer = addPersona(list, TAM, actualID, deportes, TAM_D);
                if(addPer < 0)
                {
                    printf("Ha ocurrido un problema. Intente nuevamente\n");
                }
                else
                {
                    printf("Operacion exitosa.\n");
                    actualID++;
                }
                break;
            case 2:
                borrar = removePersona(list, TAM, deportes, TAM_D);
                if(!borrar)
                {
                    printf("Baja exitosa.\n");
                }
                else if(borrar == 1)
                {
                    printf("Baja cancelada por usuario.\n");
                }
                else
                {
                    printf("Problemas al realizar la baja. Intente nuevamente\n");
                }
                break;
            case 3:
                modificarPer = modifiePersona(list, TAM, deportes, TAM_D);
                if(!modificarPer)
                {
                    printf("Modificacion exitosa.\n");
                }
                else
                {
                    printf("Problemas al realizar la modificacion. Intente nuevamente\n");
                }
                break;
            case 4:
                imprimirPersonas = printPersonas(list, TAM, deportes, TAM_D);
                if(imprimirPersonas < 0)
                {
                    printf("\nError al imprimir personas./n");
                }
                break;
            case 5:
                system("cls");
                mostrarDeportes(deportes, TAM_D);
                break;
            case 6:
                printf("Opcion en mantenimiento\n");
                break;
            case 7:
                printf("Opcion en mantenimiento\n");
                break;
            case 8:
                printf("Saliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while(opcion != 8);

    return 0;
}



/*
//informar x deporte
int informarXDeporte(ePersona lista, int tamP, eDeporte listaD, int tamD){
    int error = -1;
    int deportID;
    if(lista != NULL && listaD != NULL && tamP > 0 && tamD > 0){
        system("cls");
        printf("******************************************\n");
        printf("               DEPORTES \n"                 );
        printf("****************************************** \n");
        printf("   ID            DESCRIPCION\n"               );
        printf("******************************************\n");
        mostrarDeportes(listaD, tamD);
        printf("\nIngrese ID del deporte: ");
        //fflush(stdin);
        scanf("%d", &deportID);
        printf("\nNombres")
    }
}
*/


