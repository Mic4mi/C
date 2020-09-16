#include <stdio.h>
#include <stdlib.h>

#define TAM 4

/*
1_ Suma Acumulada
2_ Mayor Edad
3_ Menor edad
4_ Cant mayor edad repetida
5_ Cant menor edad repetida
6_ Promedio
*/

int sumarVector(int vec[], int tam);
int mayorNum(int vec[], int tam);
int menorNum(int vec[], int tam);
int contenidoRepetido(int vec[], int tam, int r);
float promedioVector(int vec[], int tam);

int main()
{
    int ojete[] = {24, 30, 24, 25};
    int suma;
    int mayor;
    int menor;
    float prom;

    // Suma
    suma = sumarVector(ojete, TAM);
    printf("1. La suma del contenido del vector es: %d\n", suma);

    // Mayor
    mayor = mayorNum(ojete, TAM);
    printf("2. El numero mayor es: %d\n", mayor);

    // Menor
    menor = menorNum(ojete, TAM);
    printf("3. El numero menor es: %d\n", menor);

    // Cuantas veces se repite el mayor
    printf("4. Cantidad de repeticiones del numero mayor: %d\n", contenidoRepetido(ojete, TAM, mayor));

    // Cuantas veces se repite el menor
    printf("5. Cantidad de repeticiones del numero menor: %d\n", contenidoRepetido(ojete, TAM, menor));

    // Promedio
    prom = promedioVector(ojete, TAM);
    printf("6. El promedio de los elementos del vector es: %.2f\n", prom);

    return 0;
}

int sumarVector(int vec[], int tam)
{
    int suma = 0;
    for(int i = 0; i < tam; i++)
    {
        suma += vec[i];
    }
    return suma;
}

int mayorNum(int vec[], int tam)
{
    int mayor;
    for(int i = 0; i < tam; i++)
    {
        if(mayor == 0 || mayor <= vec[i])
        {
            mayor = vec[i];
        }
    }
    return mayor;
}

int menorNum(int vec[], int tam)
{
    int menor;
    for(int i = 0; i < tam; i++)
    {
        if(menor == 0 || menor >= vec[i])
        {
            menor = vec[i];
        }
    }
    return menor;
}

int contenidoRepetido(int vec[], int tam, int r)
{
    int repeticiones = 0;
    for(int i = 0; i < tam; i++)
    {
        if(vec[i] == r)
        {
            repeticiones++;
        }
    }
    return repeticiones;
}

float promedioVector(int vec[], int tam){
    int suma = 0;
    float prom;
    for(int i = 0; i < tam; i++)
    {
        suma += vec[i];
    }

    prom = (float) suma / tam;

    return prom;
}
