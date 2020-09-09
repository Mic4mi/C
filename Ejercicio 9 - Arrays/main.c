#include <stdio.h>
#include <stdlib.h>

/*
1)declarar un vector de 7 elementos
2)carga x igreso del usuario
3)mostrar de atrás para adelante
*/

int main()
{
    int numeros[7];

    for(int i = 0; i < 7; i++){
        printf("Ingrese un numero\n");
        scanf("%d", &numeros[i]);
    }

    system("cls");
    printf("Los numeros en orden decreciente: \n");
    for(int i = 6; i >= 0; i--){
        printf("%d\n", numeros[i]);
    }

    return 0;
}
