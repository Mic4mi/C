#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 3


typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    int nota1;
    int nota2;
    float prom;
} eAlumno;


int main()
{
    eAlumno lista[TAM];

    //Cargamos la lista
    for(int i = 0; i < TAM; i++)
    {
        printf("Ingrese legajo: \n");
        scanf("%d", &lista[i].legajo);

        printf("Ingrese nombre: \n");
        fflush(stdin);
        scanf("%s", &lista[i].nombre);

        printf("Ingrese sexo: \n");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);

        printf("Ingrese nota del primer parcial: \n");
        scanf("%d", &lista[i].nota1);

        printf("Ingrese nota del segundo parcial: \n");
        scanf("%d", &lista[i].nota2);

        //promedio
        lista[i].prom = (float)(lista[i].nota1 + lista[i].nota2) /2;

    }


    //mostrar las estructuras
    system("cls");
    printf("ALUMNOS:\n");
    for(int i = 0; i < TAM; i++)
    {
        printf("Nombre del alumno: %s\n", lista[i].nombre);
        printf("Legajo: %d\n", lista[i].legajo);
        printf("Sexo: %c\n", lista[i].sexo);
        printf("Primer parcial: %d\n", lista[i].nota1);
        printf("Segundo parcial: %d\n", lista[i].nota2);
        printf("Promedio: %.2f\n", lista[i].prom);
        printf("\n\n");
    }
    return 0;
}
