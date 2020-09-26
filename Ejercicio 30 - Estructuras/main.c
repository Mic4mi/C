#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



/*
Con las estructuras se declara un nuevo tipo de dato.
*/
typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    int nota1;
    int nota2;
    float prom;
} eAlumno;

int main()
{
    //hardcodeado
    eAlumno unAlumno = {1598, "Micaela", 'f', 5, 6, 5.5};
    eAlumno otroAlumno;

    /*
    LO BUENO DE LAS ESTRCTURAS ES QUE PUEDO DECIR QUE UNA ES IGUAL A OTRA PARA COPIAR LOS DATOS.
    */

    otroAlumno = unAlumno;

    //mostrar datos harcodeados
    // printf("Nombre del alumno: %s\n", unAlumno.nombre);
    // printf("Legajo: %d\n", unAlumno.legajo);


    //pedir datos
    /*
    printf("Ingrese legajo: \n");
    scanf("%d", &otroAlumno.legajo);

    printf("Ingrese nombre: \n");
    fflush(stdin);
    scanf("%s", &otroAlumno.nombre);

    printf("Ingrese sexo: \n");
    fflush(stdin);
    scanf("%c", &otroAlumno.sexo);

    printf("Ingrese nota del primer parcial: \n");
    scanf("%d", &otroAlumno.nota1);

    printf("Ingrese nota del segundo parcial: \n");
    scanf("%d", &otroAlumno.nota2);

    //promedio
    otroAlumno.prom = (float)(otroAlumno.nota1 + otroAlumno.nota2) /2;
    */

    //mostrar datos
    printf("Nombre del alumno: %s\n", otroAlumno.nombre);
    printf("Legajo: %d\n", otroAlumno.legajo);
    printf("Sexo: %c\n", otroAlumno.sexo);
    printf("Primer parcial: %d\n", otroAlumno.nota1);
    printf("Segundo parcial: %d\n", otroAlumno.nota2);
    printf("Promedio: %.2f\n", otroAlumno.prom);

    return 0;
}
