#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    Cuando declaramos variables de la siguiente manera:

    int x = 100;
    char z = 'm';
    ePersona persona1;

    Estamos haciendo una declaración sobre la memoria estática.

    ¿Cómo podemos manejar la mamemoria dinamicamente?
     --> Debemos emplear funciones de manero de memoria dinámica.

    malloc(); --> Memory Allocate (asignacion de memoria)
    void* malloc(int); -> toma como parametros la cantidad
                         de bytes que le vamos a pedir en
                         memoria.

    Retorna un puntero a void que se puede castear a cualquier
    otro tipo de puntero (char, int, float, estructuras); Sino
    encuentra espacio retorna null.

    memoria estática -> pequeña. Cuando se declara una variable tiene nombre.
    memoria dinámica -> más grande. Para reservar espacio se emplean funciones.
                        Las variables declaradas no poseen nombre.

                        ----------------------------------------------------
                        |      |                                           |
                        |  __  |                                           |
    var estatica   ->       | |10| |                                           |
                        |  __  |                                 __        |
    var puntero   ->        | | *| |   --> pide espacio en dinamica | e|       |
                        |      |                                           |
                        |      |                                           |
                        |      |                                           |
                        |      |                                           |
                        |      |                                           |
                        |      |                                           |
                        |      |                                           |
    Memo estatica        <- |      |                                           | -> Memo dinamica
                        |______|___________________________________________|


    */

    int numero = 10; //declaracion estatica

    printf(" Numero vale: %d\n", numero);

    int* pNumero; //declaracion dinamica
    pNumero = (int*) malloc(sizeof(int)); //le tengo que pasar la cantidad de bytes q necesito y castearlo

    if(pNumero == NULL) //Si malloc no consigue espacio retorna null. Hay que validar.
    {
        printf("\nNo hay espacio en memoria.\n");
        exit(EXIT_FAILURE);
    }

    *pNumero = 10;

    printf(" pNumero vale: %d\n", *pNumero);

    free(pNumero); //Antes de terminar el programa, liberamos la memoria dinamica

    return 0;
}
