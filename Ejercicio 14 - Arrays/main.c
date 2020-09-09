#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define TAM 6

/*
1) Vector de 6 elementos
2) Pedir 5 numeros
3) En la ultima posicion poner la suma de los 5 numeros previos
*/

int main()
{
    int numeros[TAM] = {0};
    int suma;

    for(int i = 0; i < TAM-1; i++)
    {
        printf("Ingrese un numero\n");
        scanf("%d", &numeros[i]);
    }

    // sumar elementos
    for(int i = 0; i < TAM-1; i++){
        suma += numeros[i];
    }
    numeros[5] = suma;

    printf("El array quedo: \n");
    for(int i = 0; i < TAM; i++){
        printf("%d\n", numeros[i]);
    }
    return 0;
}
