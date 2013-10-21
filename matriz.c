#include "matriz.h"

/******************************************************************************
* Descripción: setea los valores iniciales de la matriz.
******************************************************************************/
void inicializar_matriz(Matriz* matriz, int n, int m, FILE* fdata){
    int i=0, complete=1;
    char* datos, c;
    matriz->n=n;
    matriz->m=m;
    matriz->datos=(char*)malloc(sizeof(char)*n*m);

    datos= matriz->datos;
    fseek(fdata, 0, SEEK_SET);
    while (complete==1){
        while (i++<n*m &&  (c=getc(fdata))!=FIN_ARCHIVO)
            *datos++=c;

        if (c==FIN_ARCHIVO)
           fseek(fdata, 0, SEEK_SET);
        else
           complete=0;
    }
}

/******************************************************************************
* Descripción: devuelve el carácter en la posición suministrada. En caso de ser una
* posición inválida se retorna POSICION_INVALIDA.
*
* Parametros: pos.x: [1..inf], pos.y: [1..inf]
******************************************************************************/
char get_elemento(Matriz *matriz, Posicion pos){
    if ((pos.x>matriz->m || pos.x <1) || (pos.y>matriz->n || pos.y <1))
        return POSICION_INVALIDA;

return *(matriz->datos+(matriz->m*(pos.y-1)+(pos.x-1))*sizeof(char));
}

/******************************************************************************
* Descripción: imprime la matriz en formato algebraico.
******************************************************************************/
void imprimir_matriz(Matriz *matriz){
    Posicion pos;
    for (pos.y=1; pos.y<=matriz->n; pos.y++){
        printf("[");
        for (pos.x=1; pos.x<= matriz->m; pos.x++)
            printf("%c ", get_elemento(matriz, pos));

        printf("]\n");
    }
}

/******************************************************************************
* Descripción: libera la memoria dinamica utilizada por la matriz.
******************************************************************************/
void eliminar_matriz(Matriz* matriz){
    free(matriz->datos);
}


