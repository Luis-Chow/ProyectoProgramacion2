#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

class Vehiculo{
    private:
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

    public:
    void insercion();
    void borrar();
    void actualizar();
    void consulta();
};


