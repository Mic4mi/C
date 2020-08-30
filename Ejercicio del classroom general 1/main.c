#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
    1. Edad, sexo y legajo de 5 personas.
    2. Edad promedio
    3. Cant mujeres -> NO
    4. Cant Hombres
    5. Edad máxima y mínima
    6. desestimar 3 -> DONE
    7. legajo del hombre más viejo
    8. legajo de mujer más joven
*/


int main()
{
    int edad;
    int legajo;
    int contadorEdad = 0;
    int contadorMasc = 0;
    int edadMaxima = 0;
    int edadMinimaFlag = 0;
    int edadMinima;
    int edadMaximaHombreFlag = 0;
    int edadMaximaHombre;
    int edadMaximaHombreLegajo;
    int edadMinimaMujerFlag = 0;
    int edadMinimaMujer;
    int edadMinimaMujerLegajo;
    float edadPromedio;
    char sexo;

    for(int i = 0; i < 5; i++)
    {
        printf("Ingrese edad\n");
        scanf("%d", &edad);
        while(edad <= 0 || edad >= 116)
        {
            printf("Invalido. Ingrese edad\n");
            scanf("%d", &edad);
        }

        printf("Ingrese numero de legajo:\n");
        scanf("%d", &legajo);
        while(legajo < 1000 || legajo > 9999)
        {
            printf("Invalido. Ingrese numero de legajo:\n");
            scanf("%d", &legajo);
        }

        printf("Ingrese f para femenino o m para masculino\n");
        fflush(stdin);
        scanf("%c", &sexo);
        sexo = tolower(sexo);
        while(sexo != 'f' && sexo != 'm')
        {
            printf("Invalido. Ingrese f para femenino o m para masculino\n");
            fflush(stdin);
            scanf("%c", &sexo);
            sexo = tolower(sexo);
        }

        // Promedio
        contadorEdad += edad;

        //Edad máxima y mínima
        if(edad > edadMaxima)
        {
            edadMaxima = edad;
        }

        if(edadMinimaFlag == 0 || edad < edadMinima)
        {
            edadMinima = edad;
            edadMinimaFlag = 1;
        }

        //Legajo hombre más viejo + legajo mujer más joven
        if(sexo == 'm')
        {
            contadorMasc++;
            if(edadMaximaHombreFlag == 0 || edad > edadMaximaHombre)
            {
                edadMaximaHombre = edad;
                edadMaximaHombreLegajo = legajo;
                edadMaximaHombreFlag = 1;

            }
        }
        else
        {
            if(edadMinimaFlag == 0 || edad < edadMinimaMujer)
            {
                edadMinimaMujer = edad;
                edadMinimaMujerLegajo = legajo;
                edadMinimaMujerFlag = 1;
            }
        }
    }

    //promedio
    edadPromedio = (float) contadorEdad / 5;

    //prints
    printf("Promedio edad total: %.2f\n", edadPromedio);
    printf("La edad maxima es: %d\n", edadMaxima);
    printf("La edad minima es: %d\n", edadMinima);
    printf("El legajo del hombre mas viejo es: %d\n", edadMaximaHombreLegajo);
    printf("El legajo de la mujer mas joven es: %d\n", edadMinimaMujerLegajo);
    if(contadorMasc == 0)
    {
        printf("No hay hombres");
    }
    else
    {
        printf("La cantidad total de hombres es de: %d\n", contadorMasc);
    }

    return 0;
}
