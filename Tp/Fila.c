#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Fila.h"
#include "Factura.h"

void inicFila(fila * filita)
{
    filita->inicio = inicFactura();
    filita->fin = inicFactura();
}

void listatoFila (fila * filita, lista_factura * lista)
{
    filita->inicio=lista;
    filita->fin=buscarUltimo(lista);

}


void agregarFila (fila * filita,lista_factura * nodoNuevo)
{
    if(filita->inicio==NULL)
    {
        filita->inicio = nodoNuevo;
        filita->fin = nodoNuevo;
    }
    else
    {
        filita->inicio = agregarFinal(filita->inicio,nodoNuevo);
        filita->fin = nodoNuevo;
    }

}

factura verPrimero (lista_factura * lista)
{
    factura resp;

    if(lista)
    {
        resp = lista->dato;
    }
    else
    {
        resp = generica();
    }
    return resp;
}

factura generica ()
{
    factura aux;

    strcpy(aux.cliente,"xxxxxxxxxx");
    aux.id = -1;
    aux.despachado = -1;
    aux.numero_factura = -1;
    aux.validosPedidos = 0;
    aux.valor = 0;

    return aux;
}

lista_factura * borrarPrimero (lista_factura * lista)
{
    lista_factura * borrar = lista;

    if(lista!=NULL)
    {
        lista = lista->siguiente;
        if(lista!=NULL)
        {
            lista = lista->anterior = NULL;
        }
        free(borrar);
    }
    return lista;
}

void extraer (fila * filita)
{
    if(filita->inicio!=NULL)
    {
        while(filita->inicio->dato.despachado==1 && filita->inicio!=NULL)
        {
            filita->inicio=filita->inicio->siguiente;
        }
        if(filita->inicio!=NULL)
        {
            mostrarUnaFactura(filita->inicio);
            system("pause");
            filita->inicio->dato.despachado = 1;
        }
    }
}

int comprobarFila (fila filita)
{
    int flag=0;
    while (filita.inicio!=NULL && flag==0)
    {
        if(filita.inicio->dato.despachado==0)
        {
            flag=1;
        }
        filita.inicio=filita.inicio->siguiente;
    }
    return flag;
}

