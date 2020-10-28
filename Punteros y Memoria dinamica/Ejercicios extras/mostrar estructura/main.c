#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[21];
    char sexo;
    float sueldo;
} eEmpleado;

void mostrarEmpleado(eEmpleado e); //Sin puntero
void mostrarEmpleadoP(eEmpleado* pEmp); //Con puntero
void mostrarEmpleadoPRemasterizada(eEmpleado* pEmp); //Con puntero pero usando operador flecha

int main()
{
    eEmpleado jorge = {1002, "Jorge", 'm', 45950.25};

    mostrarEmpleadoPRemasterizada(&jorge);

    return 0;
}

void mostrarEmpleado(eEmpleado e)
{
    printf("___________________________________\n");
    printf("ID     NOMBRE    SEXO    SUELDO\n");
    printf("___________________________________\n");
    printf("%d   %s      %c      %.2f\n",
           e.id,
           e.nombre,
           e.sexo,
           e.sueldo);
}

void mostrarEmpleadoP(eEmpleado* pEmp)
{
    printf("___________________________________\n");
    printf("ID     NOMBRE    SEXO    SUELDO\n");
    printf("___________________________________\n");
    printf("%d   %s      %c      %.2f\n",
           pEmp-> id,
           (*pEmp).nombre,
           (*pEmp).sexo,
           (*pEmp).sueldo);
}

void mostrarEmpleadoPRemasterizada(eEmpleado* pEmp)
{
    printf("___________________________________\n");
    printf("ID     NOMBRE    SEXO    SUELDO\n");
    printf("___________________________________\n");
    printf("%d   %s      %c      %.2f\n",
           pEmp->id,
           pEmp->nombre,
           pEmp->sexo,
           pEmp->sueldo);
}

