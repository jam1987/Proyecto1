/* 
 * File:   Pila.h
 * Author: julio
 *
 * Created on 17 de enero de 2013, 12:28
 */


#include<stdio.h>

#ifndef PILA_H
#define	PILA_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PILA_H */


struct caja {
    char *elemento;
    int duracion;
    struct elemento *siguiente;
};

typedef struct caja Caja;

typedef  struct caja  *Pila;

extern Pila insertar(char*,Pila);
extern char *desempilar(Pila);
extern int vacia(Pila);
extern void imprimir(Pila); 
