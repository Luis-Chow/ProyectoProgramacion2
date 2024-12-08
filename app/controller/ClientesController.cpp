#include "../model/Clientes/Clientes.h"
#include <iostream>

using namespace std;

void Cliente::insercion(){
    int confirmar;
    ofstream Vout("model/Clientes/Clientes.csv");
    cout<<"Cedula: "; cin>>cedula;
    cout<<"Nombre: "; cin>>nombre;
    cout<<"Apellido: "; cin>>apellido;
    cout<<"Correo electronico: "; cin>>email;
    cout<<"Cantidad de Vehiculos rentados: "; cin>> cantidad_vehiculos_rentados; cin.ignore(100,'/n');
    cout<<"Direccion "; getline(cin, direccion);
    cout<<"El cliente se encuentra activo? (Si | No) "; getline(cin,activo);
    cout<<"Desea confirmar los cambios? 1. Si | 2. No"<<endl; cin>>confirmar;
    if(confirmar==1){
        Vout<<cedula<<","<<nombre<<","<<apellido<<","<<email<<","<<cantidad_vehiculos_rentados<<","<<direccion<<","<<activo;
    } else if (confirmar==2){
        cout<<"Cancelando cambios..."<<endl;
    }
    Vout.close();
}

void Cliente::borrar(){
    int confirmar;
    ifstream input("model/Clientes/Clientes.csv");
    ofstream temp("model/Clientes/temp.csv");
    int numero_fila=0;
    int filaABorrar;
    cout<< "Ingrese la fila a borrar: " ; cin>>filaABorrar; filaABorrar -=1;
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
    cin.ignore(100,'/n');
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