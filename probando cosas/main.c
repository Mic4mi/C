#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int menu(int b1, int b2, int operando1, int operando2);

int main()
{
    /*
    int x;
    int y;
    int xF = 0;
    int yF = 0;

    x = 5;
    xF = 1;
    y = 2;
    yF = 1;
    */

    char letra;
    printf("Escribe un carácter:\n");
    scanf("%c", &letra);
    if (!isalpha(letra))
    {
       printf("NO es una letra");
    }
    else
    {
        printf("Es una letra");
    }





    //menu(xF, yF, x, y);

    //isalpha(x);

    /*
    Una funcion que imprima el menu, pero si x tiene valor y su bandera ahora es true; reciba eso
    y reemplaze x por ese valor (lo mismo con y).
    */

    //menu();

    return 0;
}

int menu(int b1, int b2, int operando1, int operando2)
{
    system("cls");
    printf("********Menu de opciones********\n");

    if(b1 == 0 && b2 == 0)
    {
        printf("1. Ingresar 1er operando (A = x)\n");
        printf("2. Ingresar 2do operando (B = y)\n");
    }
    else if(b1 == 1 && b2 == 0)
    {
        printf("1. Ingresar 1er operando (A = %d)\n", operando1);
        printf("2. Ingresar 2do operando (B = y)\n");
    }
    else if(b1 == 0 && b2 == 1)
    {
        printf("1. Ingresar 1er operando (A = x)\n");
        printf("2. Ingresar 2do operando (B = %d)\n", operando2);
    }
    else
    {
        printf("1. Ingresar 1er operando (A = %d)\n", operando1);
        printf("2. Ingresar 2do operando (B = %d)\n", operando2);
    }
    printf("3. Calcular todas las operaciones\n");
    printf("   a) Calcular la suma (A+B)\n");
    printf("   b) Calcular la resta (A-B)\n");
    printf("   c) Calcular la division (A/B)\n");
    printf("   d) Calcular la multiplicacion (A*B)\n");
    printf("   e) Calcular el factorial (A!)\n");
    printf("4. Informar resultados\n");
    printf("   a) Resultado de (A+B): \n");
    printf("   b) Resultado de (A-B): \n");
    printf("   c) Division de (A/B): \n");
    printf("   d) Multiplicacion de (A*B): \n");
    printf("   e) Factorial (A!): \n");
    printf("5. Salir\n\n");

    return 0;
}

