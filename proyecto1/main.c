#include <stdio.h>
#include <stdlib.h>

int main()
{
    //printf("Hola Micaela!\n");
    //return 0;

    // declaración de variables
    // tipoDeDato + nombreVariable
    //int edad; guarda datos enteros.
    //float peso; guarda datos decimales
    //char sexo; guarda un caracter, ejemplo, una letra. Se guardan entre comillas simples.

    //mascaras %d las mascaras pueden ser octales, decimales, etc.

    int edad;
    float peso;
    char sexo;
    char nombre[10] = "Pepa";
    peso = 65.5;
    sexo = 'f';

    // El %d lo que va a hacer es hacer que se imprima el valor declarado de la variable edad
    // Podemos modificar la máscara, por ejemolo, la f si le pongo adelante .1 me muestra un sólo decimal
    //printf("La variable edad vale: %d, la variable peso vale: %.1f, la variable sexo es: %c", edad, peso, sexo);
    //printf("La persona se llama %s", nombre);

    // pedir datos:
    printf("Ingrese edad");
    scanf("%d", &edad);
    printf("Ingresaste el valor %d", edad);

    return 0;
}
