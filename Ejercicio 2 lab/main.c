#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Pedir dos numeros y mostrar promedio
    // para convertir datos se puede poner, si es flotante por ejemplo, (float) adelante del texto
    int n1;
    int n2;
    float promedio;

    printf("Ingrese un número: ");
    scanf("%d", &n1);

    printf("Ingrese otro número: ");
    scanf("%d", &n2);

    promedio = (n1 + n2)/2;

    printf("El promedio es: %.2f", promedio);
    return 0;
}
