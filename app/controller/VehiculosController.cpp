#include "../model/Vehiculos/vehiculos.h"



void Vehiculo::insercion(){
    string linea;
    int confirmar;
    ifstream input("./model/Vehiculos/Vehiculos.csv");
    ofstream Vout("./model/Vehiculos/temp.csv");
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
    while(getline(input, linea)){
        Vout<<linea<<endl;
    };
    Vout<<modelo<<","<<marca<<","<<placa<<","<<color<<","<<anio<<","<<kilometraje<<","<<rentado<<","<<motor<<","<<precio_renta<<","<<ced_cliente<<","<<fecha_de_entrega<<endl;
    Vout.close();
    input.close();
    cout<<"Desea confirmar el cambio?  1. Si |  2. No"<<endl; cin>>confirmar;
    if (confirmar==1){
        remove("./model/Vehiculos/Vehiculos.csv");
        rename("./model/Vehiculos/temp.csv", "./model/Vehiculos/Vehiculos.csv");
    } else if (confirmar==2){
        remove("./model/Vehiculos/temp.csv");
    }
}
void Vehiculo:: borrar(){
    int filaAborrar;
    int confirmar;
    ifstream input("./model/Vehiculos/Vehiculos.csv");
    ofstream temp("./model/Vehiculos/temp.csv");
    string linea;
    int numero_fila=1;
    cout<<"Ingrese la fila a borrar: "; cin>>filaAborrar;
    if(filaAborrar == 1){
        cout<<"No se puede borrar la fila 1 ya que es la cabecera del archivo..."<<endl;
        return;
    }
    while(getline(input, linea)){
        if (numero_fila != filaAborrar){
            temp<<linea<<endl;
        }
        numero_fila++;
    }
    input.close();
    temp.close();
    cout<<"Desea confirmar el cambio?  1. Si |  2. No"<<endl; cin>>confirmar;
    if (confirmar==1){
        remove("./model/Vehiculos/Vehiculos.csv");
        rename("./model/Vehiculos/temp.csv", "./model/Vehiculos/Vehiculos.csv");
    } else if (confirmar==2){
        remove("./model/Vehiculos/temp.csv");
    }
}
void Vehiculo::actualizar() {
    ifstream input("./model/Vehiculos/Vehiculos.csv");
    ofstream temp("./model/Vehiculos/temp.csv");
    int numero_fila = 0;
    int fila_actualizar, columna_actualizar;
    string nuevoDato;
    string linea;
    int confirmar;
    cout << "Ingrese la fila a actualizar: "; cin >> fila_actualizar; fila_actualizar -= 1;
    cout << "Ingrese el dato a actualizar:  1.Modelo | 2.Marca | 3.Placa | 4.Color | 5.Anio | 6.Kilometraje | 7.Rentado | 8.Motor | 9.Precio de renta | 10.Cedula_cliente | 11.Fecha_de_entrega " << endl;
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
        remove("./model/Vehiculos/Vehiculos.csv");
        rename("./model/Vehiculos/temp.csv", "./model/Vehiculos/Vehiculos.csv");
    } else if (confirmar == 2) {
        remove("./model/Vehiculos/temp.csv");
    } else {
        cout << "Opción no válida, cancelando cambios...";
        remove("./model/Vehiculos/temp.csv");
    }
}
void Vehiculo::consulta(){
    string placa_consulta;
    ifstream input("./model/Vehiculos/Vehiculos.csv");
    string linea;
    cout<<"Introduzca la placa del vehiculo que desea consultar: "; cin>>placa_consulta;
    while(getline(input, linea)){
        stringstream ss(linea);
        string marca, modelo, placa, color, anio, kilometraje, rentado, motor, precio_renta, ced_cliente, fecha_de_entrega;
        getline(ss, marca, ','); getline(ss, modelo, ','); getline(ss, placa, ','); getline(ss, color, ',');
        getline(ss, anio, ','); getline(ss, kilometraje, ','); getline(ss, rentado, ','); getline(ss, motor, ',');
        getline(ss, precio_renta, ','); getline(ss, ced_cliente, ','); getline(ss, fecha_de_entrega, ',');
        if (placa == placa_consulta){
            cout<<"Marca: "<<marca<<endl;
            cout<<"Modelo: "<<modelo<<endl;
            cout<<"Placa: "<<placa<<endl;
            cout<<"Color: "<<color<<endl;
            cout<<"Anio de lanzamiento: "<<anio<<endl;
            cout<<"Kilometraje: "<<kilometraje<<endl;
            cout<<"Rentado: "<<rentado<<endl;
            cout<<"Motor: "<<motor<<endl;
            cout<<"Precio de renta: "<<precio_renta<<endl;
            if (rentado == "Si" || rentado == "si" || rentado == "SI") {
                cout<<"Cedula del cliente: "<<ced_cliente<<endl;
                cout<<"Fecha de entrega: "<<fecha_de_entrega<<endl;
            }
        }
    }
    input.close();
}