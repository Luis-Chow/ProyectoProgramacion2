#include "../model/Usuario/Usuarios.h"
#include "../controller/ClientesController.cpp"
#include "../controller/VehiculosController.cpp"
#include "../controller/RepuestosController.cpp"

void registro(const string& nombre,const string& apellido, int opcion1) {
    ofstream archivo("./model/Usuario/Usuarios.csv", ios::app);
    if (archivo.is_open()) {
        if(opcion1 == 1){
            archivo << nombre << " "<< apellido<< "," << "Admin" << "\n";
        } else if (opcion1 == 2){
            archivo << nombre << " "<< apellido << "," << "Manager" << "\n";
        } else if (opcion1 == 3){
            archivo << nombre << " "<< apellido << "," << "Empleado" << "\n";
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo para escribir." << endl;
    }
}

void borrarRegistro(){
    int confirmar;
    ifstream input("../model/Usuario/Usuarios.csv");
    ofstream temp("../model/Usuario/temp.csv");
    int numero_fila=1;
    int filaABorrar;
    cout<< "Ingrese la fila a borrar: " ; cin>>filaABorrar;
    if(filaABorrar == 1){
        cout<<"No se puede borrar la fila 1 ya que es la cabecera del archivo..."<<endl;
        return;
    }
    string linea;
    while(getline(input, linea)) {
        if (numero_fila != filaABorrar) {
            temp << linea << endl;
        }
        numero_fila++;
    }
    input.close();
    temp.close();
    cout<<"Desea confirmar el cambio?  1. Si |  2. No"<<endl; cin>>confirmar;
    if (confirmar==1){
        remove("../model/Usuario/Usuarios.csv");
        rename("../model/Usuario/temp.csv", "../model/Usuario/Usuarios.csv");
    } else if (confirmar==2){
        remove("../model/Usuario/temp.csv");
    }
}

void leerUsuariosCSV() {
    ifstream archivo("../model/Usuario/Usuarios.csv");
    if (archivo.is_open()) {
        string linea;
        cout << "Lista de usuarios registrados:" << endl;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo para leer." << endl;
    }
}

void Admin::copia_seguridad() {
    string linea;
    string archivo;
    int opcion;
    cout << "Copia de seguridad" << endl;
    cout << "Que archivo desea respaldar? \n1 = Vehiculos | 2 = Clientes | 3 = Repuestos | 4 = Usuarios\n"; cin >> opcion;
    if (opcion == 1) {
        archivo = "../model/Vehiculos/Vehiculos.csv";
    } else if (opcion == 2) {
        archivo = "../model/Clientes/Clientes.csv";
    } else if (opcion == 3) {
        archivo = "../model/Repuestos/Repuestos.csv";
    } else if(opcion == 4){
        archivo = "../model/Usuario/Usuarios.csv";
    } else {
        cout << "Opcion no valida" << endl;
        return;
    }

    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream ss;
    ss << "../model/backup/" <<ltm->tm_mday << "-" << 1 + ltm->tm_mon << "-" << 1900 + ltm->tm_year;
    string backupFileName = ss.str();
    ifstream input(archivo);
    ofstream temp("../model/Backup/temp.csv");
    while (getline(input, linea)) {
        temp << linea << endl;
    }
    input.close();
    temp.close();
    if(opcion==1){
        backupFileName+=" Vehiculos.csv";
        rename("../model/Backup/temp.csv", backupFileName.c_str());
    }else if(opcion==2){
        backupFileName+=" Clientes.csv";
        rename("../model/Backup/temp.csv", backupFileName.c_str());
    }else if(opcion==3){
        backupFileName+=" Repuestos.csv";
        rename("../model/Backup/temp.csv", backupFileName.c_str());
    }else if(opcion==4){
        backupFileName+=" Usuarios.csv";
        rename("../model/Backup/temp.csv", backupFileName.c_str());
    }
    cout << "Copia de seguridad creada: " << backupFileName << endl;
}

void Admin::vehiculos_admin(){
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
    cout<<"Que accion desea realizar? \n1 = Borrar | 2 = Actualizar | 3 = Insercion | 4 = Consulta\n"; cin>>opcion;
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
    cout<<"Que accion desea realizar? \n1 = Borrar | 2 = Actualizar | 3 = Insercion | 4 = Consulta\n"; cin>>opcion;
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

void Admin::usuarios_admin(){
    int opcion;
    cout<<"USUARIOS"<<endl;
    cout<<"Que accion desea realizar? 1. Registro | 2. Borrar | 3. Consulta"<<endl; cin>>opcion;
    string nombre;
    string apellido;
    int opcion1;
    switch(opcion){
        case 1:
            cout<<"Ingrese el nombre del usuario: "; cin>>nombre;
            cout<<"Ingrese el apellido del usuario: "; cin>>apellido;
            cout<<"Ingrese el tipo de usuario: 1.Admin | 2.Manager | 3.Empleado"<<endl; cin>>opcion1;
            registro(nombre, apellido, opcion1);
            break;
        case 2:
            borrarRegistro();
            break;
        case 3:
            leerUsuariosCSV();
            break;
        default:
            cout<<"Opcion no valida"<<endl;
    }
}

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

void Manager::usuarios_manager(){
    int opcion;
    cout<<"USUARIOS"<<endl;
    cout<<"Que accion desea realizar? 1. Registro | 2. Borrar | 3. Consulta"<<endl; cin>>opcion;
    string nombre;
    string apellido;
    int opcion1=0;
    int opcion2;
    switch(opcion){
        case 1:
            cout<<"Ingrese el nombre del usuario: "; cin>>nombre;
            cout<<"Ingrese el apellido del usuario: "; cin>>apellido;
            cout<<"Ingrese el tipo de usuario: 1.Manager | 2.Empleado: "<<endl; cin>>opcion2;
            if(opcion2<1 || opcion2>2){
                cout<<"Opcion no valida"<<endl;
            }else if(opcion2==1 || opcion2 == 2){
            opcion1 = 1 + opcion2;
            registro(nombre, apellido, opcion1);
            }
            break;
        case 2:
            borrarRegistro();
            break;
        case 3:
            leerUsuariosCSV();
            break;
        default:
            cout<<"Opcion no valida"<<endl;
    }
}

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


