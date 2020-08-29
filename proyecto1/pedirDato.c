#include <stdio.h>
#include <stdlib.h>

int pedirDato (){
    int edad;

    printf("Ingrese edad");
    scanf("%d", &edad);
    printf("Ingresaste el valor %d", edad);

    return 0;
}
