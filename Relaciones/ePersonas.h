#ifndef EPERSONAS_H_INCLUDED
#define EPERSONAS_H_INCLUDED
#include "eFechas.h"


typedef struct
{
    int legajo;
    char nombre[21];
    char sexo;
    float altura;
    eFecha fechaNac;
    //int idDeporte;
    int isEmpty;
} ePersona;

void menu();
int hardcodearPersonas(ePersona* lista, int tam, int cantPersonas);
int initPersonas(ePersona* list, int tam);
int findPersonaById(ePersona* list, int len,int id);
void showPersona(ePersona persona);
int printPersonas(ePersona* list, int len);
int addPersona(ePersona* list, int len, int ID);
int modifiePersona(ePersona* list, int len);
int removePersona(ePersona* list, int len);

#endif // EPERSONAS_H_INCLUDED
