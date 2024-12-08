#include "../model/Clientes/Clientes.h"

void Cliente::insercion(){
    int confirmar;
    string linea;
    ifstream input("model/Clientes/Clientes.csv");
    ofstream Vout("model/Clientes/temp.csv");
    cout<<"Cedula: "; cin>>cedula;
    cout<<"Nombre: "; cin>>nombre;
    cout<<"Apellido: "; cin>>apellido;
    cout<<"Correo electronico: "; cin>>email;
    cout<<"Cantidad de Vehiculos rentados: "; cin>> cantidad_vehiculos_rentados; cin.ignore(100,'\n');
    cout<<"Direccion "; getline(cin, direccion);
    cout<<"El cliente se encuentra activo? (Si | No) "; getline(cin,activo);
    while(getline(input, linea)){
        Vout<<linea<<endl;
    }
    Vout<<cedula<<","<<nombre<<","<<apellido<<","<<email<<","<<cantidad_vehiculos_rentados<<","<<direccion<<","<<activo;   
    cout<<"Desea confirmar los cambios? 1. Si | 2. No"<<endl; cin>>confirmar;
    Vout.close();
    input.close();
    if(confirmar==1){
        remove("model/Clientes/Clientes.csv");
        rename("model/Clientes/temp.csv", "model/Clientes/Clientes.csv");
    } else if (confirmar==2){
        remove("model/Clientes/temp.csv");
    } else {
        cout<<"Error en la confirmacion, cancelando cambios...";
        remove("model/Clientes/temp.csv");
    }
}

void Cliente::borrar(){
    int confirmar;
    ifstream input("model/Clientes/Clientes.csv");
    ofstream temp("model/Clientes/temp.csv");
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
        remove("model/Clientes/Clientes.csv");
        rename("model/Clientes/temp.csv", "model/Clientes/Clientes.csv");
    } else if (confirmar==2){
        remove("model/Clientes/temp.csv");
    }
}

void Cliente:: actualizar(){
    ifstream input("model/Clientes/Clientes.csv");
    ofstream temp("model/Clientes/temp.csv");
    int numero_fila=0;
    int fila_actualizar, columna_actualizar;
    string nuevoDato;
    string linea;
    int confirmar;
    cout<< "Ingrese la fila a actualizar: " ; cin>>fila_actualizar; fila_actualizar -=1;
    cout<< "Ingrese el dato a actualizar:  1. Cedula del cliente | 2.Nombre | 3.Apellido | 4.Email | 5.Cantidad de Vehiculos Rentados | 6.Direccion | 7.Activo "<<endl; 
    cin>>columna_actualizar; 
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
    input.close();
    temp.close();
    cout<<"Quieres confirmar los cambios? 1. Si | 2. No: "; cin>>confirmar;
    if(confirmar==1){
        remove("model/Clientes/Clientes.csv");
        rename("model/Clientes/temp.csv", "model/Clientes/Clientes.csv");
    } else if(confirmar==2){
        remove("model/Clientes/temp.csv");
    }else {
        cout<<"Error en la confirmacion, cancelando cambios...";
        remove("model/Clientes/temp.csv");
    }
}

void Cliente::consulta(){
    ifstream input("model/Clientes/Clientes.csv");
    string cedula_consulta;
    cout<<"Introduzca la cedula de identidad del cliente a consultar: "; cin>>cedula_consulta;
    string linea;
    while (getline(input, linea)) {
        stringstream ss(linea);
        string ced_cliente, nombre, apellido, email, cantidad_vehiculos_rentados, direccion, activo;
        getline(ss, ced_cliente, ','); getline(ss, nombre, ','); getline(ss, apellido, ','); getline(ss, email, ',');
        getline(ss, cantidad_vehiculos_rentados, ','); getline(ss, direccion, ','); getline(ss, activo, ',');
        if (ced_cliente == cedula_consulta){
            cout<<"Cedula del cliente: "<<ced_cliente<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Apellido: "<<apellido<<endl;
            cout<<"Email: "<<email<<endl;
            cout<<"Cantidad de vehiculos rentados: "<<cantidad_vehiculos_rentados<<endl;
            cout<<"Direccion: "<<direccion<<endl;
            cout<<"Activo: "<<activo<<endl;
        }
    }
    input.close();
}