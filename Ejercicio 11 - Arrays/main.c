#include <stdio.h>
#include <stdlib.h>

/*
1)declarar un vector de 5 numeros
2)carga x igreso del usuario
3)mostrar el indice del mayor de los numeros
*/

int main()
{
    int numeros[5];
    int maxNum;
    int maxPos;

    for(int i = 0; i < 5; i++)
    {
        printf("Ingrese un numero\n");
        scanf("%d", &numeros[i]);
    }

    maxNum = numeros[0];

    for(int i = 0; i < 5; i++)
    {
        if(numeros[i] > maxNum)
        {
            maxNum = numeros[i];
            maxPos = i;   // si quisiera mostrar la posición real al usuario, debería devolver i + 1
        }
    }

    printf("El mayor de los 5 numeros es %d. Se encuentra en la posicion %d del array numeros\n", maxNum, maxPos);

    return 0;
}
