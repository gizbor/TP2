#include <stdio.h>
#include "procesador.h"

/************ 75.42 - TALLER DE PROGRAMACION I: Cátedra Veiga **************
*    TRABAJO PRACTICO 2: "Detalle de recorrido de matrices"
*    Alumno: Gustavo Martín Borello
*    Padrón: 90670
*    Año/Cuatrimestre: 2013/2
******************************************************************************/

int main(int argc, char* argv[]){
    FILE* f1= fopen(argv[1], "r"), *f2;

    if (argc==3)
        f2=fopen(argv[2], "r");
    else
        f2=stdin;

    procesar(f1, f2);

    fclose(f2);
    fclose(f1);

 return 0;
}









