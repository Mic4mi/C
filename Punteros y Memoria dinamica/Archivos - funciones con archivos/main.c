#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int id;
    char nombre[128];
    char sexo;
    float sueldo;
} Employee;


int main()
{
    //Employee emp1 = {1000,"Jorge", 'm', 45000};


    FILE* f = fopen("datos.txt", "w"); //w sirve para escribir como texto

    if(f != NULL)
    {
        //Lo usamos
        //fn para leer
        //fn para escribir
        fprintf(f, "hola %d", 10); //Para escribir texto en un archivo
        fclose(f); //Me asegura que lo que escribí queda en el archivo
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }

    /**/

    return 0;
}
