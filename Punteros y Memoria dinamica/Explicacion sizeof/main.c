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

    Para reservar memoria se debe saber exactamente el n�mero de bytes
    que ocupa cualquier estructura de datos. Una peculiaridad del lenguaje
    C es que estos tama�os pueden variar de una plataforma a otra.
    �C�mo sabemos, entonces, cu�ntos bytes reservar para una tabla de,
    por ejemplo, 10 enteros? El propio lenguaje ofrece la soluci�n a este
    problema mediante la funci�n sizeof();
    La funci�n recibe como �nico par�metro o el nombre de una variable,
    o el nombre de un tipo de datos, y devuelve su tama�o en bytes.

    Cuando quiero obetener la posici�n de algo en un array, para desplazarme
    me voy a mover x cantidad de sizeof(tipoDeDato) a partir del primer elemento.

    *(vec + 1)  -> ese +1 implica que se le esta sumando 1 sizeoff, considerando que
                   'vec' (o cualquiera sea el nombre del array) hace referencia a la
                   primer posici�n del array

    Esto se llama aritmetica de punteros. Ejemplo

    int numeros  = {1,15,4};

    *vec = 1;
    *(vec + 1) = 15;
    *(vec + 2) = 4;

    El �ndice siempre es "cuanto me desplazo desde el primer elemento".

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
