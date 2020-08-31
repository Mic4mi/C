#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define a "Hola, felices fiestas"
#define b "Chin chin! Brindemos"
#define c "Feliz año, chau chau"
#define d "Salis"

/*Para brindar, primero hay que saludar
Para despedirse, primero hay que brindar y saludar*/

int main()
{
    char opcion;
    char seguir = 's';
    int saludarBandera = 0;
    int brindarBandera = 0;

    do
    {
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

        switch(opcion)
        {
        case 'a':
            printf("%s\n", a);
            saludarBandera = 1;
            break;
        case 'b':
            if(saludarBandera == 0)
            {
                printf("Para brindar, primero hay que saludar.\n");
            }
            else
            {
                printf("%s\n", b);
                brindarBandera = 1;
            }
            break;
        case 'c':
            if(saludarBandera == 0 || brindarBandera == 0)
            {
                printf("Para despedirte, primero hay que saludar y/o brindar!!\n");
            }
            else
            {
                printf("%s\n", c);
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
