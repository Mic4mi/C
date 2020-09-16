#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarVectoresEnteros(int vec[], int tam);
void mostrarVectoresDecimales(float vec[], int tam);
void mostrarAlumno(int legajo, int n1, int n2, float promedio, char genero);
void mostrarAlumnos(int legajos[], int notas1[], int notas2[], float promedios[], char generos[], int tam);


int main()
{
    int legajos[TAM] = {1234, 4567, 6789, 1598, 7532};
    int notasP1[TAM] = {8, 9, 10, 5, 1};
    int notasP2[TAM] = {4, 2, 6, 8, 7};
    float promedios[TAM] = {6, 5.5, 8, 6.5, 4};
    char generos[TAM] = {'m', 'm', 'f', 'f', 'm'};
    float auxFloat;
    int auxInt;
    char auxChar;



    /*
    for(int i = 0; i < TAM; i++)
    {
        //Cargar legajos
        printf("Ingrese los numeros de legajo\n");
        scanf("%d", &legajos[i]);

        //Cargar notas p1
        printf("Ingrese la nota del primer parcial\n");
        scanf("%d", &notasP1[i]);

        //Cargar notas p2
        printf("Ingrese la nota del segundo parcial\n");
        scanf("%d", &notasP2[i]);

        //Cargar generos
        printf("Ingrese el genero: 'f' femenino o 'm' masculino\n");
        fflush(stdin);
        scanf("%c", &generos[i]);

        //mostrar promedio
        promedios[i] = (float) (notasP1[i] + notasP2[i]) / 2;
    }
    */

    mostrarAlumnos(legajos, notasP1, notasP2, promedios, generos, TAM);

    for(int i = 0; i < TAM - 1; i++)
    {
        for(int j = i + 1; j < TAM; j++)
        {
            if(promedios[i] < promedios[j])  // Se puede elegir el criterio de organización dependiendo del vector
            {
                auxFloat = promedios[i];
                promedios[i] = promedios[j];
                promedios[j] = auxFloat;

                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = notasP1[i];
                notasP1[i] = notasP1[j];
                notasP1[j] = auxInt;

                auxInt = notasP2[i];
                notasP2[i] = notasP2[j];
                notasP2[j] = auxInt;

                auxChar = generos[i];
                generos[i] = generos[j];
                generos[j] = auxChar;
            }
        }
    }

    mostrarAlumnos(legajos, notasP1, notasP2, promedios, generos, TAM);

    return 0;
}

void mostrarAlumno(int legajo, int n1, int n2, float promedio, char genero)
{
    printf(" %4d      %2d     %4d        %2.2f      %c\n", legajo, n1, n2, promedio, genero);
}

void mostrarAlumnos(int legajos[], int notas1[], int notas2[], float promedios[], char generos[], int tam)
{
    //system("cls");
    printf("Legajo  Parcial1  Parcial2  Promedio  Genero\n\n");

    for(int i = 0; i < tam; i++)
    {
        mostrarAlumno(legajos[i], notas1[i], notas2[i], promedios[i], generos[i]);
    }
    printf("\n\n");
}

// Ordenar todos los alumos por promedio de mayor a menor
