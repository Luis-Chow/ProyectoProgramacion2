#include "../controller/ClientesController.cpp"
#include "../controller/VehiculosController.cpp"
#include "../controller/RepuestosController.cpp"
#include "../model/Usuario/Empleado.h"

void Empleado::clientes_empleados(){
    Cliente c;
    int opcion, opciong;
    cout<<"CLIENTES"<<endl;
    cout<<"Que accion desea realizar? 1.Vender | 2.Consultar"<<endl; cin>>opcion;
    if(opcion==1){
        cout<<"El cliente esta registrado? 1.Si | 2.No"<<endl; cin>>opciong;
        if(opciong==1){
            c.actualizar();
        } else if(opciong==2){
            c.insercion();
        } else {
            cout<<"Opcion no valida"<<endl;
        }
    } else if(opcion==2){
        c.consulta();
    } else {
        cout<<"Opcion no valida"<<endl;
    }
}

void Empleado::vehiculos_empleados(){
    Vehiculo v;
    int opcion;
    cout<<"VEHICULOS"<<endl;
    cout<<"Que accion desea realizar? 1. Consultar | 2.Actualizar (Realizar una venta) " <<endl; cin>>opcion;
    if (opcion==1){
        v.consulta();
    } else if (opcion==2){
        v.actualizar();
    } else {
        cout<<"Opcion no valida"<<endl;
    }
}

void Empleado::repuestos_empleados(){
    Repuesto r;
    int opcion;
    cout<<"REPUESTOS"<<endl;
    cout<<"Que accion desea realizar? 1. Consultar | 2.Actualizar (Realizar una venta) " <<endl; cin>>opcion;
    if (opcion==1){
        r.consulta();
    } else if (opcion==2){
        r.actualizar();
    } else {
        cout<<"Opcion no valida"<<endl;
    }
}