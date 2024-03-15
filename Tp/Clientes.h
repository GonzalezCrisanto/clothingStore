#include <stdio.h>
#include <stdlib.h>
#include "Factura.h"
#include <string.h>
#include <conio.h>
#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    int cuil;
    char mail[70];
    float saldo;
    int alta;
} datoCliente;


typedef struct stcliente
{
    datoCliente dato;
    lista_factura * listaFactura;
    struct stcliente* siguiente;

} stcliente;

stcliente* inic_cliente();
datoCliente datos_cliente(int* cant, stcliente * lista);
stcliente* cargar_cliente(datoCliente dato);
stcliente* lista_id(stcliente* lista, stcliente* nuevoN);
int cant_cliente(stcliente* lista);
stcliente* cargar_VariosCliente(stcliente* lista);
void pasarListaToArchivo (char archCliente[],char archFactura[], stcliente* lista);
int pasarArchivoClienteToArbolPorID(stcliente ** arbol, char archivo[]);
stcliente * busquedaCliente (stcliente * lista, int id);
stcliente * pasarArchivoClienteToLista(stcliente * lista, char archCliente[], char archFactura[]);
void mostrar_lista_clientes(stcliente* cliente);
void mostrar_un_cliente(datoCliente cliente);
void dar_baja(stcliente* cliente);
lista_factura* pasarArchivoToFactura (FILE* buff,lista_factura * lista, char nombreCliente[]);
void hacer_pedido(stcliente* cliente, nodoPrenda * arbolP);
void buscar_uncliente_mostrar(stcliente* lista, int id);
int validaCuil (stcliente * lista, int cuil);
int validaEmailCliente (stcliente * lista, char email[]);
int validaNombre(stcliente * lista, char nombreEmpresa[]);
datoCliente modificarCliente (stcliente * lista, datoCliente aux);
void mostrarEstado (stcliente * nodoC);
factura cargarUnaFactura(int * cant, nodoPrenda * arbolP, stcliente * aux2);
#endif // CLIENTES_H_INCLUDED
