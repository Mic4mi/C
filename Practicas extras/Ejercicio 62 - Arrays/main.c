#include <stdio.h>
#include <stdlib.h>

#define TAM 3

/*
De los 100 empleados de una fábrica se registra:
número de legajo (coincide con el número de índice),
edad y salario.
Se pide:
a)Ingresar los datos correlativamente,
b)Calcular la edad promedio
c) informando número de legajo de los empleados cuya
edad supere el promedio
*/

int main()
{
    int legajoEdad[TAM] = {0};
    int legajoSalario[TAM] = {0};
    int edadAcum = 0;
    int edadPromedio;

    // Ingresar datos
    for(int i = 0; i < TAM; i++)
    {
        printf("\nIngrese edad ");
        scanf("%d", &legajoEdad[i]);
        printf("\nIngrese salario ");
        scanf("%d", &legajoSalario[i]);

        // Calcular la edad promedio
        edadAcum += legajoEdad[i];
    }

    // Calcular la edad promedio
    edadPromedio = edadAcum / TAM;
    printf("\nLa edad promedio es %d\n", edadPromedio);

    // Obtener legajos cuya edad supere el promedio
    printf("\nLegajos que superan la edad promedio:\n");
    for(int i = 0; i < TAM; i++){
        if(legajoEdad[i] > edadPromedio){
            printf("\nLegajo %d\n", i);
        }
    }

    return 0;
}
