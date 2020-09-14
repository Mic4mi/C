#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

/** \brief Busca cada ocurrencia de un caracter y lo reemplaza por otro
 *
 * \param Vector sobre el cual se realiza la busqueda
 * \param Tamaño del vector
 * \param Caracter a buscar y reemplazar
 * \param Caracter que reemplaza
 * \return La cantidad de caracteres reemplazados
 *
 */
int buscarReemplazar(char vec[], int tam, char a, char b);

/** \brief Recibe un vector de caracteres y su tamaño, lo recorre y lo muestra
 *
 * \param Vector
 *
 */
void mostrarVectorChar();

int main()
{
    char letras[] = {'s', 'r', 'u', 'p', 's', 's', 'a', 'd', 'f', 's', 's', 'l'};
    int ocurrencias;

    mostrarVectorChar(letras, 12);
    printf("\n");

    ocurrencias = buscarReemplazar(letras, 12, 's', 'Z');

    mostrarVectorChar(letras, 12);

    return 0;
}

int buscarReemplazar(char vec[], int tam, char a, char b)
{
    int cantidad = 0;
    for(int i = 0; i < tam; i++)
    {
        if(vec[i] == a)
        {
            vec[i] = b;
            cantidad++;
        }
    }
    return cantidad;
}

void mostrarVectorChar(char vec[], int tam){
    for(int i = 0; i < tam; i++)
    {
       printf("%c ", vec[i]);
    }
}
