#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int id;
    char nombre[21];
    char sexo;
    float sueldo;
    eFecha fIngreso;
} eEmpleado;

void cargarEmpleado(eEmpleado* pEmp);
void mostrarEmpleadoPRemasterizada(eEmpleado* pEmp);

int main()
{
    eEmpleado emp1;

    cargarEmpleado(&emp1);

    mostrarEmpleadoPRemasterizada(&emp1);

    return 0;
}

void cargarEmpleado(eEmpleado* pEmp)
{
    if(pEmp != NULL)
    {
        printf("Cargue un empleado!!\n");

        printf("\nIngrese id: ");
        fflush(stdin);
        scanf("%d", &pEmp->id);

        printf("\n\nIngrese nombre: ");
        fflush(stdin);
        gets(pEmp->nombre); //los strings son punteros, no requieren &

        printf("\n\nIngrese sexo: ");
        fflush(stdin);
        scanf("%c", &pEmp->sexo);

        printf("\n\nIngrese salario: ");
        fflush(stdin);
        scanf("%f", &pEmp->sueldo);

        printf("\n\nFecha de ingreso dd/mm/aaaa: ");
        fflush(stdin);
        scanf(
            "%d/%d/%d",
            &pEmp->fIngreso.dia,
            &pEmp->fIngreso.mes,
            &pEmp->fIngreso.anio
        );

        printf("\n\n");

    }
}

void mostrarEmpleadoPRemasterizada(eEmpleado* pEmp)
{
    system("cls");
    printf("_____________________________________________________________\n");
    printf("ID     NOMBRE    SEXO      SUELDO         FECHA DE INGRESO\n");
    printf("_____________________________________________________________\n");
    printf("%d   %s      %c       %.2f        %d/%d/%d\n",
           pEmp->id,
           pEmp->nombre,
           pEmp->sexo,
           pEmp->sueldo,
           pEmp->fIngreso.dia,
           pEmp->fIngreso.mes,
           pEmp->fIngreso.anio);
}
