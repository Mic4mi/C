#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 20;
    int *puntero = &x;  //Siempre guardan direcciones de memoria de otrss variables.

    printf("La dirección de memoria de x es: %p\n", puntero);
    printf("x vale: %d\n", x);
    //También es lo mismo emplear el puntero que contiene la dirección de memoria
    printf("x vale: %d\n", *puntero);

    /*
    un * se usa para declarar una variable de tipo puntero, el otro uso del * es
    para acceder al contenido de la variable apuntada
    */

    //Puedo escribir la variable x a través del puntero!!
    *puntero = 60;
    printf("Ahora, x vale: %d\n", x);

    //Imprimir punteros con diferentes mascaras
    //Esto tira warning pero no pasa nada
    printf("Formato puntero -> La direccion de memoria de x es: %p\n", puntero);
    printf("Formato hexadecimal -> La direccion de memoria de x es: %x\n", puntero); //Formato hexadecimal
    printf("Formato octal -> La direccion de memoria de x es: %o\n", puntero); //Formato octal
    return 0;
}
