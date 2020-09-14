#include <stdio.h>
#include <stdlib.h>

#define TAM 5

/*Leer 20 números enteros positivos, indicar cuál
es el mayor y en qué orden fue leído (a que elemento
pertenece). Mostrar el vector completo
*/

int main()
{
    int numeros[TAM];
    int numeroMax;
    int numeroMaxPos;

    for(int i = 0; i <= TAM; i++)
    {
        printf("Ingrese un numero entero positivo ");
        scanf("%d", &numeros[i]);
        /*while(numeros[i] <= 0)
        {
            printf("Incorrecto.\nIngrese un numero entero positivo ");
            scanf("%d", numeros);
        }
        */
    }

    for(int i = 0; i <= TAM; i++){
        if(numeroMax == 0 || numeroMax <= numeros[i]){
            numeroMax = numeros[i];
            numeroMaxPos = i + 1;
        }
    }

    printf("\nEl mayor de los 5 numeros es %d, y esta en la posicion %d\n", numeroMax, numeroMaxPos);
}
