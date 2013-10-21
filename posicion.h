#ifndef POSICION_H_INCLUDED
#define POSICION_H_INCLUDED

typedef struct posicion Posicion;
struct posicion {
    int x, y;
};

void clonar(Posicion p1, Posicion*p2);

#endif
