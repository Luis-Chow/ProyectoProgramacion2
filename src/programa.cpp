#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

struct vehiculo{
    string marca;
    string modelo;
    int anio;
    string placa;
    string color;
    float precio_renta;
    float kilometraje;
    string rentado;
    string motor;
    int ced_cliente;
    string fecha_de_entrega;
}V;

struct cliente{
    int cedula;
    string nombre;
    string apellido;
    string direccion;
    int cantidad_vehiculos_rentados;
    string email;
    string activo;
}C;

struct respuestos{
    string marca;
    string nombre;
    string modelo_carro;
    int anio_carro;
    int precio;
    int existencias;
}R;

void borrarFilaCSV(const string& archivo, int filaABorrar) {
    ifstream input(archivo);
    ofstream temp("temp.csv");
    string linea;
    int numeroFila = 1;
    while (getline(input, linea)) {
        if (numeroFila != filaABorrar) {
            temp << linea << endl;
        }
        numeroFila++;
    }

    input.close();
    temp.close();

    remove(archivo.c_str());
    rename("temp.csv", archivo.c_str());
}
void actualizarCSV(const string& archivo){
    ifstream input(archivo);
    ofstream temp("temp.csv");
    int numero_fila=0;
    int fila_actualizar, columna_actualizar;
    string nuevoDato;
    string linea;
    int confirmar;
    cout<< "Ingrese la fila a actualizar: "; cin>>fila_actualizar; fila_actualizar -=1;
    cout<< "Ingrese el numero de columna a actualizar: "; cin>>columna_actualizar; columna_actualizar= columna_actualizar;
    cin.ignore(100,'\n');
    while(getline(input, linea)) {
        if (numero_fila==fila_actualizar){
            cout<< "Ingrese el nuevo dato: "; getline(cin,nuevoDato);
            stringstream ss(linea);
            string resto_de_fila;
            int columna_actual= 1;
            bool columna1= true;
            while(getline(ss,resto_de_fila,',')){
                if (!columna1){
                    temp<<",";
                }
                if (columna_actual == columna_actualizar){
                    temp<< nuevoDato;
                } else {
                    temp << resto_de_fila;
                }
                columna_actual++;
                columna1= false;
            }
            temp<< endl;
        } else{
            temp<< linea << endl;
        }
        numero_fila++;
    }
    cout<<"Quieres confirmar los cambios? 1. Si | 2. No: "; cin>>confirmar;
    if(confirmar==1){
        input.close();
        temp.close();
        remove(archivo.c_str());
        rename("temp.csv", archivo.c_str());
    } else if(confirmar==2){
        input.close();
        temp.close();
        remove("temp.csv");
    }else {
        cout<<"Error en la confirmacion, cancelando cambios...";
        input.close();
        temp.close();
        remove(archivo.c_str());
        rename("temp.csv", archivo.c_str());
    }
}
int main(){
    int opcion1 = 0;
    int opcion2 = 0;
    int opciong = 0;
    cout<<"Que archivo desea leer? \n1 = vehiculos | 2 = clientes | 3 = repuestos\n"; cin>>opcion1;
    ifstream input;

    switch (opcion1){
        case 1: {  // Vehiculos
            cout<<"VEHICULOS"<<endl;
            cout<<"Que accion desea realizar? \n1 = Borrar | 2 = Actualizar | 3 = Insercion\n"; cin>>opcion2;
            input.open("./bin/Vehiculos.csv");
            if (!input.is_open()) {
                cout<<"Error al abrir el archivo Vehiculos.csv"<<endl;
                return 1;
            }
            switch (opcion2) {
                case 1: { // Vehiculos > Borrar
                    cout<<"Que fila desea borrar? "; cin>>opciong;
                    input.close();
                    borrarFilaCSV("./bin/Vehiculos.csv", opciong);
                    break;
                }
                case 2: {  //Vehiculos Actualizar
                    input.close();
                    actualizarCSV("./bin/Vehiculos.csv");
                    break;
                } 
                case 3: {   //Vehiculos Insercion
                    cout<<"Ingrese los nuevos datos: \n" ; cin.ignore(100,'\n');
                    cout<<"Modelo: "; getline(cin,V.modelo);
                    cout<<"Marca: "; cin>>V.marca;
                    cout<<"Placa: "; cin>>V.placa;
                    cout<<"Color:"; cin>>V.color;
                    cout<<"Fecha de lanzamiento: "; cin>> V.anio;
                    cout<<"Kilometraje:"; cin>>V.kilometraje; cin.ignore(100,'\n');
                    cout<<"Estado de renta (yes/no/pending) "; getline(cin,V.rentado);
                    cout<<"Motor: "; cin>>V.motor;
                    cout<<"Precio de renta: "; cin>>V.precio_renta; 
                    cout<<"Cedula del cliente: "; cin>>V.ced_cliente;
                    cout<<"Fecha de entrega (dd/mm/yyyy)"; cin>>V.fecha_de_entrega;
                    string linea;
                    ofstream Vout("./bin/temp.csv");
                    while(getline(input, linea)){
                        Vout<<linea<<endl;
                    };
                    Vout<<V.modelo<<","<<V.marca<<","<<V.placa<<","<<V.color<<","<<V.anio<<","<<V.kilometraje<<","<<V.rentado<<","<<V.motor<<","<<V.precio_renta<<","<<V.ced_cliente<<","<<V.fecha_de_entrega;
                    cout<<"Desea confirmar los cambios? 1. Si | 2. No"<<endl; cin>>opciong;
                    if(opciong == 1){
                        input.close();
                        Vout.close();
                        remove("./bin/Vehiculos.csv");
                        rename("./bin/temp.csv","./bin/Vehiculos.csv");
                    } else if (opciong == 2){
                        input.close();
                        Vout.close();
                        remove("./bin/temp.csv");
                    }
                    break;
                }
                default: {
                    cout<<"Opcion no valida"<<endl;
                    break;
                }
            }
            break;
        }
        case 2: { // Clientes
            cout<<"CLIENTES"<<endl;
            cout<<"Que accion desea realizar? \n1 = Borrar | 2 = Actualizar | 3 = Insercion | 4 = Lectura\n"; cin>>opcion2;
            input.open("./bin/Clientes.csv");
            if (!input.is_open()) {
                cout<<"Error al abrir el archivo Clientes.csv"<<endl;
                return 1;
            }
            switch (opcion2) {
                case 1: { // Clientes > Borrar
                    cout<<"Que fila desea borrar? "; cin>>opciong;
                    input.close();
                    borrarFilaCSV("./bin/Clientes.csv", opciong);
                    break;
                }
                case 2: {  //Clientes > Actualizar
                    input.close();
                    actualizarCSV("./bin/Clientes.csv");
                    break;
                } 
                case 3: {   // Clientes > Insercion
                    cout<<"Ingrese los nuevos datos: \n" ; cin.ignore(100,'\n');
                    cout<<"Cedula: "; cin>>C.cedula;
                    cout<<"Nombre: "; cin>>C.nombre;
                    cout<<"Apellido: "; cin>>C.apellido;
                    cout<<"Correo electronico: "; cin>>C.email;
                    cout<<"Cantidad de Vehiculos rentados: "; cin>> C.cantidad_vehiculos_rentados; cin.ignore(100,'\n');
                    cout<<"Direccion "; getline(cin, C.direccion);
                    cout<<"El cliente se encuentra activo? (yes/no/pending) "; getline(cin,C.activo);
                    string linea;
                    ofstream Vout("./bin/temp.csv");
                    while(getline(input, linea)){
                        Vout<<linea<<endl;
                    };
                    Vout<<C.cedula<<","<<C.nombre<<","<<C.apellido<<","<<C.email<<","<<C.cantidad_vehiculos_rentados<<","<<C.direccion<<","<<C.activo;
                    cout<<"Desea confirmar los cambios? 1. Si | 2. No"<<endl; cin>>opciong;
                    if(opciong == 1){
                        input.close();
                        Vout.close();
                        remove("./bin/Clientes.csv");
                        rename("./bin/temp.csv","./bin/Clientes.csv");
                    } else if (opciong == 2){
                        input.close();
                        Vout.close();
                        remove("./bin/temp.csv");
                    }
                    break;
                }
                default:
                    cout<<"Opcion no valida" << endl;
                    break;
            }
            break;
        }
        case 3: { // Repuestos
            cout<<"REPUESTOS"<<endl;
            cout<<"Que accion desea realizar? \n1 = Borrar | 2 = Actualizar | 3 = Insercion | 4 = Lectura\n"; cin>>opcion2;
            input.open("./bin/Repuestos.csv");
            if (!input.is_open()) {
                cout<<"Error al abrir el archivo repuestos.csv"<<endl;
                return 1;
            }
            switch (opcion2) {
                case 1: { // Repuestos > Borrar
                    cout<<"Que fila desea borrar? "; cin>>opciong;
                    input.close();
                    borrarFilaCSV("./bin/Repuestos.csv", opciong);
                    break;
                }
                case 2: { //Repuestos > Actualizar
                    input.close();
                    actualizarCSV("./bin/Repuestos.csv");
                    break;
                }
                case 3: {        // Repuestos > Insercion
                    cout<<"Ingrese los nuevos datos: \n" ; cin.ignore(100,'\n');
                    cout<<"Marca del repuesto: "; getline(cin,R.marca);
                    cout<<"Nombre del repuesto: "; cin>>R.nombre;
                    cout<<"Modelo del carro: "; cin>>R.modelo_carro;
                    cout<<"Anio del carro: "; cin>>R.anio_carro;
                    cout<<"Precio del repuesto: "; cin>>R.precio;
                    cout<<"Existencias del repuesto: "; cin>>R.existencias;
                    string linea;
                    ofstream Vout("./bin/temp.csv");
                    while(getline(input, linea)){
                        Vout<<linea<<endl;
                    };
                    Vout<<R.marca<<","<<R.nombre<<","<<R.modelo_carro<<","<<R.anio_carro<<","<<R.precio<<","<<R.existencias;
                    cout<<"Desea confirmar los cambios? 1. Si | 2. No"<<endl; cin>>opciong;
                    if(opciong == 1){
                       input.close();
                        Vout.close();
                        remove("./bin/Repuestos.csv");
                        rename("./bin/temp.csv","./bin/Repuestos.csv");
                    } else if (opciong == 2){
                        input.close();
                        Vout.close();
                        remove("./bin/temp.csv");
                    }
                    break;
                }
                default:
                    cout<<"Opcion no valida"<<endl;
                    break;
            }
            break;
        }
        default:
            cout<<"Opcion no valida"<<endl;
            break;
    }
    return 0;
}
