#include "Pila.h"

Pila insertar(char *elemento, Pila pila) {
    if (!pila) {
        pila = (Pila *) malloc(sizeof(Pila));
        pila->elemento=elemento;
        pila->duracion=0;
        pila->siguiente=NULL;
    } else {
        Pila auxiliar = (Pila*)malloc (sizeof(Pila));
        auxiliar->elemento= elemento;
        auxiliar->duracion = 0;
        auxiliar->siguiente = pila;
        pila= auxiliar;
    }
    return pila;
}

char *desempilar(Pila pila) {
    Pila auxiliar= pila;
    if (pila->siguiente) {
        pila = pila->siguiente;
    } else {
        pila = NULL;
    }
    char *contenido =auxiliar->elemento;
    free(auxiliar);
    return contenido;
}

int vacia(Pila pila) {
    return (pila==NULL);
}

void imprimir(Pila pila) {
    Pila auxiliar = pila;
    int fin=1;
    while (auxiliar && fin) {
        printf("%s\n",auxiliar->elemento);
        if (auxiliar->siguiente) {
            auxiliar = auxiliar->siguiente;
        } else {
            fin = 0;
        }
    }
}

int main() {
    Pila *pila;
    pila = NULL;
    char *elem = "Hola mundo";
    pila = insertar(elem,pila);
    char *elem2="Como estas?";
    pila = insertar(elem2,pila);
    char *elem3 = "Bien y tu?";
    pila = insertar(elem3,pila);
    imprimir(pila);

    
}
