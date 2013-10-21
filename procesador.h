#ifndef PROCESADOR_H_INCLUDED
#define PROCESADOR_H_INCLUDED
#include <stdio.h>
#include "matriz.h"
#include "lista.h"
#include "posicion.h"

#define MOVIMIENTO_INVALIDO -2

void imprimir_lista_formateada(Lista* lista);
void imprimirResultado(int movimientos_validos, Lista* lista);
int parsear_dimension(FILE* f2, int* n, int* m);
void procesar(FILE* f1, FILE* f2);

#endif
