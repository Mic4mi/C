#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ePersonas.h"
#include "validaciones.h"
#define TAM 25
#define TAM_D 6
#define INIT_ID 2000

typedef struct
{
    int id;
    char descripcion[20];
} eDeporte;

int mostrarDeportes(eDeporte* sports, int tam);
void mostrarDeporte(eDeporte sport);


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
        {1005, "Parapente"},
    };


    initPersonas(list, TAM);
    resultadoHarcodeo = hardcodearPersonas(list, TAM, 10);
    actualID += resultadoHarcodeo;
    do
    {
        menu();
        opMenu = getOption(&opcion, "\nOpcion invalida, intente nuevamente\n", 1, 8);
        if(!opMenu)
        {
            switch(opcion)
            {
            case 1:
                addPer = addPersona(list, TAM, actualID);
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
                borrar = removePersona(list, TAM);
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
                modificarPer = modifiePersona(list, TAM);
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
                imprimirPersonas = printPersonas(list, TAM);
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
        for(int i = 0; i < tam; i++) {
            mostrarDeporte(sports[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}
void mostrarDeporte(eDeporte sport) {
    printf("%d      %20s\n", sport.id, sport.descripcion);
}
// Un deporte puede ser practicado por muchas personas = m:1 (Uno a muchos).
// de persona a deporte 1:1 (Una persona practica un deporte. Uno a Uno).
// Una estructura Personas tiene un campo Id deportes que hace referencia a una matriz de deportes
// que tiene el numero id del deporte y la descripción (nombre) del mismo
