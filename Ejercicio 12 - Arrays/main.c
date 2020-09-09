#include <stdio.h>
#include <stdlib.h>

/*
1)declarar un vector de 5 numeros
2)carga x igreso del usuario
3)mostrar el numero mayor
4)determinar si el mayor numero se repite y también informarlo
*/

int main()
{
    int numeros[5];
    int maxNum;
    int maxPos;
    int repetido = 0;

    // Cargar numeros
    for(int i = 0; i < 5; i++)
    {
        printf("Ingrese un numero\n");
        scanf("%d", &numeros[i]);
    }

    // Obtener el mayor
    for(int i = 0; i < 5; i++)
    {
        if(i == 0 || numeros[i] > maxNum)
        {
            maxNum = numeros[i];
        }

    }

    printf("El mayor de los 5 numeros es %d. Se encuentra en la posicion: ", maxNum);

    for(int i = 0; i < 5; i++)
    {
        if(numeros[i] == maxNum)
        {
            printf("%d ", i);
        }
    }

    return 0;
}


