#include <stdio.h>
#include <stdlib.h>

void saludar();
void despedir();
void queHago(void (*callback)(void));

int main()
{
    void (*pFunc)();

    pFunc = saludar;

    pFunc();

    pFunc = despedir;

    pFunc();

    printf("\nAhora con la funcion queHago: \n");

    queHago(saludar);
    queHago(despedir);

    /*
    PUNTERO A FUNCION

    - Segmento de codigo
      --> Cuando se hace click en un .exe, las variables y funciones que contiene
          ese programa se cargan en memoria, en el "segmento de codigo".
          A medida que se va ejecutando se carga en la pila (stack). Todo el codigo
          del programa va a parar a este segmento.

      --> Un vector vec[] representa la direcci�n de memoria del primer elemento. El
          nombre del vector por si s�lo es puntero al primer elemento del array.
          Una funcion func() tambi�n es puntero a un trozo de c�digo. En el nombre de
          la funci�n, la maquina guarda la direcci�n de memoria de un trozo de c�digo
          ejecutable. Cuando invocamos a la funci�n func() el programa a buscar ese
          pedazo de codigo para ejecutarlo. El nombre de la funcion es un puntero a
          d�nde esta guardado el c�digo de la funci�n. Cuando escribimos el nombre de
          la funci�n con () func(), estamos pidiendole a la maquina que busque ese trozo
          de codigo y lo cargue en memoria para ejecutarlo.

      --> El objetivo es poder pasarle a funcion como par�metro un puntero a otra funcion
          de esta manera lograr�amos que la funci�n se comporte de x manera sin tener que
          escribir varias versiones dela misma funci�n.
          Una �nica funci�n va a tener multiples comportamientos.
          En C# y JAVA esto se conoce como "delegados", en JavaScript se le conoce como
          "callbacks".

           _________
       _> |M|_|_|_|_|  ---> Main              Cuando se carga el programa, se carga main.
      |   |_|S|_|_|_|  ---> Saludar           Saludar guarda la direcci�n de memoria de
      |   |_|D|_|_|_|  ---> Despedir          el bloque de codigo que ejecuta un printf("hola")
      |                                       al igual que despedir que ejecuta printf("chau").
      |    _________                          En la memoria est�tica, tenemos un *pFunc que puede
      |   |_|_|_|_|_|                         guardar la direcci�n de memoria de otra funci�n, por ej
      |_  |*pF|_|_|_|  *pFunc                 pFunc=saludar; Ahora pFunc guarda lo que esta en la
          |_|_|_|_|_|                         direccion de memoria de la funcion saludar.


          Para que una funcion reciba como parametro otra funcion, debe recibir la direcci�n de memoria
          de la misma, es decir, un puntero a funcion.
    */


    return 0;
}

void saludar()
{
    printf("\nHola!\n");
}

void despedir()
{
    printf("\nChau!\n");
}

void queHago(void (*callback)(void))
{
    callback();
}
