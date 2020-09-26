#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarVectoresEnteros(int vec[], int tam);
void mostrarVectoresDecimales(float vec[], int tam);
void mostrarAlumno(char nombre[], int legajo, int n1, int n2, float promedio, char genero);
void mostrarAlumnos(char nombres[][20],int legajos[], int notas1[], int notas2[], float promedios[], char generos[], int tam);


int main()
{
    int legajos[TAM] = {1234, 4567, 6789, 1598, 7532};
    int notasP1[TAM] = {8, 9, 10, 5, 1};
    int notasP2[TAM] = {4, 2, 6, 8, 7};
    float promedios[TAM] = {6, 5.5, 8, 6.5, 4};
    char generos[TAM] = {'m', 'm', 'f', 'f', 'm'};
    char nombres[TAM][20] = {"Saturno", "Homeros", "Marita", "Beruska", "Carlito"};
    float auxFloat;
    int auxInt;
    char auxChar;
    char auxStr[20];



    /*
    for(int i = 0; i < TAM; i++)
    {
        //Cargar legajos
        printf("Ingrese los numeros de legajo\n");
        scanf("%d", &legajos[i]);

        //Cargar nombres
        printf("Ingrese nombre: \n");
        fflush(stdin);
        fgets(nombres[i], 20, stdin);

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

    mostrarAlumnos(nombres, legajos, notasP1, notasP2, promedios, generos, TAM);

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

                strcpy(auxStr, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxStr);
            }
        }
    }

    mostrarAlumnos(nombres, legajos, notasP1, notasP2, promedios, generos, TAM);

    return 0;
}

void mostrarAlumno(char nombre[], int legajo, int n1, int n2, float promedio, char genero)
{
    printf(" %20s %4d      %2d     %4d        %2.2f      %c\n", nombre, legajo, n1, n2, promedio, genero);
}

void mostrarAlumnos(char nombres[][20], int legajos[], int notas1[], int notas2[], float promedios[], char generos[], int tam)
{
    //system("cls");
    printf("              Nombre  Legajo  Parcial1  Parcial2  Promedio  Genero\n\n");

    for(int i = 0; i < tam; i++)
    {
        mostrarAlumno(nombres[i], legajos[i], notas1[i], notas2[i], promedios[i], generos[i]);
    }
    printf("\n\n");
}

// Ordenar todos los alumos por promedio de mayor a menor
