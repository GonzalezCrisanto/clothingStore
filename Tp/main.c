#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include "Fila.h"
#include "Clientes.h"
#include "Factura.h"
#include "Prendas.h"
#include "empleados.h"

///PROTOTIPADOS
void menuPrincipal(nodoPrenda ** arbolP, char archivoCliente[],char archivoFactura[], char archivoPrenda[], stcliente** ListaCliente, lista_factura* Factu);
void menuStock(nodoPrenda ** arbolP, char archPrenda[]);
void menuClientes(stcliente** lista, lista_factura* facturas, nodoPrenda ** arbolP, char archivoCliente[],char archFactura[]);
void menuFacturas (fila * filita, stcliente * cliente);
void logueo(nodoEmp ** lista);
void menuUsuario(nodoEmp ** lista);
void gotoxy(int X,int Y);

int main()
{
    //system("COLOR B0");
    //nombre archivos
    char archCliente[] = {"clientes.dat"};
    char archFactura[]= {"facturas.dat"};
    char archEmpleado[]= {"empleados.dat"};
    char archPrenda[]= {"prendas.dat"};




    // apertura de archivos
    nodoPrenda * arbolP;
    arbolP = inicArbolPrenda();
    stcliente* ListaCliente = inic_cliente();
    lista_factura* Factu = inicFactura();
    nodoEmp * listaEmp = inicListaEmp();
    //fila * filita;
    //inicFila(filita);

    archToListaEmp(archEmpleado,&listaEmp);
    cargaArbolPrenda(archPrenda,&arbolP);
    ListaCliente = pasarArchivoClienteToLista(ListaCliente,archCliente,archFactura);

    //logueo
    //menu
    logueo(&listaEmp);
    menuPrincipal(&arbolP, archCliente,archFactura,archPrenda, &ListaCliente, Factu);
    //cierre de archivos



    arboltoArchivoPrenda(arbolP,archPrenda);

    pasarListaToArchivo(archCliente,archFactura,ListaCliente);
    listaEmpToarch(archEmpleado,listaEmp);


    return 0;
}

void logueo(nodoEmp ** lista)
{
    datoEmpleado aux;
    int flag;
    do
    {
        printf("\nIngrese el usuario: ");
        fflush(stdin);
        gets(aux.nomYApe);
        printf("Ingrese la contrasenia: ");
        fflush(stdin);
        gets(aux.contrasenia);
        if(strcmpi(aux.nomYApe, "admin") == 0 && strcmpi(aux.contrasenia,"admin")==0)
        {
            menuUsuario(lista);
        }
        flag = validaUsuario(aux,*lista);
        if(flag == 0)
        {
            printf("Contrasenia incorrecta\n");
            system("pause");
        }
        system("cls");
    }
    while(flag == 0);
}

void menuUsuario(nodoEmp ** lista)
{
    system("cls");
    int opc = -1;
    char aux[50];
    nodoEmp * nodoAux;

    while(opc != 0)
    {
        printf("---- Bienvenido al menu de usuario  ----\n\n\n");
        printf("1- Cargar usuario\n"); // 1- carga cliente 2- dar de baja 3- ver cliente (ver sus facturas / crear factuas) 4- ver  lista client
        printf("2- Mostrar usuarios\n");
        printf("3- Borrar usuario\n");
        printf("4- Mostrar un usuario\n");
        printf("5- Modificar un usuario\n"); //v
        printf("0- Salir\n");
        do
        {
            scanf("%d",&opc);
        }
        while(opc < 0 || opc > 5);

        system("cls");
        switch(opc)
        {
        case 1:

            cargaManualEmp(lista);
            listaEmpToarch("empleados.dat",*lista);
            break;
        case 2:
            mostrarListaEmpleados(*lista);
            break;
        case 3:
            printf("Ingrese el mail del usuario: ");
            fflush(stdin);
            gets(aux);
            *lista = eliminarEmp(*lista,aux);
            listaEmpToarch("empleados.dat",*lista);
            break;
        case 4:
            printf("Ingrese el mail del usuario: ");
            fflush(stdin);
            gets(aux);
            nodoAux = buscaEmp(*lista,aux);
            if(nodoAux != NULL)
            {
                mostrarUnEmpleado(nodoAux->dato);
            }
            else
            {
                printf("ERROR USUARIO NO ENCONTRADO\n");
            }
            break;
        case 5:
            printf("Ingrese el mail del usuario: ");
            fflush(stdin);
            gets(aux);
            nodoAux = buscaEmp(*lista,aux);
            if(nodoAux != NULL)
            {
                nodoAux->dato = modificarEmp(nodoAux->dato,*lista);
                listaEmpToarch("empleados.dat",*lista);
                printf("Usuario modificado correctamente\n");
            }
            else
            {
                printf("ERROR USUARIO NO ENCONTRADO\n");
            }
            break;

        case 0:
            break;
        }
        system("pause");
        system("cls");
    }

}

void menuPrincipal(nodoPrenda ** arbolP, char archivoCliente[],char archivoFactura[], char archivoPrenda[],stcliente** ListaCliente, lista_factura* Factu)
{
    int opc = -1, id;
    stcliente * aux;
    fila  filita;
    inicFila(&filita);

    while(opc != 0)
    {
        gotoxy(40, 1);
        printf("---- Bienvenido  ----\n\n\n");
        printf("Ingrese a que menu quieres acceder: \n\n");
        printf("1- Menu clientes\n"); // 1- carga cliente 2- dar de baja 3- ver cliente (ver sus facturas / crear factuas) 4- ver  lista client
        printf("2- Menu stock\n");
        printf("3- Despacho de mercaderia\n"); //v
        printf("0- Salir\n");
        do
        {
            scanf("%d",&opc);
        }
        while(opc < 0 || opc > 3);


        switch(opc)
        {
        case 1:

            menuClientes(ListaCliente, Factu,arbolP,archivoCliente,archivoFactura);

            break;
        case 2:
            system("cls");
            menuStock(arbolP,archivoPrenda);
            break;
        case 3:
            printf("\nIngrese la id del cliente para despachar sus facturas: ");
            scanf("%d", &id);
            aux=busquedaCliente((*ListaCliente),id);
            if(aux!=NULL && aux->listaFactura!=NULL && aux->dato.alta!=0)
            {
                menuFacturas(&filita,aux);
            }
            if(aux==NULL)
            {
                printf("\033[0;31m");
                printf("\nNO SE ENCONTRO EL CLIENTE\n");
                printf("\033[0m");
            }
            if(aux->listaFactura == NULL)
            {
                printf("\033[0;31m");
                printf("\nEL CLIENTE NO TIENE FACTURAS\n");
                printf("\033[0m");
            }
            if(aux->dato.alta==0)
            {
                printf("\033[0;31m");
                printf("\nEL CLIENTE ESTA DE BAJA\n");
                printf("\033[0m");
            }

            break;
        case 0:
            break;
        }
        system("pause");
        system("cls");
    }
}

void menuStock(nodoPrenda ** arbolP, char archPrenda[])
{
    int opc = -1;
    prenda aux;
    int codigoPrenda,cantEliminar;
    nodoPrenda * buscador;
    while(opc != 0)
    {
        printf("---- Menu Stock ----\n\n\n");
        printf("1- Mostrar Stock\n");
        printf("2- Cargar Stock\n");
        printf("3- Eliminar Stock\n");
        printf("4- Buscar Stock\n");
        printf("0- Salir\n");
        do
        {
            scanf("%d",&opc);
        }
        while(opc < 0 || opc > 4);
        switch(opc)
        {
        case 1:
            rMostrarArbolPrenda(*arbolP);

            break;
        case 2:
            system("cls");
            aux = cargarPrenda();
            (*arbolP) = cargaNodoPrenda(*arbolP,creaNodoPrenda(aux));
            break;
        case 3:
            printf("\nIngrese el codigo de la prenda que desea eliminar: ");
            scanf("%i",&codigoPrenda);
            buscador=buscarPrenda((*arbolP),codigoPrenda);
            if (!buscador)
            {
                printf("\033[0;31m");
                printf("\nNo existe un producto con ese codigo");
                printf("\033[0m");
                system("pause");
            }
            else
            {
                mostrarPrenda(buscador->producto);
                printf("\nIngrese la cantidad de stock de la prenda que desea eliminar: ");
                scanf("%i",&cantEliminar);
                while ((cantEliminar<0) || (cantEliminar> (*arbolP)->producto.datos.cantidadCajas))
                {
                    printf("\033[0;31m");
                    printf("\nCantidad invalida");
                    printf("\033[0m");
                    printf("\nIngrese la cantidad de stock de la prenda que desea eliminar: ");
                    scanf("%i",&cantEliminar);
                }
                (*arbolP)=eliminarStock(*arbolP,codigoPrenda,cantEliminar);
            }
            break;
        case 4:
            printf("\nIngrese el codigo de la prenda que desea buscar: ");
            scanf("%i",&codigoPrenda);
            buscador=buscarPrenda((*arbolP),codigoPrenda);
            if (!buscador)
            {
                printf("\033[0;31m");
                printf("\nNo existe un producto con ese codigo");
                printf("\033[0m");
                printf("\nIngrese el codigo de la prenda que desea buscar: ");
                scanf("%i",&codigoPrenda);
                buscador=buscarPrenda((*arbolP),codigoPrenda);
            }
            buscador=buscarPrenda((*arbolP),codigoPrenda);
            mostrarPrenda(buscador->producto);
            printf("\n");
            break;
        case 0:
            break;
        }
        system("pause");
        system("cls");

    }
    system("cls");
}


void menuClientes(stcliente** lista, lista_factura* facturas, nodoPrenda ** arbolP, char archivoCliente[],char archivoFactura[])
{
    int opcion,id;
    char resp;
    stcliente * aux;

    do
    {

        printf("\nIngrese la opcion que desea realizar");
        printf("\n1- Cargar clientes.");
        printf("\n2- Cambiar estado cliente (alta/baja)");
        printf("\n3- Hacer una factura");
        printf("\n4- Mostrar todos los clientes");
        printf("\n5- Mostrar un cliente");
        printf("\n6- Modificar cliente");
        printf("\n0- Salir\n");
        do
        {
            scanf("%d",&opcion);
        }
        while(opcion < 0 || opcion > 6);
        switch(opcion)
        {

        case 1:
            (*lista) = cargar_VariosCliente((*lista));

            printf("\nSu cliente a sido cargado");
            pasarListaToArchivo(archivoCliente,archivoFactura,(*lista));

            break;
        case 2:
            printf("\nIngrese la id del cliente que quiera cambiar su estado: ");
            scanf("%d", &id);
            aux=busquedaCliente((*lista),id);
            if (!aux)
            {
                printf("\033[0;31m");
                printf("\nNo existe un usuario con ese id");
                printf("\033[0m");
            }
            else
            {
                mostrar_un_cliente(aux->dato);
                mostrarEstado(aux);
                printf("\nEsta seguro que desea cambiar el estado de este cliente (s/n): ");
                fflush(stdin);
                scanf("%c",&resp);

                if(resp=='s')
                {
                    dar_baja(aux);
                }
            }

            break;
        case 3:
            printf("\nIngrese la id del cliente para facturar\n");
            scanf("%d", &id);
            aux=busquedaCliente((*lista),id);
            if (!aux)
            {
                printf("\033[0;31m");
                printf("\nNo existe un usuario con ese id");
                printf("\033[0m");
            }
            else
            {
                hacer_pedido(aux,(*arbolP));
            }

            break;

        case 4:
            mostrar_lista_clientes(*lista);
            break;
        case 5:

            printf("\nIngrese la id del cliente que desea ver\n");
            scanf("%d", &opcion);
            buscar_uncliente_mostrar(*lista, opcion);
            break;
        case 6:
            printf("\nIngrese la id del cliente que quiere modificar: ");
            scanf("%d", &id);
            aux=busquedaCliente(*lista,id);
            if (aux!=NULL)
            {
                aux->dato=modificarCliente(*lista,aux->dato);
                mostrar_un_cliente(aux->dato);
                pasarListaToArchivo(archivoCliente,archivoFactura,(*lista));
            }
            break;
        case 0:
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion !=0);
    system("cls");
}

void menuFacturas (fila * filita, stcliente * cliente)
{

    int opcion;

    listatoFila(filita,cliente->listaFactura);
    do
    {

        printf("\nIngrese la opcion que desea realizar");
        printf("\n1- Mostrar facturas");
        printf("\n2- Despachar facturas");
        printf("\n0- Salir\n");
        do
        {
            scanf("%d",&opcion);
        }
        while(opcion < 0 || opcion > 2);
        switch(opcion)
        {
        case 1:
            mostrarListaFactura(cliente->listaFactura);

            break;
        case 2:
            if(comprobarFila(*filita))
            {
                extraer(filita);
                mostrarListaFactura(cliente->listaFactura);
            }
            else
            {
                printf("\nYa se despacharon todos los pedidos de este cliente\n");
            }
            break;
        }
        system("pause");
        system("cls");
    }
    while (opcion!=0);
    system("pause");
    system("cls");
}


void gotoxy(int X,int Y)  /// Cambia las coordenadas del cursor
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=X;
    dwPos.Y=Y;
    SetConsoleCursorPosition(hcon,dwPos);
}

