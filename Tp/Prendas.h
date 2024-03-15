#ifndef PRENDAS_H_INCLUDED
#define PRENDAS_H_INCLUDED

typedef struct
{
    char color[20];
    char marca[20];
    char nombrePrend[20];
    char talle [3];
    int cantidadCajas;
    int codigo;
}descripcion;

typedef struct{
    descripcion datos;
    float valor;
}prenda;

typedef struct nodoPrenda{
    prenda producto;
    struct nodoPrenda* der;
    struct nodoPrenda* izq;
}nodoPrenda;


prenda cargarPrenda();
void mostrarPrenda (prenda aux);
void rMostrarArbolPrenda(nodoPrenda * arbol);
nodoPrenda* inicArbolPrenda();
nodoPrenda* creaNodoPrenda(prenda dato);
nodoPrenda* cargaNodoPrenda(nodoPrenda* arbol, nodoPrenda* nodoN);
void cargaArbolPrenda(char nombreArch[], nodoPrenda** arbol);
void arboltoArchivoPrenda (nodoPrenda * arbol, char nombre[]);
void recorreArbolPrenda(FILE* buf,nodoPrenda * arbol);
nodoPrenda * borrarPrenda (nodoPrenda * arbol, int codigoAborrar);
nodoPrenda * BMDP(nodoPrenda * arbol);
nodoPrenda * BMIP(nodoPrenda * arbol);
prenda cargarMarcaPrenda (prenda dato);
descripcion menuDC (descripcion dato,float * valor);
descripcion menuReef (descripcion dato,float * valor);
descripcion menuRipCurl (descripcion dato,float * valor);
descripcion menuColorPrendas (descripcion dato);
descripcion menuTallePrendas (descripcion dato);
nodoPrenda * eliminarStock(nodoPrenda * arbol, int codigoAeliminar, int cantEliminar);
nodoPrenda * buscarPrenda (nodoPrenda * arbol,int codigoPrenda);


#endif // PRENDAS_H_INCLUDED
#ifndef PRENDAS_H_INCLUDED
#define PRENDAS_H_INCLUDED

typedef struct
{
    char color[20];
    char marca[20];
    char nombrePrend[20];
    char talle [3];
    int cantidadCajas;
    int codigo;
}descripcion;

typedef struct{
    descripcion datos;
    float valor;
}prenda;

typedef struct nodoPrenda{
    prenda producto;
    struct nodoPrenda* der;
    struct nodoPrenda* izq;
}nodoPrenda;


prenda cargarPrenda();
void mostrarPrenda (prenda aux);
void rMostrarArbolPrenda(nodoPrenda * arbol);
nodoPrenda* inicArbolPrenda();
nodoPrenda* creaNodoPrenda(prenda dato);
nodoPrenda* cargaNodoPrenda(nodoPrenda* arbol, nodoPrenda* nodoN);
void cargaArbolPrenda(char nombreArch[], nodoPrenda** arbol);
nodoPrenda * borrarPrenda (nodoPrenda * arbol, int codigoAborrar);
nodoPrenda * BMDP(nodoPrenda * arbol);
nodoPrenda * BMIP(nodoPrenda * arbol);
prenda cargarMarcaPrenda (prenda dato);
descripcion menuDC (descripcion dato,float * valor);
descripcion menuReef (descripcion dato,float * valor);
descripcion menuRipCurl (descripcion dato,float * valor);
descripcion menuColorPrendas (descripcion dato);
descripcion menuTallePrendas (descripcion dato);


#endif // PRENDAS_H_INCLUDED
