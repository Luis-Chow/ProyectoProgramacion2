#include "../controller/ClientesController.cpp"
#include "../controller/VehiculosController.cpp"
#include "../controller/RepuestosController.cpp"
#include "../model/Usuario/Usuario.h"

void Manager::clientes(){
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

void Manager::vehiculos(){
    Vehiculo v;
    int opcion;
    cout<<"VEHICULOS"<<endl;
    cout<<"Que accion desea realizar? 1. Consultar | 2.Actualizar " <<endl; cin>>opcion;
    if (opcion==1){
        v.consulta();
    } else if (opcion==2){
        v.actualizar();
    } else {
        cout<<"Opcion no valida"<<endl;
    }
}

void Manager::repuestos(){
    Repuesto r;
    int opcion;
    cout<<"REPUESTOS"<<endl;
    cout<<"Que accion desea realizar? 1. Consultar | 2.Actualizar " <<endl; cin>>opcion;
    if (opcion==1){
        r.consulta();
    } else if (opcion==2){
        r.actualizar();
    } else {
        cout<<"Opcion no valida"<<endl;
    }
}