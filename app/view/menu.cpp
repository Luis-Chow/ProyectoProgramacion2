#include "../controller/UsuariosController.cpp"

int main(){
    bool continuarexterno = true;
    string nombre,apellido;
    int opcion1, opcion2,opcioninterno,opcionexterno;
    cout << "SISTEMA DE GERENCIA" << endl;
    while(continuarexterno){
    bool continuarinterno = true;
    cout << "Por favor ingrese su Nombre: " << endl;
    cin >> nombre;
    cout << "Por favor ingrese su Apellido: " << endl;
    cin >> apellido;
    cout << "Por favor ingrese su tipo de usuario" << endl;
    cout << "1 = Admin | 2 = Manager | 3 = Empleado" << endl; cin >> opcion1;
    if(opcion1<0 && opcion1>4){
        cout << "Opcion no valida" << endl;
        return 0;
    }
    registro(nombre, apellido, opcion1);

    switch(opcion1){
        case 1:
            cout << "Bienvenido " << nombre << ", Eres un admin" <<endl;
            while(continuarinterno){
            Admin a;
            cout << "Que accion desea realizar? " <<endl;
            cout << "1. Manejar el archivo de vehiculos" << endl;
            cout << "2. Manejar el archivo de clientes" << endl;
            cout << "3. Manejar el archivo de repuestos" << endl;
            cout << "4. Manejar el archivo de usuarios" << endl; 
            cout << "5. Crear copia de seguridad"<< endl; cin >> opcion2;
            switch(opcion2){
                case 1:
                    a.vehiculos_admin();
                    break;
                case 2:
                    a.clientes_admin();
                    break;
                case 3:
                    a.repuestos_admin();
                    break;
                case 4:
                    a.usuarios_admin();
                    break;
                case 5:
                    a.copia_seguridad();
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
            cout<< "Desea continuar el programa? 1.Si | 2.No"<<endl; cin>>opcioninterno;
            if(opcioninterno==2){
                continuarinterno = false;
            } else{
                cout << "Continuando..." << endl;
            }
            }
            break;
        case 2:
            cout << "Bienvenido " << nombre << ", Eres un manager" << endl;
            while(continuarinterno){
                Manager m;
            cout << "Que accion desea realizar? " << endl;
            cout << "1. Manejar el archivo de vehiculos" << endl;
            cout << "2. Manejar el archivo de clientes" << endl;
            cout << "3. Manejar el archivo de repuestos" << endl; 
            cout << "4. Manejar el archivo de usuario" << endl; cin >> opcion2;
            switch(opcion2){
                case 1:
                    m.vehiculos_manager();
                    break;
                case 2:
                    m.clientes_manager();
                    break;
                case 3:
                    m.repuestos_manager();
                    break;
                case 4:
                    m.usuarios_manager();
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
            cout<< "Desea continuar el programa? 1.Si | 2.No"<<endl; cin>>opcioninterno;
            if(opcioninterno==2){
                continuarinterno = false;
            } else{
                cout << "Continuando..." << endl;
            }
            }
            break;
        case 3:
            cout << "Bienvenido " << nombre << ", Eres un empleado" << endl;
            while(continuarinterno){
            Empleado e;
            cout << "Que accion desea realizar? " << endl;
            cout << "1. Asociado a vehiculos" << endl;
            cout << "2. Asociado a clientes" << endl;
            cout << "3. Asociado a repuestos" << endl; cin >> opcion2;
            switch(opcion2){
                case 1:
                    e.vehiculos_empleados();
                    break;
                case 2:
                    e.clientes_empleados();
                    break;
                case 3:
                    e.repuestos_empleados();
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
            cout<< "Desea continuar el programa? 1.Si | 2.No"<<endl; cin>>opcioninterno;
            if(opcioninterno==2){
                continuarinterno = false;
            } else{
                cout << "Continuando..." << endl;
            }
            }
            break;
        default:
        cout << "Opcion no valida" << endl;
        break;
    }
    cout << "Ingrese la siguiente accion"<<endl;
    cout << "1. Cambiar de usuario" <<endl;
    cout << "2. Salir del programa" <<endl; cin >> opcionexterno;
    if(opcionexterno==2){
        continuarexterno = false;
    } else{
        cout << "Reiniciando sesion..." << endl;
        cout << endl;
    }
    }
    return 0;
}