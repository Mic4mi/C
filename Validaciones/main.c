#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int charOnly(char str[]);
int addPersona(char name[]);

int main()
{
    char personilla[21];

    addPersona(personilla);
    printf("Persona: %s", personilla);

    return 0;
}



int charOnly(char str[])
{

    int i = 0;
    while (str[i])
    {
        if (
            !isalpha(str[i])
            && str[i] != ' '
        )
            return -1;
        i++;
    }

    return 0;
}

int addPersona(char name[])
{
    int error = -1;
    char nameAux[100];
    int valid;
    if(name != NULL)
    {

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nameAux);
        valid = charOnly(nameAux);
        while(strlen(nameAux) > 21 || valid < 0)
        {
            printf("Dato Invalido. Ingrese nombre: ");
            fflush(stdin);
            gets(nameAux);
            valid = charOnly(nameAux);
        }
        strcpy(name, nameAux);

        error = 0;

    }

    return error;
}
