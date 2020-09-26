#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[20] = "juan"; // se pod�a escribir {"Juan"} pero no es necesario
    char otroNombre[20];
    char nombre3[20] = "Pepe";
    char nombre4[20];
    char tuNombre[20];
    int longitud;

    printf("Hola %s, como andas?\n", nombre);
    puts(nombre); // s�lo imprime el contenido de nombre, m�s no permite escribir un msje. No se suele usar.

    /*
    Como los vectores son direcciones de memoria, no puedo asignarle a algo que esta esperando un dato
    del tipo puntero, una cadena de caracteres, por eso mismo no se puede hacer esto:

    char nombre[20];
    nombre = "juan";

    Para copiar una cadena en otra, existe una funci�n, debe incluirse una biblioteca string.h.
    Todas las funciones nativas de manejo de cadena arrancan con el nombre str (string).
    Para copiar una cadena en otra se emplea STRCPY (string copy). Recibe como parametro dos vectores:

    strcpy(origen, destino);

    origen: el elemento que quiero copiar.
    destino: d�nde quiero copiar ese elemento.

    La funci�n hace un BREAK cuando encuentra el /0, no recorre la totalidad del vector.

    con STRING NO SE PUEDE HACER ASIGANCI�N CON UN =

    IMPORTANTE TENER EN CUENTA EL TAMA�O DE LOS ARRAYS PARA NO REBALSAR LA MEMORIA

    -------------------------------------------------
    SCANF
    Scan f toma el espacio como un salto, entonces en el momento en el cual sienta un espacio
    dejara de tomar lo que sigue.
    ejemplo: si le paso "Juan Carlos", solo toma "Juan". Por lo tanto es mejor usar GETS

    --------------------------------------------------
    GETS || fgets

    Solo recibe como par�metro el vector d�nde quiero guardar el string

    FGETS
    es una funci�n de archivos, recibe un puntero para guardar un string, la longitud que hay disponible
    y un puntero al bufer del teclado (stdin)

    fgets(nombre, 5, stdin); Es una funci�n segura.
    --------------------------------------------------
    STRLEN - > Se refiere al largo de la cadena
    recibe como parametro un vector y devuelve la cantidad de caracteres de esa cadena
    */
    strcpy(otroNombre, "Mariela");
    printf("Hola %s, como andas?\n", otroNombre);

    strcpy(nombre4, nombre3);
    printf("Nombre 3 vale: %s\n", nombre3);
    printf("Nombre 4 vale: %s\n", nombre4);


    // gets
    printf("Como te llamas?\n");
    fflush(stdin),
    gets(tuNombre);
    printf("Hola %s, como andas?\n", tuNombre);

    longitud = strlen(tuNombre);
    printf("Tu nombre mide: %d\n", longitud);

    /* c�mo evitar el desbordamiento del vector?
    1) MANERA 1
        Empleando la funci�n fgets, ya que recibe como parametro el puntero a d�nde queremos
        guardar la cadena, luego un numero entero que indica la longitud de la cadena. Esto impide
        que el usuario ingrese m�s caracteres que lo permitido. Siempre guarda 1 caracter menos de lo que
        vale el valor que pasamos por par�metro. Ej: si hacemos fgets(nombre, 5, stdin), guardar� 4 char.

    2) MANERA 2

    */





    return 0;
}
