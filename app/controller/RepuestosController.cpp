#include "../model/Repuestos/Repuestos.h"


void Repuesto::insercion(){
    string linea;
    int confirmar;
    ifstream input("./model/Repuestos/Repuestos.csv");
    ofstream Vout("./model/Repuestos/temp.csv");
    cout<<"Marca del repuesto: "; getline(cin,marca);
    cout<<"Nombre del repuesto: "; cin>>nombre;
    cout<<"Modelo del carro: "; cin>>modelo_carro;
    cout<<"Anio del carro: "; cin>>anio_carro;
    cout<<"Precio del repuesto: "; cin>>precio;
    cout<<"Existencias del repuesto: "; cin>>existencias;
    while(getline(input, linea)){
        Vout<<linea<<endl;
    }
    Vout<<marca<<","<<nombre<<","<<modelo_carro<<","<<anio_carro<<","<<precio<<","<<existencias<<endl;
    Vout.close();
    input.close();
    cout<<"Desea confirmar la insercion? 1. Si | 2. No"<<endl; cin>>confirmar;
    if (confirmar==1){
        remove("./model/Repuestos/Repuestos.csv");
        rename("./model/Repuestos/temp.csv", "./model/Repuestos/Repuestos.csv");
    } else if (confirmar==2){
        remove("./model/Repuestos/temp.csv");
    }

}

void Repuesto::borrar(){
    int confirmar;
    ifstream input("./model/Repuestos/Repuestos.csv");
    ofstream temp("./model/Repuestos/temp.csv");
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
        remove("./model/Repuestos/Repuestos.csv");
        rename("./model/Repuestos/temp.csv", "./model/Repuestos/Repuestos.csv");
    } else if (confirmar==2){
        remove("./model/Repuestos/temp.csv");
    }
}

void Repuesto:: actualizar(){
    ifstream input("./model/Repuestos/Repuestos.csv");
    ofstream temp("./model/Repuestos/temp.csv");
    int numero_fila=0;
    int fila_actualizar, columna_actualizar;
    string nuevoDato;
    string linea;
    int confirmar;
    cout<< "Ingrese la fila a actualizar: " ; cin>>fila_actualizar; fila_actualizar -=1;
    cout<< "Ingrese el dato a actualizar:  1.Marca | 2.Nombre | 3.Modelo_carro | 4.Anio_carro | 5.Precio | 6.Existencia "<<endl; 
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
        remove("./model/Repuestos/Repuestos.csv");
        rename("./model/Repuestos/temp.csv", "./model/Repuestos/Repuestos.csv");
    } else if(confirmar==2){
        remove("./model/Repuestos/temp.csv");
    }else {
        cout<<"Error en la confirmacion, cancelando cambios...";
        remove("./model/Repuestos/temp.csv");
    }
}

void Repuesto::consulta(){
    ifstream input("./model/Repuestos/Repuestos.csv");
    string linea;
    string nombre_consulta;
    cout<<"Introduzca el nombre del repuesto a consultar (minusculas): "; cin>>nombre_consulta;
    cout<<"Marca | Nombre | Modelo del carro | Anio | Precio | Existencias:"<<endl;
    while (getline(input, linea)) {
        stringstream ss(linea);
        string marca, nombre, modelo_carro, anio_carro, precio, existencias;
        getline(ss, marca, ','); getline(ss, nombre, ','); getline(ss, modelo_carro, ','); getline(ss, anio_carro, ',');
        getline(ss, precio, ','); getline(ss, existencias, ',');
        if (nombre == nombre_consulta){                                                  
            cout<<marca<<","<<nombre<<","<<modelo_carro<<","<<anio_carro<<","<<precio<<","<<existencias<<endl;
        }
    }
    input.close();
}