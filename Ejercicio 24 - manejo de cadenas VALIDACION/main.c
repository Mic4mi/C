#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // cómo evitar que un usuario sobre escriba la variable e indicarle que se esta pasando?
    char nombre[20];
    char auxCad[100];

    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(auxCad);
    while(strlen(auxCad) >= 20)
    {
        printf("Nombre demasiado largo. Reingrese nombre\n");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(nombre, auxCad);

    printf("Su nombre es %s\n", nombre);


    //int cantidad = strlen(nombre);
    //printf("%d\n", cantidad);

    return 0;
}
