#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ePersonas.h"
#include "validaciones.h"
#define TAM 25
#define INIT_ID 2000


int main()
{
    ePersona list[TAM];
    int opMenu;
    int opcion;
    int resultadoHarcodeo;
    // case 1
    int addPer;
    int actualID = INIT_ID;
    // case 3
    int modificarPer;
    // case 4
    int imprimirPersonas;

    initPersonas(list, TAM);
    resultadoHarcodeo = hardcodearPersonas(list, TAM, 10);
    actualID += resultadoHarcodeo;
    do
    {
        menu();
        opMenu = getOption(&opcion, "\nOpcion invalida, intente nuevamente\n", 1, 7);
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
                printf("Opcion en mantenimiento\n");
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
                printf("Opcion en mantenimiento\n");
                break;
            case 6:
                printf("Opcion en mantenimiento\n");
                break;
            case 7:
                printf("Saliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while(opcion != 7);

    return 0;
}


// Un deporte puede ser practicado por muchas personas = m:1 (Uno a muchos).
// de persona a deporte 1:1 (Una persona practica un deporte. Uno a Uno).
// Una estructura Personas tiene un campo Id deportes que hace referencia a una matriz de deportes
// que tiene el numero id del deporte y la descripción (nombre) del mismo
