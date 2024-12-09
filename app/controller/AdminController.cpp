#include "ManagerController.cpp"
#include "../model/Usuario/Admin.h"



void Admin::copia_seguridad() {
    string archivo;
    int opcion;
    cout << "Copia de seguridad" << endl;
    cout << "Que archivo desea respaldar? \n1 = Vehiculos | 2 = Clientes | 3 = Repuestos\n"; cin >> opcion;
    if (opcion == 1) {
        archivo = "../model/Vehiculos/Vehiculos.csv";
    }
    if (opcion == 2) {
        archivo = "../model/Clientes/Clientes.csv";
    }
    if (opcion == 3) {
        archivo = "../model/Repuestos/Repuestos.csv";
    }

    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream ss;
    ss << "../model/backup/" << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday << "_" << ltm->tm_hour << "-" << ltm->tm_min << "-" << ltm->tm_sec << ".csv";
    string backupFileName = ss.str();
    ifstream src(archivo, ios::binary);
    ofstream dst(backupFileName, ios::binary);
    dst << src.rdbuf();

    src.close();
    dst.close();

    cout << "Copia de seguridad creada: " << backupFileName << endl;
}
void Admin :: vehiculos_admin(){
    Vehiculo v;
    int opcion;
    cout <<"VEHICULOS"<<endl;
    cout<<"Que accion desea realizar? \n1 = Borrar | 2 = Actualizar | 3 = Insercion | 4 = Consulta\n"; cin>>opcion;
    if (opcion==1){
        v.borrar();
    }
    if (opcion ==2){
        v.actualizar();
    }
    if (opcion==3){
        v.insercion();
    }
    if (opcion==4){
        v.consulta();
    }
}

void Admin::clientes_admin(){
    Cliente c;
    int opcion;
    cout<<"CLIENTES"<<endl;
    cout<<"Que accion desea realizar? /n1 = Borrar | 2 = Actualizar | 3 = Insercion | 4 = Consulta/n"; cin>>opcion;
    if (opcion==1){
        c.borrar();
    }
    if (opcion ==2){
        c.actualizar();
    }
    if (opcion==3){
        c.insercion();
    }
    if (opcion==4){
        c.consulta();
    }
}

void Admin::repuestos_admin(){
    Repuesto r;
    int opcion;
    cout<<"REPUESTOS"<<endl;
    cout<<"Que accion desea realizar? /n1 = Borrar | 2 = Actualizar | 3 = Insercion | 4 = Consulta/n"; cin>>opcion;
    if (opcion==1){
        r.borrar();
    }
    if (opcion ==2){
        r.actualizar();
    }
    if (opcion==3){
        r.insercion();
    }
    if (opcion==4){
        r.consulta();
    }
}