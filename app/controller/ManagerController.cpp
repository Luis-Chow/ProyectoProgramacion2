#include "../controller/ClientesController.cpp"
#include "../controller/VehiculosController.cpp"
#include "../controller/RepuestosController.cpp"
#include "../model/Usuario/Usuario.h"

void Manager::clientes_manager(){
    Cliente c;
    int opcion;
    cout<<"CLIENTES"<<endl;
    cout<<"Que accion desea realizar? 1. Borrar | 2. Actualizar | 3. Insercion | 4. Consulta"<<endl; cin>>opcion;
    if (opcion==1){
        c.borrar();
    } else  if (opcion ==2){
        c.actualizar();
    } else if (opcion==3){
        c.insercion();
    } else if (opcion==4){
        c.consulta();
    } else{
        cout<<"Opcion no valida"<<endl;
    }
}

void Manager::vehiculos_manager(){
    Vehiculo v;
    int opcion;
    cout<<"VEHICULOS"<<endl;
    cout<<"Que accion desea realizar? 1. Borrar | 2. Actualizar | 3. Insercion | 4. Consulta"<<endl; cin>>opcion;
    if (opcion==1){
        v.borrar();
    } else  if (opcion ==2){
        v.actualizar();
    } else if (opcion==3){
        v.insercion();
    } else if (opcion==4){
        v.consulta();
    } else {
        cout<<"Opcion no valida"<<endl;
    }
}

void Manager::repuestos_manager(){
    Repuesto r;
    int opcion;
    cout<<"REPUESTOS"<<endl;
    cout<<"Que accion desea realizar? 1. Borrar | 2. Actualizar | 3. Insercion | 4. Consulta"<<endl; cin>>opcion;
    if (opcion==1){
        r.borrar();
    } else  if (opcion ==2){
        r.actualizar();
    } else if (opcion==3){
        r.insercion();
    } else if (opcion==4){
        r.consulta();
    } else {
        cout<<"Opcion no valida"<<endl;
    }
}