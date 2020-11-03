#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int legajo;
    char nombre[21];
    char sexo;
    float altura;
}ePersona;

int personas_inicializar(ePersona** lista, int tam);

int main()
{
    int tam = 5;
    ePersona** lista = (ePersona**) malloc(tam * sizeof(ePersona*));

    /*
    lista es un puntero a puntero, ya que apunta a la dirección
    de memoria del primer elemento de la lista, que es un puntero.
    Por eso tiene doble asterísco **
    Entonces, hay que castear el puntero como PUNTERO A PUNTERO
    con doble asterico tambien

    100PRE que declaramos un puntero hay que inicializarlo en NULL
    */

    if(lista == NULL){
        printf("\nNo se pudo conseguir memoria...\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < tam; i++){
        *(lista + i) = NULL;
        //(lista+i) hace referencia al primer elemento del array.
        // con * adelanrte hacemos referencia al valor de lon que hay en esa posición
    }

    return 0;
}
