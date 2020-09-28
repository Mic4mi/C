#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    /*
    tarea:
    Vector char nombre[20];
    Vector char apellido[20];
    Vector nombreCompleto[tamañoJusto];

    1) Pedir nombre - puede ingresarlo como quiera, mayus, minus etc
    2) Pedir apellido - ´´ mismo arriba ´´
    3) en nombreCompleto se tiene que guardar:
    Apellido -> inicial en mayus, resto en minus + una coma , + espacio
    Nombre -> inicial en mayus, resto en minus.
    4) Todas las modificaciones deben hacerse sobre nombreCompleto
    */

    char nombre[20];
    char apellido[20];
    char nombreCompleto[41]; // corrección de clase

    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(nombreCompleto);
    while(strlen(nombreCompleto) > 19)
    {
        printf("Nombre demasiado largo. Reingrese nombre\n");
        fflush(stdin);
        gets(nombreCompleto);
    }
    strcpy(nombre, nombreCompleto);

    printf("Ingrese apellido\n");
    fflush(stdin);
    gets(nombreCompleto);
    while(strlen(nombreCompleto) > 19)
    {
        printf("Apellido demasiado largo. Reingrese nombre\n");
        fflush(stdin);
        gets(nombreCompleto);
    }
    strcpy(apellido, nombreCompleto);

    // concat
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    for(int i = 0; i < strlen(nombreCompleto); i++)
    {
        if(i == 0)
        {
            if(nombreCompleto[i] >= 'a' && nombreCompleto[i] <= 'z')
            {
                nombreCompleto[i] = toupper(nombreCompleto[i]);
                continue;
            }
        }
        if(nombreCompleto[i] == ' ')
        {
            i++;
            if(nombreCompleto[i] >= 'a' && nombreCompleto[i] <= 'z')
            {
                nombreCompleto[i] = toupper(nombreCompleto[i]);
                continue;
            }
        } else{
            if(nombreCompleto[i] >= 'A' && nombreCompleto[i] <= 'Z'){
                nombreCompleto[i] = tolower(nombreCompleto[i]);
                continue;
            }
        }
    }


    printf("%s\n", nombre);
    printf("%s\n", apellido);
    printf("%s\n", nombreCompleto);


    return 0;
}
