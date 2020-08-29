#include <stdio.h>
#include <stdlib.h>

int main()
{
    //system cls para limpiar consola
    // system pause para pausa
    int edad;
    float peso;
    char sexo;
    char nombre[15];

    printf("Ingrese edad: ");
    scanf("%d", &edad);

    printf("Ingrese peso: ");
    scanf("%f", &peso);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &sexo);

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%s", nombre);

    printf("Edad: %d\n", edad);
    printf("Peso: %.2f\n", peso);
    printf("Sexo: %c\n", sexo);
    printf("Nombre: %s", nombre);


    return 0;
}
