#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 5

typedef struct
{
    int legajo;
    int edad;
    char sexo;
} eEmpleado;

int obtenerOpcion(int* pResultado, char* errorMsj, int min, int max);
void imprimirMenuPrincipal();
int obtenerEdadPromedio(eEmpleado* vec, int tam, float* edadPromedio);
int obtenerEmpleadoMayor(eEmpleado* vec, int tam);
int obtenerMujeres1978(eEmpleado* vec, int tam);

int main()
{
    eEmpleado empleados[TAM] =
    {
        {1000, 42, 'f'},
        {1001, 50, 'm'},
        {1002, 38, 'm'},
        {1003, 25, 'f'},
        {1004, 42, 'f'}
    };

    int menuPrincipal;
    int opcionPrincipal;

    float promedio;

    do
    {
        imprimirMenuPrincipal();
        menuPrincipal = obtenerOpcion(
                            &opcionPrincipal,
                            "\n\nOpcion invalida. Vuelva a intentar.\n\n",
                            1,
                            4
                        );
        if(!menuPrincipal)
        {
            switch(opcionPrincipal)
            {
            case 1:
                if(obtenerEdadPromedio(empleados, TAM, &promedio) < 0)
                {
                    printf("\nLo sentimos, ha ocurrido un error.\n");
                }
                else
                {
                    printf("\nEl promedio de todas las edades da: %.2f\n", promedio);
                }
                break;
            case 2:
                if(obtenerEmpleadoMayor(empleados, TAM) < 0)
                {
                    printf("\nLo sentimos, ha ocurrido un error.\n");
                }
                else
                {
                    printf("\nEl promedio de todas las edades da: %.2f\n", promedio);
                }
                break;
            case 3:
                if(obtenerMujeres1978(empleados, TAM) < 0)
                {
                    printf("\nLo sentimos, ha ocurrido un error.\n");
                }
                else
                {
                    printf("\nEl promedio de todas las edades da: %.2f\n", promedio);
                }
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while(opcionPrincipal != 4);

    return 0;
}

int obtenerOpcion(int* pResultado, char* errorMsj, int min, int max)
{
    int error = -1;
    int opcion;
    int validar;
    if(pResultado != NULL && errorMsj != NULL && min <= max && min > 0 && max > 0)
    {

        do
        {
            printf("\nIngrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            validar = isdigit(opcion);
            if((opcion >= min && opcion <= max) && !validar)
            {
                *pResultado = opcion;
                error = 0;
            }
            else
            {
                printf("%s\n", errorMsj);
                system("pause");
            }
        }
        while(error != 0);
    }
    return error;
}

void imprimirMenuPrincipal()
{
    system("cls");
    printf("______________________________________________________\n");
    printf("              INFORMES DE EMPLEADOS\n");
    printf("______________________________________________________\n");
    printf("                  MENU PRINCIPAL\n");
    printf("______________________________________________________\n");
    printf("1. CONOCER EDAD PROMEDIO DE LOS EMPLEADOS DE LA FABRICA.\n");
    printf("2. CONOCER EL LEGAJO Y SEXO DE LA PERSONA DE MAYOR EDAD.\n");
    printf("3. CONOCER CUANTAS MUJERES NACIERON EN EL ANIO 1978.\n");
    printf("4. SALIR\n");
}

int obtenerEdadPromedio(eEmpleado* vec, int tam, float* edadPromedio)
{
    int error = -1;
    int acumEdad = 0;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            acumEdad += (vec + i)->edad;
        }
        *edadPromedio = (float) acumEdad / tam;
        error = 0;
    }

    return error;
}

int obtenerEmpleadoMayor(eEmpleado* vec, int tam)
{
    int error = -1;
    eEmpleado mayor = *(vec);
    if(vec != NULL && tam > 0)
    {

        for(int i = 0; i < tam; i++)
        {
            if(mayor.edad < (vec + i)->edad)
            {
                mayor = *(vec + i);
            }
        }

        printf("\nLa persona de mayor edad tiene %d\n", mayor.edad);
        printf("\nSu legajo es %d\n", mayor.legajo);
        if(mayor.sexo == 'm')
        {
            printf("\nSexo masculino.\n");
        }
        else
        {
            printf("\nSexo femenino.\n");
        }
        error = 0;
    }

    return error;
}

int obtenerMujeres1978(eEmpleado* vec, int tam)
{
    int error = -1;
    int mujeres = 0;

    if(vec != NULL && tam > 0)
    {

        for(int i = 0; i < tam; i++)
        {
            if((vec + i)->edad == 42)
            {
                mujeres++;
            }
        }

        if(mujeres == 0)
        {
            printf("\nNo hay mujeres con esas caracteristicas\n");
        }
        else
        {
            printf("\nHay %d mujeres nacidas en 1978.\n", mujeres);
        }

        error = 0;
    }

    return error;
}
