#include <stdio.h>
#include <stdlib.h>
#include "Factura.h"
#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED


typedef struct
{
  lista_factura * inicio;
  lista_factura * fin;
}fila;

void inicFila(fila * filita);
void listatoFila (fila * filita, lista_factura * lista);
void agregarFila (fila * filita,lista_factura * nodoNuevo);
factura verPrimero (lista_factura * lista);
factura generica ();
lista_factura * borrarPrimero (lista_factura * lista);
void extraer (fila * filita);
int comprobarFila (fila  filita);

#endif // FILA_H_INCLUDED

