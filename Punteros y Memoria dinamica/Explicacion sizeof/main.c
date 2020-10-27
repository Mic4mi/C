#include <stdio.h>
#include <stdlib.h>
#define CADENA_TAM 10


typedef struct
{
    int x;
    int p;
} miEstructura;

int main()
{
    /*

    Para reservar memoria se debe saber exactamente el número de bytes
    que ocupa cualquier estructura de datos. Una peculiaridad del lenguaje
    C es que estos tamaños pueden variar de una plataforma a otra.
    ¿Cómo sabemos, entonces, cuántos bytes reservar para una tabla de,
    por ejemplo, 10 enteros? El propio lenguaje ofrece la solución a este
    problema mediante la función sizeof();
    La función recibe como único parámetro o el nombre de una variable,
    o el nombre de un tipo de datos, y devuelve su tamaño en bytes.

    Cuando quiero obetener la posición de algo en un array, para desplazarme
    me voy a mover x cantidad de sizeof(tipoDeDato) a partir del primer elemento.

    *(vec + 1)  -> ese +1 implica que se le esta sumando 1 sizeoff, considerando que
                   'vec' (o cualquiera sea el nombre del array) hace referencia a la
                   primer posición del array

    Esto se llama aritmetica de punteros. Ejemplo

    int numeros  = {1,15,4};

    *vec = 1;
    *(vec + 1) = 15;
    *(vec + 2) = 4;

    El índice siempre es "cuanto me desplazo desde el primer elemento".

    */

    miEstructura estructuraEj;
    int x;
    float y;
    char w;
    char cadena[CADENA_TAM];

    printf("Sizeof de la estructura: %d\n", sizeof(estructuraEj));
    printf("Sizeof de un entero: %d\n", sizeof(x));
    printf("Sizeof de un flotante: %d\n", sizeof(y));
    printf("Sizeof de un caracter: %d\n", sizeof(w));

    return 0;
}
