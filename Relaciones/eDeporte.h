#ifndef EDEPORTE_H_INCLUDED
#define EDEPORTE_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];
} eDeporte;

int mostrarDeportes(eDeporte* sports, int tam);
void mostrarDeporte(eDeporte sport);
int findDeporteById(eDeporte* list, int len,int id);
int cargarDescripcionDeporte(eDeporte* sports, int len, int id, char* descripcion);


#endif // EDEPORTE_H_INCLUDED
