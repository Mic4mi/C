#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define d "Salis"

/*Para brindar, primero hay que saludar
Para despedirse, primero hay que brindar y saludar*/


char menu();
int saludar();
int brindar(int saludo);
int despedir(int saludo, int brindis);

int main()
{
    char seguir = 's';
    int saludarBandera = 0;
    int brindarBandera = 0;

    do
    {
        switch(menu())
        {
        case 'a':
            if(!saludar())
            {
                saludarBandera = 1;
            }
            break;
        case 'b':
            if(!brindar(saludarBandera))
            {
                brindarBandera = 1;
            }
            break;
        case 'c':
            if(!despedir(saludarBandera, brindarBandera))
            {
                saludarBandera = 0;
                brindarBandera = 0;
            }
            break;
        case 'd':
            printf("¿Realmente desea salir? s para si, n para no\n");
            fflush(stdin);
            scanf("%c", &seguir);
            seguir = tolower(seguir);

            if(seguir == 's')
            {
                printf("%s\n", d);
                seguir = 'n';
            }
            else if (seguir == 'n')
            {
                printf("Bueno, segui...\n");
                seguir = 's';
            }
            else
            {
                printf("Opcion invalida\n");
                seguir = 's';
            }
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause"); //pausar
    }
    while(seguir == 's');

    return 0;
}

char menu()
{
    char opcion;
    // Limpiar la pantalla:
    system("cls");
    printf("******Menu de opciones******\n");
    printf("a. Saludar\n");
    printf("b. Brindar\n");
    printf("c. Despedir\n");
    printf("d. Salir\n\n");
    printf("Ingrese opcion\n");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = tolower(opcion);
    return opcion;
}
int saludar()
{
    int cant;
    int error = 0;
    cant = printf("Hola, felices fiestas!\n");
    if( cant != 23)
    {
        error = 1;
    }
    return error;
}

int brindar(int saludo)
{
    int error = 0;
    if(saludo)
    {
        printf("Chin chin! Brindemos\n");
    }
    else
    {
        printf("Para brindar, primero hay que saludar.\n");
        error = 1;
    }
    return error;
}

int despedir(int saludo, int brindis)
{
    int error = 0;
    if(!saludo)
    {
        printf("Para despedirte, primero hay que saludar...\n");
        error = 1;
    }
    else if (!brindis)
    {
        printf("Para despedirte, primero hay que brindar...\n");
        error = 1;
    }
    else
    {
        printf("Feliz anio, chau chau\n");
    }
    return error;
}
