#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<stdbool.h>

/*
1)De 5  personas que ingresan al hospital se deben tomar y
validar los siguientes datos.
nombre , temperatura, sexo y edad.
a)informar la cantidad de personas de cada sexo.
b)la edad promedio en total
c)la mujer con más temperatura(si la hay)
pedir datos por prompt y mostrar por document.write o console.log
*/

int main()
{
    char nombre[15];
    char sexo;
    char inicial;
    int edad;
    float temperatura;
    int contM = 0;
    int contF = 0;
    int acumEdad = 0;
    float promedioEdad;
    float maxTemp;
    char inicialMaxTemp;


    for(int i = 0; i < 5; i++)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%s", &nombre);

        printf("Ingrese inicial del nombre: ");
        fflush(stdin);
        scanf("%c", &inicial);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);
        sexo = tolower(sexo);
        while(sexo != 'f' && sexo != 'm')
        {
            printf("Incorrecto. Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &sexo);
            sexo = tolower(sexo);
        }

        printf("Ingrese edad: ");
        scanf("%d", &edad);
        while(edad < 0 || edad > 115)
        {
            printf("Incorrecto. Ingrese edad: ");
            scanf("%d", &edad);
        }

        printf("Ingrese temperatura: ");
        scanf("%f", &temperatura);
        while(temperatura < 33 || temperatura > 44)
        {
            printf("Incorrecto. Ingrese temperatura: ");
            scanf("%f", &temperatura);
        }

        acumEdad += edad;

        if(sexo == 'f')
        {
            contF++;
            if(contF == 0 || temperatura > maxTemp)
            {
                maxTemp = temperatura;
                inicialMaxTemp = inicial;
            }
        }
        else if (sexo == 'm')
        {
            contM++;
        }

    }

    //promedio
    promedioEdad = (float) acumEdad/5;

    printf("Hay %d hombres y %d mujeres\n", contM, contF);
    printf("El promedio de edad es %.2f\n", promedioEdad);
    if(contF == 0)
    {
        printf("No hay mujeres");
    }
    else
    {
        printf("La mujer con mayor temperatura tiene %.2f y su incial es %c", maxTemp, inicial);
    }

    return 0;
}
