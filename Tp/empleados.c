#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include "empleados.h"

fecha fechaActual(){
    fecha aux;
    time_t t = time(NULL);
    struct tm tiempoActual =  *localtime(&t);
    aux.anio = tiempoActual.tm_year + 1900;
    aux.mes = tiempoActual.tm_mon + 1;
    aux.dia = tiempoActual.tm_mday;
    return aux;
}

datoEmpleado creaUnEmpleado(nodoEmp * lista){
    datoEmpleado aux;
    int flag;
    aux.ingreso = fechaActual();
    printf("Ingrese el nombre y apellido del empleado: ");
    fflush(stdin);
    gets(aux.nomYApe);
    do{
        printf("Ingrese el mail del empleado............: ");
        fflush(stdin);
        gets(aux.mail);
        flag = validaEmail(lista,aux.mail);
        if(flag == 1){
            printf("Mail invalido, por favor ingrese otro\n");
        }
    }while(flag == 1);
    do{
        printf("Ingrese la contrasenia del empleado......: ");
        fflush(stdin);
        gets(aux.contrasenia);
        flag = validaContra(aux.contrasenia);
        if(flag == 1){
            printf("Contraseña invalida, por favor ingrese otra (minimo 4 caracteres)\n");
        }
    }while(flag == 1);
    printf("Ingrese la fecha de su nacimiento\n");
    do{
        printf("Dia: ");
        scanf("%d",&aux.nacimiento.dia);
        printf("Mes: ");
        scanf("%d",&aux.nacimiento.mes);
        printf("Anio: ");
        scanf("%d",&aux.nacimiento.anio);
        system("cls");
        flag = validaFecha(aux.nacimiento);
    if(flag == 1){
        printf("Fecha invalida, por favor ingrese otra\n");
    }
    }while(flag == 1);
    return aux;
}

nodoEmp * inicListaEmp(){
    return NULL;
}

nodoEmp * creaNodoEmp(datoEmpleado aux){
    nodoEmp * nodoN = (nodoEmp*) malloc(sizeof(nodoEmp));
    nodoN->sig = NULL;
    nodoN->dato = aux;
    return nodoN;
}

nodoEmp * cargarEmpPpio(nodoEmp * lista, nodoEmp * nodoN){
    if(lista!=NULL){
        nodoN->sig = lista;
    }
    lista = nodoN;
    return lista;
}

void archToListaEmp(char nombreArch[], nodoEmp ** lista){
    FILE * arch = fopen(nombreArch,"rb");
    datoEmpleado aux;
    if(arch){
        while(fread(&aux,sizeof(datoEmpleado),1,arch)>0){
            *lista = cargarEmpPpio(*lista,creaNodoEmp(aux));
        }
        fclose(arch);
    }
}

void cargaManualEmp(nodoEmp ** lista){
    datoEmpleado aux;
    aux = creaUnEmpleado(*lista);
    *lista  = cargarEmpPpio(*lista,creaNodoEmp(aux));
}

void listaEmpToarch(char nombreArch[], nodoEmp * lista){
    FILE * arch = fopen(nombreArch,"wb");
    datoEmpleado aux;
    if(arch){
        while(lista != NULL){
            aux = lista->dato;
            fwrite(&aux,sizeof(datoEmpleado),1,arch);
            lista = lista->sig;
        }
        fclose(arch);
    }
}

int validaUsuario(datoEmpleado aBuscar, nodoEmp * lista){
    int flag = 0;
    while(flag == 0 && lista != NULL){
        if(strcmp(lista->dato.nomYApe,aBuscar.nomYApe)== 0 && strcmp(lista->dato.contrasenia,aBuscar.contrasenia)== 0){
            flag = 1;
        }else{
            lista = lista->sig;
        }
    }
    return flag;
}


//Todas las validaciones Retornan 1 en caso de no ser valida la contrasenia. 0 en caso de ser valida.

int validaEmail(nodoEmp * lista,char email[])
{
    char * arr;
    char * punt;
    int flag=0;
    while(flag == 0 && lista!= NULL)
    {
        if(strcmp(lista->dato.mail,email)== 0)
        {
            flag = 1;
        }else{
            lista = lista->sig;
        }
    }
    if(lista==NULL)
    {
        arr = strstr(email,"@");
        punt = strstr(email,".");
        if(arr == NULL || punt == NULL){
            flag = 1;
        }
    }
    return flag;
}

int validaContra(char contrasenia[])
{
	int flag = 0;
	int tamCon = strlen(contrasenia);
	if(tamCon < 4){
        flag = 1;
	}
	return flag;
}

int validaFecha(fecha dato)
{
    int flag=0;
    fecha aux = fechaActual();
    if((aux.anio - dato.anio) < 18 || (aux.anio - dato.anio) > 150)
    {
        flag = 1;
    }else if(1 > dato.mes || dato.mes > 12){
        flag = 1;
    }else{
         switch ( dato.mes ){
            case  1 :
            case  3 :
            case  5 :
            case  7 :
            case  8 :
            case 10 :
            case 12 : if ( dato.dia < 1 || dato.dia > 31 ){
                            flag = 1;
                      }
                      break;

            case  4 :
            case  6 :
            case  9 :
            case 11 : if ( dato.dia < 1 || dato.dia > 30 ){
                        flag = 1;
                      }
                      break;
            case  2 : if( ((dato.anio % 4 == 0) && (dato.anio % 100 != 0)) || (dato.anio % 400 == 0) ){
                            if ( dato.dia < 1 || dato.dia > 29 ){
                                flag = 1;
                            }
                      }else
                          if ( dato.dia < 1 || dato.dia > 28 ){
                                flag = 1;
                          }
                      break;
         }
    }
    return flag;
}

void mostrarUnEmpleado(datoEmpleado aux){
    printf("Nombre y Apellido..: %s\n",aux.nomYApe);
    printf("Mail:..............: %s\n",aux.mail);
    printf("fecha de nacimiento: %d/%d/%d\n",aux.nacimiento.dia,aux.nacimiento.mes,aux.nacimiento.anio);
    printf("fecha de ingreso...: %d/%d/%d\n",aux.ingreso.dia,aux.ingreso.mes,aux.ingreso.anio);
}

void mostrarListaEmpleados(nodoEmp * lista){
    while(lista != NULL){
        mostrarUnEmpleado(lista->dato);
        printf("-------------------------------------\n");
        lista = lista->sig;
    }
}

nodoEmp * buscaEmp(nodoEmp * lista, char mail[50]){
    nodoEmp * aux = NULL;
    while(lista != NULL && aux == NULL){
            if(strcmp(lista->dato.mail,mail)==0){
                aux = lista;
            }else{
                lista = lista->sig;
            }
    }
    return aux;
}
nodoEmp * eliminarEmp(nodoEmp * lista, char mail[50]){
    if(lista != NULL){
        if(strcmp(lista->dato.mail,mail)==0){
            nodoEmp * aux = lista;
            lista = lista->sig;
            free(aux);
        }else{
            nodoEmp * seg = lista->sig;
            nodoEmp * ant = lista;
            while(seg != NULL && strcmp(seg->dato.mail,mail)!=0){
                ant = seg;
                seg = seg->sig;
            }
            if(seg != NULL){
                ant->sig = seg->sig;
                free(seg);
                printf("Usuario eliminado correctamente\n");
            }else{
                printf("ERROR USUARIO NO ENCONTRADO\n");
            }
        }
    }
    return lista;
}

datoEmpleado modificarEmp(datoEmpleado aux, nodoEmp * lista){
    int opc = -1;
    int flag = 0;

    while(opc != 0)
    {
        mostrarUnEmpleado(aux);
        printf("Ingrese el dato a modificar: \n\n");
        printf("1- Nombre y Apellido\n"); // 1- carga cliente 2- dar de baja 3- ver cliente (ver sus facturas / crear factuas) 4- ver  lista client
        printf("2- Mail\n");
        printf("3- Contraseña\n");
        printf("4- Fecha de Nacimiento\n");//v
        printf("0- Salir\n");
        do
        {
            scanf("%d",&opc);
        }
        while(opc < 0 || opc > 4);


        switch(opc)
        {
        case 1:
              printf("Ingrese el nuevo nombre y apellido del empleado: ");
              fflush(stdin);
              gets(aux.nomYApe);
            break;
        case 2:
            do{
            printf("Ingrese el nuevo mail del empleado............: ");
                fflush(stdin);
                gets(aux.mail);
                flag = validaEmail(lista,aux.mail);
                if(flag == 1){
                printf("Mail invalido, por favor ingrese otro\n");
                }
            }while(flag == 1);
            break;
        case 3:
             do{
                printf("Ingrese la nueva contrasenia del empleado......: ");
                fflush(stdin);
                gets(aux.contrasenia);
                flag = validaContra(aux.contrasenia);
                if(flag == 1){
                    printf("Contraseña invalida, por favor ingrese otra (minimo 4 caracteres)\n");
                }
            }while(flag == 1);
            break;
        case 4:
             printf("Ingrese la fecha de su nacimiento\n");
            do{
                printf("dia: ");
                scanf("%d",&aux.nacimiento.dia);
                printf("mes: ");
                scanf("%d",&aux.nacimiento.mes);
                printf("año: ");
                scanf("%d",&aux.nacimiento.anio);
                system("cls");
                flag = validaFecha(aux.nacimiento);
                if(flag == 1){
                    printf("Fecha invalida, por favor ingrese otra\n");
                }
            }while(flag == 1);
        case 0:
            break;
        }
        system("cls");
    }
    system("Pause");
    system("cls");
    return aux;
}
