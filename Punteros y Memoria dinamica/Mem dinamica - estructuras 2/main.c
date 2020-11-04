#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char marca[20];
    float precio;
} eAuto;

void autos_hardcodearAutos(eAuto* pLista, int tam);
void autos_mostrarLista(eAuto* pLista, int tam);
void autos_mostrarItem(eAuto* unAuto);
void autos_OrdenarPorMarca(eAuto* pLista, int tam);

eAuto* newAuto();
eAuto* newAutoParam(int id, char* marca, float precio);

void autos_mostrarLista2(eAuto** pLista, int tam);
void autos_OrdenarPorMarca2(eAuto** pLista, int tam);

void autos_destroy(eAuto* unAuto);
void autos_destroyAll(eAuto** autos, int tam);


int main()
{
    eAuto* listaD = (eAuto*) malloc(sizeof(eAuto) * 5); //Array de 5 eAuto
    eAuto** lista2 = (eAuto**) malloc(sizeof(eAuto*) * 5); //Array de 5 punteros a eAuto

    *(lista2 + 0) = newAutoParam(1000, "Ferrari", 500000);
    *(lista2 + 1) = newAutoParam(1001, "Ford", 600000);
    *(lista2 + 2) = newAutoParam(1002, "Peugeot", 222000);
    *(lista2 + 3) = newAutoParam(1003, "BMX", 325000);
    *(lista2 + 4) = newAutoParam(1004, "Audi", 777000);


    autos_hardcodearAutos(listaD,5);
    autos_mostrarLista(listaD,5);
    printf("\nAhora, ordenada: \n");
    autos_OrdenarPorMarca(listaD,5);
    autos_mostrarLista(listaD,5);

    system("pause");
    system("cls");
    printf("Ahora, con array de punteros: \n");
    autos_mostrarLista2(lista2, 5);
    printf("\nAhora, ordenada: \n");
    autos_OrdenarPorMarca2(lista2,5);
    autos_mostrarLista2(lista2, 5);

    autos_destroyAll(lista2, 5);
    return 0;
}

void autos_hardcodearAutos(eAuto* pLista, int tam)
{
    int ids[5] = {1000,1001,1002,1003,1004};
    char marcas[5][21] = {"Renault", "Peugeot", "Audi", "BMW", "Ford"};
    float precios[5] = {100000,200000,300000,400000.50,200000.99};

    for(int i = 0; i<tam; i++)
    {
        (pLista + i)->id = ids[i];
        strcpy((pLista + i)->marca, marcas[i]);
        (pLista + i)->precio = precios[i];
    }
}

void autos_mostrarLista(eAuto* pLista, int tam)
{
    printf("\nLISTA DE AUTOS\n\n");
    printf(" ID        MARCA         PRECIO\n");
    for(int i = 0; i<tam; i++)
    {
        autos_mostrarItem(pLista + i);
    }
    printf("\n\n");

}

void autos_mostrarItem(eAuto* unAuto)
{
    printf("%d   %10s       $%4.2f\n",
           unAuto->id,
           unAuto->marca,
           unAuto->precio);
}


void autos_OrdenarPorMarca(eAuto* pLista, int tam)
{
    eAuto auxAuto;

    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if(strcmp((pLista+i)->marca, (pLista+j)->marca) > 0)
            {
                auxAuto = *(pLista + i);
                *(pLista + i) = *(pLista + j);
                *(pLista + j) = auxAuto;
            }
        }
    }
}

eAuto* newAuto()
{
    return (eAuto*) malloc(sizeof(eAuto));
}

eAuto* newAutoParam(int id, char* marca, float precio)
{
    eAuto* nuevo = newAuto();
    nuevo->id = id;
    strcpy(nuevo->marca, marca);
    nuevo->precio = precio;

    return nuevo;
}

void autos_mostrarLista2(eAuto** pLista, int tam)
{
    printf("\nLISTA DE AUTOS\n\n");
    printf(" ID        MARCA         PRECIO\n");
    for(int i = 0; i<tam; i++)
    {
        autos_mostrarItem(*(pLista + i));
    }
    printf("\n\n");
}

void autos_OrdenarPorMarca2(eAuto** pLista, int tam)
{
    eAuto* pAuxAuto;

    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if(strcmp((*(pLista+i))->marca, (*(pLista+j))->marca) > 0)
            {
                pAuxAuto = *(pLista + i);
                *(pLista + i) = *(pLista + j);
                *(pLista + j) = pAuxAuto;
            }
        }
    }
}

void autos_destroy(eAuto* unAuto)
{
    free(unAuto);
}

void autos_destroyAll(eAuto** autos, int tam)
{
    for(int i =0; i < tam; i++)
    {
        autos_destroy(*(autos + i));
    }
    free(autos);
}

/*
20.03 CODEBLOCSK
*/
