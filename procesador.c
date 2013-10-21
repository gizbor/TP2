#include "procesador.h"

/******************************************************************************
* Descripción: copia los valores de la dimensión desde el archivo f2 a n y m.
*
* Parametros:
* f2: puntero FILE apuntando al principio del par NXM de la linea.
* n, m: punteros a int's.
******************************************************************************/
int parsear_dimension(FILE* f2, int* n, int* m){
     int error;
     error=fscanf(f2, "%d", n);
     fseek(f2, 1, SEEK_CUR); /* saltar x ó X */
     error+=fscanf(f2, "%d", m);
return error;
}
/******************************************************************************
* Descripción: imprime la lista resultante del proceso en el formato pedido.
******************************************************************************/
void imprimir_lista_formateada(Lista *lista){
    char c;
    c=obtener(lista, 0);
    while (c!= CARACTER_INVALIDO){
        if (c == MOVIMIENTO_INVALIDO)
            printf("%s", "[E]");
        else
            printf("%c", c);
    c=siguiente(lista);
    }
}

void imprimir_resultado(int movimientos_validos, Lista* lista){
    printf("%d ", movimientos_validos);
    imprimir_lista_formateada(lista);
    printf("%c", '\n');
}

/******************************************************************************
* Descripción: proceso principal del programa. Retorna la cantidad de movimien-
* tos válidos y los caracteres leidos agregados a la lista pasada por parámetro
* (incluyendo los invalidos representados con el carácter MOVIMIENTO_INVALIDO).
*
* Parametros:
*   f1: archivo de texto (primer parámetro del programa).
*   f2: archivo con la dimension y los movimientos (segundo parámetro del prog-
*   ma o stdin)
******************************************************************************/
void procesar(FILE* f1, FILE* f2){
    Matriz matriz;
    Lista lista;
    Posicion pos, pos_anterior;
    int n, m, movimientos_validos, ignorar;
    char c;

    while ((c=getc(f2))!=FIN_ARCHIVO && !ferror(f2)){
            fseek(f2, -1, SEEK_CUR);
            parsear_dimension(f2, &n, &m);
            inicializar_matriz(&matriz, n, m, f1);
            inicializar_lista(&lista);
            /* apuntar f2 a primer movimiento */
            fseek(f2, 1, SEEK_CUR);

            pos.x=1; pos.y=1, movimientos_validos=0;
            while ((c=getc(f2)) != FIN_ARCHIVO){
               ignorar=0;
               clonar(pos, &pos_anterior);
               switch (c){
                  case UP:
                     pos.y-=1; break;
                  case DOWN:
                     pos.y+=1; break;
                  case LEFT:
                     pos.x-=1; break;
                  case RIGHT:
                     pos.x+=1; break;
                  default:
                     ignorar=1; break;
                };
               if (ignorar==0){
                  if ((c=get_elemento(&matriz, pos))==POSICION_INVALIDA){
                     clonar(pos_anterior, &pos);
                     agregar(&lista, MOVIMIENTO_INVALIDO);
                  } else {
                     movimientos_validos+=1;
                     agregar(&lista, c);
                   }
               }
            }
            imprimir_resultado(movimientos_validos, &lista);
            eliminar_matriz(&matriz);
            eliminar(&lista);
    }
}
