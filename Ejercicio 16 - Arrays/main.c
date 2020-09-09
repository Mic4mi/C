#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define TAM 5


/*
1) Declarar un vector de caracteres.
2) pedir las vocales
*/

void mostrarVectoresCaracteres(char vec[], int tam);
int contarVocal(char vec[], int tam, char vocal);

int main()
{
    char vocales[TAM];
    char vocalRepetida;

    for(int i = 0; i < TAM; i++)
    {
        printf("Ingrese una vocal\n");
        fflush(stdin);
        scanf("%c", &vocales[i]);
        while(vocales[i] != 'a' && vocales[i] != 'e' && vocales[i] != 'i' && vocales[i] != 'o' && vocales[i] != 'u')
        {
            printf("Incorrecto. Ingrese una vocal\n");
            fflush(stdin);
            scanf("%c", &vocales[i]);
        }

    }

    mostrarVectoresCaracteres(vocales, TAM);

    printf("\n Ingrese una vocal que quiera\n");
    fflush(stdin);
    scanf("%c", &vocalRepetida);
    printf("La vocal %c se repite %d veces.\n", vocalRepetida, contarVocal(vocales, TAM, vocalRepetida));


    return 0;
}

void mostrarVectoresCaracteres(char vec[], int tam)
{
    printf("\nEl vector queda:\n");
    for(int i = 0; i < tam; i++)
    {
        printf("%c ", vec[i]);
    }
    printf("\n\n");
}

int contarVocal(char vec[], int tam, char vocal)
{
    int repeticiones = 0;
    for(int i = 0; i < tam; i++)
    {
        if(vec[i] == vocal){
            repeticiones++;
        }
    }
    return repeticiones;
}
