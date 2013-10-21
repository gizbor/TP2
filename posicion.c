#include "posicion.h"

/******************************************************************************
* Descripción: copia los valores de p1 en el struct Posicion apuntado por p2.
******************************************************************************/
void clonar(Posicion p1, Posicion* p2){
    p2->x=p1.x;
    p2->y=p1.y;
}
