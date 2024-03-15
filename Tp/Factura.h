#include<stdlib.h>
#include<stdio.h>
#include "Prendas.h"
#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED


typedef struct{

int numero_factura;
int id;
char cliente[50];
float valor;
prenda pedidos[50];
int despachado;
int validosPedidos;
}factura;


typedef struct lista_factura{

factura dato;
struct lista_factura* siguiente;
struct lista_factura* anterior;
}lista_factura;

lista_factura * inicFactura ();
lista_factura * crearFactura (factura datos);
lista_factura * agregarFinal (lista_factura * lista,lista_factura * nuevo);
lista_factura * buscarUltimo (lista_factura * lista);
void mostrarListaFactura (lista_factura * lista);
void mostrarUnaFactura (lista_factura * nodo);
void pasarFacturaToArchivo (FILE* buff,lista_factura * lista);
int contar_camt_facturas(lista_factura* lista);

#endif // FACTURA_H_INCLUDED
