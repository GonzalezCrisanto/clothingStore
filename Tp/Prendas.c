#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Prendas.h"


prenda cargarPrenda()
{
    prenda aux;
    aux.valor = 0;
    aux.datos.codigo = 0;
    aux = cargarMarcaPrenda(aux);

    return aux;
}
prenda cargarMarcaPrenda (prenda dato)
{
    system("cls");
    int opcion = 0;
    printf("\nIngrese el numero de la marca que desea comprar");
    printf("\n1.DC");
    printf("\n2.RipCurl");
    printf("\n3.Reef");
    printf("\nOpcion: ");
    do
    {

        if(opcion < 1 || opcion >3)
        {
            printf("\nIngrese una opcion valida\n");
            scanf("%i",&opcion);
        }
    }
    while(opcion < 1 || opcion >3);

    switch(opcion)
    {
    case 1:
        strcpy(dato.datos.marca,"DC");
        dato.datos = menuDC(dato.datos,&dato.valor);
        break;
    case 2:
        strcpy(dato.datos.marca,"RipCurl");
        dato.datos = menuRipCurl(dato.datos,&dato.valor);
        break;
    case 3:
        strcpy(dato.datos.marca,"Reef");
        dato.datos = menuReef(dato.datos,&dato.valor);
        break;
    }

    dato.datos.codigo += opcion * (1000);

    return dato;
}

descripcion menuDC (descripcion dato,float * valor)
{
    system("cls");
    int opcion = 0;
    printf("\nIngrese el numero de la prenda que quiera agregar: ");
    printf("\n1.REMERA ($35000 VALOR CAJA)");
    printf("\n2.BUZO ($50000 VALOR CAJA)");
    printf("\n3.PANTALON ($60000 VALOR CAJA)");
    printf("\n4.MEDIAS ($15000 VALOR CAJA)");
    printf("\nOpcion: ");
    do
    {

        if(opcion < 1 || opcion >4)
        {
            printf("\nIngrese una opcion valida\n");
            scanf("%i",&opcion);
        }
    }
    while(opcion < 1 || opcion >4);

    printf("\nIngrese la cantidad de cajas de la prenda seleccionada que desea adquirir: ");
    scanf("%i",&dato.cantidadCajas);
    while (dato.cantidadCajas<0 || dato.cantidadCajas > 99999)
    {
        printf("\033[0;31m");
        printf("\nCantidad invalida");
        printf("\033[0m");
        printf("\nIngrese la cantidad de cajas de la prenda seleccionada que desea adquirir: ");
        scanf("%i",&dato.cantidadCajas);
    }

    switch(opcion)
    {
    case 1:

        strcpy(dato.nombrePrend,"REMERA");

        (*valor) += 35000 * (dato.cantidadCajas);

        break;
    case 2:

        strcpy(dato.nombrePrend,"BUZO");

        (*valor) += 50000 * (dato.cantidadCajas);

        break;
    case 3:

        strcpy(dato.nombrePrend,"PANTALON");

        (*valor) += 60000 * (dato.cantidadCajas);

        break;
    case 4:

        strcpy(dato.nombrePrend,"MEDIAS");

        (*valor) += 15000 * (dato.cantidadCajas);

        break;
    }

    dato = menuColorPrendas(dato);
    dato = menuTallePrendas (dato);
    dato.codigo += opcion * (100);

    return dato;
}

descripcion menuColorPrendas (descripcion dato)
{
    int opcion = 0;
    system("cls");
    printf("\nIngrese el color de la prenda: ");
    printf("\n1.AZUL");
    printf("\n2.NEGRO");
    printf("\n3.ROJO");
    printf("\n4.BLANCO");
    printf("\nOpcion: ");
    do
    {

        if(opcion < 1 || opcion >4)
        {
            printf("\nIngrese una opcion valida\n");
            scanf("%i",&opcion);
        }
    }
    while(opcion < 1 || opcion >4);

    switch(opcion)
    {
    case 1:

        strcpy(dato.color,"AZUL");

        break;
    case 2:

        strcpy(dato.color,"NEGRO");

        break;
    case 3:

        strcpy(dato.color,"ROJO");

        break;

    case 4:

        strcpy(dato.color,"BLANCO");

        break;
    }


    dato.codigo += opcion * 10;

    return dato;
}

descripcion menuTallePrendas (descripcion dato)
{
    int opcion = 0;

    system("cls");
    printf("\nIngrese el talle de la prenda: ");
    printf("\n1.XS");
    printf("\n2.S");
    printf("\n3.M");
    printf("\n4.L");
    printf("\n5.XL");
    printf("\n6.XXL");
    printf("\nOpcion: ");
    do
    {
        scanf("%i",&opcion);
        if(opcion < 1 || opcion >6)
        {
            printf("\nIngrese una opcion valida\n");
        }
    }
    while(opcion < 1 || opcion >6);

    switch(opcion)
    {
    case 1:

        strcpy(dato.talle,"XS");

        break;
    case 2:

        strcpy(dato.talle,"S");

        break;
    case 3:

        strcpy(dato.talle,"M");

        break;

    case 4:

        strcpy(dato.talle,"L");

        break;
    case 5:

        strcpy(dato.talle,"XL");

        break;
    case 6:

        strcpy(dato.talle,"XXL");

        break;

    }

    dato.codigo += opcion;

    return dato;
}

descripcion menuReef (descripcion dato,float * valor)
{
    int opcion = 0;

    system("cls");
    printf("\nIngrese el numero de la prenda que quiera agregar: ");
    printf("\n1.REMERA ($40000 VALOR CAJA)");
    printf("\n2.BUZO ($60000 VALOR CAJA)");
    printf("\n3.PANTALON ($55000 VALOR CAJA)");
    printf("\n4.MEDIAS ($18000 VALOR CAJA)");
    printf("\nOpcion: ");
    scanf("%i",&opcion);

    printf("\nIngrese la cantidad de cajas de la prenda seleccionada que desea adquirir: ");
    scanf("%i",&dato.cantidadCajas);
    while (dato.cantidadCajas<0 || dato.cantidadCajas > 99999)
    {
        printf("\nCantidad invalida");
        printf("\nIngrese la cantidad de cajas de la prenda seleccionada que desea adquirir: ");
        scanf("%i",&dato.cantidadCajas);
    }

    do
    {

        if(opcion < 1 || opcion >4)
        {
            printf("\nIngrese una opcion valida\n");
            scanf("%i",&opcion);
        }
    }
    while(opcion < 1 || opcion >4);

    switch(opcion)
    {
    case 1:

        strcpy(dato.nombrePrend,"REMERA");

        (*valor) += 40000 * (dato.cantidadCajas);

        break;
    case 2:

        strcpy(dato.nombrePrend,"BUZO");

        (*valor) += 60000 * (dato.cantidadCajas);

        break;
    case 3:

        strcpy(dato.nombrePrend,"PANTALON");

        (*valor) += 55000 * (dato.cantidadCajas);

        break;
    case 4:

        strcpy(dato.nombrePrend,"MEDIAS");

        (*valor) += 18000 * (dato.cantidadCajas);

        break;
    }

    dato = menuColorPrendas(dato);

    dato = menuTallePrendas (dato);
    dato.codigo += opcion * (100);

    return dato;
}

descripcion menuRipCurl (descripcion dato,float * valor)
{
    int opcion = 0;
    system("cls");
    printf("\nIngrese el numero de la prenda que quiera agregar: ");
    printf("\n1.REMERA ($30000 VALOR CAJA)");
    printf("\n2.BUZO ($450000 VALOR CAJA)");
    printf("\n3.PANTALON ($65000 VALOR CAJA)");
    printf("\n4.MEDIAS ($14000 VALOR CAJA)");
    printf("\nOpcion: ");
    do
    {

        if(opcion < 1 || opcion >4)
        {
            printf("\nIngrese una opcion valida\n");
            scanf("%i",&opcion);
        }
    }
    while(opcion < 1 || opcion >4);

    printf("\nIngrese la cantidad de cajas de la prenda seleccionada que desea adquirir: ");
    scanf("%i",&dato.cantidadCajas);
    while (dato.cantidadCajas<0 || dato.cantidadCajas > 99999)
    {
        printf("\nCantidad invalida");
        printf("\nIngrese la cantidad de cajas de la prenda seleccionada que desea adquirir: ");
        scanf("%i",&dato.cantidadCajas);
    }

    switch(opcion)
    {
    case 1:

        strcpy(dato.nombrePrend,"REMERA");

        (*valor) += 30000 * (dato.cantidadCajas);

        break;
    case 2:

        strcpy(dato.nombrePrend,"BUZO");

        (*valor) += 45000 * (dato.cantidadCajas);

        break;
    case 3:

        strcpy(dato.nombrePrend,"PANTALON");

        (*valor) += 65000 * (dato.cantidadCajas);

        break;
    case 4:

        strcpy(dato.nombrePrend,"MEDIAS");

        (*valor) += 14000 * (dato.cantidadCajas);

        break;
    }

    dato = menuColorPrendas(dato);

    dato = menuTallePrendas (dato);

    dato.codigo += opcion * (100);

    return dato;
}


void mostrarPrenda (prenda aux)
{
    printf("\nCodigo de la prenda...............: %i",aux.datos.codigo);
    printf("\nNombre de la prenda...............: %s",aux.datos.nombrePrend);
    printf("\nMarca de la prenda................: %s",aux.datos.marca);
    printf("\nColor de la prenda................: %s",aux.datos.color);
    printf("\nTalle de la prenda................: %s",aux.datos.talle);
    printf("\nCantidad de cajas de la prenda: %i",aux.datos.cantidadCajas);
    printf("\nValor por caja de la prenda: $%.2f", aux.valor/aux.datos.cantidadCajas);
    printf("\nValor en total: $%.2f",aux.valor);

}

void rMostrarArbolPrenda(nodoPrenda * arbol)
{
    if(arbol!=NULL)
    {
        rMostrarArbolPrenda(arbol->izq);
        printf("\n-----------------------------------");
        mostrarPrenda(arbol->producto);
        printf("\n-----------------------------------\n");
        rMostrarArbolPrenda(arbol->der);
    }
}

nodoPrenda* inicArbolPrenda()
{
    return NULL;
}

nodoPrenda* creaNodoPrenda(prenda dato)
{
    nodoPrenda* nodoN = (nodoPrenda*) malloc(sizeof(nodoPrenda));
    nodoN->der = NULL;
    nodoN->izq = NULL;
    nodoN->producto = dato;
    return nodoN;
}

nodoPrenda* cargaNodoPrenda(nodoPrenda* arbol, nodoPrenda* nodoN)
{
    if(arbol != NULL)
    {
        if(arbol->producto.datos.codigo != nodoN->producto.datos.codigo)
        {
            if(arbol->producto.datos.codigo > nodoN->producto.datos.codigo)
            {
                arbol->izq = cargaNodoPrenda(arbol->izq,nodoN);
            }
            else
            {
                arbol->der = cargaNodoPrenda(arbol->der,nodoN);
            }
        }
        else
        {
            if(arbol->producto.datos.cantidadCajas + nodoN->producto.datos.cantidadCajas > 99999){
                arbol->producto.valor = (float)(arbol->producto.valor / arbol->producto.datos.cantidadCajas) * 99999;
                arbol->producto.datos.cantidadCajas = 99999;
                printf("\nSe excedio el limite de cantidad de cajas a cargar");
            }else{
                arbol->producto.valor += nodoN->producto.valor;
                arbol->producto.datos.cantidadCajas += nodoN->producto.datos.cantidadCajas;
            }
        }
    }
    else
    {
        arbol = nodoN;
    }
    return arbol;
}

void cargaArbolPrenda(char nombreArch[], nodoPrenda** arbol)
{
    FILE* archP = fopen(nombreArch,"rb");
    prenda auxP;
    if(archP)
    {
        while(fread(&auxP,sizeof(prenda),1,archP)>0)
        {
            (*arbol) = cargaNodoPrenda((*arbol),creaNodoPrenda(auxP));
        }
        fclose(archP);
    }
    else
    {
        printf("ERROR 404 ARCH NOT FOUND");
    }
}

void arboltoArchivoPrenda (nodoPrenda * arbol, char nombre[])
{
    FILE * buf = fopen(nombre,"wb");
    if (buf)
    {
        recorreArbolPrenda(buf,arbol);
        fclose(buf);
    }
    else
    {
        printf("ERROR 404 ARCH NOT FOUND\n");
    }
}

void recorreArbolPrenda(FILE* buf,nodoPrenda * arbol)
{
    prenda aux;
    if(arbol!=NULL)
    {
        recorreArbolPrenda(buf,arbol->izq);
        aux=arbol->producto;
        fwrite(&aux,sizeof(prenda),1,buf);
        recorreArbolPrenda(buf,arbol->der);
    }
}

nodoPrenda * borrarPrenda (nodoPrenda * arbol, int codigoAborrar)
{
    if(arbol != NULL)
    {
        if(arbol->producto.datos.codigo == codigoAborrar)
        {
            if(arbol->izq != NULL)
            {
                nodoPrenda * menDer = BMDP(arbol->izq);
                arbol->producto = menDer->producto;
                arbol->izq = borrarPrenda(arbol->izq,menDer->producto.datos.codigo);
            }
            else if(arbol->der != NULL)
            {
                nodoPrenda* menIzq = BMIP(arbol->der);
                arbol->producto = menIzq->producto;
                arbol->der = borrarPrenda(arbol->der,menIzq->producto.datos.codigo);
            }
            else
            {
                free(arbol);
                arbol = NULL;
            }
        }
        else
        {
            if(arbol->producto.datos.codigo > codigoAborrar)
            {
                arbol->izq = borrarPrenda(arbol->izq,codigoAborrar);
            }
            else
            {
                arbol->der = borrarPrenda(arbol->der,codigoAborrar);
            }
        }
    }
    return arbol;
}

nodoPrenda * BMDP(nodoPrenda * arbol)
{
    if(arbol->der != NULL)
    {
        arbol = BMDP(arbol->der);
    }
    return arbol;
}

nodoPrenda * BMIP(nodoPrenda * arbol)
{
    if(arbol->izq != NULL)
    {
        arbol = BMDP(arbol->izq);
    }
    return arbol;
}

nodoPrenda * eliminarStock(nodoPrenda * arbol, int codigoAeliminar, int cantEliminar)
{
    nodoPrenda * aux=buscarPrenda(arbol,codigoAeliminar);
    float precioIndi=(aux->producto.valor)/(aux->producto.datos.cantidadCajas);

    aux->producto.datos.cantidadCajas=aux->producto.datos.cantidadCajas-cantEliminar;
    aux->producto.valor= aux->producto.valor - precioIndi * cantEliminar ;

    if (aux->producto.datos.cantidadCajas==0)
    {
        arbol=borrarPrenda(arbol,codigoAeliminar);
    }


    return arbol;
}

nodoPrenda * buscarPrenda (nodoPrenda * arbol,int codigoPrenda)
{
    nodoPrenda* flag=NULL;

    if(arbol!=NULL && flag ==NULL)
    {
        if (arbol->producto.datos.codigo==codigoPrenda)
        {
            flag=arbol;
        }
        else
        {
            if (arbol->producto.datos.codigo>codigoPrenda)
            {
                flag=buscarPrenda(arbol->izq,codigoPrenda);
            }
            else
            {
                flag=buscarPrenda(arbol->der,codigoPrenda);
            }
        }
    }
    return flag;
}
