#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
#include <stdio.h>
#include "posicion.h"
#include "stdlib.h"
typedef  char movimiento;
#define UP 'U'
#define DOWN 'D'
#define LEFT 'L'
#define RIGHT 'R'

#define FIN_ARCHIVO '\n'
#define POSICION_INVALIDA -3


typedef  struct matriz {
    char* datos;
    unsigned int n, m; /* n: filas, m: columnas */
} Matriz;

void inicializar_matriz(Matriz* matriz, int n, int m, FILE* fdata);
char get_elemento(Matriz *matriz, Posicion pos);
void imprimir_matriz(Matriz *matriz);
void eliminar_matriz(Matriz* matriz);

#endif
