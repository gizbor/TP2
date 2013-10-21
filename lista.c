#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/******************************************************************************
* Descripción:
*
* Parametros: -
******************************************************************************/

/******************************************************************************
* Descripción: devuelve puntero a nodo con el valor suministrado por parámetro y
* su estructura inicializada.
******************************************************************************/
Nodo* crear_nodo(char c){
    Nodo* nodo=(Nodo*)malloc(sizeof(Nodo));
    nodo->valor=c;
    nodo->siguiente=NULL;
return nodo;
}

/******************************************************************************
* Descripción: agrega al final de la lista el carácter suministrado por parámetro.
******************************************************************************/
void agregar(Lista* lista, char c){
    Nodo* nodo= crear_nodo(c);
    if (lista->primero == NULL){
        lista->primero = nodo;
        lista->ultimo = nodo;
     } else {
       lista->ultimo->siguiente =  nodo;
       lista->ultimo = nodo;
     }
    lista->tamanio++;
}

/******************************************************************************
* Descripción: setea los valores iniciales de la lista.
******************************************************************************/
void inicializar_lista(Lista* lista){
    lista->primero=NULL;
    lista->ultimo=NULL;
    lista->ultimo_leido=NULL;
    lista->tamanio= 0;
}

/******************************************************************************
* Descripción: imprime los valores de la lista de principio a fin.
******************************************************************************/
void imprimirLista(Lista *lista){
    Nodo* nodo= lista->primero;
    while (nodo!= NULL){
            printf("%c", nodo->valor);
    nodo=nodo->siguiente;
    }
}

/******************************************************************************
* Descripción: libera la memoria dinámica usada por la lista.
******************************************************************************/
void eliminar(Lista *lista){
    Nodo* nodo= lista->primero, *sig;
    while (nodo!= NULL){
        sig=nodo->siguiente;
        free(nodo);
        nodo=sig;
    }
}

/******************************************************************************
* Descripción: devuelve el caracter almacendo en la posición "index". Si no existe
* tal devuelve CARACTER_INVALIDO.
*
* Parametros: index: [0..inf]
******************************************************************************/
char obtener(Lista* lista, int index){
    int i;
    Nodo* nodo= lista->primero;
    if (index <= lista->tamanio-1){
        for (i=0; i< index; i++)
            nodo=nodo->siguiente;
        lista->ultimo_leido=nodo;
    } else {
        return CARACTER_INVALIDO;
    }
return nodo->valor;
}

/******************************************************************************
* Descripción: devuelve el carácter siguiente al último leido. Retorna
* CARACTER_INVALIDO al haber llegado al final.
******************************************************************************/
char siguiente(Lista* lista){
    Nodo* nodo;
    if ((nodo=lista->ultimo_leido->siguiente)!=NULL)
        lista->ultimo_leido=lista->ultimo_leido->siguiente;
    else
        return CARACTER_INVALIDO;
return nodo->valor;
}
