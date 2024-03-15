#include<stdlib.h>
#include<stdio.h>
#include "Prendas.h"
#include "Clientes.h"



lista_factura * inicFactura ()
{
    return NULL;
}

lista_factura * crearFactura (factura datos)
{
    lista_factura * nuevo = (lista_factura*)malloc(sizeof(lista_factura));

    nuevo->dato = datos;

    nuevo->anterior = NULL;

    nuevo->siguiente = NULL;

    return nuevo;
}



lista_factura * agregarFinal (lista_factura * lista,lista_factura * nuevo)
{
    if(lista==NULL)
    {
        lista = nuevo;
    }
    else
    {
        lista_factura * ultimo = buscarUltimo(lista);

        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        nuevo->siguiente = NULL;
    }
    return lista;
}

lista_factura * buscarUltimo (lista_factura * lista)
{
    lista_factura * ultimo;

    while(lista->siguiente!=NULL)
    {
        lista = lista->siguiente;
    }
    ultimo = lista;

    return ultimo;
}

void mostrarListaFactura (lista_factura * lista)
{
    while(lista!=NULL)
    {
        mostrarUnaFactura(lista);
        lista = lista->siguiente;
    }
}

void mostrarUnaFactura (lista_factura * nodo)
{
    int i = 0;

    printf("\n-------------------------------\n");
    printf("\nNombre del Cliente: %s",nodo->dato.cliente);
    printf("\nId Pedido: %i",nodo->dato.id);
    printf("\nNumero de Factura: %i",nodo->dato.numero_factura);
    while(i<nodo->dato.validosPedidos)
    {
        printf("\n");
        mostrarPrenda(nodo->dato.pedidos[i]);
        i++;
    }
    printf("\n");
    if(nodo->dato.despachado!=0)
    {
        printf("\nDESPACHADO");
    }
    else
    {
        printf("\nEste pedido no ha sido DESPACHADO");
    }
    printf("\nValor: %f",nodo->dato.valor);
    printf("\n-------------------------------\n");
}


void pasarFacturaToArchivo(FILE* buff,lista_factura * lista)
{

factura aux;

        while(lista!=NULL)
        {
            aux = lista->dato;
            fwrite(&aux,sizeof(factura),1,buff);
            lista = lista->siguiente;
        }
}


int contar_camt_facturas(lista_factura* lista){

int cant=0;
while(lista!=NULL){

    cant++;
    lista = lista->siguiente;

}
return cant;
}


