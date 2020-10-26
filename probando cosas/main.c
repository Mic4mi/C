#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void cualEsMayor(int a, int b);
int sumarArreglo(int vec[], int len, int* pResult);
void sumarArreglo2(int vec[], int len);

int main()
{
// a. Realizar un algoritmo que lea dos números y nos diga cual de ellos es mayor o bien si son iguales ♣
//b. Los siguientes números {10,5,23,7,15,65,85} se encuentran en un arreglo. Realizar un algoritmo que los sume.

/*
    int numeros[] = {10,5,23,7,15,65,85};
    int sumaNumeros;

    //punto a
    cualEsMayor(10, 10);
    // punto b
    sumarArreglo(numeros, 7, &sumaNumeros);
    printf("La suma del arreglo de numeros es: %d\n", sumaNumeros);
    //punto c
    sumarArreglo2(numeros, 7);
*/
if(1 && -1){
    printf("Bruno");
} else {
    printf("Teclado");
}


    return 0;
}

void cualEsMayor(int a, int b)
{
    if(a == b)
    {
        printf("Los numeros %d y %d son iguales.\n", a, b);
    }
    if(a < b)
    {
        printf("El numero %d es mayor a %d\n", b, a);
    }
    else if(a > b)
    {
        printf("El numero %d es mayor a %d\n", a, b);
    }
}

int sumarArreglo(int vec[], int len, int* pResult){
    int error = -1;
    int acumI = 0;
    if(vec != NULL && len > 0){
        for(int i = 0; i < len; i++){
        acumI += vec[i];
    }
    *pResult = acumI;
    error = 0;
    }
    return error;
}

void sumarArreglo2(int vec[], int len){
    int acumI = 0;
    for(int i = 0; i < len; i++){
        acumI += vec[i];
    }
    printf("La suma del arreglo de numeros es:: %d\n", acumI);
}
