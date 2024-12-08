#include "../model/Vehiculos/vehiculos.h"
#include <iostream>

using namespace std;

void Vehiculo::insercion(){
    ofstream Vout("model/Vehiculos/Vehiculos.csv");
    cout<<"Marca del vehiculo: "; getline(cin,marca);
    cout<<"Modelo del vehiculo: "; getline(cin,modelo);
    cout<<"Anio del vehiculo: "; cin>>anio;
    cout<<"Placa del vehiculo: "; cin>>placa;
    cout<<"Color del vehiculo: "; cin>>color;
    cout<<"Precio de renta del vehiculo: "; cin>>precio_renta;
    cout<<"Kilometraje del vehiculo: "; cin>>kilometraje;
    cout<<"Rentado? (Si | No): "; cin>>rentado;
    cout<<"Motor del vehiculo: "; cin>>motor;
    if(rentado == "Si" || rentado == "si"){
        cout<<"Cedula del cliente: "; cin>>ced_cliente;
        cout<<"Fecha de entrega (dd/mm/yyyy):"; cin>>fecha_de_entrega;
    } else {
        ced_cliente = 0;
        fecha_de_entrega = "";
    }
    Vout<<marca<<","<<modelo<<","<<anio<<","<<placa<<","<<color<<","<<precio_renta<<","<<kilometraje<<","<<rentado<<","<<motor<<","<<ced_cliente<<","<<fecha_de_entrega<<endl;
    Vout.close();
}
void Vehiculo:: borrar(){
    int confirmar;
    ifstream input("ProyectoProgramacion2/app/model/Vehiculos/Vehiculos.csv, ios");
    ofstream temp("temp.csv");
    string linea;
    int numero_fila=1;
    while(getline(input, linea)){
        if (numero_fila != 1){
            temp<<linea<<endl;
        }
        numero_fila++;
    }
    input.close();
    temp.close();
    cout<<"Desea confirmar el cambio?  1. Si |  2. No"<<endl; cin>>confirmar;
    if (confirmar==1){
        remove("ProyectoProgramacion2/app/model/Vehiculos/Vehiculos.csv");
        rename("temp.csv", "ProyectoProgramacion2/app/model/Vehiculos/Vehiculos.csv");
    } else if (confirmar==2){
        remove("temp.csv");
    }
}
void Vehiculo::actualizar() {
    ifstream input("ProyectoProgramacion2/app/model/Vehiculos/Vehiculos.csv");
    ofstream temp("temp.csv");
    int numero_fila = 0;
    int fila_actualizar, columna_actualizar;
    string nuevoDato;
    string linea;
    int confirmar;
    cout << "Ingrese la fila a actualizar: "; cin >> fila_actualizar; fila_actualizar -= 1;
    cout << "Ingrese el dato a actualizar:  1.Marca | 2.Modelo | 3.Anio | 4.Placa | 5.Color | 6.Precio_renta | 7.Kilometraje | 8.Rentado | 9.Motor | 10.Cedula_cliente | 11.Fecha_de_entrega " << endl;
    cin >> columna_actualizar;
    cin.ignore(100, '\n');
    while (getline(input, linea)) {
        if (numero_fila == fila_actualizar) {
            cout << "Ingrese el nuevo dato: "; getline(cin, nuevoDato);
            stringstream ss(linea);
            string resto_de_fila;
            int columna_actual = 1;
            bool columna1 = true;
            while (getline(ss, resto_de_fila, ',')) {
                if (!columna1) {
                    temp << ",";
                }
                if (columna_actual == columna_actualizar) {
                    temp << nuevoDato;
                } else {
                    temp << resto_de_fila;
                }
                columna_actual++;
                columna1 = false;
            }
            temp << endl;
        } else {
            temp << linea << endl;
        }
        numero_fila++;
    }
    input.close();
    temp.close();
    cout << "Desea confirmar el cambio?  1. Si |  2. No" << endl; cin >> confirmar;
    if (confirmar == 1) {
        remove("ProyectoProgramacion2/app/model/Vehiculos/Vehiculos.csv");
        rename("temp.csv", "ProyectoProgramacion2/app/model/Vehiculos/Vehiculos.csv");
    } else if (confirmar == 2) {
        remove("temp.csv");
    } else {
        cout << "Opción no válida, cancelando cambios...";
        remove("temp.csv");
    }
}