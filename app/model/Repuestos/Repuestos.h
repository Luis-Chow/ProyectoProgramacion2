#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

class Repuesto{
    private:
    string marca;
    string nombre;
    string modelo_carro;
    int anio_carro;
    int precio;
    int existencias;

    public:
    void insercion();
    void borrar();
    void actualizar();
    void consulta();
};