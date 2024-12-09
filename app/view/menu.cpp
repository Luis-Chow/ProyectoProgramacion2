
#include"../controller/AdminController.cpp"

void registro(const std::string& nombre, int opcion1) {
    std::ofstream archivo("../model/Usuario/Usuarios.csv", std::ios::app);
    if (archivo.is_open()) {
        if(opcion1 == 1){
            archivo << nombre << "," << "Admin"<< "\n";
            archivo.close();
        } else if (opcion1 == 2){
            archivo << nombre << "," << "Manager"<< "\n";
            archivo.close();
        } else if (opcion1 == 3){
            archivo << nombre << "," << "Empleado"<< "\n";
            archivo.close();
        }
    }
}

int main(){
    bool salir = false;
    string nombre;
    int opcion1, opcion2;
    cout << "SISTEMA DE GERENCIA" << endl;
    cout << "Por favor ingrese su Nombre (*Nombre* *Apellido*)" << endl; 
    getline(cin, nombre);
    cout << "Por favor ingrese su tipo de usuario" << endl;
    cout << "1 = Admin | 2 = Manager | 3 = Empleado" << endl; cin >> opcion1;
    if(opcion1<0 && opcion1>4){
        cout << "Opcion no valida" << endl;
        return 0;
    }
    registro(nombre, opcion1);

    switch(opcion1){
        case 1:
            Admin a;
            cout << "Bienvenido " << nombre << "Eres un admin" <<endl;
            cout << "Que accion desea realizar? " <<endl;
            cout << "1. Manejar el archivo de vehiculos" << endl;
            cout << "2. Manejar el archivo de clientes" << endl;
            cout << "3. Manejar el archivo de repuestos" << endl;
            cout << "4. Crear copia de seguridad" << endl; cin >> opcion2;
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
                    a.copia_seguridad();
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
            break;
        case 2:
            Manager m;
            cout << "Bienvenido " << nombre << "Eres un manager" << endl;
            cout << "Que accion desea realizar? " << endl;
            cout << "1. Manejar el archivo de vehiculos" << endl;
            cout << "2. Manejar el archivo de clientes" << endl;
            cout << "3. Manejar el archivo de repuestos" << endl; cin >> opcion2;
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
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
            break;
        case 3:
            Empleado e;
            cout << "Bienvenido " << nombre << "Eres un empleado" << endl;
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
            break;
        default:
        cout << "Opcion no valida" << endl;
        break;
    }
    
}