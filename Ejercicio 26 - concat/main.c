#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    /*
    PARA CONCATENAR CADENAS
    empleamos strcat(); string concatenate
    Sin embargo, hay que tener cuidado en dónde guardamos cadenas concatenadas, teniendo en
    cuenta su tamaño, ya que pueden desbordar una variable.
    Ej, si tengo dos cadenas con capacidad de 20, que guardan hasta 19 por el /0
    y las quiero concatenar en el espacio dela primer cadena, debo comprobar que no superen
    los 19 char, ya que desbordaría la variables.
    */
    char hola[20] = "Hola ";
    char mundo[20] = "mundooooooooooooooooooooooooooooooooooooooooooooooooo";
    char aux[39];

    strcpy(aux, hola);
    strcat(aux, mundo);

    if(strlen(aux) > 19){
        printf("Desborda la variable...");
    } else{
        printf("%s\n",strcat(hola, mundo));
    }


    //printf("%s\n", strcat(hola, mundo));


    return 0;
}
