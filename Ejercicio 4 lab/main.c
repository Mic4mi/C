#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define a "Hola, buen dia"
#define b "Felicidades, capo"
#define c "Mal ahi, eso no hace"
#define d "Adios"

int main()
{
    char opcion;
    char seguir = 's';

    do
    {
        // Limpiar la pantalla:
        system("cls");
        printf("******Menu de opciones******\n");
        printf("a. Saludar\n");
        printf("b. Felicitar\n");
        printf("c. Retar\n");
        printf("d. Salir\n\n");
        printf("Ingrese opcion\n");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = tolower(opcion);

        switch(opcion)
        {
        case 'a':
            printf("%s\n", a);
            break;
        case 'b':
            printf("%s\n", b);
            break;
        case 'c':
            printf("%s\n", c);
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
                printf("Bueno, segui\n");
                seguir = 's';
            } else {
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
