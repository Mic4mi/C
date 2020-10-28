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
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo);
//validar
int empleado_setLegajo(eEmpleado* pEmp, int legajo);
int empleado_setSueldo(eEmpleado* pEmp, float sueldo);
int empleado_setSexo(eEmpleado* pEmp, char sexo);
int empleado_setNombre(eEmpleado* pEmp, char*nombre);

int main()
{
    eEmpleado* pEmp1 = newEmpleado();
    eEmpleado* pEmp2 = newEmpleadoParam(3333, "Julia", 'f', 62000);

    if(pEmp1 == NULL && pEmp2 != NULL)
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
    mostrarEmpleado(pEmp2);

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

/*
función constructrora
devuelve un puntero a una nueva estructura empleado vacia
*/

eEmpleado* newEmpleado()
{
    eEmpleado* nuevoEmpleado = NULL;
    nuevoEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->legajo = 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->sexo = ' ';
        nuevoEmpleado->sueldo = 0;
    }
    return nuevoEmpleado;
}

/*
función constructrora con parametros
devuelve un puntero a una nueva estructura empleado cargada
*/

eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo)
{
    eEmpleado* nuevoEmpleado = newEmpleado();

    if(nuevoEmpleado != NULL)
    {

        if(
            !(!empleado_setLegajo(nuevoEmpleado, legajo) &&
              !empleado_setNombre(nuevoEmpleado, nombre) &&
              !empleado_setSexo(nuevoEmpleado, sexo) &&
              !empleado_setSueldo(nuevoEmpleado, sueldo))
        )
        {
            nuevoEmpleado = NULL;
        }
    }

    return nuevoEmpleado;
}


/*

Validaciones!!!!

getter -> Leer. Obtiene datos

setter -> Escribir


*/

int empleado_setLegajo(eEmpleado* pEmp, int legajo)
{
    int error = -1;

    if(pEmp != NULL && legajo > 0)
    {
        pEmp->legajo = legajo;
        error = 0;
    }

    return error;
}

int empleado_setSueldo(eEmpleado* pEmp, float sueldo)
{
    int error = -1;

    if(pEmp != NULL && sueldo > 0)
    {
        pEmp->sueldo = sueldo;
        error = 0;
    }

    return error;
}

int empleado_setSexo(eEmpleado* pEmp, char sexo)
{
    int error = -1;

    if(pEmp != NULL && (sexo == 'm' || sexo == 'f'))
    {
        pEmp->sexo = sexo;
        error = 0;
    }

    return error;
}

int empleado_setNombre(eEmpleado* pEmp, char*nombre)
{
    int error = -1;

    if(pEmp != NULL && nombre != NULL) //Profundizar validacion
    {
        strcpy(pEmp->nombre, nombre);
        error = 0;
    }

    return error;
}
