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
    char rentado[3];
    string motor;
    int ced_cliente;
    string fecha_de_entrega;
};

struct cliente{
    int cedula;
    string nombre;
    string apellido;
    string direccion;
    int cantidad_vehiculos_rentados;
    string email;
    char activo[3];
};

struct respuestos{
    string modelo;
    string marca;
    string nombre;
    string modelo_carro;
    int anio_carro;
    int precio;
    int existencias;
};

void borrarFilaCSV(const string& archivo, int filaABorrar) {
    ifstream input(archivo);

    ofstream temp("temp.csv");
    
    string linea;
    int numeroFila = 0;
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

int main(){
    int opcion1 = 0;
    cout << "¿Que archivo desea leer? \n 1 = vehiculos | 2 = clientes | 3 = repuestos\n";
    cin >> opcion1;
    ifstream input;

    switch (opcion1){
        case 1: { // Vehiculos
            int opcionx = 0;
            cout << "Que accion desea realizar? \n 1 = Borrar | 2 = Actualizar | 3 = Insercion | 4 = Lectura\n";
            cin >> opcionx;
            input.open("./bin/Vehiculos.csv");
            if (!input.is_open()) {
                cout << "Error al abrir el archivo Vehiculos.csv" << endl;
                return 1;
            }
            switch (opcionx) {
                case 1: { // Vehiculos > Borrar
                    int fila;
                    cout << "Que fila desea borrar? ";
                    cin >> fila;
                    input.close();
                    borrarFilaCSV("./bin/Vehiculos.csv", fila);
                    break;
                }
                case 2: // Vehiculos > Actualizar
                    // falta codigo
                    break;
                case 3: // Vehiculos > Insercion
                    // falta codigo
                    break;
                case 4: // Vehiculos > Lectura
                    // falta codigo
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
            break;
        }
        case 2: { // Clientes
            int opcionx = 0;
            cout << "Que accion desea realizar? \n 1 = Borrar | 2 = Actualizar | 3 = Insercion | 4 = Lectura\n";
            cin >> opcionx;
            input.open("./bin/Clientes.csv");
            if (!input.is_open()) {
                cout << "Error al abrir el archivo Clientes.csv" << endl;
                return 1;
            }
            switch (opcionx) {
                case 1: { // Clientes > Borrar
                    int fila;
                    cout << "Que fila desea borrar? ";
                    cin >> fila;
                    input.close();
                    borrarFilaCSV("./bin/Clientes.csv", fila);
                    break;
                }
                case 2: // Clientes > Actualizar
                    // falta codigo
                    break;
                case 3: // Clientes > Insercion
                    // falta codigo
                    break;
                case 4: // Clientes > Lectura
                    // falta codigo
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
            break;
        }
        case 3: { // Repuestos
            int opcionx = 0;
            cout << "Que accion desea realizar? \n 1 = Borrar | 2 = Actualizar | 3 = Insercion | 4 = Lectura\n";
            cin >> opcionx;
            input.open("./bin/Repuestos.csv");
            if (!input.is_open()) {
                cout << "Error al abrir el archivo repuestos.csv" << endl;
                return 1;
            }
            switch (opcionx) {
                case 1: { // Repuestos > Borrar
                    int fila;
                    cout << "Que fila desea borrar? ";
                    cin >> fila;
                    input.close();
                    borrarFilaCSV("./bin/repuestos.csv", fila);
                    break;
                }
                case 2: // Repuestos > Actualizar
                    // falta codigo
                    break;
                case 3: // Repuestos > Insercion
                    // falta codigo
                    break;
                case 4: // Repuestos > Lectura
                    // falta codigo
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
            break;
        }
        default:
            cout << "Opcion no valida" << endl;
            break;
    }
    return 0;
}
