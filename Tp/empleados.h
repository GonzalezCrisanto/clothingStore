#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}fecha;

typedef struct{
    char nomYApe[50];
    char mail[50];
    char contrasenia[20];
    fecha nacimiento;
    fecha ingreso;
}datoEmpleado;

typedef struct nodoEmp{
    datoEmpleado dato;
    struct nodoEmp * sig;
}nodoEmp;


fecha fechaActual();
datoEmpleado creaUnEmpleado();
nodoEmp * inicListaEmp();
nodoEmp * creaNodoEmp(datoEmpleado aux);
nodoEmp * cargarEmpPpio(nodoEmp * lista, nodoEmp * nodoN);
void archToListaEmp(char nombreArch[], nodoEmp ** lista);
void listaEmpToarch(char nombreArch[], nodoEmp * lista);
int validaUsuario(datoEmpleado aBuscar, nodoEmp * lista);
int validaEmail(nodoEmp * lista,char email[]);
int validaContra(char contrasenia[]);
int validaFecha(fecha dato);
nodoEmp * buscaEmp(nodoEmp * lista, char nombreYape[50]);
nodoEmp * eliminarEmp(nodoEmp * lista, char nombreYape[50]);
datoEmpleado modificarEmp(datoEmpleado aux, nodoEmp * lista);
void cargaManualEmp(nodoEmp ** lista);
void mostrarListaEmpleados(nodoEmp * lista);
void mostrarUnEmpleado(datoEmpleado aux);



#endif // EMPLEADOS_H_INCLUDED

