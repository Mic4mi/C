#include <stdio.h>
#include <stdlib.h>

void saludar(void);
void despedir(void);
int sumar(int a, int b);
int restar(int a, int b);
int calcular(int a, int b, int (*callback)(int, int));


int main()
{
    void (*pepe) (void); //puntero a funci�n
    int (*miguel) (int, int);
    pepe = saludar;

    miguel = sumar;

    printf("%d\n", sumar(10, 5));
    printf("%d\n", miguel(10, 5));

    miguel = restar;

    printf("%d\n", restar(10, 5));
    printf("%d\n", miguel(10, 5));

    int* numeros = (int*) malloc(sizeof(int) * 5);

    *(numeros + 0) = 3;
    *(numeros + 1) = 8;
    *(numeros + 2) = 4;
    *(numeros + 3) = 9;
    *(numeros + 4) = 5;

    int* p = numeros; //P est� apuntando al array de numeros

    printf("%d\n", *(numeros + 2));
    printf("%d\n", *(p + 2));

    /*
    Ambos punteros apuntan a la misma direcci�n.
    Cuando empleamos realloc hacemos esto mismo, ya que una variable auxiliar apunta
    al mismo lugar que la variable original.

    STACK && CALLBACKS
    Main es un entry point.
    A medida que se va ejecutando, cuando hay llamadas a una funci�n
    se van apilando y desapilando en el stack.
    Las funciones recursivas se llaman as� mismas por lo que se llaman y se "apilan"
    varias veces.

    EL nobre de un vector guarda la direcci�n de memoria del primer elemento.
    El nombre de una funci�n guarda la direcci�n de memoria del segmento d�nde
    esta la funci�n. El nombre de una funci�n es un PUNTERO a funci�m. Var que
    guarda la direcci�n de memoria d�nde esta el desarrollo de una funci�n.
    Cuando le ponemos los () le estamos indicando que ejecute ese pedazo
    de c�digo.
    */
    saludar();
    pepe();

    printf("\n------------------------------------------------\n");
    printf("%d\n", calcular(5, 10, sumar));
    printf("%d\n", calcular(5, 10, restar));

    return 0;
}

void saludar(void)
{
    printf("Hola!\n");
}

void despedir(void)
{
    printf("Chau!\n");
}

int sumar(int a, int b)
{
    return a + b;
}

int restar(int a, int b)
{
    return a - b;
}

int calcular(int a, int b, int (*callback)(int, int))
{
    return callback(a, b);
}
