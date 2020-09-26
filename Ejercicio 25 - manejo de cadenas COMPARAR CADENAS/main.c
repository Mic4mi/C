#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char nombre1[] = "Juan";
    char nombre2[] = "Juan";
    char nombre3[] = "Pepe";
    char nombre4[] = "Alicia";
    char nombre5[] = "JUAN";
    char nombre6[] = "anastasia";

    /* para comparar cadenas podemos emplear strcmp() que significa string comparison.
       strcmp() devuelve un entero: 0 si ambas cadenas son iguales, 1 o -1 si no lo son.
    */

    printf("%d\n", strcmp(nombre1, nombre2));
    printf("%d\n", strcmp(nombre1, nombre3));
    printf("%d\n", strcmp(nombre1, nombre4));

    /*
    Podemos ver que en el primer print devolvió 0 porque son iguales.
    En el segundo, -1 la segunda cadena viene después en el diccionario que la primera.
    En el tercero dio 1, ya que la segunda cadena viene antes en el diccionario que la primera.

    No obstante, el criterio de ordenamiento se basa en codigo ASCII y los valores de las mayúsculas
    son menores a los de las minúsculas.

    C ES CASE SENSITIVE no es lo mismo "juan" a "Juan".
    Para ese caso existe stricmp() que no es sensible a mayúsculas y minúsculas
    */
    printf("Con strcmp: %d\n", strcmp(nombre1, nombre5));
    printf("Con stricmp: %d\n", stricmp(nombre1, nombre5));


    /*
    ¿cómo paso una cadena a mayúscula o a mínuscula? NO PUEDO USAR TOLOWER
    strlwr() me convierte una cadena completa a minuscula.
    strupr() me convierte una cadena completa a mayúscula.
    */

    // esto convierte una cadena a minusculas
    printf("%s\n", nombre5);
    for(int i = 0; i < strlen(nombre5); i++)
    {
        nombre5[i] = tolower(nombre5[i]);
    }
    printf("%s\n", nombre5);

    // esto convierte una cadena a mayusculas
    printf("%s\n", nombre6);
    for(int i = 0; i < strlen(nombre6); i++)
    {
        nombre6[i] = toupper(nombre6[i]);
    }
    printf("%s\n", nombre6);

    return 0;
}
