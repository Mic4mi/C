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

void mostrarAlumnos(eAlumno vec[], int tam);
void mostrarAlumno(eAlumno unAlumno);

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

    mostrarAlumnos(lista, TAM);

    return 0;
}

void mostrarAlumnos(eAlumno vec[], int tam)
{
    system("cls");
    printf(" Legajo  Nombre  Sexo   Nota1  Nota2  Promedio\n");
    for(int i = 0; i < tam; i++)
    {
        mostrarAlumno(vec[i]);
    }
    printf("\n\n");
}

void mostrarAlumno(eAlumno unAlumno)
{
    printf(" %d %s %c %2d %2d %2.2f\n",
           unAlumno.legajo,
           unAlumno.nombre,
           unAlumno.sexo,
           unAlumno.nota1,
           unAlumno.nota2,
           unAlumno.prom);
}
