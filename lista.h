#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define CARACTER_INVALIDO -1

typedef struct nodo Nodo;
typedef struct lista Lista;

struct nodo {
    char valor;
    Nodo* siguiente;
};

struct lista {
    Nodo *primero, *ultimo, *ultimo_leido;
    int tamanio;
};

void inicializar_lista(Lista* lista);
void agregar(Lista* lista, char c);
Nodo* crear_nodo(char c);
void agregar(Lista* lista, char c);
void imprimir(Lista* lista);
void eliminar(Lista* lista);
char obtener(Lista* lista, int index);
char siguiente(Lista* lista);

#endif
