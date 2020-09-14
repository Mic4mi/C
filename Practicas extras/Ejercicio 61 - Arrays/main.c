#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define TAM 31

/*
Una persona desea saber en qu� d�a del mes realiz� m�s
gastos en compras, para ello ingresa por teclado
d�a a d�a lo que gast� por d�a, cargando un vector
definido en memoria. Puede haber varias o ninguna
compra para un determinado d�a. Informar cual fue el
d�a de mayor gasto
*/

int main()
{
    int gastosDelMes[TAM] = {0};
    int dia;
    int diaDeMayorGasto;
    int diaDeMayorGastoPos;
    char continuar = 's';


    do
    {
        printf("Ingrese el numero de dia del mes ");
        scanf("%d", &dia);
        while(dia < 1 || dia > TAM)
        {
            printf("\nInvalido. El mes tiene 31 dias.\nIngrese numero de dia para guardar el dato ");
            scanf("%d", &dia);
        }
        printf("\nIngrese el dinero total gastado ");
        scanf("%d", &gastosDelMes[dia-1]);

        printf("Quiere continuar?\n");
        fflush(stdin);
        continuar = tolower(getchar());
    }
    while(continuar == 's');

    for(int i = 0; i < TAM; i++)
    {
        if(diaDeMayorGasto == 0 || diaDeMayorGasto <= gastosDelMes[i])
        {
            diaDeMayorGasto = gastosDelMes[i];
            diaDeMayorGastoPos = i + 1;
        }
    }

    printf("\nEl dia que mas se gasto del mes fue el dia %d: $%d totales", diaDeMayorGastoPos, diaDeMayorGasto);


    /*
    printf("\nResumen del mes:\n");
    for(int i = 0; i < TAM; i++){
        printf("Dia %d: $%d\n", i + 1, gastosDelMes[i]);
    }
    */

    return 0;
}




