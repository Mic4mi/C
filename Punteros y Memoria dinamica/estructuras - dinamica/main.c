#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[21];
    char sexo;
    float sueldo;
} eEmpleado;

int mostrarEmpleado(eEmpleado* pEmp);

int main()
{
    eEmpleado* pEmp1 = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(pEmp1 == NULL)
    {
        printf("\nNo se pudo obtener memoria.\n");
        exit(EXIT_FAILURE);
    }

    //CARGAR ESTRUCTURA
    pEmp1->legajo = 1234;
    strcpy(pEmp1->nombre, "Jose");
    pEmp1->sexo = 'm';
    pEmp1->sueldo = 47265.78;

    mostrarEmpleado(pEmp1);

    free(pEmp1);
    return 0;
}

int mostrarEmpleado(eEmpleado* pEmp)
{
    int error = -1;

    if(pEmp != NULL)
    {
        printf("______________________________________________________\n");
        printf(" LEGAJO     NOMBRE          SEXO             SUELDO\n");
        printf("______________________________________________________\n");

        printf("  %d       %s             %c            $%.2f",
               pEmp->legajo,
               pEmp->nombre,
               pEmp->sexo,
               pEmp->sueldo
              );

        printf("\n\n");

        error = 0;
    }

    return error;
}
