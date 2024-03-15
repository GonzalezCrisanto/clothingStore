#include "Clientes.h"
#include "Factura.h"



stcliente* inic_cliente()
{
    return NULL;
}

datoCliente datos_cliente(int* cant, stcliente * lista)
{

    datoCliente cliente;

    cliente.alta = 1;

    printf("Ingrese el nombre de la empresa\n");
    fflush(stdin);
    gets(cliente.nombre);
    while (validaNombre(lista,cliente.nombre))
    {
        printf("Dicho nombre ya esta registrado\n");
        printf("Ingrese el nombre de la empresa\n");
        fflush(stdin);
        gets(cliente.nombre);
    }

    printf("Ingrese el su cuil del cliente\n");
    scanf("%d", &cliente.cuil);
    while (validaCuil(lista,cliente.cuil))
    {
        printf("Dicho cuil ya esta registrado\n");
        printf("Ingrese el su cuil del cliente\n");
        scanf("%d", &cliente.cuil);
    }

    printf("Ingrese el mail de contacto\n");
    fflush(stdin);
    gets(cliente.mail);
    while (validaEmailCliente(lista,cliente.mail))
    {
        printf("Dicho Mail ya esta registrado\n");
        printf("Ingrese el mail de contacto\n");
        fflush(stdin);
        gets(cliente.mail);
    }

    printf("Ingrese el saldo con el que cuenta\n");
    scanf("%f", &cliente.saldo);
    while (cliente.saldo<0)
    {
        printf("Cantidad de saldo ivalida\n");
        printf("Ingrese el saldo con el que cuenta\n");
        scanf("%f", &cliente.saldo);
    }

    cliente.id = (*cant++);

    return cliente;
}

stcliente* cargar_cliente(datoCliente dato)
{
    stcliente* nodoN= (stcliente*) malloc(sizeof(stcliente));
    nodoN->dato=dato;
    nodoN->listaFactura = inicFactura();
    nodoN->siguiente = NULL;


    return nodoN;
}


void mostrar_lista_clientes(stcliente* cliente)
{

    while(cliente!=NULL)
    {
        if(cliente->dato.alta==1)
        {
            mostrar_un_cliente(cliente->dato);

        }
        cliente = cliente->siguiente;
    }

}

void hacer_pedido(stcliente* cliente, nodoPrenda * arbolP)
{
    int cant = 0;
    factura dato;
    lista_factura* nuevoN;
    char resp;

    if(cliente->dato.alta!=0)
    {
        mostrar_un_cliente(cliente->dato);
        printf("\nQuiere facturar este cliente? (s/n): ");
        fflush(stdin);
        scanf("%c",&resp);
        while (resp!='s' && resp!='n')
        {
            printf("\nOpcion invalida");
            printf("\nQuiere facturar este cliente? (s/n): ");
            fflush(stdin);
            scanf("%c",&resp);
        }
        if (resp=='s')
        {

            printf("\nDesea ver las facturas de este cliente? (s/n): ");
            fflush(stdin);
            scanf("%c",&resp);
            while (resp!='s' && resp!='n')
            {
                printf("\nOpcion invalida");
                printf("\nDesea ver las facturas de este cliente? (s/n): ");
                fflush(stdin);
                scanf("%c",&resp);
            }
            if (resp=='s')
            {
                mostrarListaFactura(cliente->listaFactura);
            }
            system("pause");
            system("cls");

            cant = contar_camt_facturas(cliente->listaFactura);
            dato = cargarUnaFactura(&cant,arbolP,cliente);
            if(dato.valor>0)
            {
                nuevoN = crearFactura(dato);
                cliente->listaFactura = agregarFinal(cliente->listaFactura,nuevoN);

            }
            else
            {
                printf("\nNo se cargo ninguna factura");
            }
        }
    }
    else
    {
        printf("\nEste cliente esta dado de baja");
    }

}

void buscar_uncliente_mostrar(stcliente* lista, int id) //Mostrar Facturas de un cliente
{

    int flag = 0;
    while(lista!=NULL && flag == 0)
    {
        if(lista->dato.id == id)
        {
            flag=1;
            mostrar_un_cliente(lista->dato);
            mostrarListaFactura(lista->listaFactura);
            if(lista->dato.alta == 0)
            {
                printf("\033[0;31m");
                printf("\n------BAJA------\n");
                printf("\033[0m");
            }
            else
            {
                printf("\033[0;32m");
                printf("\n------ALTA------\n");
                printf("\033[0m");
            }
        }
        lista = lista->siguiente;
    }
}



void mostrar_un_cliente(datoCliente cliente)
{

    printf("\n------------------------------\n");
    printf("\nID: %d", cliente.id);
    printf("\nNombre: %s", cliente.nombre);
    printf("\nCuil: %d", cliente.cuil);
    printf("\nMail: %s", cliente.mail);
    printf("\nSaldo: %.2f", cliente.saldo);
    printf("\n------------------------------\n");

}
stcliente* cargar_lista_cliente(stcliente* lista, stcliente* nuevoN)
{
    if(lista ==NULL)
    {
        lista=nuevoN;
    }
    else
    {
        nuevoN->siguiente = lista;
        lista = nuevoN;
    }
    return lista;
}

int cant_cliente(stcliente* lista)
{

    int cant = 0;

    while(lista!=NULL)
    {
        lista = lista->siguiente;
        cant++;
    }

    return cant;
}

stcliente* cargar_VariosCliente(stcliente* lista)
{
    char control = 's';
    datoCliente cliente;
    stcliente* nuevocliente;
    int cant = cant_cliente(lista) + 1;

    do
    {
        cliente = datos_cliente(&cant,lista);
        nuevocliente = cargar_cliente(cliente);
        lista = cargar_lista_cliente(lista,nuevocliente);

        printf("\n");
        printf("Ingrese s si desea seguir cargando clientes\n");
        fflush(stdin);
        scanf("%c", &control);
        printf("\n");
        cant++;
    }
    while(control == 's');


    return lista;
}


void pasarListaToArchivo (char archCliente[],char archFactura[], stcliente* lista)
{
    FILE * buff = fopen(archCliente,"wb");
    FILE * buff2 = fopen(archFactura, "wb");
    datoCliente aux;

    if(buff && buff2)
    {

        while(lista!=NULL)
        {
            aux = lista->dato;
            pasarFacturaToArchivo(buff2,lista->listaFactura);
            fwrite(&aux,sizeof(datoCliente),1,buff);
            lista = lista->siguiente;
        }
        fclose(buff);
        fclose(buff2);
    }
    else
    {
        printf("ERROR 404 NOT FOUND");
    }
}


stcliente* pasarArchivoClienteToLista(stcliente * lista, char archCliente[], char archFactura[])
{
    FILE* archC = fopen(archCliente,"rb");
    FILE* archF = fopen(archFactura, "rb");
    datoCliente auxC;
    stcliente* aux;
    stcliente* nuevoN;
    if(archC)
    {
        while(fread(&auxC,sizeof(datoCliente),1,archC)>0)
        {
            nuevoN = cargar_cliente(auxC);
            lista = cargar_lista_cliente(lista, nuevoN);
        }


        aux = lista;
        while(aux!=NULL)
        {
            aux->listaFactura = pasarArchivoToFactura(archF,aux->listaFactura,aux->dato.nombre);
            aux = aux->siguiente;
        }
        fclose(archC);
        fclose(archF);
    }
    else
    {
        printf("ERROR 404 ARCH %s NOT FOUND\n",archCliente);
        system("pause");
        system("");
    }
    return lista;
}



stcliente * busquedaCliente (stcliente * lista, int id)
{

    while(lista !=NULL && lista->dato.id!=id)
    {
        lista = lista->siguiente;
    }
    return lista;
}


lista_factura* pasarArchivoToFactura (FILE* buff,lista_factura * lista, char nombreCliente[])
{

    lista_factura * nodoN;
    factura aux;

    fseek(buff,0,0);

    while(fread(&aux,sizeof(factura),1,buff)>0)
    {
        if(strcmpi(nombreCliente, aux.cliente)==0)
        {
            nodoN = crearFactura(aux);
            lista = agregarFinal(lista,nodoN);
        }

    }
    return lista;
}

void dar_baja(stcliente* cliente)
{
    if (cliente->dato.alta==0)
    {
        cliente->dato.alta=1;
    }
    else
    {
        cliente->dato.alta=0;
    }
}

int validaEmailCliente (stcliente * lista, char email[])
{
    char * arr;
    char * punt;
    int flag=0;
    while(flag == 0 && lista!= NULL)
    {
        if(strcmp(lista->dato.mail,email)== 0)
        {
            flag = 1;
        }
        else
        {
            lista = lista->siguiente;
        }
    }
    if(lista==NULL)
    {
        arr = strstr(email,"@");
        punt = strstr(email,".");
        if(arr == NULL || punt == NULL)
        {
            flag = 1;
        }
    }
    return flag;
}

int validaCuil (stcliente * lista, int cuil)
{
    int flag=0;

    if(lista!=NULL)
        while(flag == 0 && lista!= NULL)
        {
            if(lista->dato.cuil==cuil)
            {
                flag = 1;
            }
            else
            {
                lista = lista->siguiente;
            }
        }

    return flag;
}

datoCliente modificarCliente (stcliente * lista, datoCliente aux)
{
    int opc = -1;
    float saldoMas=0;
    while (opc!=0)
    {
        mostrar_un_cliente(aux);
        printf("ingrese el dato a modificar: \n\n");
        printf("1- Nombre y Apellido\n"); // 1- carga cliente 2- dar de baja 3- ver cliente (ver sus facturas / crear factuas) 4- ver  lista client
        printf("2- Mail\n");
        printf("3- Saldo\n");
        printf("0- Salir\n");
        do
        {
            scanf("%d",&opc);
        }
        while(opc < 0 || opc > 3);

        switch(opc)
        {
        case 1:
            printf("\nIngrese el nuevo nombre y apellido del empleado: ");
            fflush(stdin);
            gets(aux.nombre);
            if (validaNombre(lista,aux.nombre))
            {
                printf("\nDicho nombre ya esta registrado");
            }
            break;
        case 2:
            do
            {
                printf("\nIngrese el nuevo mail de cliente............: ");
                fflush(stdin);
                gets(aux.mail);
                if(validaEmailCliente(lista,aux.mail))
                {
                    printf("\nMail invalido, por favor ingrese otro");

                }
            }
            while(validaEmailCliente(lista,aux.mail));
            break;
        case 3:
            printf("\nSu saldo actual es: %.2f", aux.saldo);
            printf("\nIngrese la cantidad que quiere agregar o quitar: ");
            scanf("%f",&saldoMas);
            while (saldoMas*(-1)>aux.saldo)
            {
                printf("\nNumero invalido, por favor ingrese otro");
                printf("\nIngrese la cantidad que quiere agregar: ");
                scanf("%f",&saldoMas);
            }

            aux.saldo+=saldoMas;
            break;
        case 0:
            break;
        }
        system("cls");
    }
    system("Pause");
    system("cls");
    return aux;
}

factura cargarUnaFactura(int * cant, nodoPrenda * arbolP, stcliente * aux2)
{
    factura dato;

    prenda aux1;

    nodoPrenda* aux3;


    dato.validosPedidos = 0;
    int dimension = 50;
    char control = 's';
    int i = 0;
    dato.valor = 0;
    dato.id = aux2->dato.id;
    strcpy(dato.cliente,aux2->dato.nombre);
    dato.numero_factura = (*cant)+1;

    dato.despachado = 0;


    while(dato.validosPedidos<dimension && (control=='s'))
    {
        aux1=cargarPrenda();
        aux3=buscarPrenda(arbolP,aux1.datos.codigo);
        if (aux1.valor>aux2->dato.saldo)
        {
            printf("\nSALDO INSUFICIENTE");
        }
        if(aux3==NULL || aux3->producto.datos.cantidadCajas<aux1.datos.cantidadCajas)
        {
            printf("\nSTOCK INSUFICIENTE");
        }
        if(aux1.valor<=aux2->dato.saldo && aux3!=NULL && aux3->producto.datos.cantidadCajas>=aux1.datos.cantidadCajas)
        {
            eliminarStock(arbolP,aux1.datos.codigo,aux1.datos.cantidadCajas);
            dato.pedidos[dato.validosPedidos] = aux1;
            dato.validosPedidos++;
            aux2->dato.saldo -= aux1.valor;
            printf("\nSi desea seguir cargando pedidos ingrese s: ");
            fflush(stdin);
            scanf("%c",&control);
        }
        else
        {
            control='n';
        }

    }
    if(control=='s')
    {
        printf("\nSe alcanzo el limite de pedidos por factura");
    }

    while(i<dato.validosPedidos)
    {
        dato.valor += dato.pedidos[i].valor;
        i++;
    }

    return dato;
}

int validaNombre(stcliente * lista, char nombreEmpresa[])
{
    int flag=0;

    while(lista!=NULL && flag!= 1)
    {
        if(strcmpi(lista->dato.nombre,nombreEmpresa)==0)
        {
            flag=1;
        }
        else
        {
            lista=lista->siguiente;
        }
    }
    return flag;
}

void mostrarEstado (stcliente * nodoC)
{
    if(nodoC->dato.alta == 0)
    {
        printf("\n---------BAJA------------");
    }
    else
    {
        printf("\n---------ALTA------------");
    }
}
