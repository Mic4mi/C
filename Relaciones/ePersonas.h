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
    int idDeporte;
    int isEmpty;
} ePersona;

void menu();
int hardcodearPersonas(ePersona* lista, int tam, int cantPersonas);
int initPersonas(ePersona* list, int tam);
int findPersonaById(ePersona* list, int len,int id);
void showPersona(ePersona persona, eDeporte* sports, int tamD);
int printPersonas(ePersona* list, int len, eDeporte* sports, int lenD);
int addPersona(ePersona* list, int len, int ID, eDeporte* sports, int lenD);
int modifiePersona(ePersona* list, int len, eDeporte* listD, int lenD);
int removePersona(ePersona* list, int len, eDeporte* listD, int lenD);

#endif // EPERSONAS_H_INCLUDED
