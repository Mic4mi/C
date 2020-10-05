#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/*
    IMPORTANTE:
    Cuando una estrctura contiene a otra en su interior, por ejemplo, ePersona tiene una
    eFecha de nacimiento, es necesario que la estructura que se guarda dentro de otra
    esté declarada previamente. En este caso, eFecha debe estar antes que ePersona.
*/

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char sexo;
    char nombre[21];
    float altura;
    eFecha fechaNac;
    int isEmpty; // 1 libre, cero ocupado.
} ePersona;

int main()
{
    // carga por Asignación:
    ePersona p1;
    ePersona p2;
    ePersona p3;
    eFecha f2 = {16, 4, 1986};
    //Harcodeo fuerte
    eFecha f4 = {24, 12, 1989};
    ePersona p4 = {4565, 'f', "Julia", 1.80, f4, 0};
    ePersona p5 = {7898, 'm', "Eduardo", 1.85, {4, 2, 2000}, 0};


                   p1.isEmpty = 0;
                   p1.legajo = 1232;
                   strcpy(p1.nombre, "Jose");
                   p1.sexo = 'm';
                   p1.altura = 1.75;
                   p1.fechaNac.dia = 30;
                   p1.fechaNac.mes = 3;
                   p1.fechaNac.anio = 1998;

                   printf("Persona 1:\n Legajo: %d\n Nombre: %s\n Sexo: %c\n Altura:%.2f\n Fecha de nacimiento: %0d/%0d/%d\n",
                          p1.legajo,
                          p1.nombre,
                          p1.sexo,
                          p1.altura,
                          p1.fechaNac.dia,
                          p1.fechaNac.mes,
                          p1.fechaNac.anio);

                   //Otro tipo de carga por asignacion
                   p2.isEmpty = 0;
                   p2.legajo = 1587;
                   strcpy(p2.nombre, "Mariela");
                   p2.sexo = 'f';
                   p2.altura = 1.68;
                   p2.fechaNac = f2;

                   printf("\nPersona 2:\n Legajo: %d\n Nombre: %s\n Sexo: %c\n Altura:%.2f\n Fecha de nacimiento: %0d/%0d/%d\n",
                          p2.legajo,
                          p2.nombre,
                          p2.sexo,
                          p2.altura,
                          p2.fechaNac.dia,
                          p2.fechaNac.mes,
                          p2.fechaNac.anio);

                   //Pedirle datos al usuario
                   p3.isEmpty = 1;
                   p3.legajo = 5555;

                   printf("Ingrese nombre: ");
                   fflush(stdin);
                   gets(p3.nombre);

                   printf("\nIngrese sexo: ");
                   fflush(stdin);
                   scanf("%c", &p3.sexo);

                   printf("\nIngrese altura: ");
                   scanf("%f", &p3.altura);

                   printf("\nIngrese fecha de nacimiento dd/mm/aaaa:\n");
                   scanf("%d/%d/%d", &p3.fechaNac.dia, &p3.fechaNac.mes, &p3.fechaNac.anio);

                   printf("\nPersona 3:\n Legajo: %d\n Nombre: %s\n Sexo: %c\n Altura:%.2f\n Fecha de nacimiento: %0d/%0d/%d\n",
                          p3.legajo,
                          p3.nombre,
                          p3.sexo,
                          p3.altura,
                          p3.fechaNac.dia,
                          p3.fechaNac.mes,
                          p3.fechaNac.anio);

                   //P4 & p5 harcodeadas
                   printf("\nPersona 3:\n Legajo: %d\n Nombre: %s\n Sexo: %c\n Altura:%.2f\n Fecha de nacimiento: %0d/%0d/%d\n",
                          p4.legajo,
                          p4.nombre,
                          p4.sexo,
                          p4.altura,
                          p4.fechaNac.dia,
                          p4.fechaNac.mes,
                          p4.fechaNac.anio);

                   printf("\nPersona 3:\n Legajo: %d\n Nombre: %s\n Sexo: %c\n Altura:%.2f\n Fecha de nacimiento: %0d/%0d/%d\n",
                          p5.legajo,
                          p5.nombre,
                          p5.sexo,
                          p5.altura,
                          p5.fechaNac.dia,
                          p5.fechaNac.mes,
                          p5.fechaNac.anio);



                   return 0;
                  }
