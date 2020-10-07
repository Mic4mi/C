#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dataStore.h"
#include "eFechas.h"
#include "ePersonas.h"
#include "validaciones.h"

void menu()
{
    system("cls");
    printf("**************************************************************************\n");
    printf("                                 ABM          \n");
    printf("**************************************************************************\n");
    printf("                               PERSONAS                    \n");
    printf("**************************************************************************\n");
    printf("1. ALTA\n");
    printf("2. BAJA\n");
    printf("3. MODIFICACION\n");
    printf("4. LISTAR\n");
    printf("5. ORDENAR\n");
    printf("6. INFORMES\n");
    printf("7. SALIR\n");
}

// harcodeo
int hardcodearPersonas(ePersona* lista, int tam, int cantPersonas)
{
    int retorno = -1;
    if(lista != NULL && tam > 0 && cantPersonas > 0 && cantPersonas < tam)
    {
        for(int i = 0; i < cantPersonas; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                lista[i].isEmpty = 0;
                lista[i].legajo = legajos[i];
                strcpy(lista[i].nombre, nombres[i]);
                lista[i].altura = alturas[i];
                lista[i].fechaNac.dia = dias[i];
                lista[i].fechaNac.mes = meses[i];
                lista[i].fechaNac.anio = anios[i];
                retorno++;
            }
        }
    }

    return retorno; //retorna -1 si hubo un error, sino un entero indicando la cantidad de personas que cargó
}

//Inicializar
int initPersonas(ePersona* list, int len)
{
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        return 0;
    }

    return -1;
}

//Buscar persona
int findPersonaById(ePersona* list, int len,int id)
{
    int indiceId = -1;
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].legajo == id && list[i].isEmpty == 0)
            {
                indiceId = i;
                break;
            }
        }
    }
    return indiceId;
}

//Imprimir personas
int printPersonas(ePersona* list, int len)
{
    if(list != NULL && len > 0 && len <= 1000)
    {
        //system("cls");
        printf("****************************************************************************\n");
        printf("  Legajo                Nombre        Sexo         Altura      F. Nacimiento \n");
        printf("****************************************************************************\n");
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty != 1)
            {
                showPersona(list[i]);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void showPersona(ePersona persona)
{
    printf("%6d %20s             %c            %4.2f         %d/%d/%d\n",
           persona.legajo,
           persona.nombre,
           persona.sexo,
           persona.altura,
           persona.fechaNac.dia,
           persona.fechaNac.mes,
           persona.fechaNac.anio);
}

// Añadir personas
int addPersona(ePersona* list, int len, int ID)
{
    ePersona nuevaPer;
    int validName;
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                nuevaPer.isEmpty = 0;
                nuevaPer.legajo = ID;
                //nombre
                printf("\nIngrese nombre: ");
                fflush(stdin);
                gets(nuevaPer.nombre);
                validName = charOnly(nuevaPer.nombre);
                while(strlen(nuevaPer.nombre) > 21 || validName < 0)
                {
                    printf("\nDato invalido. Ingrese nombre: ");
                    fflush(stdin);
                    gets(nuevaPer.nombre);
                    validName = charOnly(nuevaPer.nombre);
                }
                //Pedir genero
                printf("\nIngrese sexo 'f' o 'm': ");
                fflush(stdin);
                scanf("%c", &nuevaPer.sexo);
                while(nuevaPer.sexo != 'm' && nuevaPer.sexo != 'f')
                {
                    printf("\nDato invalido. Ingrese sexo 'f' o 'm':");
                    fflush(stdin);
                    scanf("%c", &nuevaPer.sexo);
                }
                //Pedir altura
                printf("\nIngrese altura: ");
                scanf("%f", &nuevaPer.altura);
                //Pedir fecha nac
                printf("\nIngrese su fecha de nacimiento dd/mm/aaaa: ");
                scanf("%d/%d/%d", &nuevaPer.fechaNac.dia, &nuevaPer.fechaNac.mes, &nuevaPer.fechaNac.anio);

                list[i] = nuevaPer;
                return 0;
            }
        }

    }

    return -1;
}

//Modificar personas
int modifiePersona(ePersona* list, int len)
{
    ePersona nuevaPer;
    int validName;
    int error = -1;
    int id;
    int index;
    int rst;
    int mOption;
    if(list != NULL && len > 0 && len <= 1000)
    {
        printPersonas(list, len);
        printf("\nIngrese legajo del empleado a modificar: ");
        scanf("%d", &id);
        index = findPersonaById(list, len, id);
        system("cls");
        if(index == -1)
        {
            printf("No hay personas con ese ID\n");
        }
        else
        {
            printf("****************************************************************************\n");
            printf("  Legajo                Nombre        Sexo         Altura      F. Nacimiento \n");
            printf("****************************************************************************\n");
            showPersona(list[index]);
            printf("4. MODIFICAR:\n");
            printf("1. Nombre\n");
            printf("2. Sexo\n");
            printf("3. Altura\n");
            printf("4. Fecha de Nacimiento\n");
            rst = getOption(&mOption, "\nOpcion invalida\n", 1, 4);
            if(!rst)
            {
                switch(mOption)
                {
                case 1:
                    //Pedir nombre y validar nombre
                    printf("\nIngrese nombre: ");
                    fflush(stdin);
                    gets(nuevaPer.nombre);
                    validName = charOnly(nuevaPer.nombre);
                    while(strlen(nuevaPer.nombre) > 21 || validName < 0)
                    {
                        printf("\nDato invalido. Ingrese nombre: ");
                        fflush(stdin);
                        gets(nuevaPer.nombre);
                        validName = charOnly(nuevaPer.nombre);
                    }
                    strcpy(list[index].nombre, nuevaPer.nombre);
                    break;
                case 2:
                    printf("\nIngrese sexo 'f' o 'm': ");
                    fflush(stdin);
                    scanf("%c", &nuevaPer.sexo);
                    while(nuevaPer.sexo != 'm' && nuevaPer.sexo != 'f')
                    {
                        printf("\nDato invalido. Ingrese sexo 'f' o 'm':");
                        fflush(stdin);
                        scanf("%c", &nuevaPer.sexo);
                    }
                    list[index].sexo = nuevaPer.sexo;
                    break;
                case 3:
                    printf("\nIngrese altura: ");
                    scanf("%f", &list[index].altura);
                    break;
                case 4:
                    printf("\nIngrese fecha de nacimiento: ");
                    scanf("%d/%d/%d", &list[index].fechaNac.dia, &list[index].fechaNac.mes, &list[index].fechaNac.anio);
                    break;
                }
            }
            error = 0;
        }
    }

    return error;
}

// borrar personas
int removeEmployee(Employee* list, int len)
{
    int error = -1;
    int id;
    int index;
    char confirmation;
    //La función podría devolver 3 enteros (0 - ok, -1 error, 1 ok pero no borró a nadie
    if(list != NULL && len > 0 && len <= 1000)
    {
        printEmployees(list, len);
        printf("\nIngrese ID del empleado a eliminar: ");
        scanf("%d", &id);
        index = findEmployeeById(list, len, id);
        if(index == -1)
        {
            printf("No hay personas con ese ID\n");
        }
        else
        {
            printf("****************************************************************************\n");
            printf("  ID                Nombre             Apellido          Salario     Sector \n");
            printf("****************************************************************************\n");
            showEmployee(list[index]);
            printf("Confirmar baja? s - si; n - no\n");
            fflush(stdin);
            scanf("%c", &confirmation);
            confirmation = tolower(confirmation);
            while(confirmation != 's' && confirmation != 'n')
            {
                printf("Opción invalida. s - si; n - no\n");
                fflush(stdin);
                scanf("%c", &confirmation);
                confirmation = tolower(confirmation);
            }

            if(confirmation == 's')
            {
                list[index].isEmpty = 1;
                error = 0;
            }
            else if(confirmation == 'n')
            {
                error = 1;
            }
        }

    }

    return error;
}
